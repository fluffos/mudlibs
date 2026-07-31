//yupei.c
#include <ansi.h>

#include <armor.h>

inherit SHIELD;
string do_wear();
string do_remove();
void create()
{
	set_name(HIB"蓝田玉佩"NOR, ({"yu pei"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "个");
		set("value", 400);
		set("long", "一枚蓝色玉佩，放在手里有阵阵温暖传入手心．\n");
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("material", "steel");
		set("wear_msg", (: do_wear :)); 
		set("remove_msg", (: do_remove :)); 
	set("armor_prop/dodge", 1);
	set("armor_prop/armor", 20);
	}

	setup();
}

int query_autoload() { return 1; }

string do_wear()
{   object me = this_player();
     me->set_temp("suit_eff/constitution",3);
}
string do_remove()
{   object me = this_player();
     me->set_temp("suit_eff/constitution",0);
}
