#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "茫茫雪峰");
	set ("long", @LONG

北风呼啸，飞雪茫茫，四面望去均是绵延不尽的雪峰。天地之间
似已毫无生迹，除了雪还是雪。
LONG);


	set("exits", 
	([ //sizeof() == 4
		"south" : "/d/moon/kunlun",
		"north" : __DIR__"xueshan2",
	]));
	set("outdoors", "xueshan");

	setup();
}

int valid_leave(object who,string dir)
{
	if( dir=="north" && userp(who)
	 && who->query_temp("maze/40tupo")
	 && time()>=who->query("maze/tupo-40")+1800
	 && ( (who->query_level()==39&&who->query("combat_exp")>=16100000) ||wizardp(who) ) )
	{
		who->delete_temp("maze");
		who->dismiss_team(who);
        	if( MAZE_D->enter_maze(who, "tupo40-3") )
        	{
        		who->set("maze/tupo-40",time());
        		message_vision(HIC"\n$N"HIC"进入了大雪山水极之地"HIW"雪山寒林"HIC"。\n"NOR,who);
                	return 2;
                }
                else	return notify_fail("你有些踌躇不前。\n");
	}
	else	return ::valid_leave(who,dir);
}
