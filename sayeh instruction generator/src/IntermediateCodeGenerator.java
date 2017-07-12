import org.omg.PortableInterceptor.INACTIVE;
import sun.awt.X11.InfoWindow;

import java.io.*;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by aliiz on 09/07/17.
 */
public class IntermediateCodeGenerator {

    private ArrayList<String> code = new ArrayList<>();
    private ArrayList<String> intermediateCode = new ArrayList<>();

    IntermediateCodeGenerator(){




        try{
            File file = new File("/home/aliiz/Desktop/simpiler/inter.txt");
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            while ((line = bufferedReader.readLine()) != null) {
                code.add(line);
            }

            fileReader.close();
        }catch(IOException e){

            e.printStackTrace();

        }

        parser(code);


        Parser parser = new Parser(intermediateCode);

        for(int i=0 ; i<parser.getMachineCode().size(); i++)
            System.out.println(parser.getMachineCode().get(i));



    }


    private void parser(ArrayList<String> code){

        for (int i=2; i<code.size(); i++){

            String [] spilt_of_each_line = code.get(i).split("[ ]+");

            String each_line = new String();

            for(int j=3; j<spilt_of_each_line.length; j++){

                each_line += spilt_of_each_line[j]+" ";

            }

            intermediateCode.add(each_line);

        }



    }

    public ArrayList<String> getIntermediateCode() {
        return intermediateCode;
    }


}
