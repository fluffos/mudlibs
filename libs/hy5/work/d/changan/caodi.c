// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "草地");
    set("long",@LONG
这是一片空旷的草地，四周长满了杂草，似乎这里已经很久没有
人来过了，面对这旷野的地方，你的心中不由得升起一丝寒意。再往
东走就是一个深不见底的绝崖了。
LONG
);
        set("outdoors","changan");
    set("exits", ([
        "west" :__DIR__"boshulin10",
        "east" :__DIR__"jueya",
]));
    set("item_desc", ([
"草地" : "在这片草地的中间，你似乎感到一些异样。\n",
]));
    setup();
}

void init()
{
    if (interactive(this_player()))
    add_action("do_kill","sha");
}

void check(object me,object ob)
{
    if (!me || !ob)
        return;
    if (!present(me,this_object())
        || !present(ob,this_object()))
        return;
    if (me->query("max_neili")<600
        || ob->query("max_neili")<600)
        return;
    if (ob->query("max_neili") < me->query("max_neili")){
        message_vision(HIR"$n被$N内力一震，往崖边倒飞下去。\n"NOR,me,ob);
      ob->move("/d/changan/qinhuang/gudi");
        ob->set_temp("killer",1);
        ob->unconcious();
    }else{
        message_vision(HIR"$N被$n内力一震，往崖边倒飞下去。\n"NOR,me,ob);
      me->set_temp("killer",1);
      me->move("/d/changan/qinhuang/gudi");
        me->unconcious();
    }
}

int do_kill(string arg)
{
    object ob,me=this_player();
    
    if (!arg || arg=="")   return 0;
    if (ob=present(arg,this_object())){
message_vision( HIY "$N和$n一见面，立即厮杀了起来。\n" NOR ,me,ob);
        ob->kill_ob(me); me->fight_ob(ob);
        if (userp(ob))
            if ( ob->query("jiali") > 50
            && me->query("jiali") > 50){
                remove_call_out("check");
                call_out("check",random(20)+5,me,ob);
            }
    }
    return 0;
}

