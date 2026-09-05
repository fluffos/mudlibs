
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "许昌城");
set("occupied",1);
	set("long", 
"许昌是中原地区的重镇，历来是兵家必争之地。朝廷在此驻
 扎重兵，盘查南来北往的行人，并负责翦灭附近山上的草寇。城
 内一队队官兵来来去去，一派森严气象。\n"NOR
	);

	set("exits", ([
		
                "southwest" : __DIR__"yidao1",
                "northwest" : __DIR__"yidao2",
                "south" : "/d/xinyang/guandaon2",
                "east" : __DIR__"guandao1",    //go peking and shenlongjiao
				"north" : __DIR__"machehang",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "zhongyuan");
	setup();
}



