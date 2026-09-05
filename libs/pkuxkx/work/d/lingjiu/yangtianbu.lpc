// Room: 阳天部
inherit ROOM;
void create()
{
  set ("short", "阳天部");
 set ("long", @LONG
这是阳天部的所在地。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"zhutianbu",
"east":__DIR__"youtianbu"
]));
        set("objects",([
               CLASS_D("lingjiu") + "/fuminyi" : 1,
  __DIR__"npc/dizi" : random(5),     	
                ]));
set("no_clean_up", 0);
set("outdoors", 1);
setup();
replace_program(ROOM);
}