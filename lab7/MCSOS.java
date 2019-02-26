public class MCSOS {
    final static int NUMBER_OF_USERS = 1;
    final static int NUMBER_OF_DISKS = 2;
    final static int NUMBER_OF_PRINTERS = 3;
    public static DirectoryManager dm = new DirectoryManager();
    public static ResourceManager rm = new ResourceManager(NUMBER_OF_DISKS, NUMBER_OF_PRINTERS);

    public static void createUserThreads() {
        for (int i = 0; i < NUMBER_OF_USERS; i++) {
            Thread user = new Thread(new User(i + 1, dm, rm), "Thread " + i);
            user.start();
        }
    }

    public static void main(String[] args) {
        createUserThreads();
    }
}