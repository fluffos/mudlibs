#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "旅途中");
        set("long", @LONG
这是一次漫长的旅途。
LONG);
	set("no_fight", 1);
	set("no_get_from", 1);
	set("no_sleep_room", 1);
	set("no_death", 1);
	setup();
}

void init()
{
	object me = this_player();
	call_out("wait", (random(20)+10)+30, me);
	call_out("do_bird", 20, me);
	add_action("do_action", "");
}

int do_action(string arg)
{
	string action = query_verb();
	switch (action) {
		case "dazuo":
		case "look":
		case "l":
		case "exercise":
		case "lian":
		case "tuna":
		case "quit":
		case "save":
		case "practice":
			write("这是一次漫长的旅途，不知什么时候才可以走完。\n");
			return 1;
	}
	return 0;
}

void do_bird()
{
	switch(random(3)) {
		case 0 : write(HIW"\n一阵微风吹过，带来一丝淡淡的花香和一股芬芳的泥土味。\n\n"NOR);
		break;
	case 1 : write(GRN"\n从不远处烟水蒙蒙的湖面上飘来一阵轻柔婉转的歌声，那是少女们在和歌嘻笑，荡舟采莲。\n\n"NOR);
		this_player()->add("potential", 1);
		break;
	case 2 : write(HIY"\n只见西北角上血红的夕阳之旁，升起一片黄蒙蒙的云雾，
		黄云中不住有紫色的光芒闪动，景色之奇丽，实是你生平从所未睹。\n\n"NOR);
		this_player()->add("combat_exp", 5);
		break;
	}
}

void wait()
{
	object me;
	me = this_player();
	tell_object(me, "你跟着徐霞客行走，不知不觉中已到达了目的地。\n\n");
	if(me->query_temp("go_hj")) {
		me->move("/d/hj/majiu");
		tell_object(me, CYN"徐霞客告诉你：西域回疆到啦！听说这附近有个什么宝藏，可没人能找到。\n\n"NOR);
		me->delete_temp("go_hj");
	}
	if(me->query_temp("go_xx")) {
		me->move("/d/xingxiu/xxh");
		tell_object(me, CYN"徐霞客告诉你：这就是西域星宿海了，你小心点，被星宿派的恶贼抓住了可不是好玩的！\n\n"NOR);
		me->delete_temp("go_xx");
	}
	if(me->query_temp("go_yili")) {
		me->move("/d/xingxiu/yili2");
		tell_object(me, CYN"徐霞客告诉你：西域伊犁城到啦，你可疑定要尝尝这里美味的哈密瓜。\n\n"NOR);
		me->delete_temp("go_yili");
	}
	if(me->query_temp("go_sl")) {
		me->move("/d/shaolin/ting");
		tell_object(me, CYN"徐霞客告诉你：看，这就是嵩山少林寺了。这里的和尚们整天舞枪弄棍的，唉。\n\n"NOR);
		me->delete_temp("go_sl");
	}
	if(me->query_temp("go_wd")) {
		me->move("/d/wudang/yuzhengong");
		tell_object(me, CYN"徐霞客告诉你：武当山到啦！从这里再往上就是武当派所在了，你自己上吧。\n\n"NOR);
		me->delete_temp("go_wd");
	}
	if(me->query_temp("go_kl")) {
		me->move("/d/kunlun/shanmen");
		tell_object(me, CYN"徐霞客告诉你：我只能爬到昆仑山这里了，再往上你就自己走吧。\n\n"NOR);
		me->delete_temp("go_kl");
	}
	if(me->query_temp("go_yz")) {
		me->move("/d/city/kedian");
		tell_object(me, CYN"徐霞客告诉你：到江南名城扬州啦！真奇怪你这人怎么这么笨，扬州都找不到？\n\n"NOR);
		me->delete_temp("go_yz");
	}
	if(me->query_temp("go_dali")) {
		me->move("/d/dali/damen");
		tell_object(me, CYN"徐霞客告诉你：南疆大理国都大理城到啦！这里民风淳朴，你就放心玩玩吧。\n\n"NOR);
		me->delete_temp("go_dali");
	}
	if(me->query_temp("go_tzb")) {
		me->move("/d/tiezhang/shanjiao");
		tell_object(me, CYN"徐霞客告诉你：这就是五指山了。你上去可要小心点，铁掌帮的人可凶了！\n\n"NOR);
		me->delete_temp("go_tzb");
	}
	if(me->query_temp("go_thd")) {
		me->move("/d/thd/haibin");
		tell_object(me, CYN"徐霞客告诉你：只能带你到这里了，要去桃花岛必须在这坐船过海。\n\n"NOR);
		me->delete_temp("go_thd");
	}
	if(me->query_temp("go_mj")) {
		me->move("/d/mingjiao/shanting");
		tell_object(me, CYN"徐霞客告诉你：前面就是明教光明顶，我可不敢上去，你自己去吧！\n\n"NOR);
		me->delete_temp("go_mj");
	}
	if(me->query_temp("go_sz")) {
		me->move("/d/suzhou/majiu");
		tell_object(me, CYN"徐霞客告诉你：到江南苏州城了，看得出你这呆子还是第一次来吧？哈哈\n\n"NOR);
		me->delete_temp("go_sz");
	}
	if(me->query_temp("go_zns")) {
		me->move("/d/gumu/shanlu1");
		tell_object(me, CYN"徐霞客告诉你：前面这山便是终南山，再往上去就是全真教重阳宫了。\n\n"NOR);
		me->delete_temp("go_zns");
	}
	if(me->query_temp("go_hz")) {
		me->move("/d/hz/tianxianglou");
		tell_object(me, CYN"徐霞客告诉你：总算到杭州了，觉得这里怎么样？“上有天堂，下有苏杭”当真不假！\n\n"NOR);
		me->delete_temp("go_zns");
	}
	tell_room(environment(me), me->name()+"和徐霞客风尘仆仆地行了过来。\n" NOR,
	({ me }));
	tell_object(me, "徐霞客又不知走到哪里去了。\n");
}