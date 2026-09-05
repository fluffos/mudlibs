//天寒山
// by steel
#include <ansi.h>
int storm(object me);

inherit ROOM;
//int to_die();
//int to_yun();

void create()
{
	set("short", "天寒山顶");
	set("long", @LONG
这里已是天寒山的山顶,只见崖缝参差,颇为险恶。就在这山顶之
上，有一座冰崖(bingya)冲天而起，仔细看看，崖上好象有斧凿的痕
迹。似乎可以顺着爬上去。
LONG
	);

       set("exits", ([
		"southdown" : __DIR__"hill1",
        ]) );
	setup();
}
void init()
{
	object ob;
	if( interactive( ob = this_player()))
	storm(ob);
    	add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object me;
    object obj;
    int dodge;
    me=this_player();
    if(!arg) return 0;
    if(arg!="bingya")return notify_fail("你要爬什么？\n");
//    if(obj=me->query_temp("armor/boots")) return notify_fail("冰崖太滑了，你爬了几下不得停下来。\n");
    dodge=me->query_skill("dodge",1);
    if(obj=me->query_temp("armor/boots"))
    {
       message_vision(HIB"$N抓紧冰崖上的石缝，慢慢爬了上去。\n"NOR,me);

      if(obj->query("id")=="snow boots")
       {
        if(dodge>80){
            me->add("jing",-80);
            me->add("qi",-80);
            tell_room(__DIR__"bingya", me->name() + "平安的从下面爬了上来。\n");
            me->move(__DIR__"bingya");
            return 1;
             }
      else
       {
       	me->start_busy(2);
            if(dodge<=60)
             {
               call_out("to_die",2);
               return 1;
             }
             else
             {
               call_out("to_yun",2);return 1;
              }
        }
       }
       }
  else
  {
  	message_vision(HIB"$N抓紧冰崖上的石缝，开始慢慢往上爬。\n"NOR,me);
  	me->start_busy(5);
    if(dodge<=60)
             {
               call_out("to_si",5);
               return 1;
             }
             else
             {
               call_out("to_yun",5);return 1;
             }
  }
}

int to_si()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());
     this_player()->receive_damage("qi", 0, "摔下冰崖");
     this_player()->die();
     return 1;
}
int to_yun()
{
     message_vision(HIR"不好!$N手上一滑,从半空中摔了下来。\n"NOR,this_player());
     this_player()->unconcious();
     return 1;
}

int storm(object me)
{
	int i, flag;
	object *inv;
        int qi = me->query("qi");

        inv = all_inventory(me);
        for(i = 0; i < sizeof(inv); i++)
        {
        	if(inv[i]->query("id") == "pi qiu" && inv[i]->query("equipped"))
        	flag = 1;
        }

	if( environment(me) == this_object())
	{
                 if( !flag )
                 {
                         tell_object(me, HIR"\n一股刺骨的寒风吹过，你只觉得浑身的血液都快被冻住了！\n"NOR);
                         write("看来不穿一件保暖的外衣，一定会被冻死的！\n");

                         me->start_busy(1);
                         me->receive_damage("qi", 10 + random(50), "冻");
                         me->receive_wound("qi", 10 + random(20), "冻");
         		if( environment(me) == this_object())
         		call_out("storm", 5 + random(5) , me);
                 }
                 else
                 tell_object(me, HIC"\n一股刺骨的寒风吹过，你将皮裘裹得更加严实了！\n"NOR);
	}
        return 1;
}
