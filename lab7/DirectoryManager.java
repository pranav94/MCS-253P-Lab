import java.util.*;

class DirectoryManager {
    Hashtable<String, FileInfo> T = new Hashtable<String, FileInfo>();

    void enter(StringBuffer key, FileInfo file) {
        T.put(key.toString(), file);
    }

    FileInfo lookup(StringBuffer key) {
        return T.get(key.toString());
    }
}