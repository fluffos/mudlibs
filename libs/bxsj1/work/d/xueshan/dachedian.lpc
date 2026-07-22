// Room: dachedian.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "招财大车店");
	set("long", @LONG
这是一间大车店，中间一个大院子，停了不少马拉车、手推车之类的运输工
具。迎面一间正房，里面灯火通明，一阵阵嘈杂的声音传了出来。门边立着个牌
子(sign)。左手一溜的马厩，马槽旁除了骡子、马以外还卧着两头少见的骆驼。
右手看来是厨房，热气腾腾的，不时有人断着饭菜走进正房中去。
LONG
	);

	set("exits", ([
		"west" : __DIR__"jiedao1",
                "enter" : __DIR__"zhengfang",
	]));

        set("item_desc",([
           "sign" : 
"通铺一夜叁两白银，酒菜另算。财物自理，丢失概不负责。不加收服务费。\n",     
           ]));
        set("no_sleep_room",1);
        set("outdoors", "雪山");
        set("objects",([__DIR__"npc/lizhaocai" : 1]));
	set("coor/x",-210);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "enter" && is_wanted(me))
		return 0;

	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("站住！想住店得掏钱！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
