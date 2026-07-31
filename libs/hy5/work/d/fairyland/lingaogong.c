// Room: /u/qingyun/jyzj/lingaogong.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "灵獒宫");
	set("long", @LONG
只见厅上扁额上写着“灵獒宫”三个血红大字。一进厅，你便吃了一惊，
但见三十余头雄健猛恶的大犬，分成三排蹲在地上，一个身穿白孤裘的女郎坐
在一张虎皮椅上，她手执皮鞭，正在指挥恶犬咬人。南边是一个大院子。
LONG	);
	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	set("objects",([
		__DIR__"npc/goupu" : 1,
		__DIR__"npc/dog1" : 1,
		__DIR__"npc/dog2" : 1,
		__DIR__"npc/dog3" : 1,
		__DIR__"npc/dog4" : 1,
		__DIR__"npc/zhu-jiuzhen" : 1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
