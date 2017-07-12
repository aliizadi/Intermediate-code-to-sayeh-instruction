import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by aliiz on 09/07/17.
 */
public class Parser {

    private ArrayList<String> intermediateCode;
    private ArrayList<String> machineCode;
    private Map T = new HashMap();
    private Map variables = new HashMap();
    private int T_number_between_0_to_2 = 0 ;
    private int variable_number_in_memory = 100 ;

    Parser(ArrayList<String> intermediateCode){

        this.intermediateCode = intermediateCode;
        this.machineCode = new ArrayList<String>();



        if__goto__assignmentOroperation();

    }


    private boolean is_T(String t){

        boolean first_char_is_t = false;

        if(t.charAt(0) == 't')
            first_char_is_t = true;

        boolean char_are_number_except_first = true;

        for(int i =1 ; i<t.length(); i++){

            if(!Character.isDigit(t.charAt(i))) {
                char_are_number_except_first = false;
                break;
            }
        }

        return first_char_is_t & char_are_number_except_first;

    }

    private boolean is_digit(String t){

        boolean digit = true;

        for(int i =0 ; i<t.length(); i++){

            if(!Character.isDigit(t.charAt(i))){

                digit = false;
                break;
            }

        }

        return digit;
    }


    private void setT_number_between_0_to_3(String t) {


        if (T_number_between_0_to_2 > 2) {
            T_number_between_0_to_2 = 0;
            T.put(t, T_number_between_0_to_2);
            T_number_between_0_to_2++;

        }
        else {
            T.put(t, T_number_between_0_to_2);
            T_number_between_0_to_2++;
        }




    }

    private void setVariable_number_in_memory(String t){
        variables.put(t, variable_number_in_memory);
        variable_number_in_memory ++;

    }

    private void if__goto__assignmentOroperation(){

        for(int i=0; i<intermediateCode.size(); i++){

            String [] line_tokens = intermediateCode.get(i).split("[ ]+");

            if(line_tokens.length == 4 )
                if_statement(line_tokens, i);

            if(line_tokens.length == 2 )
                goto_statement(line_tokens, i);

            if(line_tokens.length == 1 )
                assignment_or_operation_statement(line_tokens);

        }

    }



    private void if_statement(String [] line_tokens, int PC ){


        String [] condition_tokens = line_tokens[1].split("<=|>=|>|<|==");

        if(!is_T(condition_tokens[0]) && !is_digit(condition_tokens[0]))
            if(!variables.containsKey(condition_tokens[0]))
                setVariable_number_in_memory(condition_tokens[0]);

        if(!is_T(condition_tokens[1]) && !is_digit(condition_tokens[1]))
            if(!variables.containsKey(condition_tokens[1]))
                setVariable_number_in_memory(condition_tokens[1]);


        boolean equal=false, less_than=false, greater_than=false, equal_less_than=false, equal_greater_than=false;

        String [] which_condition = line_tokens[1].split("[A-Za-z0-9]");



        boolean source1_isVariable = false ;
        boolean source2_isVariable = false ;

        boolean source1_isdigit = false ;
        boolean source2_isdigit = false ;

        boolean source1_is_t = false ;
        boolean source2_is_t = false ;

        int source1=0;
        int source2=0;

        if(is_T(condition_tokens[0])) {
            source1_is_t = false;
            source1 = (int) T.get(condition_tokens[0]);

        }

        else if (is_digit(condition_tokens[0])){
            source1_isdigit = true;
            source1 = Integer.parseInt(condition_tokens[0]);
        }

        else {
            source1_isVariable = true;
            source1 = (int) variables.get(condition_tokens[0]);
        }


        if(is_T(condition_tokens[1])) {
            source2_isVariable = false;
            source2 = (int) T.get(condition_tokens[1]);

        }
        else if (is_digit(condition_tokens[1])){
            source2_isdigit = true;
            source2 = Integer.parseInt(condition_tokens[1]);
        }
        else {
            source2_isVariable = true ;
            source2 = (int) variables.get(condition_tokens[1]);

        }





        for(int i =0 ; i<which_condition.length; i++)
            if(which_condition[i].compareTo("<=")==0)
                equal_less_than = true;

            else if (which_condition[i].compareTo(">=")==0)
                equal_greater_than = true;

            else if(which_condition[i].compareTo("==")==0)
                equal = true ;

            else if(which_condition[i].compareTo(">")==0)
                greater_than = true;

            else if(which_condition[i].compareTo("<")==0)
                    less_than = true;


        BranchConditional branchConditional = new BranchConditional(equal, less_than, greater_than, equal_less_than, equal_greater_than,
                                                                    source1, source2, source1_isVariable, source2_isVariable, source1_isdigit, source2_isdigit, source1_is_t, source2_is_t,line_tokens[3], PC);

        for(int i=0 ; i<branchConditional.getInstruction().size(); i++)

            machineCode.add(branchConditional.getInstruction().get(i));




    }

    private void goto_statement(String [] line_tokens, int PC){

        BranchUnconditional branchUnconditional = new BranchUnconditional(line_tokens[1], PC);
        machineCode.add(branchUnconditional.getBun());


    }

    private void assignment_or_operation_statement(String [] line_tokens){


        String [] destination_and_sources = line_tokens[0].split("=");
        String [] source1_source2 = destination_and_sources[1].split("[^a-zA-Z0-9]");


        if(is_T(destination_and_sources[0]))
            setT_number_between_0_to_3(destination_and_sources[0]);




        Assignment assignment;

        if(source1_source2.length == 1) {

            if(!is_T(destination_and_sources[0]) && !is_digit(destination_and_sources[0]))
                if(!variables.containsKey(destination_and_sources[0]))
                    setVariable_number_in_memory(destination_and_sources[0]);

            if(!is_T(source1_source2[0]) && !is_digit(source1_source2[0]))
                if(!variables.containsKey(source1_source2[0]))
                    setVariable_number_in_memory(source1_source2[0]);



            int destination =0, source  =0;

            boolean source_is_t = false;
            boolean source_is_digit = false;

            if(is_T(source1_source2[0])){
                source_is_t = true;
                source = (int) T.get(source1_source2[0]);
            }

            else if(is_digit(source1_source2[0])){
                source_is_digit = true;
                source = Integer.parseInt(source1_source2[0]);
            }

            destination =(int) variables.get(destination_and_sources[0]);




            assignment = new Assignment(source, destination, source_is_t, source_is_digit);


            for(int i=0 ; i<assignment.getInstruction().size(); i++)

                machineCode.add(assignment.getInstruction().get(i));




        }

        else if (source1_source2.length == 2) {




            if(!is_T(destination_and_sources[0]) && !is_digit(destination_and_sources[0]))
                if(!variables.containsKey(destination_and_sources[0]))
                    setVariable_number_in_memory(destination_and_sources[0]);

            if(!is_T(source1_source2[0]) && !is_digit(source1_source2[0]))
                if(!variables.containsKey(source1_source2[0]))
                    setVariable_number_in_memory(source1_source2[0]);

            if(!is_T(source1_source2[1]) && !is_digit(source1_source2[1]))
                if(!variables.containsKey(source1_source2[1]))
                    setVariable_number_in_memory(source1_source2[1]);


            String [] operator = destination_and_sources[1].split("[a-zA-Z0-9]");
            boolean and=false;  boolean or=false;  boolean not=false; boolean xor=false;
            boolean add=false;  boolean sub=false; boolean mul=false; boolean div=false;
            for(int i=0; i<operator.length; i++){

                if(operator[i].compareTo("+")==0)
                    add = true;
                else if(operator[i].compareTo("&")==0)
                    and = true;
                else if(operator[i].compareTo("|")==0)
                    or = true;
                else if(operator[i].compareTo("~")==0)
                    not = true;
                else if(operator[i].compareTo("*")==0)
                    mul = true;
                else if(operator[i].compareTo("/")==0)
                    div = true;
                else if(operator[i].compareTo("-")==0)
                    sub = true;
                else if(operator[i].compareTo("^")==0)
                    xor = true;


            }

            boolean source1_isVariable = false ;
            boolean source1_isT = false;
            boolean source1_isDigit = false;

            boolean source2_isVariable = false ;
            boolean source2_isT = false;
            boolean source2_isDigit = false;

            boolean destination_isVariable = false ;
            boolean destination_isT = false;





            int source1=0;
            int source2=0;
            int destination=0;

            /****************source1******************/
            if(is_T(source1_source2[0])) {
                source1_isT = true;
                source1 = (int) T.get(source1_source2[0]);

            }
            else if(is_digit(source1_source2[0])){
                source1_isDigit = true;
                source1 = Integer.parseInt(source1_source2[0]);
            }
            else{
                source1_isVariable = true;
                source1 = (int) variables.get(source1_source2[0]);
            }

            /****************source2******************/

            if(is_T(source1_source2[1])) {
                source2_isT = true;
                source2 = (int) T.get(source1_source2[1]);

            }
            else if(is_digit(source1_source2[1])){
                source2_isDigit = true;
                source2 = Integer.parseInt(source1_source2[1]);
            }
            else{
                source2_isVariable = true;
                source2 = (int) variables.get(source1_source2[1]);
            }

            /****************destination******************/

            if(is_T(destination_and_sources[0])) {
                destination_isT = true;
                destination = (int) T.get(destination_and_sources[0]);

            }
            else{
                destination_isVariable = true;
                destination = (int) variables.get(destination_and_sources[0]);

            }




            ArithmeticOrLogicOperator arithmeticOrLogicOperator = new ArithmeticOrLogicOperator(destination, source1, source2,
                                                              and, or, not, xor, add, sub, mul, div,
                                                                source1_isVariable, source1_isT, source1_isDigit,
                                                                source2_isVariable, source2_isT, source2_isDigit,
                                                                destination_isVariable, destination_isT);

            for(int i=0 ; i<arithmeticOrLogicOperator.getInstruction().size(); i++)

                machineCode.add(arithmeticOrLogicOperator.getInstruction().get(i));


        }

    }


    public ArrayList<String> getMachineCode() {
        return machineCode;
    }
}
