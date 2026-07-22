// Room: /d/emei/basipan3.c 峨嵋派 八十四盘3

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIC "八十四盘" NOR);
	set("long", @LONG
八十四盘，道路艰险陡峭，迂回盘折，令人不能喘息。路左是蔽日遮天的
冷杉林，路右是深不见底的绝壁峡谷。由此往上至接引殿，北下到洗象池。
LONG
	);
	set("outdoors", "峨眉山");
	set("exits", ([
		"northdown" : __DIR__"basipan2",
		"northwest" : __DIR__"lengshanlin2",
		"southeast" : __DIR__"jieyindian",
	]));
	setup();

}
int valid_leave(object me, string dir)
{
 if (dir == "southeast" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex")/2);
      me->receive_damage("jingli", (int)me->query("dex"));
      return 1; }     return ::valid_leave(me, dir);

} 


