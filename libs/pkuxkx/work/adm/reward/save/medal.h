#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_look","look");
}

int do_look(string id)
{
	if(id(id))
	{
		if(file_size("/adm/reward/save/"+query("owner")+".txt") > 0)
			cat("/adm/reward/save/"+query("owner")+".txt");
		return 1;
	}
	return 0;
}