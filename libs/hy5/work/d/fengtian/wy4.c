// Room: /d/fengtian/wy4.c

inherit ROOM;

void create()
{
	set("short", "威远路");
	set("long", @LONG
威远路是一条东西贯串的大街，也是盛京最繁华的街道，这
里向西是个大的十字路口，向东是威远路的中段，路南有一家挺
大的绸缎庄。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"chou",
  "west" : __DIR__"cross",
  "east" : __DIR__"wy5",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
