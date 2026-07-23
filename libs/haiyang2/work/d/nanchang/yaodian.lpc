
inherit ROOM;


void create ()
{
  set ("short","药店");
  set ("long", @LONG
这里是一家药店。这里的药物种类齐全，在南昌有极高的信誉。现
在局势混乱，药典的生意更是兴旺。只见门前挂着一幅大匾，上面写着：
华佗再生，治病救人 八个大字。几个伙计正在那里给病人包药，还有很
多病人在椅子上排队等候。
LONG);

  set("exits", ([ 

  "north":__DIR__"dongdajie1",
        ]));

  set("objects",([
	  __DIR__"npc/huang":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

