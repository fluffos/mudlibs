#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"碎屍"NOR, ({ "broken corpse","corpse" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
	set("weight",9999);
                set("long", "這是一個人的屍體, 你看見他身上穿的隱隱約約是海政司的官服, 你可以看看(view)他有沒有啥遺物...");
                }
        setup();
}

void init()
{
       add_action("typeview","view");
}
     int typeview(string arg)
{
        object me,obj,p;
        me=this_player();
      obj=this_object();
        if(arg != "corpse" && arg != "broken corpse") return 0;
     message_vision(CYN"$N在碎屍上找了一找....\n"NOR,me);
	if (obj->query_temp("thing") == 0)
	{
	message_vision(HIY"$N從碎屍中拿出一個官印!!.\n"NOR,me);      
	 p=new(__DIR__"west_mark");
       	p->move(me);
	obj->set_temp("thing",1);
	return 1;
	}
	else
	{
	message_vision(HIY"但是$N什麼也沒發現....\n"NOR,me);
	return 1;
	}
}

