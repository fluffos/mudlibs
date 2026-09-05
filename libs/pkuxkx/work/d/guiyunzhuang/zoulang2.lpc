// guiyunzhuang/zoulang2走廊
#include <ansi.h>

inherit ROOM;

void create()
{
         set("short", "走廊");
        set("long", @LONG
这里是归云庄的长廊，里面不时地穿梭着忙碌着的仆人。
LONG);
         set("exits", ([ /* sizeof() == 3*/
         "south" : __DIR__"dating",
         "east" : __DIR__"xiuxishi",
"north":__DIR__"fanting",                  ]));
	set("objects",([__DIR__"npc/zhuangpu":2,]));
	setup();
}
int valid_leave(object me, string dir)
{
	object room;
	if ( me->query("family/family_name") == "桃花岛"||me->query_temp("shediaoquest/guiyun/step")>=10) return 1;	
	
    if ( dir != "east" ) return 1;
	if( objectp(room = find_object("/d/guiyunzhuang/xiuxishi")))
	if( ! objectp( present("xiao hua", room ) ) )
			return 1;
	tell_object(me, HIC "你被小花赶了出来，好丢脸啊，居然到别的门派来休息。\n" NOR);
	return notify_fail("");
}
