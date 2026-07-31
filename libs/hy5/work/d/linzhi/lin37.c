// Room: /d/linzhi/lin37.c

inherit ROOM;

void create()
{
	set("short", "加兴沟");
	set("long", @LONG
你来到这里，只闻到处是哗哗的水声，原来这里就是以水帘
洞瀑布而闻名的加兴沟了。西面就是最大的水帘洞瀑布。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin43",
  "west" : __DIR__"lin38",
  "southeast" : __DIR__"lin36",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
