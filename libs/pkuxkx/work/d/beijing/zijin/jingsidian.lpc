#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"敬思殿"NOR);
	set("long",
HIC"殿内梁枋、斗拱及梁架底面上，保留着飞天、荷花、牡丹等彩绘数十
幅，这些彩绘不仅笔法细腻，而且形象生动；殿内柱础为石造，其四周雕
以牡丹、莲花等图案。\n"NOR
	);

	set("exits", ([
		"north" : __DIR__"gzxd2",
		"south" : __DIR__"wuyingdian",
	]));

	setup();
	replace_program(ROOM);
}