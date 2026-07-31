// diy pfm
// 2/25/2001  by emnil
/*
参数设置为 sld_pfm/??? :
diypfm:         pfm英文名
cdiypfm:        pfm中文名
neili_require:  内力需求
jingli_require: 精力需求
neilicost:      最低消耗内力
jinglicost:     最低消耗精力
weapon:         是否要求有兵器，0为不能有兵器，1为无所谓
msg:            发出pfm时的描述
failmsg:        失败描述
succesmsg:      成功描述
succesmsg2:     第二段成功描述，非必须
endmsg:         pfm结束时的描述
failbusy:       失败的pfm busy，非必须
succesbusy:     成功的pfm busy，非必须
pfmtype:        pfm类别
lvl:            pfm等级
下面参数用于判断成功与否：
rate:           成功率，为百分比
succes:         为0则由以下参数判断，为1则pfm肯定成功
bjingli:        判断精力，1为判断，0为不判断此项
bneili:         判断内力
bexp:           判断经验
bstr:           判断臂力
bdex:           判断身法
bint:           判断智力
bkar:           判断福缘
bskill1:        判断技能1
bskill2:        判断技能2
skill1:         判断的技能1
skill2:         判断的技能2
*/

#include <ansi.h>

//inherit SSERVER;

string addcolor(string arg) {
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        return arg+NOR;
}

int perform(object me, object target ,string action)
{
        string cpfm,skilltype;
        object weapon,weapon2;
        int succes,monk,rate,i,lvl;

        if( (!me->query("sld_pfm/diypfm")) || (me->query("sld_pfm/diypfm")!=action) )
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if( (int)me->query_skill("dulong-dafa", 1) < 256 )
                return notify_fail("你的修为太差了，不能施用所领悟的绝学。\n");

        cpfm = addcolor(me->query("sld_pfm/cdiypfm"));
        //if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("「"+cpfm+"」只能对战斗中的对手使用。\n");

        if( me->query("neili") < (me->query("sld_pfm/neili_require")+1) )
                return notify_fail("你的内力不足，无法使用「"+cpfm+"」。\n");
        if( me->query("jingli") < (me->query("sld_pfm/jingli_require")+1) )
                return notify_fail("你的精力不足，无法使用「"+cpfm+"」。\n");

        weapon = me->query_temp("weapon");
        if ( !me->query("sld_pfm/weapon") && weapon )
                return notify_fail("你手持兵刃，无法使用「"+cpfm+"」。\n");

        me->add("jingli", -me->query("sld_pfm/jinglicost"));
        me->add("neili", -me->query("sld_pfm/neilicost"));      

        message_vision(addcolor(me->query("sld_pfm/msg"))+"\n",me,target);

        succes = me->query("sld_pfm/succes");
        rate = me->query("sld_pfm/rate");
        if ( target->query_skill("buddhism",1)>100 ) monk=120; else monk=100;
        if( (me->query("sld_pfm/bjingli")) && (((me->query("jingli")+1)*rate/100/2)>random(target->query("jingli"))) )
                succes = 1;
        if( (me->query("sld_pfm/bneili")) && (((me->query("neili")+1)*rate/100/2)>random(target->query("neili"))) )
                succes = 1;
        if( (me->query("sld_pfm/bexp")) && ((me->query("combat_exp")*rate/100/2)>random(target->query("combat_exp"))) )
                succes = 1;
        if( (me->query("sld_pfm/bstr")) && ((me->query_str()*rate/100/2)>random(target->query_str())) )
                succes = 1;
        if( (me->query("sld_pfm/bdex")) && ((me->query_dex()*rate/100/2)>random(target->query_dex())) )
                succes = 1;
        if( (me->query("sld_pfm/bint")) && ((me->query_int()*rate/100/2)>random(target->query_int())) )
                succes = 1;
        if( (me->query("sld_pfm/bkar")) && ((me->query_kar()*rate/100/2)>random(target->query_kar())) )
                succes = 1;
        skilltype = (string)me->query("sld_pfm/skill1");
        if( (me->query("sld_pfm/bskill1")) 
          && (((me->query_skill(skilltype)+1)*rate/100/2)>random(target->query_skill(skilltype))) )
                succes = 1;
        skilltype = (string)me->query("sld_pfm/skill2");
        if( (me->query("sld_pfm/bskill2")) 
          && (((me->query_skill(skilltype)+1)*rate/100/2)>random(target->query_skill(skilltype))) )
                succes = 1;

        if (succes) {
                message_vision(addcolor(me->query("sld_pfm/succesmsg"))+"\n",me,target);
                me->add("jingli", -(me->query("sld_pfm/jingli_require")-me->query("sld_pfm/jinglicost")));
                me->add("neili", -(me->query("sld_pfm/neili_require")-me->query("sld_pfm/neilicost"))); 
                if ( (int)me->query("sld_pfm/succesbusy") ) 
                        i = (int)me->query("sld_pfm/succesbusy");
                else
                        i = 3;
                me->start_perform(i,"「"+cpfm+"」");

                lvl = me->query("sld_pfm/lvl"); 
                switch((int)me->query("sld_pfm/pfmtype")) {
                        case 1:  // 缠
                                if (lvl>=5) lvl+=2;
                                i = ((me->query_skill("dulong-dafa",1)+1)/60+1+lvl)*monk/100;
                                target->start_busy(i);
                                me->start_perform(i+1,"「"+cpfm+"」");
                                call_out("remove_effect",i,0,me,target,i,cpfm);
                                break;
                        case 2:  // 连击
                                i = target->query("qi");
                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                if (present(target,environment(me)) && me->is_fighting(target))
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
                                if ((lvl>1) && present(target,environment(me)) && me->is_fighting(target))
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
                                if ((lvl>2) && present(target,environment(me)) && me->is_fighting(target))
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
                                if ((lvl>3) && present(target,environment(me)) && me->is_fighting(target))
                                        if (monk>100)
                                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                                        else
                                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                if ((lvl>4) && present(target,environment(me)) && me->is_fighting(target))
                                        if (monk>100)
                                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                                        else
                                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                if ((lvl>4) && present(target,environment(me)) && me->is_fighting(target)) {
                                        if (target->query("qi")>=i) 
                                                target->set_temp("must_be_hit",1);
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                                        target->delete_temp("must_be_hit");
                                }
                                if ( me && target )
                                        message_vision(addcolor(me->query("sld_pfm/endmsg"))+"\n",me,target);   
                                break; 
                        case 3:  // 消弱防御
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*lvl/15*monk/100;
                                target->add_temp("apply/dodge",-i);
                                target->add_temp("apply/parry",-i);
                                me->start_perform(lvl*5,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*5,1,me,target,i,cpfm);
                                break;
                        case 4:  // 消弱攻击
                                if (lvl>=5) lvl+=2;
                                i = me->query_con()*lvl/12*monk/100;
                                target->add_temp("apply/strength",-i);
                                target->add_temp("apply/attack",-i*5);
                                me->start_perform(lvl*5,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*5,2,me,target,i,cpfm);
                                break;
                        case 5:  // 增强防御
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*lvl/15*monk/100;
                                me->add_temp("apply/dodge",i);
                                me->add_temp("apply/parry",i);
                                me->start_perform(lvl*5,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*5,3,me,target,i,cpfm);
                                break;
                        case 6:  // 增强攻击
                                if (lvl>=5) lvl+=2;
                                i = me->query_con()*lvl/7*monk/100;
                                me->add_temp("apply/strength",i);
                                me->add_temp("apply/attack",i*2);
                                me->start_perform(lvl*5,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*5,4,me,target,i,cpfm);
                                break;
                        case 7:  // 化学，减气
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*(2+lvl)*monk/100;
                                if (i>5500) i=5500;
                                i = i/2+random(i);
                                target->add("qi",-i);
                                target->add("eff_qi",-i/2);
                                break;
                        case 8:  // 化学，减气内力精力
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*(2+lvl)/2*monk/100;
                                if (i>3000) i=3000;
                                i = i/2+random(i);
                                target->add("qi",-i);
                                target->add("eff_qi",-i/2);
                                target->add("jingli",-i/3);
                                target->add("neili",-i/2);
                                break;
                        case 9:  // 对耗内力
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*(1+lvl)/3*monk/100;
                                i = i/2+random(i);
                                me->add("neili",-i);
                                target->add("neili",-i*(10+lvl*3)/10);
                                if (me->query("neili")<0) me->set("neili",0);
                                if (target->query("neili")<0) target->set("neili",0);
                                break;
                        case 10: // 毒，减精
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*(1+lvl)/6*monk/100;
                                i = i/2+random(i);
                                target->add("sld_pfm/pjing",i);
                                target->set("sld_pfm/ptype",1);
                                target->set("sld_pfm/pmsg",addcolor(me->query("sld_pfm/succesmsg2")));
                                target->apply_conditon("sld_poison",me->query_skill("force")/30);
                                break;
                        case 11: // 毒，减气内力精力
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*(1+lvl)/5*monk/100;
                                i = i/2+random(i);
                                target->add("sld_pfm/pqi",i);
                                target->set("sld_pfm/ptype",2);
                                target->set("sld_pfm/pmsg",addcolor(me->query("sld_pfm/succesmsg2")));
                                target->apply_conditon("sld_poison",me->query_skill("force")/30);
                                break;
                        case 12: // 增强加连击
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*lvl/20*monk/100;
                                me->add_temp("apply/dodge",i);
                                me->add_temp("apply/attack",i);

                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                if (present(target,environment(me)) && me->is_fighting(target))
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
                                if ((lvl>4) && present(target,environment(me)) && me->is_fighting(target))
                                        if (monk>100)
                                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                                        else
                                                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                                if ((lvl>4) && present(target,environment(me)) && me->is_fighting(target))
                                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);

                                me->start_perform(lvl*3,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*3,5,me,target,i,cpfm);
                                break;
                        case 13: // 化学加增强
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*lvl/20*monk/100;
                                me->add_temp("apply/dodge",i);
                                me->add_temp("apply/attack",i);
                                me->start_perform(lvl*3,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*3,5,me,target,i,cpfm);

                                i = me->query_skill("force")*(1+lvl)/2*monk/100;
                                if (i>3000) i=3000;
                                i = i/2+random(i);
                                target->add("qi",i);
                                target->add("eff_qi",i/2);
                                break;
                        case 14: // 增强攻击，消弱防御
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*lvl/12*monk/100;
                                me->add_temp("apply/attack", i);
                                me->add_temp("apply/strength",i/5);
                                me->add_temp("apply/dodge",-i/2);
                                me->add_temp("apply/parry",-i/2);
                                me->start_perform(lvl*4,"「"+cpfm+"」");
                                call_out("remove_effect",lvl*4,6,me,target,i,cpfm);
                                break;
                        case 15: // 放大伤害，超强连击
                                if (lvl>=5) lvl+=2;
                                i = me->query_skill("force")*lvl/18*monk/100;
                                me->set_temp("sld_pfm/nowqi",me->query("qi"));
                                me->start_perform(6,"「"+cpfm+"」");
                                call_out("super_attack",1,6,me,target,i);
                                break;
                        case 16: // 断兵器
                                weapon2 = target->query_temp("weapon");
                                if (!weapon2) 
                                        return notify_fail("对方手无兵刃，你何须施用「"+cpfm+"」。\n");
                                if ( (lvl<5) && (weapon2->query("unique")) )
                                        return notify_fail("对方手持神兵利器，你功力不足无法施用「"+cpfm+"」。\n");
                                i = me->query_skill("force")/60*monk/100;
                                weapon2->add("rigidity",-i);
                                if (weapon2->query("rigidity")<=0) {
                                        weapon2->unequip();
                                        weapon2->move(environment(target));
                                        weapon2->set("name", "碎裂的" + weapon2->query("name"));
                                        weapon2->set("value", 49);
                                        weapon2->set("weapon_prop", 0);
                                        target->reset_action();
                                        message_vision(addcolor(me->query("sld_pfm/succesmsg2"))+"\n",me,target);
                                }
                                else {
                                        message_vision(HIY"$n手中兵器虽为神兵利器，但也隐隐露出几道裂痕！\n"NOR,me,target);
                                }
                                break;
                }
        }
        else {
                if ( me && target )
                        message_vision(addcolor(me->query("sld_pfm/failmsg"))+"\n",me,target);
                if ( (int)me->query("sld_pfm/failbusy") ) 
                        i = (int)me->query("sld_pfm/failbusy");
                else
                        i = 3;
                me->start_perform(i,"「"+cpfm+"」");
        }

        return 1;
}
 
void remove_effect(int rtype,object me,object target,int arg1,string cpfm)
{
        switch(rtype) {
                case 0:
                        if (me)
                                me->start_perform(1,"「"+cpfm+"」");
                        break;
                case 1:
                        if (target) {
                                target->add_temp("apply/dodge",arg1);
                                target->add_temp("apply/parry",arg1);
                        }
                        if (me)
                                me->start_perform(1,"「"+cpfm+"」");
                        break;
                case 2:
                        if (target) {
                                target->add_temp("apply/strength",arg1);
                                target->add_temp("apply/attack",arg1*5);
                        }
                        if (me)
                                me->start_perform(1,"「"+cpfm+"」");
                        break;
                case 3:
                        if (me) {
                                me->add_temp("apply/dodge",-arg1);
                                me->add_temp("apply/parry",-arg1);
                                me->start_perform(1,"「"+cpfm+"」");
                        }
                        break;
                case 4:
                        if (me) {
                                me->add_temp("apply/strength",-arg1);
                                me->add_temp("apply/attack",-arg1*2);
                                me->start_perform(1,"「"+cpfm+"」");
                        }
                        break;
                case 5:
                        if (me) {
                                me->add_temp("apply/dodge",-arg1);
                                me->add_temp("apply/attack",-arg1);
                                me->start_perform(1,"「"+cpfm+"」");
                        }
                        break;
                case 6:
                        if (me) {
                                me->add_temp("apply/attack",-arg1);
                                me->add_temp("apply/strength",-arg1/5);
                                me->add_temp("apply/dodge",arg1/2);
                                me->add_temp("apply/parry",arg1/2);
                                me->start_perform(1,"「"+cpfm+"」");
                        }
                        break;
        }

        if ( me && target )
                message_vision(addcolor(me->query("sld_pfm/endmsg"))+"\n",me,target);   
}

void super_attack(int count,object me,object target,int arg)
{
        int i;

        if (!me->is_fighting(target)) 
                return;

        i = me->query_temp("sld_pfm/nowqi") - me->query("qi");
        if (i>0) me->add("qi",-i);
        me->set_temp("sld_pfm/nowqi",me->query("qi"));

        if (count<=0) {
                message_vision(addcolor(me->query("sld_pfm/succesmsg2"))+"\n",me,target);
                me->add_temp("apply/attack",arg);
                me->add_temp("apply/damage",arg/3);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                if (present(target,environment(me)) && me->is_fighting(target))
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                if (present(target,environment(me)) && me->is_fighting(target)) {
                        target->set_temp("must_be_hit",1);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
                        target->delete_temp("must_be_hit");
                }
                me->add_temp("apply/attack",-arg);
                me->add_temp("apply/damage",-arg/3);

                if ( me && target )
                        message_vision(addcolor(me->query("sld_pfm/endmsg"))+"\n",me,target);
        }
        else {
                call_out("super_attack",1,count-1,me,target,i);
        }
}
