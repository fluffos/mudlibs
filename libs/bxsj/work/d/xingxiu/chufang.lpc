//chufang.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short","厨房");
       set("long", @LONG
这是星宿的厨房, 虽然不大, 但是锅碗瓢盆, 油盐酱醋, 都很奇全。灶台
上堆满了新鲜瓜果蔬菜, 活鱼活虾, 满屋的果香和肉香，使你一走进这里，闻
得阵阵的香气，就立即想饱餐一顿。有一个厨子正在忙碌着。
LONG);

        set("exits", ([         
                "east" : __DIR__"xx3",
        ]));             

        set("objects",([
                FOOD_D("hulu") : 2,
                FOOD_D("caiyao") : 1,
                __DIR__"npc/chuzi"  : 1,
        ]));

        set("no_fight", 1);

        set("coor/x",-330);
  set("coor/y",180);
   set("coor/z",0);
   setup();
}
