//xuezhutang。c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	seteuid(getuid());
       set("short", "血竹堂");
	set("long", @LONG
这里是血河派的血竹堂。此处乃派内刑部所在地，气氛凝重深严，刚
踏进这里，感觉让人透不过气来。血河派之所以能傲视群雄，威赫武林，
与其治帮严谨，门规深严是分不开的。派内弟子向心力之强在众多帮派当
首屈一指。虽然血河弟子很少在江湖闯荡，然其派的威名依然让不少好事
之徒不敢冒然前来挑衅。这里四处布满刑具和家法，使人不油毛骨悚然。
LONG);	
	set("valid_startroom",1);
	set("exits", ([
		"east" : __DIR__"weitiange",
		"west" : __DIR__"xueku",
	]));

        set("area", "龙门");

        setup();

	replace_program(ROOM);
}
