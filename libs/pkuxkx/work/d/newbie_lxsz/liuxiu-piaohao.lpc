//D:\xkx\d\liuxiu-shanzhuang\liuxiu-piaohao.c柳秀票号
// labaz 2012/10/22
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
	set("short", HIY"票号"NOR);
	set("long", @LONG
这是柳秀山庄下的一处资产。票号虽是老字号，但规模并不大。发行
的银票也只能是柳秀山庄内通行。钱庄老板在盯着伙计查账。在对面的墙
上挂了块牌子(paizi)。如果你不懂这里的规矩，你可以看看牌子。(l paizi)
LONG
	);

	set("item_desc", ([
			"paizi" : "查帐：check\n存钱：cun 数量 种类(gold,silver)\n取钱：qu 数量 种类(gold,silver)\n",
	]));


	set("no_drop",1);
	set("exits", ([
		"west" : __DIR__"shanzhuang-damen",
	]));

	set("objects", ([
		__DIR__"npc/liuzhuqian" : 1
	]));
	setup();
}
void init()
{
	int balance;

	if( !this_player()->query("newsaver") ) 
	{
		balance = this_player()->query("balance");
		if( balance >= 100000 ) balance = 1000000;
		this_player()->set("balance", balance);
		this_player()->set("newsaver", 1);
	}
	
	this_player()->save();
	
	add_action("show_quest","quest");
}

