// file.c

int file_size(string file)
{
    object me=this_player();

    if(!me) me=previous_object();
    if(!me) return efun::file_size(file);
    if(SECURITY_D->valid_read(file,me))
      return efun::file_size(file);
    else
      return -1;
}
void cat(string file, int trans)
{
  string tmp;

  tmp = read_file(file);

  if (trans)
    tmp = trans_color(tmp);

  write(tmp);
  tmp = 0;
}

void log_file(string file, string text)
{
	write_file(LOG_DIR + file, text);
}

void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");
	dir = dir[0..sizeof(dir)-2];
	path = "/";
	for(i=0; i<sizeof(dir); i++) {
		path += dir[i];
		mkdir(path);
		path += "/";
	}
}

string base_name(object ob)
{
	string file;

        if( sscanf(file_name(ob), "%s#%*d", file)==2 )
                return file;
       else
                return file_name(ob);
}

int mkdirs(string path)
{
        string *parts, dir;
        int j;

        seteuid(geteuid(previous_object()));
        parts = explode(path, "/");
	dir = "";
        for (j = 0; j < sizeof(parts); j++) {
                dir += parts[j];
                mkdir(dir);
		dir += "/";
        }
     j=sizeof(dir);
    return (file_size(dir[0..j-1]) == -2);
}
