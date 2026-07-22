#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("牧马关密道");
  set_long( @CLong
你走在牧马关的地下密道中，从支撑函洞的木架看来，这里似乎才刚开凿不久，
但从墙上整齐的火把看来，不但施工的速度并不慢，而且管理也十分周到。这里的通
风并不好，空气中混杂著泥土和水的气味；但是可能因为是在地下，这里并不会感到
燥热。东边和西边两间房间的小门上分别用小木牌写著『武器库』和『装备库』。北
边的密道中不时传来的挖掘声和吆喝声，夹著回音，在密道中缭绕不绝。
CLong
);
set( "light",1 );
set("exits",([
               "south": UNDER "path03",
               "north": UNDER "path05",
               "east": UNDER "w_vault",
               "west": UNDER "a_vault"
             ]));
reset();
}
