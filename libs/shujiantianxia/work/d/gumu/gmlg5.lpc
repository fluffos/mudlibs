// gmlg5.c By River 98/08/30
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC"石室"NOR);
	set("long", @LONG
这石室比之先前捉麻雀的石室长阔均约大了一倍，室中已有多只麻雀在内。
地方大了这麽多，捕捉麻雀自然远为艰难。石室密闭，墙上两只火把照得整个
石室灯火通明。
LONG
	);

	set("exits", ([        
		"north" : __DIR__"gmlg4",
	]));

	setup();
}

void init()
{
	add_action("do_zhuo", "zhuo");
}

int do_zhuo(string arg)
{
	mapping fam;
	object me = this_player();          

	if (!living(me)) return 0;

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓传人，如何能领悟古墓武功？\n");

	if ( arg == "maque"){
		if ( me->query("gender")!="男性")
			return notify_fail("古墓女弟子可以去修炼美女拳法。\n");
		if ((int)me->query_skill("dodge",1 ) < 10)
			return notify_fail("你轻功身法太低，捉不住这么多麻雀的。\n");
		if ((int)me->query_skill("hand", 1) < 10)
			return notify_fail("你的基本手法还不够娴熟，可能抓不住麻雀。\n");
		if ((int)me->query_skill("tianluo-diwang", 1) > 1)
			return notify_fail("你已经学会天罗地网势了，自己好好揣摩吧。\n");
		if ( (int)me->query("jingli") < 30 )
			return notify_fail("你太累了, 先休息一下。\n");
		tell_object(me,"你双掌这边挡，那边拍，麻雀尽数聚在你胸前三尺之内。\n");         
		me->receive_damage("jing", 5);
		me->receive_damage("jingli",15);
		me->improve_skill("tianluo-diwang", 2);
		return 1;
	}
	return notify_fail("你要捉什么？\n");       
}
