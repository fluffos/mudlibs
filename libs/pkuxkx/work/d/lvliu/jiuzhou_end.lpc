//九州画廊-尽头
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIW "宫廷密藏" NOR);
	set("long", 
HIY "你的眼前忽然光芒大炽，一阵闪耀的金光差点亮瞎了双眼。只见一间不大的密室\n" +
"中满是各色奇珍异宝，无数金砖银饼堆积如山。一人高的" HIR "红珊瑚" HIY "、光彩璀璨的" HIC "夜明珠" HIY"，\n" +
"更有" HIB "辟寒犀角" HIY "、" HIM "浮光裘" HIY "、" HIW "玉龙子" HIY "、" NOR + 
CYN "青泥珠" HIY "、" HIC "玉辟邪" HIY "，各式宝藏不可胜数。\n\n");
    set("no_die",1);
	set("no_fight",1);
	set("no_kill",1);
	set("no_perform",1);
	set("no_steal",1);
	set("no_sleep_room",1);
    set("least_msg",1);
	setup();
}

int prevent_die(object me)
{
	if (!objectp(me) || !userp(me))
		return 0;
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", 1);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", 1);
	me->clear_condition();
	message_vision(HIM"$N忽然眼前一亮，拾起一颗丹药塞进嘴里，叹道：「幸好这有灵丹妙药，捡回一条命……」\n"NOR, me);
	return 1;
}

void init()
{
	object me = this_player();
	if (wizardp(me) || me->query_temp("lvliu/jiuzhou/pass"))
		call_out("give_reward", 5, me);
	else 
		call_out("get_out", 1, me, 0);
}

void give_reward(object me)
{
	object box;
	if (objectp(me) && environment(me)== this_object())
	{
		me->start_busy(2);
		message_vision(HIG "$N张大了嘴，呆呆望着眼前无数珍宝，口水滴滴答答地流淌下来也没察觉。\n"
			+"过了半晌，$P忽然嚎啕大哭起来：「这么多宝贝，竟然只能看、带不走，气死我了！」\n" NOR, me);
		tell_object(me, HIW"\n外面传来一阵喧哗，似乎有一大群守卫正在朝这里冲过来。来不及了，你只能四下扫\n"
			+"视了一番，将一个供在角落里的锦盒藏入怀中，就急急夺门而逃。\n"NOR);
		message_vision("$N将一个锦盒收入怀中。\n", me);
		box = new(__DIR__"obj/box");
		if (objectp(box))
		{
			box->set("lvl", 9);
			box->set("owner", me->query("id"));
			box->move(me);
		}
		call_out("get_out", 1, me, 1);
	}
}

void get_out(object me, int reward)
{
	me->move(__DIR__"dating");
	if (reward)
		message_vision(HIY"\n$N怀中鼓鼓囊囊的，眼神四处乱溜瞟了几眼，见没人注意到自己，故作镇静地咳了一声。\n\n"NOR, me);
}