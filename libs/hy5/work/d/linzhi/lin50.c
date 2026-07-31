// Room: /d/linzhi/lin50.c

inherit ROOM;

void create()
{
	set("short", "林芝温泉群区");
	set("long", @LONG
这里是林芝的温泉群区，由于地貌变化，这里四处都是温泉，
大的高数十米，小的也有二三米，皆是上佳的沐浴和水疗之处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wenquan01",
  "south" : __DIR__"lin49",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3400);
	setup();
	replace_program(ROOM);
}
