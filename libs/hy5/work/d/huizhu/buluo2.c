// Room: /d/huizhu/buluo2.c

inherit ROOM;

void create()
{
	set("short", "回族部落");
	set("long", @LONG
此处三面是树林，北面的斜坡通向大草原，成群的牛羊在草原上吃
草嘻戏。远处天山山脉如同天地之间的一块屏障，把后面的一切都遮挡
住了。四外是几个帐篷。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zhangpeng3",
  "east" : __DIR__"zhangpeng2",
  "south" : __DIR__"buluo1",
  "northdown" : __DIR__"xiepo",
]));
	set("outdoors", "huizhu");

	setup();
	replace_program(ROOM);
}
