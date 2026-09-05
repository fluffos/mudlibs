//Cracked by Roath
// jinchuang.c 金创药

inherit ITEM;
#include "../../newbie_village.h"



int cure_ob(object);
void create()
{
	set_name("金创药", ({"jinchuang yao", "yao", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("base_unit", "包");
		set("long", "这是一包武林人士必备的金创药。\n");
		set("value", 5000);
		set("medicine", 1);
	}
	setup();
}

void init()
{
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	if(id(arg))
	{
		cure_ob(this_player());
        if(check_questindex(this_player(),"去药铺买药(buy yao)，吃药(eat yao)把身上的伤完全治好") == 1)
        {
            set_nextquest(this_player(),"去药铺买药(buy yao)，吃药(eat yao)把身上的伤完全治好","你的伤治好了！快回到游庄主处，让他指导你闯荡江湖吧！", 20, 100);
        }
        destruct(this_object());
		return 1;
	}
	return 0;
}

int cure_ob(object me)
{
  if ( me->query("age")>=18 )
  {
    message_vision("$N吃下一包金疮药，但是啥效果也没有，似乎买了一包假药。\n",me);
    return 1;
  }
	if ((int)me->query("eff_qi") == 
	    (int)me->query("max_qi"))
	{
        message_vision("$N吃下一包金疮药，虽然$N并没有受伤，还是感到一股暖流。\n",me);
		return 1;
	}
	else {	
		message_vision("$N吃下一包金创药，感觉好多了。\n", me);
		me->fullme();
		return 1;
	}
}

