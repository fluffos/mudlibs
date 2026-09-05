// shuaiqi.c  帅旗
// hongdou 98.09.20

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_tear", "tear");
}

void create()
{
        set_name("帅旗", ({"shuai qi", "shuaiqi", "qi"}));
        set_weight(10);
        set("long", "这是一面破旧的帅旗，上写："+HIC+"大清国御赐黄马褂驻通吃岛一等通吃伯"+HIY+"  韦"+NOR+" 。\n");
        set("unit", "面");
}

int do_tear(string arg)
{
	object ob,obj;
        object me = this_player();
		
	if (!id(arg)) return 0;

	if ((arg=="1i") || (arg=="shuai 1i") || (arg=="shuaiqi"))
	{
	    tell_object(me, HIY "\n你将帅旗撕得粉碎。\n"NOR);
//	    me->add("pr
	    destruct(this_object());
	    return 1;
	}
}



