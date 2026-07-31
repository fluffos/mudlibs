#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "解毒药水" NOR, ({"potion"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("value", 10000000);
                set("unit", "小瓶");
                set("no_get", 1);
                set("no_drop", 1);
        }
       setup();
}

void init()
{ 
        add_action("do_heal","heal");
        add_action("do_prevent",({"tell","reply","chat","rumor","party","say","emote","new","shout","post","chat*","rumor*","party*","new*"}));
}

int do_heal(string arg)
{
        object me, ob;
        me=this_player();

        if( !arg || !objectp(ob = present(arg, environment(me))) 
        || !ob->is_character() || ob == me)
                return notify_fail("你要治疗谁？\n");
        if (ob->query("id") != query("target"))
                return notify_fail("他不是你的对象。\n");
        
        message_vision(HIG"$N手指微弹，将药水撒向了$n！\n"NOR, me, ob);
        me->set_temp("xue_finish",1);
        destruct(this_object());
        return 1;
}

int do_prevent()
{
       return notify_fail("你小心执行任务吧。\n");
}
