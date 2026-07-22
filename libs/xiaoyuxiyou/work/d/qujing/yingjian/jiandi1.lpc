//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;
int do_feel(string arg);
void delete_dir(object where);

void create ()
{
  set ("short", "涧底");
  set ("long", @LONG

涧底到处都是些水草，还有些小虾米，鱼儿穿来穿去，偶尔还能看到
一两具骸骨，看来都是白龙吃剩的骨头。

LONG);

  set("exits", ([
        "south" : __DIR__"jiandi2",
        "north" : __DIR__"jiandi3",
        "east"  : __DIR__"jiandi4",
        "west"  : __DIR__"jiandi5",
      ]));
   set("objects", ([
        "/d/jz/obj/fish": 3,
        ]));
  setup();

}

void init()
{
  object where=this_object();

  remove_call_out("delete_dir");
  call_out("delete_dir",4,where);
  add_action("do_feel","tang");
}

int do_feel(string arg)
{
  object me = this_player();
  string place;
  object yao;

  if ( me->is_busy() )
    return notify_fail("你正忙着呢！\n");

  if( ! arg || arg != "stone" )
    return notify_fail("你要淌什么?\n");

  if ((int)me->query("obstacle/number") != 1)
    return notify_fail("你什么也没有淌到。\n");
    
  if( me->query("obstacle/yj") == "done" )
    return notify_fail("这里你来过了，现在什么也淌不到。\n");

  if( me->query_temp("yj/find") )
    return notify_fail("你已经发现某个地方有入口了，还不快去找？\n");       

  if( random(5) == 1)
  {
    place = sprintf("/d/qujing/yingjian/jiandi%d",1+random(10));
    message_vision("$N仔细淌了淌脚下的石头,发现周围的珊瑚好象动了一下！\n",me);
    place->set("exits/down", __DIR__"shanhu");
    me->start_busy(1);     
    me->set_temp("yj/find",1);
    return 1;
  }

  tell_object(me,"糟了，你惊醒了水怪！\n");
  yao=new(__DIR__"npc/yao");
  yao->move(environment(me));
  yao->set_follow(me);
  return 1;
}

void delete_dir(object where)
{
  object me = this_player();
  	
  if(where->query("exits/down"))
  {
    this_object()->delete("exits/down");
    if (userp(me))
      me->delete_temp("yj/find");
  }  
  return;
}
