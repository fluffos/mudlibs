// save.c

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
	{
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int restore()
{
	string file;

	if( stringp(file = this_object()->query_save_file()) && (file_size(file+".o") > 0) )
		return restore_object(file);
	else
		return 0;
}