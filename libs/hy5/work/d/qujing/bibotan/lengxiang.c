#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "冷香殿");
  set ("long", @LONG

冷香殿上的家俱都是昆仑山中特有的冷香木制成，肌肤所触都是
冰冷异常。大厅之上弥漫这一丝淡淡的香气，让人不由得神清脑
健，精神倍增。
LONG);


	set("cold", 1);
//  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shuijg",
]));
//      
        set("water", 1);
//  
  setup();
}

