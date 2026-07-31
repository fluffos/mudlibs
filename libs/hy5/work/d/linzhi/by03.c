// Room: /d/linzhi/by03.c

inherit ROOM;

void create()
{
	set("short", "镇东斜街");
	set("long", @LONG
这里是八一镇镇东斜街，街西侧帐房是一家杂货店，东首帐
房是一家肉铺。猛然一个大汉迎面走来，瞪了你一眼什么话也没
就走开了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"by02",
  "northwest" : __DIR__"by04",
  "west" : __DIR__"shop",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
