//  Convert Command
//  Converts Win32 line endings with Linux endings

int cmd_convert(string s) {
    int i;
    string *f;
    if(!s || s == "") return notify_fail("Convert what file?\n");
    s = resolv_path((string)this_player()->get_path(), s);
    if(!file_exists(s)) return notify_fail("No file to convert.\n");
    i=sizeof(f=explode(read_file(s), "\n\r"));
    if(!i || i <= 1) return notify_fail("Error, couldnt find any Win32 line endings in the file.\n");
    cp(s, s+".conv.bak");
    rm(s);
    while(i--) {
	write_file(s, f[i]);
    }
    write("File written successfully.  Original file backed up to *.conv.bak.");
    return 1;
}

void help() {
    write("This command will change standard Win32 line endings (\n\r) to a *nix style line "
      "ending (\n).");
}

