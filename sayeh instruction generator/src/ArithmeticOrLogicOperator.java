import java.util.ArrayList;

/**
 * Created by aliiz on 09/07/17.
 */
public class ArithmeticOrLogicOperator {

    private static final String and= "0110";
    private static final String orr = "0111";
    private static final String not = "1000";
    private static final String add = "1011";
    private static final String sub = "1100";
    private static final String mul = "1101";
    private static final String div = "1001";
    private static final String xor = "1010";
    private static final String mvr = "0001";
    private static final String sta = "0011";
    private static final String awp = "00001010";
    private static  final String three = "00000011";
    private static final  String minus_three = "11111101";
    private static final String cwp = "00000110";

    private static final String mil_mih = "1111";
    private static final String lda = "0010";


    private ArrayList<String> instruction = new ArrayList<>();

    private boolean is_and, is_or, is_not, is_xor, is_add, is_sub, is_mul, is_div;

    ArithmeticOrLogicOperator(int destination, int source1, int source2, boolean is_and, boolean is_or, boolean is_not, boolean is_xor,
                              boolean is_add, boolean is_sub, boolean is_mul, boolean is_div,
                              boolean source1_isVariable,
                              boolean source1_isT,
                              boolean source1_isDigit,
                              boolean source2_isVariable,
                              boolean source2_isT,
                              boolean source2_isDigit,
                              boolean destination_isVariable,
                              boolean destination_isT){


        this.is_add = is_add;
        this.is_and = is_and;
        this.is_div = is_div;
        this.is_mul = is_mul;
        this.is_not = is_not;
        this.is_or = is_or;
        this.is_sub = is_sub;
        this.is_xor = is_xor;

        if(source1_isDigit && source2_isDigit){

            instruction.add(awp + three);
            instruction.add(mil_mih+"0000" + extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih+"0001" + extend(Integer.toBinaryString(source1)).substring(0,8));

            instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(source2)).substring(0,8));

            instruction.add(which_operation() + "0001");

            if(destination_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));
                instruction.add((sta+ "0100"));
                instruction.add(cwp);
            }

            else if(destination_isT) {
                instruction.add(cwp);
                instruction.add(mvr + extend_1bit_to_two_bit(Integer.toBinaryString(destination)));
            }

        }



        else if(source1_isT && source2_isT){

            instruction.add(mvr + "11" + extend_1bit_to_two_bit(Integer.toBinaryString(source1)));
            instruction.add(which_operation() + "11" + extend_1bit_to_two_bit(Integer.toBinaryString(source2)));

            if(destination_isT)
                instruction.add(mvr + extend_1bit_to_two_bit(Integer.toBinaryString(destination))+"11");

            else if(destination_isVariable){
                instruction.add(awp + three);
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));
                instruction.add(sta + "0100");

                instruction.add(cwp);
            }

        }



        else if (source1_isVariable && source2_isVariable){

            instruction.add(awp + three);


            instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(source1)).substring(0,8));
            instruction.add(lda + "0001" );


            instruction.add(mil_mih+"1100" + extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih+"1101" + extend(Integer.toBinaryString(source2)).substring(0,8));
            instruction.add(lda + "1011" );

            instruction.add(which_operation() + "0010");

            if(destination_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));
                instruction.add(sta +"0100");
                instruction.add(cwp);
            }
            else if (destination_isT){
             instruction.add(cwp);
             instruction.add(mvr + extend_1bit_to_two_bit(Integer.toBinaryString(destination))+"11");
            }

        }


        else if((source1_isDigit && source2_isVariable) || (source1_isVariable&& source2_isDigit)){

            instruction.add(awp + three);

            if(source1_isDigit){
                instruction.add(mil_mih+"0000" + extend(Integer.toBinaryString(source1)).substring(8,16));
                instruction.add(mil_mih+"0001" + extend(Integer.toBinaryString(source1)).substring(0,8));
            }
            else if(source2_isDigit){
                instruction.add(mil_mih+"0000" + extend(Integer.toBinaryString(source2)).substring(8,16));
                instruction.add(mil_mih+"0001" + extend(Integer.toBinaryString(source2)).substring(0,8));
            }

            if(source1_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(source1)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(source1)).substring(0,8));
                instruction.add(lda + "1001");
            }
            else if(source2_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(source2)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(source2)).substring(0,8));
                instruction.add(lda + "1001");
            }

            instruction.add(which_operation() + "0010");

            if(destination_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));
                instruction.add(sta +"0100");
                instruction.add(cwp);
            }
            else if (destination_isT){
                instruction.add(cwp);
                instruction.add(mvr + extend_1bit_to_two_bit(Integer.toBinaryString(destination))+"11");
            }

        }


        else if((source1_isDigit && source2_isT) || (source1_isT && source2_isDigit)){

            instruction.add(awp + three);

            if(source1_isDigit){
                instruction.add(mil_mih+"0000" + extend(Integer.toBinaryString(source1)).substring(8,16));
                instruction.add(mil_mih+"0001" + extend(Integer.toBinaryString(source1)).substring(0,8));
            }
            else if(source2_isDigit){
                instruction.add(mil_mih+"0000" + extend(Integer.toBinaryString(source2)).substring(8,16));
                instruction.add(mil_mih+"0001" + extend(Integer.toBinaryString(source2)).substring(0,8));
            }

            instruction.add(cwp);

            if(source1_isT)
                instruction.add(which_operation()+ "11" + extend_1bit_to_two_bit(Integer.toBinaryString(source1)));
            else if(source2_isT)
                instruction.add(which_operation()+ "11" + extend_1bit_to_two_bit(Integer.toBinaryString(source2)));

            if(destination_isT)
                instruction.add(mvr + extend_1bit_to_two_bit(Integer.toBinaryString(destination))+"11");

            else if(destination_isVariable){
                instruction.add(awp + three);
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));
                instruction.add(sta +"0100");
                instruction.add(cwp);
            }

        }



        else if((source1_isVariable && source2_isT) || ( source1_isT && source2_isVariable )){

            instruction.add(awp + three);

            if(source1_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(source1)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(source1)).substring(0,8));
                instruction.add(lda + "0001");
            }
            else if(source2_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(source2)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(source2)).substring(0,8));
                instruction.add(lda + "0001");
            }

            if(destination_isVariable){
                instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
                instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));
                instruction.add(sta +"0100");
                instruction.add(cwp);
            }
            else if (destination_isT){
                instruction.add(cwp);
                instruction.add(mvr + extend_1bit_to_two_bit(Integer.toBinaryString(destination))+"11");
            }


        }
    }


    public ArrayList<String> getInstruction() {
        return instruction;
    }

    public String which_operation(){

        if(is_add)
            return  add;
        else if(is_and)
            return and;
        else if(is_or)
            return orr;
        else if(is_not)
            return not;
        else if(is_sub)
            return  sub;
        else if(is_mul)
            return mul;
        else if(is_div)
            return div;
        else if(is_xor)
            return xor;
        else return "";

    }

    private String extend(String t){

        int length = t.length();
        for(int i=0 ; i<16 - length; i++ )
            t = "0" + t;

        return  t;
    }


    private String  extend_1bit_to_two_bit(String t){

        if(t.length() == 1 )
            return "0" + t ;
        else
            return t;

    }




}
