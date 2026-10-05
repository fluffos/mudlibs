#include <under.h>
inherit ROOM;
int spade = 1;
 
void create()
{
        ::create();
  set_short("将军寝室");
  set_long( @CLong
你走进了将军寝室，这儿简单得让人吃惊。除了一张铺著军毯的低矮木床(bed)
和一张小小的书桌(desk)外，这里真可说是家徒四壁了。比起李□，你觉得这儿的主
人似乎朴实得多。
CLong
);
set("light",1);
set("c_item_desc",([ "bed":"@@to_bed",
                     "desk":"@@to_desk" ]) );
set("search_desc",([ "bed":"@@search_bed" ]) );
set("exits",([
               "south": UNDER "room01"
             ]));
reset();
}
 
string to_bed()
{
    return "一张乾乾净净整整齐齐的床。\n";
}
string to_desk()
{
    return "一张小木桌，桌上的一盏烛光照亮了整个房间。\n";
}
string search_bed()
{
        object obj;
 
        if( !spade || present("spade", this_object()) ) return
          "你几乎把整张床都翻了过来，还是什麽都没找到。\n";
        obj = new( OBJS"spade" );
        obj->move( this_object() );
        spade = 0;
        return
          "\n你东翻西找..终於在床下找到了一支圆锹！\n\n你心中想著：这真是位体恤下属的好将军\n";
}
