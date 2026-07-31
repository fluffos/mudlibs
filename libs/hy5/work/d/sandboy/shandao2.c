// Room: /d/sandboy/shandao 
#include <ansi.h>
inherit ROOM; 
 
void create ()
{
  set ("short", "山道");
  set ("long", @LONG
这是一条幽静的山道。太阳暖洋洋地在头上，溪水活泼泼地在脚边流过。 
小鸟儿唧唧叫着飞过不远的树林，道边地上有一大堆砍好的毛竹。一只酒 
葫芦就放在那堆毛竹边，和一个陶罐、一个瓷碗以及两件打着补丁的粗布 
衣裳放在一起。向西是一片竹林，传来咔咔的砍竹声。 
LONG);

  set("objects", ([ /* sizeof() == 4 */
  "/d/hainan/npc/man1" : 2,
  __DIR__"obj/taoguan.c" : 1,
  __DIR__"obj/ciwan.c" : 1,
  "/d/hainan/npc/man2" : 2,
]));
set("outdoors","/d/jiangnan");
  set("item_desc", ([ /* sizeof() == 3 */
  "树林" : "一片杂树林，大约有好几十棵。 
",
  "竹林" : "这里的毛竹很多，一山一山的，散发着浓郁的竹香。 
",
  "溪水" : "山泉从高处流下，形成的小溪流。 
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhulin",
  "east" : __DIR__"shandao",
]));

  setup();
}
void init()
{
 add_action("do_get","get");
 add_action("do_kan","kan");
}
int do_get(string arg)
{
  object ob,ob1;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   if (arg=="all"||arg=="hulu"||arg=="cloth"||arg=="taoguan"||arg=="ciwan")
    { 
        message_vision(HIY+"突然从地上弹起一根竹梢，把$N倒吊了起来.\n"+NOR,ob);
        ob->move(__DIR__"zhushao");

         ob1=present("cuizhu",this_object());
         if (!ob1)
         {
           ob1=new(__DIR__"obj/cuizhu");
                    ob1->move(this_object());
                 }
     ob1->init();
     return 1;
    }
  return notify_fail("");
}
int do_kan(string arg)
{
   object ob,ob1,ob2,*inv,ob3;
   int i;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   if (arg=="翠竹"||arg=="cuizhu")
           {
               ob1=present("cuizhu",this_object());
               if (!ob1) return notify_fail("哪有你要砍的翠竹?\n");
               ob3=ob->query_temp("weapon");
               if(!ob3||(ob3->query("name")!="砍竹刀")) 
                                 return notify_fail("你没有装备砍竹刀!\n");
               message("vision","只听咔嚓一声,"+HIG+"翠竹"+NOR+"被"+ob->query("name")+"砍断了!\n",this_object());
               destruct(ob1);
            new(__DIR__"obj/cuizhu2")->move(this_object());
                     ob2=load_object(__DIR__"zhushao");
               	inv=all_inventory(ob2);
        	if(sizeof(inv))
                {   
                        tell_room(__DIR__"zhushao",HIR+"只听咔嚓一声，竹子被砍断了，你掉了下去!\n"+NOR);
                        tell_room(__DIR__"shandao2",HIR+"有人从竹梢上掉了下来!\n"+NOR);
                   	for(i=0;i<sizeof(inv);i++)	{
                                        inv[i]->move(this_object());
                                               }
                              }
                return 1;
             }
    return notify_fail("你要砍什么?\n");
}



