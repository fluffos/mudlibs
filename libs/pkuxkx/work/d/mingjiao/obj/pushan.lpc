// 蒲扇 mj新手任务 By Zine
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("蒲扇", ({ "pu shan" }));
        set_weight(7000);
        set("unit", "柄");
        set("long", "这是一柄蒲扇，可以用来扇风(shanfeng)。\n");
        set("value", 0);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回腰间。\n");
        set("no_get",1);
        init_blade(2);
        setup();
        call_out("dest",600);
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
        return 1;
    }
}

void init()
{
    add_action("do_shan","shanfeng");
    add_action("do_get","get");
}

int do_get(string arg)
{
    object ob=this_object();
    object me=this_player();
    if (arg=="pu shan"&&ob->query("owner")==me->query("id"))
    {
        message_vision("$N拣起了一柄$n。\n",me,ob);
        remove_call_out("dest");
        ob->move(me);
        return 1;
    }
    
}

int do_shan()
{
    object me=this_player();
    if (!me->query_temp("mingjiao/tasks/task1start"))
    return notify_fail("你还没开始看守圣火，扇什么风？\n");
    if (me->is_busy()||me->is_fighting())
    return notify_fail("你正忙着呢。\n");
    if (base_name(environment(me))!="/d/mingjiao/fireroom")
    return notify_fail("你拿起扇子对着自己扇了扇。\n");
    if (me->query_temp("mingjiao/tasks/task1act")=="shan")
    {
        message_vision("$N用蒲扇扇了扇，圣火燃烧得更加健旺了。\n",me);
        me->delete_temp("mingjiao/tasks/shan");
        me->delete_temp("mingjiao/tasks/task1act");
        me->add_temp("mingjiao/tasks/task1actsuc",1);
        return 1;
    }
    else
    {
        message_vision("因为$N的胡乱操作，圣火熄灭了。快去狮王那里领罪吧。\n",me);
        me->delete_temp("mingjiao/tasks/task1act");
        me->set_temp("mingjiao/tasks/task1fail",1);
        return 1;
    }
}