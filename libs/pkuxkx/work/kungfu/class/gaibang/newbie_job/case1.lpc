
#include <ansi.h>
inherit ITEM;


void create()
{
        set_name("钩子",({ "gou zi", "gouzi"}) );
        set("long","这是一个钩子，使用(use)起来可以在短时间内帮助提高偷窃的成功率，这是一件消耗品，关键时刻再用比较合适。\n");
        set_weight(40000);
        set("gb_newbie",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
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
    me->set_temp("steal_assist",time());
    message_vision("$N被$n弄得变形藏在手中，你可以开始偷窃了。\n",ob,me);
    destruct(ob);
    return 1;
}