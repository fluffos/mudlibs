// by mayue

inherit ROOM;

void create()
{
	set("short", "万毒窟外");
	set("long", @LONG
这里是五毒教饲养毒物的地方，山壁旁有一个天然的石洞，里
面黑漆漆的看不清楚。一阵山风吹来，你闻到一股腥味。有一个衣
衫褴褛的枯瘦老妇正靠在洞边打盹。 
LONG
	);
        set("outdoors", "wudujiao");
set("roomif","$botten#迎击任务|毒虫任务|完成工作|取消迎击:ask he about attackjob|ask he about job|ask he about finish|ask he about attackfail$#");	  
	set("exits", ([
//		"eastup" : __DIR__"wdsl5",
		"south" : __DIR__"wandu2",
//		"westdown" : __DIR__"wdsl3",
		"north" : __DIR__"wdsl3",
	]));
        set("objects", ([
                 "quest/menpaijob/wudujiao/hehongyao": 1,
	]));
    

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    me=this_player();
   if(dir=="south")
      {
     if( !present("tie shao", me)
        & objectp(present("he hongyao", environment(me))))
          return notify_fail("何红药身形一晃，忽然挡住你，厉声说道：这位" +
           RANK_D->query_respect(me) + "没有教主准许，不得进入本教圣地。\n");
      }
  return ::valid_leave(me, dir);
}
