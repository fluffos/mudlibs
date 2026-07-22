// Room: /d/emei/lingwenge.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void create()
{
	set("short",HIW "灵文阁" NOR);
	set("long", @LONG
这里是福寿庵的灵文阁，是主持静照师太传授佛法的地方。两名青衣小尼
随侍在旁，似乎在聆听师太的教晦。阁内布置简陋，靠墙放着几把竹椅，地上
放着几个蒲团。东首有一禅房。西面是一个斋厅。
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"chanfang",
  "west" : __DIR__"fushouanzt",
  "out" : __DIR__"fushouan",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-zhao" : 1,
]));
	setup();
}
