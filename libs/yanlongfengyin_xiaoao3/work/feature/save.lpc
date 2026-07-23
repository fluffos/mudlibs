// save.c

varargs int save(string data)
{
	string file;

	if ( data && data != "" )
		return save_object(data);

	if( stringp(file = this_object()->query_save_file()) )
	{
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	
	return 0;
}

varargs int restore(string data)
{
	string file;

	if ( data && data != "" )
		return restore_object(data);

	if( stringp(file = this_object()->query_save_file()) )
		return restore_object(file);
	
	return 0;
}