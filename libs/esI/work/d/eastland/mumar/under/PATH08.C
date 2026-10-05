#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("坑道");
  set_long( @CLong
你走在牧马关的地下密道中，这儿看起来十分潮□而泥泞。可能是才刚开凿不久
，所以没有支撑也没有火把，空气也显得更为混浊。西北边的坑道中不时传来的吵杂
的挖掘声和吆喝声，夹著回音，使人头痛欲裂，在密道中缭绕不绝。而东北边则是一
片死寂，让人毛骨悚然。
CLong
);
set( "pre_exit_func", ([ "northeast" : "check_zhao" ]) );
set("exits",([
               "south": UNDER "path07",
               "northwest": UNDER "path09",
               "northeast": UNDER "path10"
             ]));
set("objects",([ "general": MOB"zhao" ]));
reset();
}
int clean_up() {return 0;}
int check_zhao()
{
   if( present("zhao") ) {
      tell_object(this_player(),
      "赵子扬突然挡住你说: 别乱逛。\n" );
      return 1;
   }
}
