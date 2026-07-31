// abandon.c

#include <ansi.h>
inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string skill;
        int level, lvl = 0;
	object sk;

	
        if( !arg ) return notify_fail("指令格式：abandon|fangqi <技能名称> [级数]\n");

        sscanf(arg, "%s %d", arg, lvl);
          
        level = me->query_skill(arg, 1);

        if (!intp(lvl) || lvl < 0) 
                return notify_fail("级数不可为负数。\n");
                
if (arg=="magic-dark")
                return notify_fail("这个技能不能放弃。\n");
if (arg=="magic-light")
                return notify_fail("这个技能不能放弃。\n");
if (arg=="biguan")
                return notify_fail("这个技能不能放弃。\n");

	if( !me->query_skill(arg, 1) )
		return notify_fail("你不会这种技能。\n");
if
(	(int)me->query_temp("apply/attack",1) > 200
	|| (int)me->query_temp("apply/armor",1) >8500
	|| (int)me->query_temp("apply/dexerity",1) >200
        || (int)me->query_temp("apply/strength",1)>200
        || (int)me->query_temp("apply/dodge",1)>200
        || (int)me->query_temp("apply/damage",1)>8500
        || (int)me->query_temp("apply/intelligence",1)>200
        || (int)me->query_temp("apply/constitution",1)>200)

return notify_fail("你正在使用某些加力的武功，请在正常状态下放弃武功!\n");
        if( (int)me->query_temp("powerupxtg") ) 
        return notify_fail("你已经在先天大法了，请在正常状态下放弃武功!\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("你正在运太玄功了，请在正常状态下放弃武功!\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("你正在运葵花无敌功了，请在正常状态下放弃武功!\n");
        if(me->query_temp("wdpowerup") )
        return notify_fail("你现在正在使用「五毒神功」的绝技，请在正常状态下放弃武功!\n"); 
        if(me->query_temp("zhuihun/lpf")) 
        return notify_fail("你正在使用五毒追魂钩之「乱披风」，请在正常状态下放弃武功!\n"); 
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了，请在正常状态下放弃武功!\n");
        if( me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑法中了，请在正常状态下放弃武功!\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法，请在正常状态下放弃武功!\n");
        if( me->query_temp("fumo")   )
                return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」，请在正常状态下放弃武功!\n");
        if( me->query_temp("jingang")   )
                return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」，请在正常状态下放弃武功!\n");
        if( me->query_temp("fanzhen")   )  
                return notify_fail("你正在运用「金刚不坏体神功」，请在正常状态下放弃武功!\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法，请在正常状态下放弃武功!\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了，请在正常状态下放弃武功!\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法，请在正常状态下放弃武功!\n");
       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技，请在正常状态下放弃武功!\n"); 
        if( me->query_temp("qzjtong") ) 
                return notify_fail("你已经在运同归剑法功中了，请在正常状态下放弃武功!\n");
        if (lvl <= 0 || lvl >= level) {
                write("\n注意！你将要放弃全部 "HIW + to_chinese(arg) + "("+arg+")"NOR" ，确定吗？[Y|N]\n>");
                input_to("delete_all", me, arg);
                } 
        else if (level < 100)
                return notify_fail("你这项技能还没有到能收放自如的地步。\n");
        else {
                write("\n注意！你将要放弃" + chinese_number(lvl)+ "级 "HIW+to_chinese(arg)+"("+arg+")"NOR" ，确定吗？[Y|N]\n>");
                input_to("delete_skill", me, arg, level, lvl);
                }
        return 1;
}

private void delete_all(string arg, object me, string skill)
{

        if( arg[0]=='y' || arg[0]=='Y' ){
                me->delete_skill(skill);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned ALL  %s  on %s\n",
                          me->name(1),me->query("id"), to_chinese(skill) , ctime(time()) ));
                write("你放弃了"+ to_chinese(skill) +"。\n");
                }
        else write("你决定保留"+ to_chinese(skill) +"("+skill+")。\n\n");
        
}

private void delete_skill(string arg, object me, string skill, int level, int lvl)
{
        if( arg[0]=='y' || arg[0]=='Y' ){
		me->map_skill(skill);
                me->reset_action();
                me->set_skill(skill, level - lvl);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned  %d levels of %s  on %s\n",
                          me->name(1),me->query("id"), lvl, to_chinese(skill) , ctime(time()) ));
                write("你放弃了" + chinese_number(lvl)+ "级"+ to_chinese(skill) +"("+skill+")。\n\n");
                }
        else write("你决定保留"+ to_chinese(skill) +"("+skill+")。\n\n");
        
}

int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称> [级别]

放弃一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中删除，如果你以后还要练，必须从０开始重练，请务必考虑清楚。

但如果你在放弃命令时有输入级别，将只放弃到指定级别。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。
TEXT
	);
	return 1;
}
