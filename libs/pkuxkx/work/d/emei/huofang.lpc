// Room: /u/cuer/emei/huofang.c

inherit ROOM;
int do_work(); 
void end(object);

void create()
{
	set("short", "伙房");
	set("long", @LONG
这里是峨嵋派的伙房，几个烧火尼在这里忙着做饭。
这里人声嘈杂，不时还有峨嵋派弟子进来帮忙的。一个象
是这里的管事模样的人在指挥着众人干活。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shanfang",
]));
	
	set("kitchen", 1);
	setup();
	
}
                     
void init()
{
   add_action("do_work","work");
}                               

int do_work()
{
  object me = this_player();
  if( me->is_busy())
     return notify_fail("你上一个动作还没有完成呢。\n");
  if(me->query("qi") < 50 )
     return notify_fail("你的体能太弱了，不能干体力活！\n");
  me->set("qi",me->query("qi")-50);
  message_vision("$N轻声说道：“我想干活，挣点钱。”\n一个管事走过来说：“好吧。”\n$N开始干活。\n",me);
  me->start_busy(5); 
  call_out("end",7,me);
  return 1;
}          

void end(object me)
{ 
  object ob;
  message_vision("$N终于把活干完了。\n一个管事走过来看了看，说：“不错。”\n管事给你一些铜板。\n",me);
  ob=new("/clone/money/coin");
  ob->move(me);
}
