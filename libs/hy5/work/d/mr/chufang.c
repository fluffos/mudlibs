// /u/beyond/mr/chufang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"厨房"NOR);
         set("long",@long
这是一间小厨房, 虽然不大, 但是锅碗瓢盆, 油盐酱醋, 到很奇全。灶台
上堆满了新鲜瓜果蔬菜, 活鱼活虾, 不仅不脏不乱, 还十分干净整齐。
long);
         set("objects", ([
             __DIR__"obj/lingbai-xiaren" : 1,
             __DIR__"obj/dongsun-tang" : 1,
             __DIR__"obj/yingtao-huotui" : 1,
]));
         set("valid_startroom", 1);
         set("exits",([
             "south" : __DIR__"xiaoting",
]));
         setup();
	 
}
