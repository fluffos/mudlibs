// chitang.c
// By Pingpang 

inherit ROOM;

void create()
{
    set("short", "池塘");
    set("long", @LONG
西边是一片桃林，你可以闻到一股扑鼻的桃花的香气.
这里你可以跳到池塘里去洗澡(bathing)，听说在此洗澡可以让人
容颜变得清秀而美丽，有时也可能变得丑陋。
LONG);
     set("exits", ([
        "west" : __DIR__"taolin2",
          ]));
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);
		set("no_task",1);
     setup();
}
void init()
{
  add_action("bathing","bathing");
}           

int bathing()
{
  object me = this_player();
      if(me->query("per")>40)
        return notify_fail("这么漂亮的人，就不怕变丑吗?\n");
  else
 { int jing;    
  if( me->is_busy() )
  return notify_fail("你上一个动作还没有完成呢。\n");  
  jing=me->query("jing");
  if(jing<40)                    
  return notify_fail("你太累了，无法集中精力！\n");
  message_vision("$N正在池塘里洗澡。\n",me);
  me->start_busy(30); 
  me->set("jing", jing-40); 
  call_out("finish",30,me);
  return 1;}
}          

void finish(object me)
{      
       int tt = (int)me->query("kar")/3-random(10);
       if ((int)me->query("per")<35 && random(10)>5 && (int)me->query("per")>10)  // by haiv，防止per出现负数
       {
       me->add("per",tt);
       me->add("xiantian/per/gypool",tt);
       message_vision("$N感觉到池塘对自己的皮肤很有好处。\n",me);
       }
          me->add("max_jingli", random(3)-1);
       message_vision("$N洗澡后感到身心舒畅。\n",me);
}
 
