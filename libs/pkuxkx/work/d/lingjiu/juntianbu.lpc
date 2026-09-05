// Room: 钧天部
inherit ROOM;
void create()
{
  set ("short", "钧天部");
 set ("long", @LONG
这是钧天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"lianwuchang",
"north":__DIR__"chengtianbu",
"south":__DIR__"luantianbu"
]));

set("objects",([
               CLASS_D("lingjiu") + "/cheng" : 1,
		 __DIR__"npc/dizi" : random(5),
                ]));
set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}