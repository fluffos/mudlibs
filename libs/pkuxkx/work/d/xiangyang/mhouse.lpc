inherit ROOM;

void create()
{
        set("short", "土房");
	set("long", @LONG
这是一间用土坯搭成的房屋，屋里的陈设很俭朴.
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"mroad2",
]));
        set("no_clean_up", 0);
//        set("objects", ([
  //              __DIR__"npc/oldwoman": 1 ]) );

        setup();
        replace_program(ROOM);
}
 
