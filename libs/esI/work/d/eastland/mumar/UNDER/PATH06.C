#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("牧马关密道");
  set_long( @CLong
你走在牧马关的地下密道中，从支撑函洞的木架看来，这里似乎才刚开凿不久，
但从墙上整齐的火把看来，不但施工的速度并不慢，而且管理也十分周到。由於北边
的石壁特别坚硬，通道在这里斜向东北。这里的通风并不好，空气中混杂著泥土和水
的气味；但是可能因为是在地下，这里并不会感到燥热。西边的密道中不时传来的挖
掘声和吆喝声，夹著回音，在密道中缭绕不绝。北边的墙是一道布幕，布幕中透出微
明的灯光。
CLong
);
set("light",1);
set("exits",([
               "east": UNDER "path05",
               "north": UNDER "room01",
               "northeast": UNDER "path07"
             ]));
set("pre_exit_func",(["north":"go_north"]));
reset();
}
int go_north()
{
        write("你掀开布幕，走进了一间明亮的房间。\n。");
        return 0;
}
