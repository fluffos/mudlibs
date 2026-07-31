// Room: /d/wizard/fightroom6.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "九曲长廊");
    set("long", @LONG
这是一条弯弯曲曲的，由晶莹的白玉架成的长廊。廊旁是两行
修剪整齐的花草，微风吹过，花香袭人。白色的晶石在天光下闪著
迷人的色彩。一切显的是那样的宁静。
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fightroom5",
]));
    setup();
    replace_program(ROOM);
}
