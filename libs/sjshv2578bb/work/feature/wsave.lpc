// save.c

int save_we()
{
	string file;

        if (stringp(file = this_object()->query("weapon_file"))) {
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int restore_we()
{
	string file;

        if( stringp(file = this_object()->query("weapon_file")) )
		return restore_object(file);
	return 0;
}
