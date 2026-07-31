//smzz by 2002/9/17
// 萧雨轩
#include <ansi.h>
inherit ROOM; 
void create()
{
set("short",HIC"萧雨轩"NOR);
set("long",
"这里是一间鲜花店后室，是最近才向外面开放的。每一位顾客可以在这里\n"
"找到一切日常生活用品，好象还可以拿到什么宝贝。这里面静悄悄的少了市井\n"
"的喧哗也没有江湖上腥风血雨的生活。这里可以尽享梦的快乐。西墙的墙壁上\n"
"有个壁柜，上面贴了一张布告(sign)。\n"
);
set("no_fight",1);
set("no_sleep_room",1);
set("exits", ([
       "east" : "d/city/huadian",     
]));
set("item_desc", ([ 
          "sign":
"          ┌────────"BRED+HIG"告示"NOR+"────────┐\n"
"          |    经验底于五十五万的玩家家可以从墙角边  |\n"
"          |    的大橱柜拿到一张新手地图（na tu)    |\n"
"          |     "BRED+HIY"**********************"NOR"    |\n"
"          └────────────────────┘\n"
]));
setup();
}
void init() 
{
   add_action("do_na", "na"); 
}
int do_na(string arg)
{
object me,ob; 
me = this_player(); 
if( !arg || arg=="" ) return notify_fail(HIC"你要拿什么？\n"NOR);; 
if( arg=="tu" ) 
{
  ob=new("u/smzz/obj/newbie_map");
   ob->move(me);
message_vision( "$N从壁柜里拿出一张新手帮助地图。\n" NOR,me);
}
return 1;
}
