import java.util.ArrayList;

/**
 * Created by aliiz on 09/07/17.
 */
public class BranchConditional {

    private static final String cmp = "1110";
    private  static final  String awp = "00001010";
    private  static final  String brz = "00001000";
    private  static final  String brc = "00001001";
    private  static final  String mvr = "0001";
    private static  final String three = "00000011";
    private static final  String minus_three = "11111101";
    private static final String mil_mih = "1111";
    private static final String lda = "0010";
    private static final String jpr = "00000111";
    private static final String cwp = "00000110";



    private ArrayList<String> instruction = new ArrayList<>();

    public BranchConditional(boolean equal, boolean less_than, boolean greater_than, boolean equal_less_than, boolean equal_greater_than,
                             int source1, int source2,
                             boolean src1_isVariable, boolean src2_isVariable,boolean source1_isdigit, boolean source2_isdigit, boolean source1_is_t, boolean source2_is_t,
                             String branch , int PC ) {

        int imediate = Integer.parseInt(branch) - PC - 1 ;



        if(source1_is_t && source1_is_t)
            instruction.add(cmp + extend_1bit_to_two_bit(Integer.toBinaryString(source1))+extend_1bit_to_two_bit(Integer.toBinaryString(source2)));

        else if (source1_is_t && src2_isVariable){
            instruction.add(awp+three);
            instruction.add(mil_mih + "0100"+ extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih + "0101"+ extend(Integer.toBinaryString(source2)).substring(0, 8));
            instruction.add(lda +"00" + "01");
            instruction.add(cwp);
            instruction.add(cmp + extend_1bit_to_two_bit(Integer.toBinaryString(source1)) + "11");
        }

        else if(src1_isVariable && source1_is_t){
            instruction.add(awp+three);
            instruction.add(mil_mih + "0100"+ extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih + "0101"+ extend(Integer.toBinaryString(source1)).substring(0, 8));
            instruction.add(lda +"00" + "01");
            instruction.add(cwp);
            instruction.add(cmp + extend_1bit_to_two_bit(Integer.toBinaryString(source2)) + "11");
        }
        else if (src1_isVariable && src2_isVariable){
            instruction.add(awp+three);
            instruction.add(mil_mih + "1000"+ extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih + "1001"+ extend(Integer.toBinaryString(source1)).substring(0, 8));
            instruction.add(lda +"00" + "10");

            instruction.add(mil_mih + "1100"+ extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih + "1101"+ extend(Integer.toBinaryString(source2)).substring(0, 8));
            instruction.add(lda +"01" + "11");

            instruction.add(cmp+"00" + "01");
            instruction.add(cwp);

        }

        else if (source1_isdigit && src2_isVariable){

            instruction.add(awp + three);
            instruction.add(mil_mih + "0000"+ extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih + "0001"+ extend(Integer.toBinaryString(source1)).substring(0, 8));

            instruction.add(mil_mih + "1000"+ extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih + "1001"+ extend(Integer.toBinaryString(source2)).substring(0, 8));

            instruction.add(lda +"01" + "10");
            instruction.add(cmp+"00" + "01");
            instruction.add(cwp);

        }

        else if(src1_isVariable && source2_isdigit){
            instruction.add(awp + three);
            instruction.add(mil_mih + "0000"+ extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih + "0001"+ extend(Integer.toBinaryString(source2)).substring(0, 8));

            instruction.add(mil_mih + "1000"+ extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih + "1001"+ extend(Integer.toBinaryString(source1)).substring(0, 8));

            instruction.add(lda +"01" + "10");
            instruction.add(cmp+"00" + "01");
            instruction.add(cwp);

        }

        else if(source1_isdigit && source2_is_t){

            instruction.add(mil_mih + "1100"+ extend(Integer.toBinaryString(source1)).substring(8,16));
            instruction.add(mil_mih + "1101"+ extend(Integer.toBinaryString(source1)).substring(0, 8));
            instruction.add(cmp+"11" + extend_1bit_to_two_bit(Integer.toBinaryString(source2)));

        }

        else if(source1_is_t && source2_isdigit){


            instruction.add(mil_mih + "1100"+ extend(Integer.toBinaryString(source2)).substring(8,16));
            instruction.add(mil_mih + "1101"+ extend(Integer.toBinaryString(source2)).substring(0, 8));
            instruction.add(cmp+"11" + extend_1bit_to_two_bit(Integer.toBinaryString(source1)));

        }

        if(equal)
            instruction.add(brz+sign_extend(Integer.toBinaryString(imediate)).substring(8,16));

        else if(less_than)
            instruction.add(brc + sign_extend(Integer.toBinaryString(imediate)).substring(8,16));

        //TODO handle other conditions



    }

    private String sign_extend(String t){

        int length = t.length();
        for(int i=0 ; i<16 - length; i++ )
            t = "0" + t;

        return  t;
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





    public ArrayList<String> getInstruction() {
        return instruction;
    }
}