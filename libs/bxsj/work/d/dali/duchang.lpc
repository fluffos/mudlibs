inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是大理赌场的大堂，几个赌徒光着膀子，满头大汗的推着牌九，一些
人在旁边看着，多半是输光了又不想走的人。墙上挂着一块牌子(paizi)。
LONG
	);

	set("item_desc", ([
	      "paizi" : "二楼的拱猪房正处于测试阶段。\n",
	]));
	set("exits", ([
              "south" : __DIR__"beijie5",
	]));
        set("objects", ([
                __DIR__"npc/duke" : 2,
        ]));
	set("coor/x",-290);
  set("coor/y",-370);
   set("coor/z",-20);
   set("coor/x",-290);
  set("coor/y",-370);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/duchang",1);
      }
}

int valid_leave(object me, string dir)
{
        if (dir == "up" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}
