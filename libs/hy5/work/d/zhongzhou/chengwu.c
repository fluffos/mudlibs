inherit ROOM;

void create()
{
	set("short", "小草屋");
	set("long", @LONG
一间颇为精致的小屋，似乎是女子的居所。房间的中央摆
着一个药炉，缓缓散发着清香。
LONG);
	set("exits", ([
  		"west" : __DIR__"zhongzhoudu",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                CLASS_D("hu") + "/cheng" : 1,
                CLASS_D("hu") + "/kill1" : 1,
                CLASS_D("hu") + "/kill2" : 1,
        ]));
	set("coor/x", -190);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        //replace_program(ROOM);
}
