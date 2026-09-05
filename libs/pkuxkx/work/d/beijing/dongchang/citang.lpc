#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"祠堂"NOR);
	set("long",
HIC"这是广场一侧的小厅。厅中供奉一尊人像(statue)，其人正襟危坐，神色泰然，
你定睛一看，赫然是武穆岳飞大人！西边正是东厂的广场，不时传来一些马匹的嘶
鸣声。\n"NOR
	);

	set("exits", ([
		"west" : __DIR__"guangchang",
	]));

	setup();
  set("item_desc", ([
      	"statue": "这里设计一个小秘密！\n",
       ]) );
}
