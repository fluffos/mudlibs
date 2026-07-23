#include <ansi.h>

int do_attack1(object me,object target,int damage,int ap,int dp)
{
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( target->is_busy() )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") ) 
        message_vision(HIB"$N"HIB"大喝一声：魔鹰之喙。$n眼前一花，$N"+HIB"一跃腾空，仿若恶魔之鹰，往$n"HIB"眼睛啄击而来。\n"NOR,me,target);
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIR"$n一个躲闪不及，只觉得眼睛一阵剧痛，什么也看不见了。\n"NOR,me,target);
        target->start_busy(2+random(2));
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
                message_vision(HIG"$n急忙飞身而退，避过夺眼之险。\n"NOR,me,target);
        }         
return 1;
}               

int do_attack2(object me,object target,int damage,int ap,int dp)
{
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") ) 
        message_vision(BLU"$N"BLU"大喝一声：恶狼之牙。$n"BLU"只觉得杀气扑面，$N"BLU"已化做一头巨大恶狼，张着血盆大口往$n"BLU"猛噬过来。\n"NOR,me,target);
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )          
                message_vision(HIR"$n"HIR"一不疏忽，被恶狼一口咬住咽喉，顿时血流而注，赶忙运劲招架，险被咬破喉咙。\n"NOR,me,target);
        damage = (300+random(500))*2;
        target->receive_damage("kee", damage,me);
        target->receive_wound("kee", damage/2,me);
        COMBAT_D->report_status(target);
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIG"$n急忙抽身而退，避过此招。\n"NOR,me,target);
        }
return 1;
}

int do_attack3(object me,object target,int damage,int ap,int dp)
{
string *limbs;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
limbs=target->query("limbs");   
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )         
        message_vision(HIY"$N"HIY"大喝一声：女王峰之刺。右手戟指往$n"+HIW+limbs[random(sizeof(limbs))]+HIY"猛刺而来。\n"NOR,me,target);
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )          
                message_vision(HIC"$n"HIC"一个躲闪不及，被刺个正着,身上多了个针孔般的小伤口，伤处不痛不痒。\n"NOR,me,target);
        target->apply_condition("fengdu",2+random(3));
        target->receive_damage("kee",50,me);
        COMBAT_D->report_status(target);
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIG"$n深知此招厉害，左躲右闪总算避过了这招。\n"NOR,me,target);
        }
return 1;
}

int do_attack4(object me,object target,int damage,int ap,int dp)
{
object weapon;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( !weapon=target->query_temp("weapon") ) 
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )               
        message_vision(HIB"$N"HIB"大喝一声：巨蟒之牙，右手成蛇状，迅疾往$n"HIB"猛攻而来。\n"NOR,me,target);
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )          
                message_vision(HIR"$n急忙用手中"+weapon->query("name")+HIR"攻去，只见$N"HIR"右手随着"+weapon->query("name")+HIR"来势，一把将其打脱下来。\n"NOR,me,target);
        weapon->unequip();
        weapon->move(target);
        target->reset_action();
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIG"$n深知打蛇随棍上的道理，与$N"HIG"互拼一掌，化去此招。\n"NOR,me,target);
        }
return 1;
}

int do_attack5(object me,object target,int damage,int ap,int dp)
{
object weapon;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )               
        message_vision(HIB"$N"HIB"大喝一声：吸血蝙蝠之牙,双手成爪，往$n"HIB"的脖颈抓来。\n"NOR,me,target);
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIR"$n"HIR"急忙闪身，$N"HIR"却不知道什么时候来到了身后，对准$n"HIR"的脖子就是一爪。\n"NOR,me,target);
        target->receive_damage("kee",500,me);
        COMBAT_D->report_status(target);
        me->add("kee",500);
        if ( me->query("kee")>me->query("max_kee") ) 
                me->set("kee",me->query("max_kee"));
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIG"$n"HIG"急忙一跃，凌空一个翻身，闪过此招。\n"NOR,me,target);
        }
return 1;
}

int do_attack6(object me,object target,int damage,int ap,int dp)
{
object weapon;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
        message_vision(HIW"$N"HIW"大喝一声，北极熊之爪。$n"HIW"眼前一花，眼前似乎出现了一头巨大的北极熊，猛的一爪打了过来。\n"NOR,me,target);
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIR"$n"HIR"一个躲闪不及，被打了个正着，顿时鲜血狂喷。\n"NOR,me,target);
        damage = (200+random(700))*2;
        target->receive_damage("kee", damage,me);
        target->receive_wound("kee", damage/2,me);
        COMBAT_D->report_status(target);
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIG"$n"HIG"急忙运劲招架，硬是架住了这一击。\n"NOR,me,target);  
        }
return 1;
}

int do_attack7(object me,object target,int damage,int ap,int dp)
{
object weapon;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
        {
        message_vision(HIY"$N"HIY"右手虚空一握，手中豁然出现了一把金光闪闪的黄金枪。\n"NOR, me,target);
        message_vision(HIY"$N"HIY"大喝一声将手中黄金枪脱手掷出，在空中高低左右回旋。\n",me,target);
        }
damage = (300+random(800))*2;
if ( random(ap+dp)>dp )
        {
        target->receive_damage("kee", damage,me);
        target->receive_wound("kee", damage,me);
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target,damage);
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
                message_vision(HIG "$N"HIG"看得分明，身形一让，避过了这招！\n" NOR, target);
        }
return 1;
}

int do_attack8(object me,object target,int damage,int ap,int dp)
{
object weapon;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
        {
        message_vision(HIC"$N"HIC"身体急旋，四周气劲激荡，已然化作一猛烈飓风，卷起千层巨浪，直冲云霄。\n" NOR, me,target);
        message_vision(HIW"\n$n正暗叹此招威势无匹，飓风突散，$N"HIW"身形已定，宛若天外飞瀑，携着奔流往$n直击而来。\n",me,target);
        }
damage = 1000;
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIR"$n"HIR"已被此威势所摄，心神大骇下，被轰个正着。\n\n"NOR,me,target);
        target->receive_damage("sen", damage,me);
        target->receive_wound("sen", damage/2,me);
        COMBAT_D->report_sen_status(target);
        COMBAT_D->report_sen_status(target,damage/2);
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )          
                message_vision(HIG"$n"HIG"面对滔天巨浪，不知如何躲闪，只得使个懒驴打滚，狼狈不堪，却险险躲过此招。\n"NOR,me,target);
        }
return 1;
}

int do_attack9(object me,object target,int damage,int ap,int dp)
{
object weapon;  
if ( !me || !target || !me->is_fighting(target) )
        return 0;
if ( target->is_busy() )
        return 0;
if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
        {
        message_vision(HIW"$N"HIW"右拳不断晃圈，速度越来越快，只见内劲缓缓聚集在$N"HIW"右拳之上,形成了一道旋风。\n" NOR,me,target);
        message_vision(HIC"$N"HIC"大喝一声：旋风真空拳，右拳猛的击出。\n"NOR,me,target);
        }
damage = 1500;
if ( random(ap+dp)>dp )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIR"$n"HIR"已被此威势所摄，心神大骇下，被轰个正着。\n\n"NOR,me,target);
        target->receive_wound("sen", damage/3,me);
        COMBAT_D->report_sen_status(target);
        if ( random(2) )        {
                if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
                        message_vision(HIR"$n一个失神，已被袭来的旋风卷中，身形失控。\n"NOR,me,target);
                target->start_busy(2+random(2));
                }
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )          
                message_vision(HIG"$n"HIG"乘着风势在旋风之中起起落落，毫发无伤。\n" NOR,me,target);
        }
return 1;
}

int do_attack10(object me,object target,int damage,int ap,int dp)
{
object weapon;  
int i;
if ( !me || !target || !me->is_fighting(target) )
        return 0;
damage+= (100+random(300))*2;
i = random(20);
if ( target->is_busy() ) i=5;
if ( i<10 )
        {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                message_vision(HIW"\n突然之间，万星陨落，化做万千陨石望$n扑天盖地袭来。\n"NOR,me,target);
        if ( random(ap+dp)>dp )
                {
                if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                        message_vision(HIR"$n一时手忙脚乱，不知所措，被撞得鲜血狂喷。\n"NOR,me,target);
                target->receive_wound("kee", damage,me);
                COMBAT_D->report_sen_status(target,damage);
                }
        else    {
                if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
                        message_vision(HIG "$n心神剧骇，赶忙运气凝神，一声大吼，重重幻象顿时消去。\n\n" NOR, me, target);
                }
        }
else    {
        if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
                message_vision(HIW "\n忽然眼前出现一个巨大黑洞，巨大的吸力将点点万星全部吞噬，$n亦不由自主被吸扯过去。\n" NOR,me,target);
        if ( random(ap+dp)>dp/2 )
                {
                if ( !me->query("env/no_msg") && !target->query("env/no_msg") )  
                        message_vision(HIR"$n急忙运劲相抗，堪堪稳住身形，却已无法动弹。\n\n"NOR, target,target );
                target->start_busy((int)target->query_busy()+random(4));
                }
        else    {
                if ( !me->query("env/no_msg") && !target->query("env/no_msg") )
                        message_vision(HIG "$n心神剧骇，赶忙运气凝神，一声大吼，重重幻象顿时消去。\n\n" NOR, me, target);
                }
        }     
return 1;
}

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

