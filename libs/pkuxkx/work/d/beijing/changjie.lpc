// 长街
// edit: by zine Sep 2 2010

inherit ROOM;
#include <ansi.h>


void create()
{
	set("short", "长街");
	set("long", @LONG
忽听得前面人声喧哗，喝彩之声不绝于耳，远远望去，围着好大一堆人，不
知在看什么。
LONG
	);
	set("exits", ([ 
		"enter" : __DIR__"kongdi",
        "southeast" : __DIR__"zhengyangdajie",
        "southwest" : __DIR__"tuzai",
	]));
    set("no_fight",1);
	set("item_desc", ([
		"enter" : "里面围了里三层，外三层的人，你什么也看不清楚，你可以尝试大叫(jiao)\n一下，也许可以乘机挤进去。\n", 
	]));
	setup();
}

void init()
{
	add_action("do_shout", ({ "jiao" }));
}

int reopen()
{
    object npc;
    object kd=find_object(__DIR__"kongdi");
    npc=new(__DIR__"npc/munianci");
    npc->move(kd);
    npc=new(__DIR__"npc/muyi");
    npc->move(kd);
    npc=new(__DIR__"npc/dahan");
    npc->move(kd);
    npc=new(__DIR__"npc/liumang");
    npc->move(kd);
    npc=new(__DIR__"npc/liumang");
    npc->move(kd);
    set("exits/enter", __DIR__"kongdi");
    this_object()->delete("blockdir");
}



int blockdir()
{
    delete("exits/enter",);
    this_object()->set("blockdir",1);
}

int do_shout()
{
	object me=this_player();
	if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙着哪！\n");
	}
    if (me->query("shediaoquest/bwzq") || me->query("max_qi")<1500)
	{
		return notify_fail(WHT"你正要大喝一声，人群忽然散开了，没有热闹好看了。\n"NOR);
	}
    if ((int)me->query("level")<16)
    {
        tell_object(me,WHT"你的身子板也太弱了，被别人一下就挤开了。\n"NOR);
        return 1;
    }
    if (this_object()->query("blockdir"))
    {
        return notify_fail(RED"现在人实在太多了，别人想挪点位置都做不到。\n"NOR);
    }
    if (time()-me->query("shediaoquest/bwzqstarttime")<600)
	{   
        return notify_fail("你根本挤不进去，还是过一会再来吧！\n");  
    }
    if (me->query_temp("shediaoquest/jiaoed"))
    {
        return notify_fail(RED"又想故技重施，别人可不是傻子！\n"NOR);
    }
	if (random(100)>95)
	{
		tell_object(me,HIW"你大喝一声：“开水啊，劳驾让一下。”\n"NOR);
		tell_object(me,HIM"众人连忙往旁边躲开，你乘机挤了进去，众人明白后，切～～\n"NOR);
		me->move(__DIR__"kongdi");
        me->set_temp("shediaoquest/jiaoed",1);
		return 1;
	}
	else
	{
		tell_object(me,HIW"你大喝一声：“开水啊，劳驾让一下。”\n"NOR);
		tell_object(me,HIM"众人用鄙视的眼光看着你，切～～\n"NOR);
        me->set_temp("shediaoquest/jiaoed",1);
		return 1;
	}
}

int valid_leave(object me,string dir)
{	
	if ((dir=="enter" && me->query("shediaoquest/bwzq"))|| (dir=="enter" && me->query("max_qi")<1500))
	{
		return notify_fail(WHT"你正要挤进去，人群忽然散开了，没有热闹好看了。\n"NOR);
	}
	if (dir=="enter" && time()-me->query("shediaoquest/bwzqstarttime")<600)
	return notify_fail("你根本挤不进去，还是过一会再来吧！\n");  
	if (dir=="enter" && (random(100)>35))
	{
		me->set("shediaoquest/bwzqstarttime",time());
		return notify_fail(YEL"人群堵着去路，你根本挤不进去啊，还是过一会再来吧。\n"NOR);
	}
	return ::valid_leave(me, dir);
}
