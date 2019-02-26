import java.io.*;

class User extends Thread {

    int user;
    DirectoryManager dm;
    ResourceManager rm;

    public User(int user, DirectoryManager dm, ResourceManager rm) {
        this.user = user;
        this.dm = dm;
        this.rm = rm;
    }

    public FileInfo getOrCreateFileInfo(String fileName, Disk disk) {
        StringBuffer fileStringBuffer = new StringBuffer(fileName);
        FileInfo f;
        if ((f = dm.lookup(fileStringBuffer)) == null)
            f = new FileInfo(disk.diskNumber, disk.currentSector, 0);

        dm.enter(fileStringBuffer, f);

        return f;
    }

    public void synchronizedWrite(FileInfo f, BufferedReader br, Disk disk) throws IOException {
        int sector = f.startingSector;
        String text;
        while (!(text = br.readLine()).startsWith((".end")))
            disk.write(sector++, new StringBuffer(text));
        f.fileLength = sector - f.startingSector;
        rm.releaseDisk(disk);
    }

    public void writeFileToDisk(String fileName, BufferedReader br) throws IOException {
        Disk disk = rm.getDisk();
        FileInfo f = getOrCreateFileInfo(fileName, disk);
        synchronizedWrite(f, br, disk);
    }

    public void printFileFromDisk(String fileName) throws IOException {
        StringBuffer fileStringBuffer = new StringBuffer(fileName);
        FileInfo f = dm.lookup(fileStringBuffer);
        Disk disk = rm.getDisk(f.diskNumber);
        Printer printer = rm.getPrinter();
        for (int sector = f.startingSector; sector < f.startingSector + f.fileLength; sector++) {
            StringBuffer s = disk.read(sector);
            printer.print(s);
        }
        rm.releasePrinter(printer);
    }

    private void readInput() {
        try {
            File file = new File("input/USER" + user);
            String text, command, fileName;
            BufferedReader br = new BufferedReader(new FileReader(file));
            while ((text = br.readLine()) != null) {
                String[] input = text.split(" ");
                command = input[0];
                fileName = input[1];

                if (command.equals(".save"))
                    writeFileToDisk(fileName, br);
                else if (command.equals(".print"))
                    printFileFromDisk(fileName);
            }
            br.close();
        } catch (IOException e) {
            System.out.println(e.getMessage() + "\n");
        }
    }

    @Override
    public void run() {
        readInput();
    }
}