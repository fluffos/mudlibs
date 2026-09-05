// cloth.c
//
// This is the basic equip for players just login.

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("残缺的地图", ({ "di tu" }) );
        set_weight(300);
        set("alucar_map",1);
		set("unit", "张");
		set("value",0);
        set("material", "paper");
        setup();
}

void init()
{
	add_action("do_record","record");
}

int do_record(string arg)
{
	object me=this_player();
	if (!this_object()->query("desc"))
	{
		tell_object(me,"记完就回去吧。\n");
		return 1;
	}
	if (!arg)
	{
		tell_object(me,"你自己答应帮助逍遥的，不能敷衍了事。\n");
		return 1;
	}
	if (arg!=this_object()->query("desc"))
	{
		tell_object(me,"再仔细看看，你肯定是弄错了。\n");
		return 1;
	}
	delete("desc");
	me->add("mengguquest/alucar",1);
	message_vision("$N将这里的地势描述详细地补上了逍遥的残图。\n",me);
	return 1;
}