// Room: /d/shaolin/shanlu8.c
// Date: bren

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "山路");
	set("long", @LONG
这是少室山五乳峰下的一条小路，路旁长满的青草。黄土铺就的小路看
起来很齐整，似乎有人经常打扫。不远处就是五乳峰，山势挺拔，景秀境幽
，峰上种满了松树，随着微风拂过，传来阵阵滔声。东面是一片松林，林外
竖着一块木牌(mupai)。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin1",
		"southwest" : __DIR__"shanlu7",
        ]));
        set("item_desc",([
		"mupai"	:   "少林寺护法松林，违令擅入者杀无赦！\n",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",60);
  set("coor/y",520);
   set("coor/z",160);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
