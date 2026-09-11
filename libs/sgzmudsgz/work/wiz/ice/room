// gate.c

#include <ansi.h>

inherit  OUTDOOR_ROOM;

void setup()
{
	set_area("death");
	set_light(2);
	set_brief(HIW "鬼门关" NOR);
	set_long("
这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的
黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无
法再回阳间了。
");
  set_exits( ([
		"north" : __DIR__ "gateway",
        ]) );
}
