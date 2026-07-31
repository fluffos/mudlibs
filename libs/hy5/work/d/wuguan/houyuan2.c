//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里仍然是后院，西面不时传来马嘶声，你看过去，那里是个马房，
东面屋子里也是吵吵的，好象是锯木头的声音。
LONG);
	set("exits", ([
	      "west" : __DIR__"mafang",
              "east" : __DIR__"mufang",
	      "south" : __DIR__"houyuan",
              "north" : __DIR__"houyuan3",

        ]));
        set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

