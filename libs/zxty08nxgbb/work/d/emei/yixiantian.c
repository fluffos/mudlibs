// /d/emei/yixiantian.c 峨嵋山一线天
// create by host nov,20

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "一线天");
	set("long", @LONG
这是一条沿着山脊蜿蜒而上的小路，依稀可以看到远方有一座大殿巍峨
高耸在前面。只见它的两侧面临深渊，崖下云海翻滚，不知究竟有多深。气
势既壮观，地形又极其险要，辉煌中不禁使人感到冷森森的寒意。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"northdown" : __DIR__"niuxinting",
                "southup": __DIR__"shangu",
		]));
	set("no_clean_up", 0);

	set("objects", ([ 
	]));

	setup();

}
int valid_leave(object me,string dir)
{
		
        if(me->query_skill("dodge",1) < 20  && dir=="southup" )
	{
		me->receive_damage("qi", 5);
		me->receive_wound("qi",  5);
		message_vision(HIR"$N太胖了！说什么也无法从这里挤过去。\n"NOR, me);
	        return notify_fail("");
         }
            return ::valid_leave(me,dir);
}
