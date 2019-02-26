class ResourceManager {
    Disk[] disks;
    Printer[] printers;
    int[] sectors;
    int NUMBER_OF_DISKS = 0;
    int NUMBER_OF_PRINTERS = 0;

    public ResourceManager(int NUMBER_OF_DISKS, int NUMBER_OF_PRINTERS) {
        this.sectors = new int[NUMBER_OF_DISKS];
        this.NUMBER_OF_DISKS = NUMBER_OF_DISKS;
        this.NUMBER_OF_PRINTERS = NUMBER_OF_PRINTERS;
        this.disks = new Disk[NUMBER_OF_DISKS];
        this.printers = new Printer[NUMBER_OF_PRINTERS];

        for (int i = 0; i < NUMBER_OF_DISKS; i++)
            this.disks[i] = new Disk(i + 1);

        for (int i = 0; i < NUMBER_OF_PRINTERS; i++)
            this.printers[i] = new Printer(i + 1);
    }

    synchronized public Disk getDisk() {
        while (true) {
            for (int i = 0; i < this.NUMBER_OF_DISKS; i++)
                if (this.disks[i].isFree) {
                    this.disks[i].isFree = false;
                    return this.disks[i];
                }
            try {
                this.wait();
            } catch (InterruptedException ie) {
                System.out.println(ie.getMessage());
            }
        }
    }

    synchronized public void releaseDisk(Disk disk) {
        disk.isFree = true;
        this.notify();
    }

    public Disk getDisk(int i) {
        return disks[i - 1];
    }

    synchronized public Printer getPrinter() {
        while (true) {
            for (int i = 0; i < this.NUMBER_OF_PRINTERS; i++)
                if (this.printers[i].isFree) {
                    this.printers[i].isFree = false;
                    return this.printers[i];
                }
            try {
                this.wait();
            } catch (InterruptedException ie) {
                System.out.println(ie.getMessage());
            }
        }
    }

    synchronized public void releasePrinter(Printer printer) {
        printer.isFree = true;
        this.notify();
    }

}