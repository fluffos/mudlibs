//日月神教的解药
#include <ansi.h>
inherit ITEM;

void setup()
{
}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG"解药"NOR, ({"jie yao", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这颗解药可永久解除三尸脑神丹之毒，珍贵无比。\n");
                set("value", 100000);
                set("no_give_user",1);
                set("no_put",1);
                set("no_get",1);
                set("no_sell",1);
                set("no_pawn",1);
                set("no_store",1);
        }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping fam;
	      fam = this_player()->query("family"); 
        if (arg!="jie yao" && arg!="yao")
                return 0;
        if(!fam || fam["family_name"] != "日月神教")  
                return notify_fail("你不是日月神教弟子，瞎吃什么！\n");
    	  if ( !me->query("riyue_drug"))
                return notify_fail("你又没吃过三尸脑神丹，瞎吃什么！\n");
        me->delete("riyue_drug");
        message_vision("$N吃下一颗解药，感觉似乎周身似乎十分通泰。\n", me);
        destruct(this_object());
        return 1;
}
