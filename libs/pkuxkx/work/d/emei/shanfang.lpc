// Room: /u/cuer/emei/shanfang.c

inherit ROOM;
void init();
int do_yao();
void end(object);

void create()
{
	set("short", "膳房");
	set("long", @LONG
这里是峨嵋派弟子吃饭的地方了，不时有弟子进进出
出，虽然不时吃饭的时候，也还有由于勤于练功而耽误了
吃饭的弟子在这儿吃饭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"beilang2",
  "east" : __DIR__"huofang",
]));
	set("objects",([
          __DIR__"npc/obj/bocai-fentiao" : 2,
          __DIR__"npc/obj/mantou" : 1,
          __DIR__"npc/obj/dawancha" : 2, 
            ]));   
	setup();
	
}
                  
void init()
{
 add_action("do_yao","yao");
}
                            
int do_yao()
{
 object me = this_player();        
 int jing; 
 if(me->is_busy())            
 return notify_fail("你上一个动作还没有完成呢。\n");
 message_vision("$N大喊一声：“有饭吗？”\n从里间走出一个厨娘说：“饭菜都放在桌上了，你要吃就吃，不吃自己做！”\n",me); 
 jing=me->query("jing");
 if(jing<30)
 return notify_fail("你连做饭的精力也没有！\n");
 message_vision("$N开始做饭。\n",me);
 me->start_busy(5); 
 me->set("jing", jing-30); 
 call_out("end",7,me);
 return 1;
} 

void end(object me)
{
 object ob;
 switch(random(3)){
 case 0:  ob=new(__DIR__"npc/obj/bocai-fentiao");
          ob->move(me);
          message_vision("$N做出了菠菜粉条，放在$N的身上。\n",me);
          break;
 case 1:  ob=new(__DIR__"npc/obj/mantou");
          ob->move(me);
          message_vision("$N做出了馒头，放在$N的身上。\n",me);
          break;
 case 2:
 case 3:  ob=new(__DIR__"npc/obj/dawancha");
          ob->move(me);
          message_vision("$N做出了大碗茶，放在$N的身上。\n",me);
          break;
 }
}
