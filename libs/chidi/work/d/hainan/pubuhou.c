// Room: /d/hainan/pubuhou
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "瀑布后");
  set ("long", @LONG
这是一个挺大的山洞,想不到瀑布后面会有这么个山洞,真是令人觉得 
别有洞天.由于外面的水声太大,在这里就算闹翻了天外面也听不见.正面的 
石壁上有条粗大的铁链.拴到一个胡子灰白的老人身上. 
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/luhai.c" : 1,
  __DIR__"obj/tielian.c" : 1,
]));
  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "铁链" : "一条粗大的铁链,显出暗红的光.看来不是凡铁所铸. 
",
]));
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"pubu",
]));

  setup();
}
void init()
{
   add_action("do_kan","kan");
   add_action("do_kan","zhan");
   add_action("do_kan","砍");
   add_action("do_kan","斩");
}
int do_kan(string str)
{ object ob,me,ob1,ob2,ob3;
  ob=present("lu hai");
  ob1=present("tielian");
  me=this_player();
  if (str!="寒铁链"&&str!="tielian") return notify_fail("你要砍什么?\n");
  if (!ob1) return notify_fail("看清楚些,哪有你要砍的铁链?\n");
 if( !(ob2=me->query_temp("weapon"))||(string)ob2->query("id")!="hanyue blade")
      return notify_fail("这条寒铁链只有寒月斩才能斩断!\n");
message_vision("$N大喝一声:开!... ...一刀向$n砍下!\n",me,ob1);
  if (me->query("gender")=="女性")
return notify_fail("刀离铁链还有三尺,就被铁链所发寒气挡住,看来与你纯阴体质有关!\n");
 message_vision("只听...锵...的一声,铁链应声而开,被$N断为两截!\n",me);
destruct(ob1);
ob3=new(__DIR__"obj/duantielian");
ob3->move(environment(me));
if (ob)
   { 
     ob->set("title",YEL"长离一枭"NOR);
if (find_object("/d/hainan/obj/biyu")||ob->query("no_biyu")==1)
   message_vision("$N哈哈大笑:这铁链早给我磨断了,这是我故意绕在身上的.\n",ob);
  else {
     message_vision("$N纵身跃起,放声大笑:哈哈... ...断得锁链脱蛟龙!
好!好!好!这块玉佩就送给你,聊当老夫的一点谢意!
$N递给$n一块青龙碧雪玉!\n",ob,me);
     clone_object("/d/hainan/obj/biyu")->move(me);
ob->set("no_biyu",1);
   }
     }
return 1;
}   
