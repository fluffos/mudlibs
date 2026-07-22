// Room: /d/shaolin/fumoquan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "金刚伏魔圈");
	set("long", @LONG
三棵大松树的树干上各挖了个可容身一人的大洞，有个洞口露出黑色僧
袍一角，似乎住得有人。中央是一片大草坪，中心处光秃秃的，似乎经常受
大力击打，以致寸草不生。
LONG
	);

	set("exits", ([
		"out" : __DIR__"qyping",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/du-nan" : 1,
		CLASS_D("shaolin") + "/du-e" : 1,
		CLASS_D("shaolin") + "/du-jie" : 1,
	]));
	set("outdoors", "少林寺");
	setup();
}

void init()
{
	mapping mine;
        object ob = this_player();
	mine = ob->query("family");

	if( !userp(ob) || wizardp(ob) ) return;
	if (ob->query("family/family_name") == "少林派" && (ob->query("passdu") || ob->query("pass_xin")))
		return;
	message_vision(HIR "突然间劲气纵横，三根黑索如三条黑蟒般就地滚来，瞬间近身，
化成一条笔直的兵刃，如长矛，如杆棒，如利剑，分别向$N的头，
胸，腹三处要害疾刺而至。$N一瞥间，看到三个老僧分居三个树
洞之中，正全力持鞭向$N攻来！$N已陷身于少林寺之蕴含无上降
魔大法的金刚伏魔圈！\n\n" NOR, ob);

	if ( mapp(mine)
	&& mine["generation"] > 36
	&& mine["family_name"] == "少林派"
	&& ob->query("qi") < 200 ){
		message_vision(HIR "$N被一道排山倒海般的劲气击中，顿时飞了出去！\n" NOR, ob);
		ob->move("/d/shaolin/qyping", 1);
		tell_room(environment(ob), ob->name()+"从伏魔圈飞了出来。\n", ob);
	}
}

int valid_leave(object me, string dir)
{

	if( dir == "out" && member_array("puti zi", deep_inventory(me)->query("id")) != -1 ) {
		return notify_fail("有个声音说道：不能带着菩提子离开伏魔圈 !\n");
	}
	me->delete_temp("fighter");
	return ::valid_leave(me, dir);
}
