 //libie.c
// - neon 
/*    
黯然销魂者，唯别而已矣！
...... 
日下壁而沉彩，月上轩而飞光。
见红兰之受露，望青楸之离霜。
巡层楹而空掩，抚锦幕而虚凉。
知离梦之踯躅，意别魂之飞扬。
... 
故别虽一绪，事乃万族。
... 
至若龙马银鞍，朱轩绣轴，帐饮东都，送客金谷。
琴羽张兮箫鼓陈，燕、赵歌兮伤美人，
珠与玉兮艳暮秋，罗与绮兮娇上春。
惊驷马之仰秣，耸渊鱼之赤鳞。造分手而衔涕，感寂寞而伤神。
... 
君结绶兮千里，惜瑶草之徒芳。
惭幽闺之琴瑟，晦高台之流黄。
春宫闭此青苔色，秋帐含此明月光，
夏簟清兮昼不暮，冬珙凝兮夜何长！
织锦曲兮泣已尽，回文诗兮影独伤。 
... 
是以别方不定，别理千名，有别必怨，有怨必盈。
使人意夺神骇，心折骨惊，虽渊、云之墨妙，严、乐之笔精，
金闺之诸彦，兰台之群英，赋有凌云之称，辨有雕龙之声，
谁能摹暂离之状，写永诀之情着乎？ 
...
*/ 
// 黯然销魂者唯别而巳 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int libie_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
        string msg, weather;
        int extra,skill;
        object weapon; 
        if( !target ) target = offensive_target(me); 
// capped the sword at 575,
        skill = me->query_skill("sword")>575? 575:me->query_skill("sword");
                extra = 3 * skill *2; 
                if (me->query("class")!="swordsuper") extra = extra/4;
                if(me->query_skill("sword",1)> 350) extra = 3 * skill;  
                if(me->query_skill("sword",1)> 449) extra = 4 * skill;  
         extra = me->query_skill("music",1);
        if ( extra < 280) return notify_fail("你的琴道还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［离别］］只能对战斗中的对手使用。\n");
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不是剑，难以施展［离别］。\n");
                
    if( (int)me->query_skill("xuantian-wuji", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");
//      extra = 788 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(MAG"［离别］"NOR"只能对战斗中的对手使用。\n");  
        weapon = me->query_temp("weapon"); 
if (extra> 200) extra=200;
        me->add_temp("apply/attack", extra/2); 
        me->add_temp("apply/damage", extra);
        msg = HIC"$N手中"+ weapon->name()+ HIC"发出流星般的光芒划过长空。。。\n"HIW"光芒虽短促，但天上已经没有星光能比它更灿烂，辉煌！！！\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra/2);
        me->add_temp("apply/damage", -extra);
                libie_sword(me,target,extra,weapon);
        me->start_busy(2);  

        return 1;
} 
int libie_sword(object me,object target,int extra,object weapon)
{
        string msg, wname;
        int d;
        
        if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me)) return 0;
        if(!present(weapon,me)||weapon->query("equipped")!="wielded")
                return 0; 
if (!target->is_busy()) target->start_busy(3);
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
        target->delete_temp("last_damage_from");
        msg = WHT"光芒淡去之后，$n"NOR+WHT"眼前忽然浮现出萧萧落叶下，天际间远去的孤帆，\n一时心中充满永世分离般的寂寞与伤痛。";
        msg += YEL"$N手中" + weapon->name() + YEL"慢慢划过，隐隐似有呜咽之声，\n金石震而色变，骨肉悲而心死。\n"NOR;
        me->set_temp("libie",1);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);  

        msg = HIB"四下里一片沉寂，风吹落木的声音都没有，也许是风根本就吹不到这里。"NOR;
        msg += HIG"$N手中" + weapon->name() + HIG"忽然发出幽幽声响如轻歌飘来 . . . \n谁能听出其中的暂离之状，永诀之情呢？"NOR;         
            me->add_temp("apply/attack",extra/2);
            me->add_temp("apply/damage",extra*4);
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra/2);
            me->add_temp("apply/damage",-extra*4);  

                message_vision(HIR"$N遽然而惊，在秋风飘缈，离梦别魂般的剑影中急闪而出。 \n"NOR,target);
                message_vision(HIW"黯  然  销  魂  者 ， 唯  别  而  巳  ... ...  \n"NOR,me);
                if  (random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) {
                        if  (userp(target)) 
{
                                         target->receive_damage("qi",target->query("qi")/5);
                        target->receive_wound("qi",target->query("qi")/5);
                                target->apply_condition("libie", 15);
}
else
{
                                         target->receive_damage("qi",5000);
                        target->receive_wound("qi",5000);
}

                                msg = MAG"霎那间万籁俱寂，$n"MAG"突觉一阵冰冷伤痛涌上心头。\n"NOR;
                                message_vision(msg,me,target);
        } 
me->add("neili",-500);
 me->start_busy(3);

        return 1;
}  
