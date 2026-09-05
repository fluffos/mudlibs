#pragma save_binary
//jinchuangyao.c
#include "ansi.h"
inherit COMBINED_ITEM;

void create()
{
        set_name("金疮药", ({ "medicine"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long", "这是专治跌打损伤的特效药。\n");
                set("value", 2500);
                set("base_unit", "包");
		set("unit","包");
                set("base_weiht",50);
        }
        set_amount(1);
}

void init()
{
        add_action("eat_medicine","eat");
}


int eat_medicine(string arg)  
{
       object me;
       int inss;
     
       if( !this_object()->id(arg) ) return 0;
       me = this_player();

       if( (inss = me->query("max_kee") - me->query("eff_kee")) > 0 )
       {
                if( inss > 15 ) me->add("eff_kee",10+random(5));
              else me->add("eff_kee", inss);
		add_amount(-1);	
        message_vision("$N吃了一包金疮药。\n", me);
       message_vision(HIG"$N看起来气色好多了！\n"NOR, me);
	}
	else
	{
	message_vision("你好象没有受伤。\n",me);
	}
       return 1;
}
