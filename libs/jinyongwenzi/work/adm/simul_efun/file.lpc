// file.c

void cat(string file)
{
	write(read_file(file));
}

void assure_file(string file)
{
	string path = "", *dir;
	int i, j;

	if (file_size(file)!=-1)
		return;

	dir = explode(file, "/");
	j = sizeof(dir) - 1;
	for(i=0; i<j; i++) {
		path += "/" + dir[i];
		if (file_size(path) == -1)
			mkdir(path);
	}
}

varargs void log_file(string file, string text, mixed ob, mixed *obs)
{
	LOG_D->log_file(file, text, ob, obs);
}

string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	return file_name(ob);
}
