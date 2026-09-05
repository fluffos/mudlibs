inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *ainv, item;
	if(!arg) 
	{
		message_vision("你要看谁的? \n", me);
		return 1;
	}
	
	item = find_player(arg);
	if( !item ) 
		item = find_living(arg);
	if( !item ) 
		item = present(arg, environment(me));
	

	if( !item ) 
		item = me;

	ainv = all_inventory(item);
	
	if( !sizeof(ainv) ) 
	{
		write((item==me)? "目前你身上没有任何东西。\n"
				: item->name() + "身上没有携带任何东西。\n");
		return 1;
	}
	
	for (int i = 0; i < sizeof(ainv); i++) 
	{
		printf("[%O]\n", ainv[i]);
	}
	
	return 1;
}