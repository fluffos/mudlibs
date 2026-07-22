// Room: /d/emei/qianfoandd.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "千佛庵大殿");
	set("long", @LONG
千佛庵殿宇高广宏阔，清洁庄严。庵内有一具七万千佛莲灯，有纹龙七条
环于灯体，并有佛像数百周匝排列，雕缕精致无比。
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"chanfang2",
  "out" : __DIR__"qianfoan",
]));
	set("objects",([
	CLASS_D("emei") + "/jing-hui" : 1,
	CLASS_D("emei") + "/wen-yin" : 1,
]));
create_door("east", "小门", "west", DOOR_CLOSED);
	setup();
}
