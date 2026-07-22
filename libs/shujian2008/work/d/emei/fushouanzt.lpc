// Room: /d/emei/fushouanzt.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "福寿庵斋堂");
	set("long", @LONG
这里便是峨嵋福寿庵的斋堂。福寿庵本不大，但由于经常接待其他庵的弟子，
斋堂倒也不小。只见厅内摆满了长长的餐桌和长凳，几位小师太正来回忙碌着布置
素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。北面有一扇门(door)。
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"lingwenge",
  "northup" : __DIR__"fushouanxxs",
]));
	set("objects",([
		"/d/emei/obj/mizhi-tianou" : 1,
        "/d/emei/obj/mala-doufu" : 1,
        "/d/huashan/obj/qingshui-hulu" : 1,
		"/d/emei/obj/liuli-qiezi" : 1,
]));
create_door("northup", "小门", "southdown", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "northup" && me->query("gender") != "女性" )
		return notify_fail("只听得一片寂静无声，你也打消了去那里的念头。\n");

	return ::valid_leave(me, dir);
} 
