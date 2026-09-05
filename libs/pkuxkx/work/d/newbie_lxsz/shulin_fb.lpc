// D:\xkx\d\liuxiu-shanzhuang\shulin.c树林
// labaz  2012/10/20.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

#define DIE_NOTIFY_NO_CONTINUE 486

void create()
{
    set("short", "树林");
    set("long", @LONG
你到了一片鸟鸣清啾的树林。林子里树木丛生，绿荫如茂，阳光却
还是从树枝树叶的空隙间射下，纵在白昼，地上也如繁星点点。
一阵风吹来，枝杈里藏着的鸟儿一下子全冒出来，欢叫着争相飞上
了天空。你向林子深处望去，有些麋鹿和兔子穿梭其间，好不欢快！
LONG);

    set("outdoors","liuxiu-shanzhuang");

    set("exits", ([
        "east" : __DIR__"weiminggu",
         ])
     );

	set("objects", ([
		__DIR__"obj/laohu" : 1,
	]));
	set("alternative_die",1);
    setup();
}

void init()
{
	object me;
	me=this_player();
	
	add_action("show_quest", "quest");
	set("alternative_die",1);
}

int valid_leave(object me,string dir)
{
    if (objectp(present("lao hu",this_object()))) return notify_fail("没有退路了，你必须杀死这只老虎才能离开这里。\n");
	return ::valid_leave(me, dir);
}

int alternative_die(object victim)
{
    object killer;
    if(!objectp(victim) || !userp(victim)) 
	{
		delete("alternative_die");
		victim->unconcious();
		return 1;
	}
    if(environment(victim) != this_object())
    {
        return 0;
    }
    else
    {
		tell_object(victim,HIW"你迷迷糊糊的听到一声怒吼：孽畜，不得伤人！\n"NOR);
		delete("alternative_die");
		victim->unconcious();
		victim->fullme();
		if(victim->query("gender") == "男性")
			victim->move(__DIR__"wxiangfang");
		else
			victim->move(__DIR__"exiangfang");
    }
    return 1;
}