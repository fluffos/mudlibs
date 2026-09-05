// file.c

void cat(string file)
{
        string text = read_file(file);
        if( sizeof(text) < 8192 )
                message("write",text,this_player());
        else
                write("文件长度大于8192字节，请使用 more 指令查看。\n");
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

/*object new(string file,ing flag)
{	
	object ob;
	if(!stringp(file)) return;
	if(!flag)
	{
	if( file->query_unique() )  {
            if(clonep()) {  // only the cloned copy can have unique item.
		if( !objectp(ob = new(file->clone_file())) ) return;
            } else { // master copy can't have the unique item.
                     // mon 4/5/98
                if(!file->query("replace_file") ||
                   !objectp(ob = efun::new(file->query("replace_file")))) return;
            }}
	}
	else	
		return efun::new(file);
	}
	else    return efun::new(file);
}*/

//重载get_dir，避免返回以"."开头的目录和文件，如".svn"
mixed *get_dir(string dir,int arg)
{
        mixed *list;
        int i;

        if (!arg) arg = 0;
        list = efun::get_dir(dir,arg);
        i = sizeof(list);
        while(i--)
        {
                if (arg != -1)
                {
                        if (sscanf(list[i],".%*s"))
                        {
                                list -= ({list[i]});
                                i--;
                        }
                }
                else
                        if (sscanf(list[i][0],".%*s"))
                        {
                                list -= ({list[i]});
                                i--;
                        }
                if (i<0) break;
        }
        return list;

}