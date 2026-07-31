// Room: /d/linzhi/lin21.c

inherit ROOM;

void create()
{
	set("short", "丘陵地带");
	set("long", @LONG
这里是位于河谷区的丘陵地带，海拔平均在1600米左右。在
平坦地带，住扎着不少的帐房，可能是藏商临时的住所。要是不
急地话，进入看看也好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin16",
  "westup" : __DIR__"lin22",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 1600);
	setup();
	replace_program(ROOM);
}
