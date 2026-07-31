#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "山脚");
  set ("long", @LONG
山花漫漫，绿野青青，这里是四川蜀山的山脚
远远望去，山上白雪皑皑，山顶一座直耸入云的
宝塔。
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road1",
"northup" : __DIR__"path1",
]));

        set("outdoors","shushan");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object who,string dir)
{
	if( dir=="northup" && userp(who)
	 && who->query_temp("maze/40tupo")
	 && time()>=who->query("maze/tupo-40")+1800
	 && ( (who->query_level()==39&&who->query("combat_exp")>=16100000) ||wizardp(who) ) )
	{
		who->delete_temp("maze");
		who->dismiss_team(who);
        	if( MAZE_D->enter_maze(who, "tupo40-1") )
        	{
        		who->set("maze/tupo-40",time());
        		message_vision(HIC"\n$N"HIC"进入了蜀地金极之地"HIY"销金窝"HIC"。\n"NOR,who);
                	return 2;
                }
                else	return notify_fail("你有些踌躇不前。\n");
	}
	else	return ::valid_leave(who,dir);
}
