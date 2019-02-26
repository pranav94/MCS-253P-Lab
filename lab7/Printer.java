import java.io.*;

class Printer {
    int printerNumber = 0;
    boolean isFree = true;

    public Printer(int printerNumber) {
        this.printerNumber = printerNumber;
    }

    synchronized void print(StringBuffer data) throws IOException {
        File file = new File("output/PRINTER" + printerNumber);
        BufferedWriter br = new BufferedWriter(new FileWriter(file, true));
        try {
            Thread.sleep(2750);
        } catch (InterruptedException e) {
            System.out.println(e.getMessage() + "\n" + e.getStackTrace());
        }
        br.append(data.toString() + "\n");
        br.close();
    }
}
