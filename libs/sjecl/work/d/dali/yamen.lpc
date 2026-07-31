// By River 98/12/
inherit ROOM;

void create()
{
	set("short", "府衙前厅");
	set("long", @LONG
这里是大理国机要府衙的前厅，乃大理官员商议国政军务之所，厅堂并不
很大，装饰朴素，厅门有御林军将士把手。除了南面出口，堂内另三面各有一
门，通往三公各自的司堂。
LONG
	);        
	set("exits", ([
           "south" : __DIR__"beijie1",
           "north" : __DIR__"sikong",
           "west" : __DIR__"sima",
           "east" : __DIR__"situ",
	]));

        set("objects", ([
              __DIR__"npc/bing" : 2,
              __DIR__"npc/wujiang" : 1,
        ]));

	set("coor/x",-330);
  set("coor/y",-370);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");
        if ( (!fam || fam["family_name"] != "大理" )
         && dir != "south" 
         && objectp(present("dali guanbing", environment(me))))
          return notify_fail("大理官兵拦住你，说道：府衙内不得随意进出。\n");
        if ( (!fam || fam["family_name"] != "大理" )
         && dir != "south" 
         && objectp(present("dali wujiang", environment(me))))
          return notify_fail("大理武将拦住你，说道：府衙内不得随意进出。\n");
        return ::valid_leave(me, dir);
}
