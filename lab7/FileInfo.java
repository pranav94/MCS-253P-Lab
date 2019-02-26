class FileInfo {
    int diskNumber;
    int startingSector;
    int fileLength;

    public FileInfo(int diskNumber, int startingSector, int fileLength) {
        this.diskNumber = diskNumber;
        this.startingSector = startingSector;
        this.fileLength = fileLength;
    }
}