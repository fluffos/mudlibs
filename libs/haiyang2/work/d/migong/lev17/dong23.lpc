
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"水没都市"NOR);
	set("long", GRN @LONG
    这个城市尽然在湖中,脚底下是三□来许的『水板』而两旁都是千丈高的水
墙。两旁水声轰隆隆地快要把你的耳膜震破, 挟带著漫天的水气,不禁把你的全
身都给濡湿了。 水墙里一些七彩斑斓的鱼儿正悠闲地追逐玩耍,有时游近你身
旁,一点也不怕你的样子,你不禁伸手想要穿过水墙去触摸它们,却似乎有股力
量阻挡著你。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"dong22",
                "north" : __DIR__"dong31",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
