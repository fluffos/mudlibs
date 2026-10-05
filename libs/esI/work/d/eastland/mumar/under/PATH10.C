#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("废坑道");
  set_long( @CLong
你走到了坑道的末端，不过这儿是一片死寂。这里的地面(ground)看来似乎是沙
质的，而且不同於密道其他地方的是，这里十分乾燥。从北面的墙上开凿的痕迹看来
，这儿应该不是因土石过於坚硬而放弃的。你觉得全身不舒服，想要赶快离开这里。
CLong
);
set("c_item_desc",([ "ground":"@@to_ground" ]) );
set("exits",([
               "southwest": UNDER "path08"
             ]));
reset();
}
string to_ground()
{
    return "你仔细地看著这里的地面才发现这里的地面居然铺满了金属碎屑。\n";
}
