// updated.c
// #pragma save_binary
void create() { seteuid(getuid()); }

void check_user(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();
	if(!undefinedp(my["hp"]) && !undefinedp(my["max_hp"]))
	{
		if( my["hp"] > my["max_hp"] ) my["hp"] = my["max_hp"];
	}
	
	if(!undefinedp(my["mp"]) && !undefinedp(my["max_mp"]))
	{	
		if( my["mp"] > my["max_mp"] ) my["mp"] = my["max_mp"];
	}
	
	if(!undefinedp(my["ap"]) && !undefinedp(my["max_ap"]))
	{
		if( my["ap"] > my["max_ap"] ) my["ap"] = my["max_ap"];
	}
}
