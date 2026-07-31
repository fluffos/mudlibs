// file.c

void cat(string file)
{
    if (previous_object())
        seteuid(geteuid(previous_object()));
    else
        seteuid(ROOT_UID);
    write(read_file(file));
}

void assure_file(string file)
{
    string path, *dir;
    int i;

    if (file_size(file) != -1) return;

    seteuid(ROOT_UID);
    dir = explode(file, "/");

    if (file[strlen(file) - 1] != '/')
        // the file is refer to a file, not directory
        dir = dir[0..sizeof(dir)-2];

    path = "/";
    for (i = 0; i < sizeof(dir); i++)
    {
        path += dir[i];
        mkdir(path);
        path += "/";
    }

    dir = 0;
// added by mudring
    seteuid(getuid());
}

void log_file(string file, string text)
{
    MONITOR_D->log_file(file, text);
}

string base_name(object ob)
{
    string file;

    if (sscanf(file_name(ob), "%s#%*d", file) == 2)
        return file;
    else
        return file_name(ob);
}

int file_lines(string file)
{
    int i;
    int jmp;

    i = 65536;
    jmp = i / 2;

    // added by mudring
    seteuid(ROOT_UID);
    while (jmp)
    {
        if (read_file(file, i, 1)) i += jmp; else
                       i -= jmp;
        jmp /= 2;
    }
    // added by mudring
    seteuid(getuid());

    return i - 1;
}
