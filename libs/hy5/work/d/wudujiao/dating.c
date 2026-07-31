// by mayue


inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是个宽广的大厅，高大的盘龙柱一人都合抱不过来。这里是平日教
主召集教众们议事的地方，大厅正中供奉着五圣--毒蛇，蜘蛛，蜈蚣，蝎子
蟾蜍的画像。几位长老正坐在厅中议事 。
LONG
	);
//      set("outdoors", "wudujiao");
//      set("sleep_room", 1);
//      set("no_fight", 1);
        set("valid_startroom", 1);
set("roomif","$botten#对练任务|个人任务|组队任务|上交物品|换取奖励|取消任务:job|quest|ask shi about teamjob|give <物品> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("exits", ([
		"east" : __DIR__"huayuan1",
		"south" : __DIR__"jingshi",
		"west" : __DIR__"lianwu",
		"north" : __DIR__"shufang",
	]));
        set("objects", ([
               __DIR__"npc/qiyunao": 1,
               __DIR__"npc/panxiuda": 1,
               __DIR__"npc/cenqisi": 1,
               "quest/menpai/wudujiao/shi": 1,
               "d/biwu/champion_wdj": 1,
	]));
    

	setup();
//    "/clone/board/wudu_b"->foo();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="east"||dir=="north"||dir=="south")
      {
  if ((string)me->query("family/family_name")!="五毒教"
        & objectp(present("qi yunao", environment(me))))
          return notify_fail("齐云敖身形一晃，忽然挡住你，厉声说道：这位" +
           RANK_D->query_respect(me) + "不是本教弟子，不得进入本教禁地。\n");
      }
  return ::valid_leave(me, dir);
}

