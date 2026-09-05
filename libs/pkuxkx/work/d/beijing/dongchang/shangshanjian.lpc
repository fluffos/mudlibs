#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"尚膳监"NOR);
	set("long",
HIC"尚膳监十二监之一，与光禄寺和女官系统的尚食局负责皇宫内伙食供应，
设掌印太监一员。尚膳监烹饪的食材，向光禄寺领取。室内摆满了各种各样
的山珍海味和调味料，各式各样的烹调工具是应有尽有。\n"NOR
	);

	set("exits", ([
		"south" : __DIR__"zhidianjian",
		"north" : __DIR__"shangbaojian",
		"west" : __DIR__"liandanfang",
	]));
  set("objects", ([
               __DIR__"npc/haidafu" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
