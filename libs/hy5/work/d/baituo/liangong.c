//room: /d/btshan/liangong.c
inherit ROOM;
void create()
{
  set("short","练功场");
  set("long",
      "这里是白驼山弟子的练功场。东边是一个练功房。北边是个门廊，\n"
  "西边连着一条长廊，雕梁画柱，非常气派。南面可见巍巍大厅。\n"
    );
  set("exits",([
      "east" : __DIR__"fang",
      "north" : __DIR__"menlang",
      "west" : __DIR__"changlang",
      "south" : __DIR__"dating",
     ]));
  set("roomif","$botten#牧蛇任务|讨债任务|牧蛇放弃|讨债放弃|讨债上交:ask cheng about work|ask cheng about job|ask cheng about fangqi|ask cheng about fail|give <物品> to cheng$#");

 set("objects",([
     __DIR__"npc/li" : 1,
     "quest/menpaijob/baituo/cheng" : 1,
     ]));
// set("no_clean_up", 0);

 set("outdoors", "baituo");
 setup();

 replace_program(ROOM);
}
