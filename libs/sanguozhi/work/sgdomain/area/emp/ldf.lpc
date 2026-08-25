#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"炼丹房"+NOR+"");
   set_long("
    这里是皇宫中最为神秘的地方，每一代的皇帝都供养了不少的道
士、炼丹士之流的异人，以求获得长生不老的秘术或仙丹。房间的正
中央是一个紫铜制成的炼丹炉，周围散乱摆放着几个蒲垫，墙上挂着
一把桃木剑。一个鹤发童颜的老道士正在这里炼丹。

");
   set_exits( ([
	     "south" : __DIR__+"cl6",
        ]) );
        set_objects( ([ __DIR__+"lds" : 1, ]),);
}
