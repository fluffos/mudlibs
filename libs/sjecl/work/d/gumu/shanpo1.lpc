// shanpo1.c 
// By River 98.08.29
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"山坡"NOR);
        set("long",@long
此处的山路显得稍有陡峭，四周杂草丛生，看上去危机四伏。由于江湖上
传闻古墓以前叛逆妄想前来偷取古墓秘籍，所以古墓弟子加强了巡防。一些古
墓弟子正在山坡附近巡逻。
long);

        set("outdoors","古墓");

        set("exits",([
          "southwest" : __DIR__"shanpo",                
        ]));

        setup();
}

void init()
{
        object ob, me, name1;
        me = this_player();
        name1 = me->query("id");
        if(/* ! (present("mengmian nuzi", environment(me))) && */
        (int)me->query_temp("gm/job")
         && !(int)me->query_temp("meet_nuzi")
         &&  me->query_condition("gm_job")){
		ob=new(__DIR__"npc/mmnz");
		ob->move(environment(me));
		me->set_temp("meet_nuzi", 1);
		ob->set_temp("mmnz", name1);
        }
}
