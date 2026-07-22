// Room: /d/huashan/shanlu1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
       set("short", "山路");
       set("long", @LONG
这是通往华山派总堂的山路，但见山势险峻，树木清幽，鸟鸣嘤嘤，流水
淙淙，四五座粉墙大屋依着山坡或高或低的构筑，东南方有条小道通往山上。
LONG
        );
       set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"yunu",
	"southeast" : __DIR__"shanlu2",
	]));

	set("objects",([
		__DIR__"npc/monkey" : 1,
	]));

       set("outdoors", "华山" );

       set("coor/x",70);
  set("coor/y",20);
   set("coor/z",60);
   setup();
}
