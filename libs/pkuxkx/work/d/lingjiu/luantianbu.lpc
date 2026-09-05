// Room: 鸾天部
inherit ROOM;
void create()
{
  set ("short", "鸾天部");
 set ("long", @LONG
这是鸾天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"youtianbu",
"north":__DIR__"juntianbu"
]));

set("objects", ([
 __DIR__"npc/dizi" : random(5),
]));

set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}