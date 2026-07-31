// Room: /d/huashan/shanlu2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是通往华山派总堂的山路，但见山势险峻，树木清幽，鸟鸣嘤嘤，流水
淙淙，这里已经看不见游客，偶尔会见到几只野兽出没。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"southwest" : __DIR__"xiaoxi",
	"northwest" : __DIR__"shanlu1",
	"southup" : __DIR__"taijie",
	]));

	set("objects", ([ 
		__DIR__"npc/monkey" : 1,
	]));

        set("outdoors", "华山" );

        set("coor/x",80);
  set("coor/y",10);
   set("coor/z",60);
   setup();
}
