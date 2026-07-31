inherit ROOM;

void create()
{
        set("short", "官道");
        set("long", @LONG
此处是个叉路，往西不远是洛阳，往东可到中州，西北通
往北岳恒山。不少游人顺着这条路往山上去。
LONG);
        set("exits", ([
                "west" : "/d/luoyang/road9",
  		"east" : __DIR__"wroad2",
	]));
        set("outdoors", "zhongzhou");

        set("coor/x", -310);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
