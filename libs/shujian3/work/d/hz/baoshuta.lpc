// /u/beyond/hz/baoshuta.c 宝淑塔
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIY"宝淑塔"NOR);
        set("long", @LONG
你上到山来，就是宝淑塔了，塔身玲珑修长，高耸挺拔，造型俏丽，风
格独特。从塔下仰望塔尖，有高不可抑之感；从山下远望，亭亭玉立，秀丽
玲珑。所以有句谚语说：“湖上两浮屠，雷峰如老衲，宝淑如美人。”
LONG
        );
set("objects",([
__DIR__"npc/you1" : 2,
]));
    set("outdoors", "杭州");
        set("exits", ([
            "southdown" : __DIR__"qsddao1",
            "northdown" : __DIR__"shanlu",
]));
        set("coor/x",60);
  set("coor/y",-310);
   set("coor/z",0);
   setup();
}
