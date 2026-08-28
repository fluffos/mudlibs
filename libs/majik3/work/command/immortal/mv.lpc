 // Modified 'cp.c' to work as a Unix style 'mv' command.
 //  - Mordoc@Majik
 //  - A little fix by Zimbe

int main (string str) {
    int ret;
    string source, dest;

    seteuid (getuid());

    if(!str) {
        notify_fail("usage: mv <source> <destination>\n");
        return 0;
    }

    if (sscanf(str, "%s %s", source, dest) != 2) {
        notify_fail ("usage: mv <source> <destination>\n");
        return 0;
    }

    if (!absolute_path (source))
            source = this_player()->query_cwd() + source;

    if (!absolute_path (dest))
            dest = this_player()->query_cwd() + dest;

    source = resolve_path (source);
    dest = resolve_path (dest);

    if (file_size (source) < 0) {
            notify_fail (source + ": No such file or directory.\n");
            return 0;
    }

    if (file_size(dest) > 0) {
        notify_fail("Destination exists!\n");
        return 0;
    }

    if (file_size(dest) < 0) {
        notify_fail("Destination bad or permission denied.\n");
        return 0;
    }

    ret = cp (source, dest);
    if (!ret) {
        notify_fail ("Failed.\n");
        return 0;
    }

    rm (source);
    write ("Moved: "+source+" -> "+dest+"\n");
    return 1;
}
