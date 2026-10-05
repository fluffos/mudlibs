#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("密道岗哨");
  set_long( @CLong
这里是牧马关的地下密道的入口，通道并不是很宽敞，大约只是个直径十尺的大
圆洞，大约一次可以让五六个人同时通过；骑在马上的话，还得要低著头才能过得去
。这里的通风并不好，空气中混杂著泥土和水的气味；但是可能因为是在地下，这里
并不会感到燥热。北边的密道中不时传来的挖掘声和吆喝声，夹著回音，在密道中缭
绕不绝。
CLong
);
set( "pre_exit_func", ([ "north" : "check_guard" ]) );
set("exits",([
               "north": UNDER "path02",
               "south": MUMAR "secret01"
             ]));
set("objects",([ "general": MOB"liao",
               "guard#1": MOB"guard",
               "guard#2": MOB"guard"]));
reset();
}
 
int check_guard()
{
        if( wizardp(this_player()) || !present("guard") ) return 0;
   { if(this_player()->query_temp("army_mark") )    {
        tell_object(this_player(),
                "守卫说道:长官好....。同时做出持枪敬礼的动作。\n" );
        return 0;
          }
      else   {
        tell_object(this_player(),
                "守卫说: 那里是本关重地，闲杂人等不得进入。\n" );
        return 1;
             }
   }
}
