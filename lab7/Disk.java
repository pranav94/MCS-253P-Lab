import java.util.*;

class Disk {
    static final int NUM_SECTORS = 1024;
    StringBuffer sectors[] = new StringBuffer[NUM_SECTORS];
    int currentSector = 0;
    int diskNumber = 0;
    boolean isFree = true;

    public Disk(int diskNumber) {
        this.diskNumber = diskNumber;
    }

    synchronized void write(int sector, StringBuffer data) {
        sectors[sector] = data;
        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            System.out.println(e.getMessage() + "\n" + e.getStackTrace());
        }
        currentSector++;
    }

    StringBuffer read(int sector) {
        try {
            Thread.sleep(200);
        } catch (InterruptedException e) {
            System.out.println(e.getMessage() + "\n" + e.getStackTrace());
        }
        return sectors[sector];
    }
}