// LKlv modify 2001.10.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"大悲殿"NOR);
	set("long", @LONG
大悲殿系取佛家大慈大悲之意，殿堂上四壁绘满了佛家十忍等大慈大悲
之事。系我佛弟子冥想领悟禅理增进佛法专有所在，地上摆着几个蒲团，几
本经卷，几个木鱼。几位僧人正在瞑目讼经，看来颇得禅悟。
LONG
 );
	set("exits", ([
		"north" : __DIR__"hguangz2",
		"west"  : __DIR__"xumidian",
		"south" : __DIR__"stoneroad1",
	]));
        set("objects",([
		CLASS_D("shaolin") + "/dao-zheng" : 1,
		__DIR__"obj/muchui" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (!me->query_temp("mx_times"))
		me->set_temp("mx_times", random(35)+10);
        add_action("do_mingxiang", "mingxiang");
}

int do_mingxiang()
{
	object me, ob;
	me = this_player();

	if ( me->query_temp("mx_times") == 0 ){
		message_vision(HIR"$N身子一滑，从蒲团上跌了下去。\n"NOR, me);
		me->set_temp("mx_times", random(35)+10);
		me->unconcious();
		return 1;
        }
	me->add_temp("mx_times", -1);
	message_vision("$N虔诚地跪在蒲团上闭目冥思。\n", me);

	if ( random(30) ==15) {
		ob=unew(__DIR__"obj/book-xisui");
		if (ob) {
			ob->move(this_object());
			tell_object(me, RED"你只觉心头一热，面前已多了一块血袍。\n"NOR);
		}
	}
	return 1;
}
