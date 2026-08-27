// clean_up.c
// by Annihilator@ES2
// #pragma save_binary
int clean_up()
{
	object *inv;
	int i;

	if( !clonep() && this_object()->query("no_clean_up") ) return 1;

	if(interactive(this_object())) return 1;

	// If we are contained in something, let environment do the clean
	// up instead of making recursive call. This will prevent clean-up
	// time lag.
	if(environment()) return 1;

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
	{
		if(interactive(inv[i])) return 1;
	}
	if(this_object()->is_room()) ROOM_D->clean_up_map(this_object());
	destruct(this_object());
	return 0;
}
