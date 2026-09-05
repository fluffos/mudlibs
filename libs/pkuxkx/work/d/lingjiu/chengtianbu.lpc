// Room: 成天部

inherit ROOM;
void create()
{
  set ("short", "成天部");
 set ("long", @LONG
这是成天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"xuantianbu",
"south":__DIR__"juntianbu"
]));

set("objects", ([
 __DIR__"npc/dizi" : random(5),
]));

set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}