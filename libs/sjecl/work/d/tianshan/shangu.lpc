// Room: /d/tianshan/shangu.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
这是天山山腰间的一个山谷。放眼望去，尽是一些邪魔外道在此聚会，这
些人有男有女，有俊有丑，既有僧人，亦有道士，有的大袖飘飘，有的窄衣短
打，有的是长须飞舞的老翁，有的是云髻高耸的女子，服饰多数奇形怪状，与
中土人士大不相同，一大半人持有兵刃，兵刃也大都形相古怪，说不出名目。
LONG);    
        set("objects", ([
                __DIR__"npc/wulaoda" : 1,
		__DIR__"npc/zhangdafu" : 1,
        ]));   
	set("outdoors", "天山");
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query_temp("tonglao/pass2")) {
		me->add_busy(4 + random(4));
		remove_call_out("tonglao_help");
		call_out("tonglao_help", 4, me);
	}
}

void tonglao_help(object me)
{
        object ob;
        if (!me) return;
        tell_object(me, HIW"\n你突然间只听见有人大声道：“众家兄弟，请大家取出兵刃，每人向这女娃娃\n"
		"砍上一刀，刺上一剑。这女娃娃年纪虽小，又是个哑巴，终究是缥缈峰的人物，\n"
		"大伙儿的刀头喝过了她身上的血，从此跟缥缈峰势不两立，就算再要有三心两\n"
		"意，那也不容你再畏缩后退了。”他一说完，当即擎鬼头刀在手，挥刀便向那\n"
		"身在布袋中的女童砍了下去。\n"NOR);
	tell_object(me, HIY"\n你见有人举起鬼头刀，要砍死一个全无抗拒之力的哑巴女孩，不由得慈悲心大\n"
		"动，心想不管谁是谁非，这女孩是非救不可的，当即从岩石后面冲将出来，抢\n"
		"了布袋便走。\n"
		"一股正气在你心底油然而生。\n"NOR);
	tell_object(me, YEL"\n你慌不择路，见那里树林茂密，便钻了进去。奔了将近两个时辰，竟丝毫不累。\n"
		"又奔了一阵，脚底下踏到薄薄的积雪，原来已奔到山腰。\n"NOR);
	ob = new(__DIR__"obj/bag");
	ob->set_temp("owner",me->query("id"));
	ob->move(me);
	me->delete_temp("tonglao");
	me->set_temp("tonglao/pass3",1);
	me->set_temp("tonglao/call",1);
	me->add("shen",5000+random(5000));
	me->move(__DIR__"shanyao");
	return;
}
