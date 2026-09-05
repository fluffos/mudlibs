// Room: /u/cuer/emei/shkjtou.c

inherit ROOM;
 
void init();
void setxia2(object);

void create()
{
	set("short", "蛇窟尽头");
	set("long", @LONG
你终于闯过蛇窟了，这里是蛇窟的尽头了，四周一片
黑暗，而且很是安静，一种阴森恐怖的气氛笼罩着这里。
黑暗中隐隐约约有人在看着你。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sheku",
]));
	set("no_clean_up", 0);
        set("no_task", 1);

	setup();
}

void init()
{     
  object me = this_player();
  if( me->query_temp("xia1") ==1 && !me->query_temp("xia2") )  
  {remove_call_out("setxia2");
   call_out("setxia2",1,me);
  } 
}
void setxia2(object me)
{ 
  message_vision("从黑暗中走出一个老妇人对$N说：“很好，你可以向掌门复命了。”",me);
  me->set_temp("xia2",1);
}
