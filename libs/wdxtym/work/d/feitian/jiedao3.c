// Room: /d/feitian/jiedao3.c
inherit ROOM;

#include <ansi.h>  
void create ()
{
  set ("short", "街道");
  set ("long", @LONG
街道下方有一个破破烂烂的村庄，哪里的人称这里为落人村，自己称为落人。
往上方走就到了树林了。附近有一条迷宫一样的小路走通入树林。
LONG);

  set("outdoors", "feitian");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shulin",
  "west" : __DIR__"jiedao2",
  "south" : __DIR__"luorencun",
]));

  setup();
//  replace_program(ROOM);
}
void init()
{
    add_action("do_enter", "enter");
}

int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="midao" ) 
       {
         tell_object(this_player() , "你要去哪儿？\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "飞天御剑流")
{
     message_vision("$N这是飞天御剑流的密道,你不认识路!\n",  ob);
    return 1;
}
    if(!ob->query_temp("shirenok"))
{
     message_vision("$N你先去探一下树林中的情况吧!!\n",  ob);
    return 1;
}

    ob->move("/d/feitian/pubu") ;
    tell_object(ob, BLU "你看清了小路，直接走出了树林!\n" NOR ) ;
    return 1 ;
}