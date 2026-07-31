// Room: /d/yandang/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "天冠峰");
	set("long", @LONG
原名戏狮峰.壁间石纹错综,形似狮子.从整体看,又象一顶大帽子,
因此叫作天冠峰.峰高120余米,宽150余米.峰背有两石相叠,形如猴子
捧桃.在峰下,有山洞名为响板洞.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu3",
  "southdown" : __DIR__"shanlu",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
