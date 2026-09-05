#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "玉面飞狐的书房");
        set("long",HIR+BNK+"＼｜／\n"+
					"—"+NOR+HIR+"●"+BNK+"—\n"+
					"／｜＼"+NOR+HIC+"▁▂▃▅▆█▆▅▃▂▁▂▃▅▃▂▁\n"+
					"▁▂▃▅▆████████████████████▆▅▃▂▁\n"+
					"\n\n"+
					"                                                 "+HIY+BNK+"★\n"+NOR+
					"                                              "+HIW+"╭╯╰╮\n"+NOR+
					"                                             "+HIW+"╭┴─┴╮\n"+NOR+
					"                                             "+HIW+"╭┴─┴╮\n"+NOR+
					"  ╮╮╮                                  "+HIW+"╭┴─┴╮\n"+NOR+
					"  │││                                     "+HIW+"╭┴─┴╮\n"+NOR+
					"  │││                                     "+HIW+"╭┴─┴╮\n"+NOR+
					"  │││                                "+HIY+"╭──┴──┴──╮\n"+NOR+
					"  │││                          "+HIY+"├┴─┬┴─┤╭╮├┴─┬┴─┤\n"+NOR+
					"  ││╰—╮"+HIC+"╟————╢      "+HIY+"├┬─┴┬─┤││├┬─┴┬─┤\n"+NOR+
					"  ╰——╮ "+HIC+"╱          ╲                      ※\n"+NOR+
					"           "+HIC+"╱ ╭╮╭╮╭╮ ╲※※※※※※※※※※※\n"+NOR+
					HIC+"       ※※"+NOR+"    │  │  ╰≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n"+NOR+
					HIC+"       ※  "+NOR+"    │  ╰≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n"+NOR+
					HIC+"※※※※   "+NOR+"    ╰≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈≈\n"+NOR
			+NOR);

        set("exits", ([
        "out"	:	"/d/wizard/wizard_room" ,
        "city"	:	"/d/city/guangchang",
        ]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
		"/clone/board/dum_b"->foo();
		replace_program(ROOM);
}
