// Room: /city/chaguan.c
// YZC 1995/12/04 
// Zine 2012 射雕主线quest
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "春来茶馆");
        set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字排
开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，这里
是个好所在。桌上放着几个粗茶碗，是不要钱的茶水，渴了可以随便喝(drink)。
LONG);
        set("resource/water", 1);

        set("exits", ([
                "east" : __DIR__"nandajie2",
			    "west" : __DIR__"machehang",
        ]));

        set("objects", ([
                __DIR__"npc/aqingsao" : 1,
                "/kungfu/class/murong/murongfu" : 1,
        ]));

        setup();
}
int shediao2(object me)
{
	object huang;
	me->set_temp("shediaoquest/kanglong/start",1);
	huang=new(__DIR__"npc/huang");
	huang->move(this_object());
	huang->hi(me);
	return 1;
}
int shediao(object me,int flag)
{
	if (flag==1)
	{
		if (present("huang rong",this_object()))
		{
			return 1;
		}
		if (time()-me->query("shediaoquest/kanglong/last_try")<1800)
		{
			return 1;
		}
		if (random(100)<60)
		{
			me->set("shediaoquest/kanglong/last_try",time());
			tell_object(me,"你到这里本是希望再遇上黄蓉，既然未能如愿，迟些再来吧。\n");
			return 1;
		}
		message_vision("$N正要离开，忽然听到有人呼唤。\n",me);
		shediao2(me);
		return 1;
	}
	if (flag==2)
	{
		if (present("huang rong",this_object()))
		{
			return 1;
		}
		if (time()-me->query("shediaoquest/kanglong/last_try")<900)
		{
			return 1;
		}
		if (random(100)<40)
		{
			me->set("shediaoquest/kanglong/last_try",time());
			tell_object(me,"你到这里本是希望再遇上黄蓉，既然未能如愿，迟些再来吧。\n");
			return 1;
		}
		message_vision("$N正要离开，忽然听到有人呼唤。\n",me);
		shediao2(me);
		return 1;
	}
	return 1;
}
void init()
{
	object me=this_player();
    add_action("do_drink", "drink");
	if (me->query_temp("shediaoquest/kanglong"))
	{
		return;
	}
	if (me->query("shediaoquest/kanglong/finish"))
	{
		if (!random(100))
		tell_object(me,HIC"故地重游，你不禁想起了当年和黄蓉初遇七公的情景。\n"NOR);
		return;
	}
	if (me->query("level")<12)
	{
		return;
	}
	if (!me->query("shediaoquest/bwzq"))
	{
		return;
	}
	if (me->query("shediaoquest/zjk")==3)
	{
		shediao(me,1);
		return;
	}
	if (me->query("shediaoquest/zjk")==4)
	{
		shediao(me,2);
		return;
	}
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        if(arg)
                return 0;
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->add("water", 450);
                message("vision", me->name()+"急冲冲的跑了过来，拿起茶碗一阵豪饮。\n",
                        environment(me), ({me}) );
                write("你端起桌上的粗茶碗，咕噜咕噜饮喝了几大口茶。\n");
        }
        else write("你已经不渴了，还是别喝了。\n");

        return 1;
}
