// Room: /d/emei/wanxingan.c 峨嵋派 万行庵

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "万行庵" NOR);
	set("long", @LONG
太子坪万行庵是古智禅师创建的。庵外满山长满莎椤花，花数芭合成一朵，
叶子包在花外，古人以其根坚难易而盛赞之，以喻洁身自好之高贵品质。由此
向南上便至金顶，下至接引殿。
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"jieyindian",
		"southup" : __DIR__"jinding",
	]));
        set("objects",([
		CLASS_D("emei") + "/jing-jia" : 1,
          ]));
	setup();

}
