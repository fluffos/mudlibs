#include <under.h>
inherit ROOM;
inherit DOORS;
 
void create()
{
        ::create();
  set_short("牧马关警闭室");
  set_long( @CLong
你走进了一间黑暗的牢房。牧马关是东方大国的军事重镇，这儿的部队可说是精
兵中的精兵，纪律也非常之严整，因此，这儿时常是空著的。不过你还是可以在墙壁
上看到一些低级的涂鸦和粗俚的文字。
CLong
);
  set("exits",([ "east": UNDER"jailroom" ]));
  set("objects",([ "jailor": MOB"yang" ]));
  create_door( "east","west",
             (["keyword" : ({"iron","gate"}),
               "name"    : "iron gate",
               "c_name"  : "大铁门",
               "c_desc"  : "一扇厚重的大铁门，甚至连把手都是铁铸的。\n",
               "status"  : "locked",
               "lock"    : "MUMARKEY"
              ]) );
reset();
}
 
void init()
{
   add_action( "do_knock", "knock" );
}
 
int do_knock(string arg)
{
   if( !arg || arg != "gate" )
   return notify_fail( "你要敲啥?\n" );
   if( (string)this_object()->query("doors/east/status")=="open" )
   return notify_fail( "门是开著的, 直接走出去吧。\n" );
   write( "你用力地敲门。\n" );
   tell_room( this_object(),
        this_player()->query("c_name")+"用力地敲著大铁门。\n",
        this_player() );
   tell_object( this_player(),
@ASK
 
江尚青在门外喊道: 来了来了....烦死了......
 
ASK
);
  this_player()->move_player(UNDER"jailroom");
   return 1;
}
