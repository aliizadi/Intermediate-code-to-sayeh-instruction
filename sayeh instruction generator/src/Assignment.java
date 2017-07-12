import java.util.ArrayList;

/**
 * Created by aliiz on 09/07/17.
 */

public class Assignment {



    private static final String sta = "0011";
    private static final String mil_mih = "1111";
    private static final String awp = "00001010";
    private static final String cwp = "00000110";
    private static  final String three = "00000011";
    private static final  String minus_three = "11111101";

    private ArrayList<String> instruction = new ArrayList<>();

    Assignment(int source , int destination , boolean source_is_t , boolean source_is_digit){


        if(source_is_digit){

            instruction.add(awp + three);


            instruction.add(mil_mih+"0000" + extend(Integer.toBinaryString(source)).substring(8,16));
            instruction.add(mil_mih+"0001" + extend(Integer.toBinaryString(source)).substring(0,8));

            instruction.add(mil_mih+"0100" + extend(Integer.toBinaryString(destination)).substring(8,16));
            instruction.add(mil_mih+"0101" + extend(Integer.toBinaryString(destination)).substring(0,8));

            instruction.add((sta+ "0100"));

            instruction.add(cwp);

        }

        else if (source_is_t){

            instruction.add(mil_mih+"1100" + extend(Integer.toBinaryString(destination)).substring(8,16));
            instruction.add(mil_mih+"1101" + extend(Integer.toBinaryString(destination)).substring(0,8));

            instruction.add((sta+ "11" + extend_1bit_to_two_bit(Integer.toBinaryString(source))));


        }



    }


    public ArrayList<String> getInstruction() {
        return instruction;
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
