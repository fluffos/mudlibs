// Room: /d/baituo/caidi.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "菜地");
        set("long", 
                 "这是一片菜地，种着几种很普通的蔬菜，但是看起来菜长的并不\n"
             "怎么好呀！菜地里捕食传来蝈蝈的叫声，倒是非常悦耳。从这里往西\n"
             "是个小小的广场，大概是村子里人们集会的地方吧！\n"
              );
	set("exits", ([ /* sizeof() == 2 */
           "east" : __DIR__"guangchang",
            ]));
         set("outdoors", "baituo");
	set("no_clean_up", 0);
        set("worm_sign",3);
	setup();
}

void init()
{      
       if (this_object()->query("worm_sign")>0)
           call_out("greeting",0,this_player());
       add_action("do_catch","catch");
       add_action("do_catch","zhuo");
       add_action("do_catch","zhua");
}

int do_catch( string arg)
{
       object me=this_player();
       if (!arg ||arg=="")
          return notify_fail("你要捉什么呢？\n");
       if (arg!="guoguo" && arg!="guo guo" && arg!="蝈蝈")
          return notify_fail("这里没有这个东西让你捉呀！\n");
       if (me->is_busy())
          return notify_fail("你还是先把手边的事忙完了再来捉蝈蝈吧！\n");
       if (me->query("qi")<=50||me->query("jing")<=20)
          return notify_fail("你现在太疲劳了，歇歇吧！\n");
       message_vision("$N在菜地里跳来跳去的捉蝈蝈！\n",me);
       me->start_busy(4);
       call_out("catched",2,me);
       return 1;
} 

int catched(object me)
{     
      object ob;
      int iscatch;
      iscatch=random(me->query_skill("dodge") * (this_object()->query("worm_sign") ) + 1);
      if (iscatch>=200)
      {
           ob=new("d/baituo/obj/guoguo");
           ob->move(me);
           me->receive_damage("qi",50,"抓蝈蝈累");    
           me->receive_damage("jing",20,"抓蝈蝈累");
           message_vision("$N捉到了一只绿油油的大蝈蝈！\n",me);
           this_object()->add("worm_sign",-1);
           return 1;
      }
      if (iscatch>=100||iscatch==0)
      {    message_vision("累了半天，$N什么也没有捉到！\n",me);
           me->receive_damage("qi",40,"抓蝈蝈累");
           me->receive_damage("jing",20,"抓蝈蝈累");
           return 1;
      }
      
      message_vision("$N一个不小心，惊跑了一只大蝈蝈！\n",me);
      this_object()->add("worm_sign",-1);
      me->receive_damage("qi",40,"抓蝈蝈累");
      me->receive_damage("jing",20,"抓蝈蝈累");      
      return 1;
}

int greeting(object me)
{   
	if (!me) return 1;
	message_vision("“括括括括”，一阵清脆悦耳的蝈蝈的叫声传到了你的耳朵里，你不\n禁想停下来看个究竟！\n",me);
    return 1;
}
