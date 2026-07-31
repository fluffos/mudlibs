
// magic_armor.c
#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{	set_name("ÆæÃÅ¶Ý¼×", ({"magic armor","armor"}));
	set_weight(1);
	if(clonep())
		set_default_object(__FILE__);
	else{
	set("unit","¼þ");
	set("material","gold");
	set("armor_prop/armor",50);
	set("armor_prop/dodge",10);
	    }
	set("no_get",1);
	setup();
}
