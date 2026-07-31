#include <room.h>

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这是武馆馆主的书房，房内很静，几缕阳光从窗外的绿荫中直射进来,
屋内靠窗放着一个大书架，显然都是些主人常看的书。墙上高悬着几个大
字“少壮不努力，老大徒伤悲”。
LONG);
        set("exits", ([
                "west" : __DIR__"lang5",
        ]));	
	setup();
}
void init()
{
        add_action("do_clean", ({"fan","翻","find"}));
}

int do_clean(string arg)
{
     object me,ob; 
     int i;
     i = random(50);
     me=this_player();
     
     if(!arg || arg != "书架" ) return 0;

     if (me->query_temp("book_get")){
           message_vision("$N突然觉得自己怎么这么贪，拿了一本还要拿。\n", me); 
           return 1;
           }
     if(!me->query_temp("wg_study")){
          message_vision("$N随手翻了翻。\n", me);
          return 1;
          }
   
     if(i < 6){
          message_vision("$N高兴的跳了起来，发现了一本自己想要的书。\n", me);
          switch(random(3)) {
              case 0:  ob=new("/clone/book/parry_book"); break;
              case 1:  ob=new("/clone/book/daodejing-i"); break;
              case 2:  ob=new("/clone/book/laozi1"); break;
              }
          ob->move(me); 
          me->delete_temp("wg_study");
          me->set_temp("book_get",1);
          }
     else message_vision("$N翻了半天没发现自己想要的。\n", me);
     me->receive_damage("jing", random(5));
     return 1;
}
