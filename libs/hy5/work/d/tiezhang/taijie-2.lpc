// Room: /u/bobo/tiezhang/taijie-2.c

inherit ROOM;

void create()
{
        set("short", "石阶");
        set("long", @LONG
石阶到了这里就没有了，突然四周一片光明，周围石壁上的火把燃烧起来，
你看到面前二扇铜皮包着的大门(gate)紧闭着。
LONG
        );

        set("exits", ([ 
"eastup" : __DIR__"taijie-1",
]));
        set("objects", ([
        "/d/feihu/npc/corpse" : 4,
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_open", "tui");
}

int do_open(string arg)
{
      object me;
      me=this_player();
      
      if(!arg || arg != "gate")
          return notify_fail("你要推什么？\n");
	if (objectp(present("flash corpse", environment(me))))
	   return notify_fail("附近有脏东西，你还有空做这个！！\n");

      if (arg == "gate")
      {
      if ((int)me->query_temp("marks/baowu")){
          write("你用力一推大门，脚下一个啷呛，跌了进去，大门随后就关上了。\n");
          me->move(__DIR__"dashishi");
          me->delete_temp("marks/baowu",1);
          return 1;
          }
       }
       return notify_fail("你用尽全力推大门，大门丝毫不动。你无奈地摇了摇头。\n");
}
