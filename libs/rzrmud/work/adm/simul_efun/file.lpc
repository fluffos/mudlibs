// file.c

void cat(string file)
{
	write(read_file(file));
}

void log_file(string file, string text)
{
	write_file(LOG_DIR + file, ctime(time()) + "  " + text);
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


// by emotion
void remove_rzr_file(string rzr_id)
{
	int num;
	string safe_rzr_id;
	  // security
	if (sscanf( rzr_id, "rzr%d", num ) != 1)
		return;

	seteuid(ROOT_UID);
	safe_rzr_id = "rzr" + num;
	rm("/data/npc/rzr/" + safe_rzr_id + ".o");
}

string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}
