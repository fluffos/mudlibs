// Room: quanshui.c 泉水中

inherit ROOM;

void create()
{
	set("short", "泉水中");
	set("long", @LONG
及膝深的泉水在你身边缓缓流过，清澈见底，水中不时有小鱼在鹅卵石中
游来游去。
LONG
	);
        set("objects", ([
         __DIR__"npc/liefuyu" : 2, 
        ]));
	setup();
}

 void init()
  {
        int time;
        object me;
        me = this_player();
//        add_action("do_zhuo", "zhuo");
        add_action("do_tiao", "tiao");
        if (me->query("id")!=("liefu yu"))
         {
        time = me->query("con")*10;
        message_vision( 
        "$N嗵地跳进泉水中，水花四溅，澈骨冰冷的泉水让$N直想快点离开。\n",me);
        remove_call_out("jumpout");
        call_out("jumpout",time,me);
     }
  }

/*int do_zhuo(string arg)
  {
        object me , weapon;
        me = this_player();
	weapon = me->query_temp("weapon");

        if ( arg != "yu" ) 
             return notify_fail("你伸手在水中胡乱划拉了几下，呵！水还真凉！\n");

        if (((int)me->query_skill("dodge",1) < 120 )  || ((int)me->query_skill("claw",1) < 120 ))
        return notify_fail("你轻而易举地就可以抓到小鱼，看来毫无收获。\n");
	if (objectp(weapon))
             return notify_fail("你用"+weapon->query("name")+"在水里来回划拉，溅得满脸水花。\n");
        
	if (objectp(present("liefu yu", environment(me))))
          {
           if (random(10)>3) 
              {
         message_vision( 
        "$N紧盯着小鱼，追过去探手去捉，把水趟得哗啦乱响。腾挪之际，身手比以前熟练了许多。\n",me);    
        me->add("qi", -50);
        me->add("jing", -50);
        me->add("neili", -50);
   
        me->improve_skill("dodge", me->query_skill("dodge")/5);   
        me->improve_skill("claw", me->query_skill("claw")/5);   
        return 1;
        }  

        me->add("qi", -30);
        me->add("jing", -30);
        me->add("neili", -30);
        message_vision( 
        "$N跨前一步，刚想去捉，不料脚下一滑，惊叫声中早扑倒在泉水中，
$N连忙挣扎着湿淋淋得爬了起来。\n",me);
         return 1;
         }

	return notify_fail("你低头四下打量，鱼都被吓跑了，还捉什么呀？\n");
}*/


int do_tiao(string arg) 
   {
        object me;
        me = this_player();

        if(arg != "out" ) 
             return notify_fail("你试着跳了跳，发现在水里你的轻功大打折扣。\n");
        message_vision("$N觉得水太凉了，实在受不了，只好跳出泉水。\n",me);
	remove_call_out("jumpout");
        me->move(__DIR__"xuelingquan");
        tell_room(environment(me),"只听“哗”的一声水响，"+me->query("name")+"湿漉漉的从泉水中跳了出来。\n");
	return 1;
}

void jumpout(object me)
	{
	if (!me) return;
        message_vision("$N觉得水太凉了，实在受不了，只好跳出泉水。\n",me);
	remove_call_out("jumpout");
        me->move(__DIR__"xuelingquan");
        tell_room(environment(me),"只听“哗”的一声水响，"+me->query("name")+"湿漉漉的从泉水中跳了出来。\n");
}
