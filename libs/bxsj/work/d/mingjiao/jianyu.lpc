// jianyu.c 监狱
// Modify By River@SJ 99.06
// Modify by Looklove 2000/8/26

#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIB"监狱"NOR);
       set("long", @LONG
这里是明教的地下监狱。四面都是石壁，只有一扇铁门，只有外面的人打
开铁门才能出去。想要自已逃出去是不可能的地上十分潮湿，看来在这时间一
久必得重病。石壁上用刀子刻着一些忏悔的话语....“不应斗胆偷上光明顶来，
以至受些活罪”等言语。
LONG);
	set("objects",([
                FOOD_D("zongzi") : 2,
                FOOD_D("zhuhu") : 1,
        ]));
	set("no_update", 1);
        setup();
}

void init()
{
	object me = this_player();

	if( (int)me->query_condition("mj_jail") <= 0
	&& !wizardp(me)){
		message("vision",HIY "只听铁门匡地一响，一个昏迷不醒的的家伙被扔了进来！\n\n" NOR, environment(me), me);
		me->set("startroom", "/d/mingjiao/jianyu");
		me->apply_condition("mj_jail", 30);
        }
}
