// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "宝库");
        set("long", @LONG  
这是一个宽阔的密封地室，室顶四角均有通气口，两边 
平排放置共几十个该是装载奇珍异宝的箱子(xiang)，贴
墙有几十个兵器架(jia)，放满各种，兵器 ,足够装备一
个几千人的军队了!
LONG
        ); 
        set("item_desc", ([ 
          "xiang" : "箱子里刻着一些字符，好象是一样武功，你不由想仔细看(think)一下!\n",      
       "jia" : "兵器架上其中有一把剑特别吸引人，你要拿(pick)出来看看吗?\n",      

                          ]));
        set("exits", ([
                "up" : __DIR__"baoku",
                      ]));
set("objects", ([
		__DIR__"obj/corpse" : 2,
	]));                      
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player(); 
    add_action("do_think", "think"); 
        add_action("do_pick", "pick"); 
     } 
void check_tishi()
{
    object room;
            message("vision", HIC"你心中琢磨着，感到不对呀，怎么会没有圣舍利呢?。\n",
            this_object() );
}
int do_pick(string arg)
{
        object sword, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="jia" )
                             {  
if(query_temp("nasword")){ 
   message_vision("$N想去拿宝剑结果发现已经给人拿了\n", this_player());
     return 1;
 }
                                message_vision(
HIY"$N在兵器架上拿下了一把宝剑!\n"NOR, this_player());
                    sword = new(__DIR__"obj/kaitian-jian");
                        sword->move(me);   
set_temp("nasword",1);
// message("channel:chat", HBRED HIW"【海洋】"+me->query("name")+"在杨公宝库里发现了开天魔剑了!\n"NOR,users()); 
if (random(10)<3)
{
  check_tishi();  
}
return 1;
                }
        return 0;
}
int do_think(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("你要看什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="xiang" || dir=="箱子" ) { 
          me->receive_damage("qi", me->query("max_qi")/500 );
 me->receive_damage("jing", me->query("max_jing")/500 );
me->improve_skill("dodge", (int)me->query_skill("dodge", 1)/30);
write(HIB"你看了看箱子里的字符，发现自己的轻功修为有所增加!。\n"NOR); 
                 return 1;
}
         else {
            write("你想看什么东西?\n");
            return 1;
        }
}
}

