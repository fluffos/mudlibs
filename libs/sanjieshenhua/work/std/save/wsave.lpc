// save.c

string query_weapon_save_file()
{ return this_object()->query("weapon_file");}
int weapon_save()
{
	string file;

	if( stringp(file = this_object()->query_weapon_save_file()) ) {
		assure_file(file+ __SAVE_EXTENSION__);
		return save_object(file);
	}
	return 0;
}

int weapon_restore()
{
	string file;

	if( stringp(file = this_object()->query_weapon_save_file()) )
		return restore_object(file);
	return 0;
}

