// Room: /d/linzhi/by02.c

inherit ROOM;

void create()
{
	set("short", "镇东斜街");
	set("long", @LONG
这里是八一镇镇东斜街，街的南面有一座帐房，看上去像是
本地藏民的住处。你走着走着，忽然觉得脚下一滑，低头一看，
原来是踩在了羊粪蛋上，你暗自骂了一句。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"by01",
  "northwest" : __DIR__"by03",
  "south" : __DIR__"house01",
]));
        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
