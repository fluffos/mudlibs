// Room: /d/yandang/nankefang.c

inherit ROOM;

void create()
{
	set("short", "男客房");
	set("long", @LONG
这里是男客的房间,由于客栈小,只有这一间大房间,摆了一长条通
铺,够睡十多个汉子的,你进去的时候正有几个人坐在铺上天南地北地
海吹,见你进来也没在意.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yuanluo",
]));
	set("no_magic", 1);
	set("no_fight", 1);
	set("sleep_equipment", "通铺");
	set("hotel",1);
	set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
