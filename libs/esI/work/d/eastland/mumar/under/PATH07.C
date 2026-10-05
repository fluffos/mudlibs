#pragma save_binary
#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("坑道");
  set_long( @CLong
你走在牧马关的地下密道中，这儿看起来十分潮□而泥泞。可能是才刚开凿不久
，所以没有支撑也没有火把，空气也显得更为混浊。北边的坑道中不时传来的吵杂的
挖掘声和吆喝声，夹著回音，让人头痛欲裂，在密道中缭绕不绝。
CLong
);
set("exits",([
               "north": UNDER "path08",
               "southwest": UNDER "path06"
             ]));
reset();
#include <replace_room.h>
}
