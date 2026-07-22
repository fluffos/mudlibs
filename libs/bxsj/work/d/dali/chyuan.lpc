// Room: /dali/chahuayuan.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <wanted.h>
void create()
{
        set("short",HIC"茶花园"NOR);
        set("long", @LONG
大理茶花名满天下，这个里是一个小山坡，花园依山而建，山坡上种满了
茶花，有上等品种「红妆素裹」，「十八学士」，也有差一些的「落第秀才」，
和「抓破美人脸」。
LONG
       );
        set("exits", ([ 
           "northup" : __DIR__"chyuan2",
           "west" : __DIR__"dongjie6",
	]));
        set("outdoors","大理");
        set("objects", ([
             __DIR__"npc/xiaosi" : 1, 
        ]));        
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && is_wanted(me))
		return 0;
	if ( !me->query_temp("flower_paid") && dir == "northup" )
	return notify_fail("想看茶花园，先付钱啊！\n");     
	return ::valid_leave(me, dir);
}
