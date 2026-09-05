// by paladin

inherit ROOM;

void create()
{
set("short","山间小路");
        set("long", @LONG
这里是山间小路, 到出是齐腰高的蒿草，常有蛇出没。
LONG
        );
set("outdoors", "dali");

        set("exits", ([
"southeast" : __DIR__"foothill",
"northup" : __DIR__"sroad2",
"north" : __DIR__"gu",
        ]));

 set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));

        setup();
        replace_program(ROOM);
}
