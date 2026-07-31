//changlang4.c 长廊
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short", HIY"西厢长廊"NOR);
            set("long",@LONG
西厢长廊短而精致，其右是景色秀丽的花圃，所种植的奇花异草更是惹人
喜爱，引得蜂蜂蝶蝶都围着花儿忙个不停。其左是供休息的小巧座椅，配有精
致的雕花扶手，整条廊子充满了勃勃生机。它的南北二侧是休息室。
LONG
    );

            set("exits",([
                "north": __DIR__"sleep1",
                "south": __DIR__"sleep2",
                "east": __DIR__"lang1",
                "west": __DIR__"lang5",
            ]));
 
            setup();
}

int valid_leave(object me, string dir)
{
        if ((me->query("gender") == "女性") && dir == "north") 
           return notify_fail("女孩子家怎么能进男人房间呢，否则以后怎么嫁人呢！\n");
        if ((me->query("gender") == "男性") && dir == "south") 
           return notify_fail("你一个大男人怎么能进女孩子房间呢，太过份了！\n");
        if ((me->query("gender") == "无性") && (dir == "south" || dir == "north"))
	   return notify_fail("这位公公，这里没有地方可以让您休息。\n");
           return ::valid_leave(me, dir);
}
