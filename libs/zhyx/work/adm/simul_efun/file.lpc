// file.c
#include <ansi.h>

void cat(string file)
{
    if (previous_object())
        seteuid(geteuid(previous_object()));
    else
        seteuid(ROOT_UID);
    write(read_file(file));
}

void log_file(string file, string text)
{
    seteuid(ROOT_UID);
    write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
    string path, *dir;
    int i;

    if (file_size(file) != -1)
        return;

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
}

string base_name(object ob)
{
    string file;

    if (sscanf(file_name(ob), "%s#%*d", file) == 2)
        return file;
    else
        return file_name(ob);
}

string color_filter(string content)
{
    if (!content)
        return "";

    // Foreground color
    content = replace_string(content, "$BLK$", BLK);
    content = replace_string(content, "$RED$", RED);
    content = replace_string(content, "$GRN$", GRN);
    content = replace_string(content, "$YEL$", YEL);
    content = replace_string(content, "$BLU$", BLU);
    content = replace_string(content, "$MAG$", MAG);
    content = replace_string(content, "$CYN$", CYN);
    content = replace_string(content, "$WHT$", WHT);
    content = replace_string(content, "$HIR$", HIR);
    content = replace_string(content, "$HIG$", HIG);
    content = replace_string(content, "$HIY$", HIY);
    content = replace_string(content, "$HIB$", HIB);
    content = replace_string(content, "$HIM$", HIM);
    content = replace_string(content, "$HIC$", HIC);
    content = replace_string(content, "$HIW$", HIW);
    content = replace_string(content, "$NOR$", NOR);

    // Background color
    content = replace_string(content, "$BBLK$", BBLK);
    content = replace_string(content, "$BRED$", BRED);
    content = replace_string(content, "$BGRN$", BGRN);
    content = replace_string(content, "$BYEL$", BYEL);
    content = replace_string(content, "$BBLU$", BBLU);
    content = replace_string(content, "$BMAG$", BMAG);
    content = replace_string(content, "$BCYN$", BCYN);
    content = replace_string(content, "$HBRED$", HBRED);
    content = replace_string(content, "$HBGRN$", HBGRN);
    content = replace_string(content, "$HBYEL$", HBYEL);
    content = replace_string(content, "$HBBLU$", HBBLU);
    content = replace_string(content, "$HBMAG$", HBMAG);
    content = replace_string(content, "$HBCYN$", HBCYN);

    content = replace_string(content, "$U$", U);
    content = replace_string(content, "$BLINK$", BLINK);
    content = replace_string(content, "$REV$", REV);
    content = replace_string(content, "$HIREV$", HIREV);
    content = replace_string(content, "$BOLD$", BOLD);

    return content;
}

void color_cat(string file)
{
    if (previous_object())
        seteuid(geteuid(previous_object()));
    else
        seteuid(ROOT_UID);

    write(color_filter(read_file(file)));
}

int file_lines(string file)
{
#ifdef DOING_IMPROVED
    return efun::file_lines(file);
#else
    int i;
    int jmp;

    i = 65536;
    jmp = i / 2;

    while (jmp)
    {
        if (read_file(file, i, 1))
            i += jmp;
        else
            i -= jmp;
        jmp /= 2;
    }

    return i - 1;
#endif
}

void tail(string file)
{
    int line = file_length(file);

    if (line > 0)
    {
        int start = line - 10;
        if (start < 1)
        {
            start = 1;
        }
        write(read_file(file, start, line));
    }
}

// Function name:   read_lines
// Description:     reads in a file, ignoring lines that begin with '#'
// Arguements:      file: a string that shows what file to read in.
// Return:          Array of nonblank lines that don't begin with '#'
// Note:            must be declared nosave (else a security hole)
string *read_lines(string file)
{
    string *list;
    string str;
    int i;

    str = read_file(file);
    if (!str)
        return ({});

    list = explode(str, "\n");
    for (i = 0; i < sizeof(list); i++)
        if (list[i][0] == '#' || list[i][0] == ';')
            list[i] = 0;

    list -= ({ 0 });
    return list;
}

// 游戏配置内容的读取或设置
varargs mixed env(string key, mixed value)
{
    if (nullp(key))
    {
        return ENV_D->query_entire_dbase();
    }

    if (nullp(value))
    {
        return ENV_D->query(key);
    }
    else
    {
        return ENV_D->set(key, value);
    }
}
