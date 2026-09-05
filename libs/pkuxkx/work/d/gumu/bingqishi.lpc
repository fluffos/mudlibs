// Room: /u/cuer/emei/houshan2.c

inherit ROOM;     

int do_search();  
void end(object);

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这里是古墓中的一个小洞，中神通王重阳当时常把义
军的武器藏在这儿，以避免不必要的麻烦。现在这儿仍还
有许多兵器，不过大多数都上锈了，搜一下也许能搜到好
的兵器、

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mudao7",
]));
 	 
     set("shen",random(2));
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
  qi=me->query("qi");
  if(qi<50)                    
  return notify_fail("你无法集中力量查看！\n");
  message_vision("$N开始查看这里的一兵一器，希望能找到一把刀剑什么的。\n",me);
  me->start_busy(2); 
  me->set("qi", qi-30); 
  call_out("end",3,me);
  return 1;
}  
                 
void end(object me)
{
 object ob;              
 object obj = environment(me);
 switch(random(4)){
 case 2:  if(obj->query("shen") != 0)
          {ob=new(__DIR__"obj/tiejia");
          obj->set("shen",obj->query("shen")-1);
          ob->move(me);
          message_vision("$N找到了一副铁甲，放在$N的身上。\n",me);
          break;                            
          }
 case 1: ob=new(__DIR__"obj/changbian");
          ob->move(me);
          message_vision("$N找到了一条长鞭，放在$N的身上。\n",me);
          break; 
 case 0:  message_vision("$N找到一把长剑，放在$N的身上。\n",me);
          ob=new(__DIR__"obj/changjian");
          ob->move(me);
          break;  
 default: message_vision("$N累了个半死，结果什么都没有找到。\n",me);
          break;          
 }
}

