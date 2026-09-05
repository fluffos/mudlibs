
#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("假肢",({ "jia zhi", "jiazhi"}) );
        set("long","这是一条假腿，使用(use)起来可以在短时间内帮助提高乞讨的成功率，这是一件消耗品，关键时刻再用比较合适。\n");
        set_weight(40000);
        set("gb_newbie",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1);            
			}
        setup();
}

void init()
{
    add_action("do_use","use");
}

int do_use()
{
    object me=this_player();
    object ob=this_object();
    me->set_temp("beg_assist",time());
    message_vision("$N戴上了一条$n，开始假装瘸子准备乞讨了。\n",me,ob);
    destruct(ob);
    return 1;
}