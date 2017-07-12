/**
 * Created by aliiz on 09/07/17.
 */
public class BranchUnconditional{

    private  String go_to;
    private int PC ;
    private static final String jpr = "00000111";
    private int imediate;
    private String bun;

    BranchUnconditional(String go_to, int PC ){

        this.go_to = go_to;
        this.PC = PC;

        imediate = Integer.parseInt(go_to) - PC - 1 ;


        bun = jpr + sign_extend(Integer.toBinaryString(imediate)).substring(8,16);


    }


    public String getBun() {
        return bun;
    }


    private String sign_extend(String t){

        int length = t.length();
        for(int i=0 ; i<16 - length; i++ )
            t = "0" + t;

        return  t;
    }


    public static void main(String[] args) {

        System.out.println(new BranchUnconditional("5", 10).getBun());


    }

}
