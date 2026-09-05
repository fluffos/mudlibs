// tiandi.c     天地庄，聚天地之精华以补精
// Rewrote by iszt@pkuxkx, 2007-05-18
// 战斗时减低内力消耗

#include <ansi.h>
#include "linjizhuang.h";

void end_linji(object me, int pflv);
int check_fight(object me, int pflv);
void remove_effect(object me);

int exert(object me, string arg)
{
        string linji = "天地庄";

		int pflv;
		string* ljz;
		ljz = linji_zhuang_count(me);
		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;
		if (pflv>5) pflv=5;

		if (buff_full(pflv, ljz))
			return notify_fail("你已经运行了"+show_buff(ljz)+"，无法再运行"+linji+"。\n");
//        if(me->query_temp("linji"))
//                return notify_fail("你正在运行"+me->query_temp("linji")+"，无法运行"+linji+"。\n");
        if(me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if( !me->is_fighting() )
                return notify_fail("你只能在战斗中运行"+linji+"。\n");
        if( me->query("class") != "bonze" && me->query("chushi/last_family")!="峨嵋派")
                return notify_fail("你尘心未灭，无法运行临济十二庄"+linji+"。\n");
        if((int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够。\n");
        if((int)me->query_skill("linji-zhuang",1) < 150)
                return notify_fail("你的临济十二庄修为太低，无法运行"+linji+"。\n");

//        me->set_temp("linji", linji);
        me->set_temp("linji_zhuang/"+linji, 1);
        me->start_busy(2);

        tell_object(me,MAG"\n你潜运天地二庄，益气升阳，益阴潜阳，升降反正，天地二气交泰于身，顿觉自己内力源源不止。\n"NOR);
        call_out("end_linji", 2, me, pflv);
        me->add("neili", -500);
        return 1;
}

void end_linji(object me, int pflv)
{	float j;
	int i;
	j=me->query_skill("emei-jiuyanggong",1)/20+1;
	if (j > 4)
	{
		j = 4;
	}
	if (me->is_realuser() && me->query("family/family_name")=="峨嵋派")
	{
		j *= me->query("max_neili");
	}
	else
	{
		if (j > 1 && me->query("family/family_name")=="峨嵋派")
		{
			j = me->query("max_neili")*3/2;
		}
		else
		{
			j = me->query("max_neili");
		}
		if (pflv>=3)
			j += j*(pflv-2)/5;
	}
	i=j;
    message_vision(HIW"\n只见$N脸上红光时隐时现，一下变得神采弈弈。\n\n"NOR, me);
    me->set_temp("linji_neili", i);
	if (pflv>=5) {
		me->add_temp("apply/enforce_enhance", 50);
		me->set_temp("linjizhuang/enforce_enhance", 50);
	}
    check_fight(me, pflv);
}

int check_fight(object me, int pflv)
{
	int rdm_cnt,xishu;
        if( !me || !me->query_temp("linji_zhuang/天地庄"))
                return 0;

        me->add_temp("linji_time", 1);
        if(me->query_temp("lingji_time") > me->query_skill("force"))
        {
                call_out("remove_effect", 1, me);
                return 0;
        }

        if( me->is_ghost()|| !living(me))
                me->delete_temp("linji");

        if( !me->is_fighting()
        || me->query("neili") <= 100
        || (userp(me) && me->query_skill_mapped("force") != "linji-zhuang"))
                call_out("remove_effect", 1, me);
        else
        {
			rdm_cnt = 2 * (1+ me->query("chushi/done") + me->query("betrayer"));
            if(random(rdm_cnt)==0 && me->query("neili") < (int)me->query_temp("linji_neili"))
            {
                 tell_object(me, HIG"你体内天地之力运转不息，内力似乎源源不绝！\n"NOR);
                 me->add("neili", (me->query_temp("linji_neili")-me->query("neili"))/rdm_cnt);
                 if (me->query_skill("emei-jiuyanggong",1)>1 && me->query("family/family_name")=="峨嵋派")
                 {
					 if (me->is_realuser())
					 {
						 xishu = 7;
					 }
					 else
					 {
						 if (pflv>=3) xishu = (pflv-1);
						 else xishu = 1;
					 }
					xishu *= 9;
					xishu += random(9);
					if (me->query("chushi/done") || me->query("betrayer"))
					{
						xishu /= 2;
					}
                     //me->add("neili", me->query_skill("emei-jiuyanggong",1)*(60+random(40)));
					me->add("neili", me->query_skill("emei-jiuyanggong",1)*xishu);
				    write(HIR"峨嵋九阳功将你的内力又提至一个极限。\n"NOR);
                 }
            }
            call_out("check_fight", 1, me, pflv);
        }
        return 1;
}

void remove_effect(object me)
{
        if( !me || !me->query_temp("linji_zhuang/天地庄"))
                return;
//        me->delete_temp("linji");
		me->delete_temp("linji_zhuang/天地庄", 1);
        me->delete_temp("linji_neili");
		if (me->query_temp("linjizhuang/enforce_enhance"))
			me->add_temp("apply/enforce_enhance", -1 * me->query_temp("linjizhuang/enforce_enhance"));
        message_vision(HIR"$N所聚之精气已散回天地之间，又恢复了原有的气力消耗。\n\n"NOR, me);
}
