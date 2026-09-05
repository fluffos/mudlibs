//wuqiku.c
inherit ROOM;

int do_search();  
void end(object);

void create()
{
        set("short", "武器库");
        set("long",
             "这里是『白驼山』弟子的武器库，『白驼山』弟子可以到此拿取\n"
         "练功用的各种武器。不过别派弟子是不允许进来的。\n"
         "    只见架子上放着各式兵器，琳琅满目。但都是寻常器械，没有什\n"
         "么神兵利器,你可以搜索一下看看。\n"
        );

        set("exits", ([
                "east" : __DIR__"yuanzi",
        ]));
//      set("objects",([
//              __DIR__"npc/shiwei" : 1,
//      ]));
      set("shen",random(2));
	  set("hsz_no_task",1);
        setup();
}
void init()
{         
   add_action("do_search","search");
}                                   

int do_search()
{
  object me = this_player();
  object ob ; 
  int qi;    
  if( me->is_busy() )
    return notify_fail("你上一个动作还没有完成呢。\n");
  if( time()-me->query("baituo/wuqiku")<=600 )
    return notify_fail("这里啥都没有了，过一会儿再来吧！\n");
  qi=me->query("qi");
  if(qi<50)                    
  return notify_fail("你无法集中力量查看！\n");
  message_vision("$N开始查看这里的一兵一器，希望能找到一把刀剑什么的。\n",me);
  me->start_busy(2); 
  me->set("qi", qi-30); 
  me->set("baituo/wuqiku",time());
  call_out("end",3,me);
  return 1;
}  
                 
void end(object me)
{
 object ob;              
 object obj = environment(me);
 switch(random(4)){
 case 2:  if(obj->query("shen") != 0)
          {ob=new("/d/city/obj/tiejia");
          obj->set("shen",obj->query("shen")-1);
          ob->move(me);
          message_vision("$N找到了一副铁甲，放在$N的身上。\n",me);
          break;                            
          }
 case 1: ob=new(__DIR__"obj/shebian");
          ob->move(me);
          message_vision("$N找到了一条蛇鞭，放在$N的身上。\n",me);
          break; 
 case 0:  message_vision("$N找到一把长剑，放在$N的身上。\n",me);
          ob=new("/d/city/obj/changjian");
          ob->move(me);
          break;  
 default: message_vision("$N累了个半死，结果什么都没有找到。\n",me);
          break;          
 }
}
