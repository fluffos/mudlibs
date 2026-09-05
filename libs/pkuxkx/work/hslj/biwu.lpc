// by yuer
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "华山之巅" NOR);
set("outdoors","huashan");
	set("long", 
"此处乃华山之巅，为武林人士论剑之所。金大虾每年都在这里举行华山论剑。\n得胜者就为武林第一人！。\n\n"
);

	set("exits", ([ /* sizeof() == 1 */
  	"down" : "/hslj/register" ]));

     set("no_fight", "1");
       set("no_steal", "1");
	setup();
	call_other("/clone/board/report_b", "???");
	replace_program(ROOM);
}

void init()
{
add_action("do_punish","perform");
add_action("do_punish","yong");
add_action("do_punish","yun");
add_action("do_punish","exert");
}
int do_punish()
{
 if( this_player()->is_fighting() ) return 0;
 tell_object(this_player(), RED+"比武主持告诉你："+NOR+"现在是公平比武，你想干什么？小心我把你踢出去！\n");
 return 1;
}
 
