// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit ROOM;

void setup() 
{
    string river = "你会被河水淹死的。\n";

    set_area ("pirate");

    set_brief("大洞穴");
    set_long("大得甚至可以容的下一个小城市。一条小河由西向东缓缓流过洞穴的中部，"
             "到处都是巨大的钟乳石和石笋，有的还聚集在一起形成百余尺高的柱子。"
             "南面有一个小通道，岩洞继续向东南方延伸。");
    set_light(0);
    set_exits( ([
        "south" : "low_crawl",
        "east"  : river,
        "west"  : river,
        "southeast" : "small_dock", 
        "north" : "north_cave",
        ]) );
    set_hidden_exits("east","west");
    set_default_exit ("这个方向没有明显的出口。\n");
    add_item("钟乳石", "石笋", "石柱",
              "钟乳石和石笋都没有什么特殊的地方。" );

    add_item("cavern", "cave", "洞穴", "它大极了..." );

    add_item("river", 
             ([
                 "swim" : "在河水里游泳没有什么用",
                 "wade" : "涉水而过也没有什么用",
                 ]));


    set_objects( ([]) );
}
