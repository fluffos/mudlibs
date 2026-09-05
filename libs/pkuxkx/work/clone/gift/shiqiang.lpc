//gift十强赛

inherit ITEM;

#include <ansi.h>

void create()
{
        set_name(HIY"十强屠狼，胜利共享"NOR,({"victory gift","gift"}));
        set("long","庆祝中国国家足球队2:0主场战胜那谁，送给你一块巧克力啦！\n"
        );
        set("value",50000);
        set_weight(10);
set("unit","块");
        setup();
}

void init()
{
if(environment(this_object())==this_player())
                add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object me=this_player();
        if(!arg) return 0;
        if(arg!="victory gift"&&arg!="gift") return 0;
        if(me->query("gift/shiqiang")) return 0;
        message_vision(HIR"$N兴高采烈得一口吞下巧克力，摸了摸嘴：好爽！还有么？\n"NOR,me);
        me->add("combat_exp",1000+random(500));
        me->add("potential",100+random(50));
        me->add("per",2+random(2));
        write("你得实战经验增加了!\n");
        write("你得潜能增加了！\n");
        write("你得什么什么也增加了！\n");
        me->set("gift/shiqiang",1);
        me->save();
        destruct(this_object());
        return 1;
}
