//jinling  dangpu
#include <room.h>
inherit HOCKSHOP;

void create()
{
        set("short", "天马当铺");
        set("long", @LONG
这里是金陵城的天马当铺,由于财资雄厚,你可以在这里典当任何物品。
由于这里人来人往。因此不时这里也能有一写贵重的宝物出售。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
       "east" : __DIR__"beijie2",
]));
set("objects", ([
  __DIR__"npc/dangpu_boss" : 1,
      ]) );

        set("no_clean_up", 0);

        setup();
}
