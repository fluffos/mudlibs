// Room: 幽天部
inherit ROOM;
void create()
{
  set ("short", "幽天部");
 set ("long", @LONG
这是幽天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"yangtianbu",
"east":__DIR__"luantianbu"
]));

set("objects", ([
 __DIR__"npc/dizi" : random(5),
]));

set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}