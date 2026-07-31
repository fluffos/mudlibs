//Room: ssyb.c 舍身崖壁
//Date: Oct. 21 1997 by That

inherit ROOM;
void create()
{
      set("short","舍身崖壁");
      set("long",@LONG
你终于游到崖壁。抬头上望，微见天光。壁面潮湿，裂缝中微有水渗
出。脚下是污浊的臭水，四周的景物都看不清。向东就是你来时的水潭。
LONG);
      set("outdoors","emei");
      set("objects", ([
          __DIR__"npc/frog" : 1,
      ]) );
      set("exits",([ /* sizeof() == 1 */
          "east"  : __DIR__"st8", 
      ]));
      set("no_clean_up", 0);
      set("no_fight",1);
      setup();
}
void init()
{
    add_action("do_dig","dig");
    add_action("do_climb","climb");
}
int do_climb()
{
    object me;
    me = this_player();
    message("vision", me->name()+"使劲爬上去，花了九牛二虎之力。\n", environment(me), ({me}) );
    me->move(__DIR__"gudelin1");
    message("vision", me->name()+"花了九牛二虎之力，到了这个地方，却不知道在哪里？\n", environment(me), ({me}) );
    return 1;
}
int do_dig()
{
    object ob,me;
    me = this_player();
    message("vision", me->name()+"在地上挖了很长时间......\n", environment(me), ({me}) );
    if (query("nosword")>3)
    {
       message_vision("倚天剑已经给人拿走了，$N深深叹了口气。\n",me);
       return 1;
    }
if (present("sky sword", me))
    {
       message_vision("你身上不是有着吗？\n",me);
       return 1;
    }

    if (me->query_temp("skyswordf") || me->query("max_neili")<500)
    {
       message_vision("这里什么也没有了，$N深深叹了口气。\n",me);
       return 1;
    }
    if (me->query("marks/skysword") )
    {
       if ((random(5))==1)
       {
          message_vision("$N忽然挖到个硬的东西。捡起来抹了土看看，高兴的大笑起来。\n", me);
          write("梦寐以求的倚天剑啊！\n");
          me->set("marks/倚天剑",1);
          ob = new(__DIR__"obj/skysword");
          ob->move(me);
add("nosword",1);
       }
       else
       {
         message_vision("$N忽然挖到个硬的东西。捡起来抹了土看看，高兴的大笑起来。\n", me);
          write("梦寐以求的倚天剑啊！\n");
          me->set("marks/倚天剑",1);
          ob = new(__DIR__"obj/skysword");
          ob->move(me);
//add("nosword",1); 
       }
       return 1;
    } 
}
