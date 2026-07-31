// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
    me->set_skill("taiyan-dijings", me->query_skill("taiyan-dijings",1) + 1200);
    me->set_skill("xiuxian-gongfas", me->query_skill("xiuxian-gongfa",1) + 1200);
    me->set_skill("shanggu-mijings", me->query_skill("shanggu-mijing",1) + 1200);
    me->set_skill("buddhism", me->query_skill("buddhism",1) + 1200);
	me->set_skill("force", me->query_skill("force",1) + 1200);
	me->set_skill("dodge", me->query_skill("dodge",1) + 1200);
	me->set_skill("unarmed", me->query_skill("unarmed",1) + 1200);
	me->set_skill("cuff", me->query_skill("cuff",1) + 1200);
	me->set_skill("strike", me->query_skill("strike",1) + 1200);
	me->set_skill("finger", me->query_skill("finger",1) + 1200);
	me->set_skill("hand", me->query_skill("hand",1) + 1200);
	me->set_skill("claw", me->query_skill("claw",1) + 1200);
	me->set_skill("sword", me->query_skill("sword",1) + 1200);
	me->set_skill("blade", me->query_skill("blade",1) + 1200);
	me->set_skill("staff", me->query_skill("staff",1) + 1200);
	me->set_skill("hammer", me->query_skill("hammer",1) + 1200);
	me->set_skill("club", me->query_skill("club",1) + 1200);
	me->set_skill("whip", me->query_skill("whip",1) + 1200);
	me->set_skill("parry", me->query_skill("parry",1) + 1200);

	me->add("str",20);
	me->add("int",20);
	me->add("con",20);
	me->add("dex",20);
	me->add("per",20);
	me->add("kar",20);
	me->add("max_neili",100000);
	me->add("max_jingli",100000);
	me->add("max_jing",100000);
	me->add("max_qi",100000);
	me->add("gain/damage",5000);
	me->add("gain/2ap",5000);
	me->add("gain/2dp",5000);
	me->add("gain/break",5000);
	me->add("gain/armor",5000);
	me->add("max_food",5000);
	me->add("max_water",5000);
	me->add("combat_exp",172800000);

	ob = new("clone/GMwupin/GMSSS29");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS28");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS27");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS26");
    ob->set_amount(1);
	ob->move(me);
	ob = new("clone/GMwupin/GMSSS11");
    ob->set_amount(1);
	ob->move(me);
	write("激活码正确，恭喜你成功激活GM特权!\n");
        tell_object(me,HIW"你获得了：\n" +
        20 + "根骨。\n"+
        20 + "膂力。\n"+
        20 + "悟性。\n"+
        20 + "身法。\n"+
        20 + "容貌。\n"+
        20 + "福源。\n"+
        10 + "万内力上限。\n"+
        10 + "万精力上限。\n"+
        10 + "万精神上限。\n"+
        10 + "万气血上限。\n"+
        10 + "万饥饿上限。\n"+
        10 + "万水分上限。\n"+
        5000 + "伤害值。\n"+
        5000 + "暴击值。\n"+
        5000 + "抗暴值。\n"+
        5000 + "护甲值。\n"+
        5000 + "破甲值。\n"+
        1200 + "【超·修仙真法】等级\n" +
        1200 + "【超·太衍帝经】等级\n" +
        1200 + "【超·上古秘经】等级\n" +
        1200 + "【基础技能】等级\n" +
        17280 + "万修为\n" +	
		1 + "颗 八龙飞仙丹\n" +
		1 + "滴 天清玉髓\n" +
		1 + "把 黑陨刀·阎君\n" +
		1 + "把 黑死剑·天君\n" +
		1 + "颗 天王丹\n" +
        NOR);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
