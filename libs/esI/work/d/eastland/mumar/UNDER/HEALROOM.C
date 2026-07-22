#include <under.h>
inherit ROOM;
 
void create()
{
        ::create();
  set_short("牧马关医务室");
  set_long( @CLong
你走进了一间狭窄而克难的医务室，刺鼻的药味和燃烧艾草的气味压过了密道的
泥土味，让你觉得有些呛鼻。房间的墙上到处是用木板钉成的架子，放了许许多多大
大小小的白色瓷瓶和长短不一的银针，地上则是用白布铺成的通铺，七横八竖地躺了
一些伤兵。南边墙壁的上方有几个通气的小孔，透射出几道光线，也使得整个房间明
亮不少。
CLong
);
set("light",1);
set("c_item_desc",([ "wall":"@@to_wall" ]) );
set("search_desc",([ "wall":"@@to_search_wall" ]) );
 
set("exits",([
               "west": UNDER "path02"
             ]));
set("objects",([
               "healer": MOB"healer",
               "soldier": MOB"wounded",
               ]));
reset();
}
string to_search_wall()
{
    write("当你专注地触摸著这道墙时，将重心时放在墙上的你突然一个踉跄跌到墙外......\n");
    this_player()->move_player(UNDER"cloth");
    return "\n";
}
 
string to_wall()
{
    return "你看著南面这道墙，总觉得它看起来十分「软」，不像一般的土墙。\n";
}
