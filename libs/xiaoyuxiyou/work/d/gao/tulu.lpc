#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "土路");
  set ("long", @LONG

一条湿漉漉的小路，路边开着许多野花．路边小渠里溪水缓缓的
流着．水田中也偶尔传来青蛙＂呱呱＂的叫声．远远望去，稻田
中绿油油的．北边可望到高家镇，南边就到了村里．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"daotian2",
"south" : __DIR__"cunkou",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object who,string dir)
{
	if( dir=="south" && userp(who)
	 && who->query_temp("maze/40tupo")
	 && time()>=who->query("maze/tupo-40")+1800
	 && ( (who->query_level()==39&&who->query("combat_exp")>=16100000) ||wizardp(who) ) )
	{
		who->delete_temp("maze");
		who->dismiss_team(who);
        	if( MAZE_D->enter_maze(who, "tupo40-4") )
        	{
        		who->set("maze/tupo-40",time());
        		message_vision(HIC"\n$N"HIC"进入了火极之地"NOR HIR"星石巨坑"NOR HIC"。\n"NOR,who);
                	return 2;
                }
                else	return notify_fail("你有些踌躇不前。\n");
	}
	else	return ::valid_leave(who,dir);
}
