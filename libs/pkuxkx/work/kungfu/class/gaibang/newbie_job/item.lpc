
#include <ansi.h>
#include "/kungfu/class/gaibang/bonus.h"
inherit ITEM;


void create()
{
        set_name("物品",({ "item", "thing"}) );
        set_weight(40000);
        set("gb_newbie",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 1);            
			}
        setup();
        call_out("dest_gb_newbie_item",900);
}

void init()
{
    add_action("do_jiao","shangjiao");
    add_action("do_jiao","jiao");
}

int dest_gb_newbie_item()
{
    if (this_object())
    {
        destruct(this_object());
    }
    return 1;
}

int do_jiao()
{
    object me=this_player();
    object ob=this_object();
    object target;
    object env=environment(me);
    
    if (!present("peng youjing",env))
    {
        tell_object(me,"彭长老不在，你要上缴给谁？\n");
        return 1;
    }
    target=(present("peng youjing",env));
    if (!target->query("is_peng"))
    {
        tell_object(me,"彭长老不在，你要上缴给谁？\n");
        return 1;
    }
    if (me->query("gbnewbiejob/start")
        &&ob->query("pin")
        &&(int)ob->query("pin")==(int)me->query_temp("gbnewbiejob/pin")
        &&ob->query("begby")==me->query("id"))
    {
        bonus(me);
        destruct(ob);
        return 1;
    }
    else if (ob->query("pin")&&(int)ob->query("pin")!=(int)me->query_temp("gbnewbiejob/pin"))
    {
        message_vision("$N道：我要去你讨来的不是这样东西吧？\n",target);
        return 1;
    }
    else if (ob->query("begby")!=me->query("id"))
    {
        message_vision("$N道：我让你去讨来，不是去抢，乞丐也要有尊严的！\n",target);
        return 1;
    }
    else
    {
        return notify_fail("这是什么玩意？\n");
    }
}