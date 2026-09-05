#include <ansi.h>

inherit ITEM;

void create()
{
	      set_name(HIG"千年人参"NOR, ({"qiannian renshen", "renshen", "shen", }));
        set_weight(20);
	      if (clonep())
	      	set_default_object(__FILE__);
	      else {
	      	set("unit", "棵");
	      	set("long", "产自长白山的千年人参，甘、微寒、无毒，大补元气，复脉固脱。\n");
          set("value", 80000);
		  set("drugcode",39);
	      }
	      setup();
}

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	      if(!id(arg))
	      	return 0;
	      	if( this_player()->query("max_neili")<5000)
	      this_player()->set("neili", this_player()->query("max_neili")+random(50));
          else
        this_player()->set("neili", 5000+random(50));  	
	      message_vision("$N服下一棵$n，经脉各处内息充盈多了。\n", this_player(), this_object());
        
	      destruct(this_object());
	      return 1;
}
