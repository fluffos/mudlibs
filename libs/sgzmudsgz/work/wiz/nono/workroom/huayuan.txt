#include <mudlib.h>
#include <ansi.h>
#include <sanguo.h>

inherit ROOM;

private mapping exits;

void bind_exit(string direction, object room, int both);
void setexits();


void setup()
{
    set_area("nono_room");
    set_light(50);
    set_brief(""+HIW+"花园"+NOR+"");
    set_long(
"你走进大院，明显可以看到一排排的垂柳，鼻中闻到随风漂来的淡淡茶花香味，
心中不禁一阵清明。这里四周景色秀丽，恬静宜人。石亭里有一张石桌，几张石
凳，供人休息。");


    set_exits( (["west" : "/wiz/nono/fuyuan.c",
                  ]) );              
}


