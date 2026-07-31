inherit ROOM;

void create()
{
    set("short", "水房");
    set("long", @LONG
一进屋，你看见屋内放着几口大缸，好象是装水用的，不过缸似乎都是
空的，这里没有一个人，估计仆人都跑了。
LONG);
	set("exits", ([
	     "east" : __DIR__"houyuan",
        ]) );
        set("no_fight",1);
        set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

