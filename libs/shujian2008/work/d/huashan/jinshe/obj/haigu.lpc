// Room: /d/huashan/jinshe/obj/haigu.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
        add_action("do_move", "move");
}

void create()
{
       set_name("骸骨", ({"haigu","skeleton"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "具");
       set("long", "这副骸骨躺在这里已经很久了。\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}
