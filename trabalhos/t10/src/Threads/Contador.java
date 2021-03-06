package Threads;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;

class Contador extends Thread {
    private Array array;
    private String string="";
    Contador(Array a) {
        array = a;
    }

    private void ordenaVetor(String linha){
        int j;
        String[] vetor2 = linha.split(",");
        int tamanho = vetor2.length;
        int[] vetor = new int[tamanho];

        for(j=0;j<tamanho;j++) {
            vetor[j] = Integer.parseInt(vetor2[j]);
        }

        Arrays.sort(vetor);

        for (j=0; j<tamanho; j++) {
            string = string.concat(vetor[j] + ",");
        }

    }

    @Override
    public void run() {
        int arq;
        while (true) {
            synchronized (this) {
                array.i++;
                arq = array.i;
                if (arq > 3000) {
                    break;
                }
            }

            try {
                FileReader fr = new FileReader("source-files/"+arq+".txt");
                BufferedReader br = new BufferedReader(fr);
                while (br.ready()) {
                    String linha = br.readLine();
                    ordenaVetor(linha);
                }
            } catch (Exception ex) {
                Logger.getLogger(Contador.class.getName()).log(Level.SEVERE, null, ex);
            }

            try {
                FileWriter fw = new FileWriter("output-files/"+arq+".txt");
                BufferedWriter bw = new BufferedWriter(fw);
                bw.write(string);
                bw.close();
                fw.close();
            } catch (Exception ignored) {
            }

            string = "";
        }
    }
}
