#include <ansi.h>
inherit "/newbiequest/dynroom";

mapping virtualSetting=
(["entry":([
	"file":({__DIR__"enter"}),
	"show":(["林间小道":"一条长满荒草的小道，前面似乎通向了一片小树林！\n"]),
	"virtual":1]),
	"maze":([
	"file":({__DIR__"maze"}),
	"short":({HIG"榕树林"NOR,YEL"榕树林"NOR,CYN"榕树林"NOR}),
	"desc":({"稀稀落落得长着南方常见的榕树，茂盛的茅草大概有一个人多高，\n四周似乎危机起伏，需要小心了。\n"}),
	"virtual":1]),
	"out":([
	"file":({__DIR__"out"}),
	"show":([RED"小木屋"NOR:"小树林中间不知道那位猎人建了一座小木屋，虽然有些破旧，但是好歹能够抵挡风雨！\n"]),
	"virtual":1]) ]);

#include "dest_clone.h"

void create()
{
  init_virtualMap();
}

int query_dynamic_type()
{
	return 4;
}

