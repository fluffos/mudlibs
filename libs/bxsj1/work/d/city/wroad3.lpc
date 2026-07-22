// /d/city/wroad3.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条土路上，偶尔有马匹经过，搞得尘土飞扬。因为地近安徽，所
以可能会有山贼出没。往西就进入安徽境内了。东边通向扬州城。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
		"east" : __DIR__"wroad2",
       		"west" : "/d/xiangyang/outeroad1",
//                "north" : "/data/group/zongtan",
                "north" : "/d/mingjiao/hdg/shanbi",
	]));
        
        set("objects", ([
                  "clone/npc/jianjie" : 1,
              ]));
	set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("coor/x",40);
  set("coor/y",0);
   set("coor/z",0);
   set("incity",1);
	setup();
}
/*
int valid_leave(object me, string dir)
{
        if (!me->query("g_title") && dir == "north")
        return notify_fail("那里是帮派的地盘，你还是别去了。\n");
        return ::valid_leave(me, dir);
}*/
