//baxian.c 【八仙大阵】weiqi...980307
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

nosave string npc_dir = "/d/qujing/wuzhuang/npc/";
nosave string *bagua = ({ "乾","坤","震","巽","坎","离","艮","兑", });
nosave string *npcs = ({
	"ludongbin","hexiangu","tieguaili",
	"hanzhongli","lancaihe","hanxiangzi",
	"caoguojiu","zhangguolao",
});	

void baxian(object invoker, object target,int num);

void remove_effect(object me)
{
	if( me && me->query_temp("wzg_baxian") )
	{
		me->delete_temp("wzg_baxian");
		me->set_temp("baxian_end",time());
		return;
	}	
}

int cast(object me, object target)
{
	string msg;
	
	object where;

	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");
	if((string)me->query("family/family_name") != "五庄观" ) 
        	return notify_fail("你又不是五庄观弟子，八仙哪里会帮你拿人。\n");
	if((int)me->query_skill("taiyi", 1) < 200)
	    	return notify_fail("你的太乙仙法修为不深，请不动八仙。\n");
	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够，没办法知会八仙。\n");
	if((int)me->query("sen") < 100 )
		return notify_fail("你现在神智不清，不被人拿已是万幸了！\n");
        if( time()<me->query_temp("baxian_end")+8 )
        	return notify_fail("你刚刚召唤过八仙。\n");
        if( me->query_temp("wzg_baxian") )
        	return notify_fail("你正在摆八仙大阵呢。\n");
        			
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你想请八仙拿谁？\n");
	if((string)target->query("family/family_name") == "五庄观" )
		return notify_fail("同门相斗也叫八仙帮忙？\n");

	me->add("mana", -100);
	me->receive_damage("sen",50,me);
	if( random(me->query("max_mana")) < 50 ) 
	{
		write("咦？这一次好像不灵。\n");
		return 1;
	}

	message_vision(HIC "$N"HIC"手掐阴阳诀，一道八卦隐现半空，大喝一声：八仙何在！\n"NOR,me);
	me->set_temp("wzg_baxian",1);
	if( !target->is_killing(me->query("id")) )
	{
		msg = HIR "$n"HIR"对着$N"HIR"高声骂道：好家伙，一拥而上了，我宰了你！\n" NOR;
		message_vision(msg, me, target);
		target->kill_ob(me);
	}	
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:),60);
	where=environment(target);
	baxian(me, target,1);
	return 1;
}

void baxian(object me, object target,int num)
{
	int i;
	object bx;
	string msg;

	if( !me )
		return;
	if( num>8 || num<1 )
	{
		remove_effect(me);
		return;
	}	
	bx = new(npc_dir+npcs[num-1]);
	if( !bx || !target || !living(me) || !me->is_fighting(target) )
	{
		remove_effect(me);
		return;
	}	
	me->add("mana",-25);	
	QUEST_D->information(bx,me);
	bx->set("force_factor",me->query("force_factor")*2/3);
	bx->set("mana_factor",me->query("mana_factor")*2/3);	
	bx->set_temp("invoker",me);
        me->set_temp("invocation",bx);
		
	if( !bx->move(environment(me)) )
	{
		destruct(bx);
		num++;
		call_out("baxian",1+random(4),me,target,num);
		return;
	}
	msg = "只听半空中有声音答道："+	bagua[num-1]+"位"+bx->name()+"在此！随之隐现一道玄仙虚影。$N一指$n：拿人！ \n";
	message_combatd(msg,me,target);
	bx->kill_ob(target);
	COMBAT_D->do_attack(bx,target,bx->query_temp("weapon"),TYPE_QUICK);
	message_combatd("$N的虚影渐渐淡去。。。。\n\n",bx);
	bx->remove_all_killer();
	all_inventory(environment(bx))->remove_killer(bx);
	destruct(bx);
	
	num++;
	if( me->query_skill("taiyi",1)>num*60 && me->query("mana")>25)
		call_out("baxian",1+random(4),me,target,num);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：八仙大阵
        法术所属：太乙仙法
        法术效果：以阵法召唤八仙虚像协同作战
        	  太乙仙法等级越高，召唤的八仙越多
                  护体状态结束后冷却8秒
        法术条件：
        	  五庄观弟子
        	  人物等级25级	
                  法力200点，消耗100点
                  精神100点，消耗50点
                  太乙仙法 200 级
STR;
        me->start_more(str);
        return 1;
}