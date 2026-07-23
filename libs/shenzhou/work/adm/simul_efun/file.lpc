// Code of ShenZhou
// /adm/daemons/file.c
// modified by sdong to support Big5, 11/25/98
// modify by Karlopex@sz at 06/03/2002


void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");
        if (file[strlen(file) - 1] != '/') // the file is refer to a file, not directory
		dir = dir[0..sizeof(dir)-2];
	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}
	dir = 0;
}

string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
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
                if (read_file(file, i, 1)) i += jmp; else
                                           i -= jmp;
                jmp /= 2;
        }

        return i - 1;
#endif
}

