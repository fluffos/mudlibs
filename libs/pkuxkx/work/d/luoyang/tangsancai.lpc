//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"唐三彩"NOR);
	set("long", @LONG
瓷器之中以唐三彩最为名贵，而洛阳的唐三彩又是出的最多，而且最
有名的。这家店铺的主人独辟蹊径，在此开了一家唐三彩专卖店，生意相
当兴隆。据说，唐三彩上色时所有的颜色均只以红，黄，蓝三原色为基础
手工调制而成，是故极其珍贵。
LONG
	);

	set("exits", ([
	       "west" : __DIR__"beidajie1",            
	]));
	set("objects", ([
	__DIR__"npc/zhaolaoban":1,

	]));

	setup();
	replace_program(ROOM);
}
