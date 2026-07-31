// /d/wizard/wizard_jail.c
// bbb 99.1.25
// Modify By Look 991021
// Modify by Looklove 2000/8/26  because food& water

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","监狱");
       set("long", @LONG
这里是监狱，是关押重刑犯的地方。四面都是石壁，想要自已逃出去是
不可能的。地上十分潮湿，看来在这时间一久必得重病。石壁上用刀子刻着
一些忏悔的话语....“不应得罪广大人民，不该违反游戏规则，以致受此活
罪”等言语。
LONG
     );
        set("no_fight",1);
	set("no_update", 1);
        set("valid_startroom", 1);
        set("no_get",1);
        set("objects", ([ __DIR__"npc/yuzu" : 1, ]));
        setup();
}

void init()
{
	object me = this_player();
        me->set("food",100);
        me->set("water",100);
	if (userp(me) && !wiz_level(me) && !me->query_condition("killer"))
		me->apply_condition("killer", 1);
        add_action("do_kill", "");
}

int do_kill(string arg)
{
        string action = query_verb();
        switch (action) {
        case "kill":
        case "hit":
        case "throw":
        case "fight":
        case "perform":
        case "dazuo":
        case "exercise":
        case "tuna":
        case "lian":
        case "practice":
        case "du":
        case "study":
        case "respirate":
        write("都已经到这个地方了，还想那些俗事做什么？\n");
        return 1;
        }
return 0;
}
