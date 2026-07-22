// Room: /d/jiaxing/tieqiang.c
// Lklv@SJ modify for dgb Quest at 2001.10.08

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"铁枪庙"NOR);
	set("long", @LONG
这铁枪庙里祀奉的是五代时的名将，铁枪王彦章。因为年久失修，香火不
是很旺盛，庙里的设施多已破损。庙旁有座高塔，建于何年何月人们已经无从
知晓，塔顶群鸦世代为巢，当地乡民传说铁枪庙的乌鸦是神兵神将，向来不敢
侵犯，以致乌鸦生养繁殖，越来越多。
LONG
	);
	set("exits", ([
		"west" : __DIR__"jxnanmen",
		"north" : __DIR__"dbianmen",
	]));
	set("objects", ([
		__DIR__"npc/wuya": 2,
		__DIR__"npc/limochou": 1,
	]));
	setup();
}

void init()
{
	object me = this_player();

	if (me->query_temp("get_wugou") && !query("quest")) {
		add_action("do_da", ({"da", "huida"}));
		add_action("do_han", ({"han", "yell"}));
	}
}

int do_han(string arg)
{
	object me, ob, env;
	int count;

	if (localtime(TIME_TICK)[2] > 2)
		return 0;
	me = this_player();
	count = time() - me->query_temp("get_wugou");
	if (count < 0 || count > 11 * 60)
		return 0;
	env = this_object();
	count = me->query_temp("h7g_quest/han");

	if (ob = present("li mochou", env))
		return notify_fail("李莫愁喝道：“深更半夜，鬼苦一样大呼小叫什么？”\n");
	if (me->is_busy() || !arg )
		return notify_fail("你要喊什么？先喘口气吧。\n");

	if (present("hong qigong", env)){
		message_vision(CYN"洪七公对$N喝道：“喊什么喊，我又没死！”\n"NOR, me);
		me->delete_temp("h7g_quest/han");
		me->start_busy(1);
		return 1;
	}
	if ( count > 3 ){
		message_vision(CYN"$N吸了口气，大喊一声“洪七公～～，徒儿"+me->name()+""CYN"等你好久了！”，声音传出去很远。\n"NOR, me);
		me->start_busy(1);
		me->add_temp("h7g_quest/han",1);
		remove_call_out("happen");
		remove_call_out("happen2");
		call_out("happen2", 10, me);
		return 1;
	}
	if (arg=="七公" || arg=="师父" || arg=="帮主") {
		if ( arg =="帮主" && count == 1){
			me->start_busy(1);
			me->add_temp("h7g_quest/han", 1);
			message_vision(CYN"$N小声喊了一声：“"+arg+"！你在嘛？”\n"NOR, me);
			return 1;
		}
		if ( arg =="七公" && count == 2){
			me->start_busy(1);
			me->add_temp("h7g_quest/han", 1);
			message_vision(CYN"$N清了清嗓子，小声又喊了一声：“"+arg+"！你在嘛，徒儿"+me->name()+""CYN"来了。”\n"NOR, me);
			return 1;
		}
		if ( arg =="师父" && count == 3){
			message_vision(CYN"$N等了一会，发现没动静，试探着又喊了一声：“"+arg+"！不肖徒儿"+me->name()+""CYN"让您久等了。”\n"NOR, me);
			me->start_busy(1);
			me->add_temp("h7g_quest/han",1);
			call_out("happen", 30, me);
			return 1;
		}
		message_vision(CYN"$N看了看四周没人，喊了一声“"+arg+"！你在嘛，我来了。”\n"NOR, me);
		me->start_busy(1);
		me->add_temp("h7g_quest/han",1);
		return 1;
	}
	message_vision(HIW"$N吸了口气，大喊一声“洪七公～～"+arg+"～～”，声音传出去很远。\n"NOR, me);
	me->add_temp("h7g_quest/han",1);
	me->start_busy(1);
	set("quest",1);
	return 1;
}

void happen(object me)
{
	object ob, env;
	int i, j;
	i = me->query_skill("dagou-bang",1);
	j = me->query_skill("bangjue",1);

	env = this_object();
	if (!me) return;
	if ( me->query("dgb/wugou") >5 || !me->query_temp("get_wugou")) return;

	if (!(ob = present("hong qigong", env))) {
		ob = new(CLASS_D("gaibang/h7g"));
		ob->move(env);
		tell_room(env, HIY"夜色中有人咳嗽了一声，只见洪七公伸着懒腰，走了过来。\n"NOR, ({}));
	}
	if (!present(me, env)) {
		tell_room(env, CYN"洪七公伸了个懒腰，嘴里嘀咕着：“天色不早了，找地方睡觉去咯”。说罢转身走了。\n"NOR, ({}));
		destruct(ob);
		return;
	}
	if ( i < 200 || j < 100 ){
		message_vision(HIW"洪七公看了看$N说道：“徒儿，你的功夫练的怎么样了？”\n"NOR, me);
		message_vision(HIW"$N大声得意地说道：“师父，我的打狗棒现在已经"+CHINESE_D->chinese_number(i)+"级，棒诀已经"+CHINESE_D->chinese_number(j)+"级了。”\n"NOR, me);
		message_vision(HIW"洪七公口吐白沫，倒飞了出去，满脸失望地说道：“那你回去继续练功吧，没什么事了，走吧。”\n"NOR, me);
		me->delete_temp("get_wugou");
		me->delete_temp("get_wugou2");
		me->delete_temp("h7g_quest/han");
		call_out("dest", 2, ob);
		return;
	}
	me->set_temp("get_wugou2",1);
	message_vision(HIW"洪七公拍了拍$N的头说道：“好徒儿，来的正是时候，为师问你个问题：打狗棒最注重的特点是什么？回答我(da)。”\n"NOR, me);
	call_out("dest", 200, ob);
}

void happen2(object me)
{
	if( !me || !living(me) ) return;
	if( me->query("dgb/wugou") >5 || !me->query_temp("get_wugou")) return;
	me->delete_temp("h7g_quest/han");
	me->delete_temp("get_wugou");
	delete("quest");
	message_vision(HIW"突然远处传来一声长啸“洪七公～～这名字好熟～～洪七公～你在哪里？不要跑～～告诉我我是谁～～”\n"NOR, me);
	message_vision(HIW"洪七公从庙后闪了出来，对$N说道，“不好，被老毒物找到了，这人很难缠，你快走，我来应付他！”\n"NOR, me);
	message_vision(HIW"正说话间，一个人影头下脚上飞快向$N扑来，嘴里还发出“呱呱”的声音，神态极是骇人。\n"NOR, me);
	me->unconcious();
	return;
}

void dest(object ob)
{
	delete("quest");
	if(!ob ) return;
	tell_room(this_object(), CYN"洪七公伸了个懒腰，嘴里不耐烦地嘀咕：“天色不早了，找地方睡觉去咯。”说罢转身走了。\n"NOR, ({}));
	destruct(ob);
}

int do_da(string arg)
{
	object me, ob, env;
	int count;

	me = this_player();
	env = this_object();
	ob = present("hong qigong", env);
	count = me->query_temp("h7g_quest/da");

	if (!me || !me->query_temp("get_wugou2")) return 0;
	if (me->is_busy() || !arg )
		return notify_fail("你要说什么？先喘口气吧。\n");

	if (!present("hong qigong", env)){
		message_vision(CYN"洪七公在远处喊道：“"+me->name()+""CYN"徒儿，你再回去好好想想吧，这次我先走了！”\n"NOR, me);
		me->delete_temp("h7g_quest/da");
		me->delete_temp("get_wugou");
		me->delete_temp("get_wugou2");
		me->start_busy(1);
		return 1;
	}
	if (count > 5) {
		message_vision(CYN"$N想了想说：“师父……，徒儿以为是"+arg+"”。\n"NOR, me);
		message_vision(HIW"洪七公长叹了一口气说道：“看来你的悟性太低了，我本来想传你几招。”\n"NOR, me);
		me->start_busy(1);
		me->add_temp("h7g_quest/da",1);
		me->delete_temp("h7g_quest/da");
		me->delete_temp("get_wugou");
		me->delete_temp("get_wugou2");
		remove_call_out("dest");
		call_out("dest", 5, ob);
		return 1;
	}
	if (arg=="轻灵奇巧") {
		me->start_busy(1);
		me->add_temp("h7g_quest/da", 1);
		message_vision(CYN"$N想了想说道：“师父，徒儿以为打狗棒的要领应该是"+arg+"。”\n"NOR, me);
		message_vision(CYN"洪七公满意地点了点头道：”"+me->name()+""CYN"，你不愧为师的得意门生。我想起一个新招，你附耳过来。”\n"NOR, me);
		message_vision(CYN"$N凑上前去，洪七公在$N耳边细说着打狗棒的要领，$N面露喜色，不住点头道：“多谢师父！徒儿记得了！”\n"NOR, me);
		me->set("dgb/wugou",6);
		call_out("dest", 2, ob);
		return 1;
	}
	message_vision(CYN"$N抓耳挠腮，想了半天说道：“师父……，徒儿以为是"+arg+"”。\n"NOR, me);
	switch(random(6)){
		case 5:
		message_vision(HIW"洪七公口吐白沫，昏了过去。\n"NOR, me);
		break;
		case 4:
		message_vision(HIW"洪七公已经受不了这情景了，只见他口中鲜血狂喷而倒，眼见是活不成了。\n"NOR, me);
		break;
		case 3:
		message_vision(HIW"洪七公愤声说道：“我呸！我呸！我呸呸呸！”\n"NOR, me);
		break;
		case 2:
		message_vision(HIW"洪七公气得脸色通红，怒道：“你……你简直要气死老叫化我了！！”\n"NOR, me);
		break;
		case 1:
		message_vision(HIW"洪七公摇了摇头说道：“不对，应该是：轻……奇……，你再想想。”\n"NOR, me);
		break;
		case 0:
		message_vision(HIW"洪七公摇头道：“不对不对！应该是：……灵……巧，你再想想。”\n"NOR, me);
		break;
	}
	me->add_temp("h7g_quest/da",1);
	me->start_busy(1);
	return 1;
}
