// Room: 赤天部
inherit ROOM;
void create()
{
  set ("short", "赤天部");
 set ("long", @LONG
这是赤天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"haotianbu",
"east":__DIR__"xuantianbu"
]));

set("objects", ([
 __DIR__"npc/dizi" : random(5),
]));

set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}