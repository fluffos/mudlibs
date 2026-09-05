// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "军器监作坊");
	set("long", @LONG
这里是将军器监设在城北的作坊。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"east" : "/d/hangzhou/beimen",
	]));
	/*set("objects", ([
          __DIR__"npc/junqi1" : 1,
		__DIR__"npc/junqi2" : 1,
        ])); */
	set("at_hangzhou",1);
	setup();
}

void init()
{
    add_action("do_duzao","duzao");
}

int do_duzao()
{
    object me=this_player();
    int n=1+random(5);
	if (me->query_temp("songtasks/junqi/1/finish"))
	{
		tell_object(me,"军械越发充足，你可以回军器监复命了。\n");
        return 1;
	}
    if (me->query_temp("songtasks/junqi/task")!=1)
    {
        return notify_fail("谁让你来城北作坊的，军备官没有放行的意思。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("songtasks/junqi/xie_degree")>50)
    {
		me->set_temp("songtasks/junqi/1/finish",1);
        tell_object(me,"军械越发充足，你可以回军器监复命了。\n");
        return 1;
    }
    me->add_busy(3);
    message_vision("大批民夫在$N监督下开始制造军械。\n",me);
    me->add_temp("songtasks/junqi/xie_degree",(int)me->query_temp("songtasks/junqi/xie_degree")+n);
    tell_object(me,HIG"地上的军械越积越多……\n"NOR);
    return 1;
}