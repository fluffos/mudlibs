// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"铁舟上"NOR);
	set("long", @LONG
那铁舟翘起了头鼓浪逆行，水流虽不如瀑布般猛冲而下，却也极是急促，
你划得面红气促，好几次险些给水冲得倒退下去。
LONG
	);
	set("outdoors", "桃源县");
	set("no_fight", 1);
	set("no_save", 1);
	setup();
}

void init()
{
	remove_call_out("check_ppl");
	call_out("check_ppl", 1, this_player(), 300);
	add_action("do_hua", ({ "ban", "hua" }));
	add_action("do_jump", ({ "jump", "tiao" }));
}

void check_ppl(object me, int count)
{
	if ( ! me || environment(me) != this_object()){
		delete("ppl");
		return;
	}
	if ( count -- < 1) {
		message_vision("突然间一股大力冲到，$N未曾防备，铁桨几欲脱手，又被急流冲回了原处。\n", me);
		me->move(__DIR__"pubu");
		delete("ppl");
		return;
	}
	call_out("check_ppl", 1, me, count);
}

int do_hua(string arg)
{
	object me = this_player();
	object weapon;

	if ( !arg || arg != "boat")
		return notify_fail("你要划什么啊？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if (!weapon= me->query_temp("weapon"))
		return notify_fail("你真行，空手划船？\n");

	if ( weapon->query("id") != "tie jiang" )
		return notify_fail("你真行，用"+weapon->name()+"划船？\n");

	if ( me->query_temp("yideng/hua_done"))
		return notify_fail("你已经划到岸了，想办法上岸吧！\n");

	if ( me->query_temp("yideng/hua"))
		return notify_fail("你正在划呢！\n");

	message_vision(HIW"\n$N左手铁桨急忙挥出，用力一扳，铁舟登时逆行了数尺，右手铁桨再是一扳，\n"+
		"那舟又向上逆行了数尺。\n\n"NOR, me);
	me->add_busy(3);
	me->set_temp("yideng/hua", 1);
	call_out("next_place", 10 , me);
	return 1;
}

void next_place(object me)
{
	if (! me || environment(me) != this_object()) return;
	message_vision(HIC"\n又行一阵，划过两个急滩，一转弯，眼前景色如画，清溪潺潺，水流平稳之极，\n"+
			"几似定住不动。那溪水宽约丈许，两旁垂柳拂水，绿柳之间夹植着无数桃树，\n"+
			"若在春日桃花盛开之时，想见一片锦绣，繁华耀眼。这时虽无桃花，但水边生\n"+
			"满一丛丛白色小花，芳香馥郁。\n\n"NOR, me);
	call_out("next_place1", 10 , me);
	return;
}

void next_place1(object me)
{
	if (! me || environment(me) != this_object()) return;
	message_vision(HIC"\n溪水碧绿如玉，深难见底，你持住桨柄顶端，将铁桨竖直下垂，想探知溪底究\n"+
			"有多深，突然间一股大力冲到，你未曾防备，铁桨几欲脱手，原来溪面水平如\n"+
			"镜，底下却有一股无声的激流。\n\n"NOR, me);
	message_vision(HIW"\n那铁舟缓缓向前驶去，绿柳丛间时有飞鸟鸣啭，忽然钻入了一个山洞。\n"NOR, me);
	me->set_temp("yideng/hua_done", 1);
	return;
}

int do_jump(string arg)
{
	object me = this_player();
	object ob = present("tie jiang", me);

	if ( !me->query_temp("yideng/hua_done")) return 0;

	if (! arg || arg != "shandong")
		return notify_fail("你往那里跳？\n");

	message_vision(HIY"\n$N飞身上了岸，将铁舟拉起放在石上，回过头来，却见水柱在太阳照耀下映出\n"+
			"一条眩目奇丽的彩虹。\n\n"NOR, me);

	if ( objectp(ob))
		destruct(ob);

	me->delete_temp("yideng");
	delete("ppl");
	me->move(__DIR__"shandong");
	return 1;
}
