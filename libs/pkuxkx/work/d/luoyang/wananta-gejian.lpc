//wananta-gejian.c -- 万安塔十层隔间（乌旺阿普室中）
//Zone: 万安寺
//Created by ddid
//2009-6-18

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"万安塔十层隔间"NOR);
  set("long", @LONG
这里是塔内十层的一个小隔间，鹿杖客的大弟子乌旺阿普就住在这里
。乌旺阿普是万安塔的守塔总管，居于第十层，便于眺望四周，控制全局
。屋内的陈设很简单，里边靠墙，有一张大床。

LONG
  );
  set("no_task",1);
  set("exits", ([     
      "east" : __DIR__"xiangfang-north",   
  ]));

  setup();
}

void init()
{
	add_action("do_nothing", "nothing");
}

int do_nothing()
{
	
	return 1;
}
