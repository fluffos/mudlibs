// by paladin


inherit ROOM;

void create()
{
set("short","小路");
        set("long", @LONG
这里是小路, 到出是齐腰高的蒿草，常有蛇出没。
LONG
        );
set("outdoors", "dali");

        set("exits", ([
"northup" : __DIR__"houshan",
"southdown" : __DIR__"sroad2",
        ]));

 set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/jinshe" : random(2),
     ]));

        setup();
        replace_program(ROOM);
}
