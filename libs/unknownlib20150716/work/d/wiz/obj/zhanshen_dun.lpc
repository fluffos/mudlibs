#include <armor.h>
#include <ansi.h>
#include <combat.h>

inherit SHIELD;

void jia_condition(object me,object ob);
void check_owner();
void destroy(object ob);
void over(object me);
object offensive_target(object me);

string name = "$N";

void create()
{
set_name(HIR"战神盾"NOR, ({"zhanshen dun", "dun", "shield"}));
set_level(20);
set_weight(5000);
if ( clonep() )
     set_default_object(__FILE__);
else {
        set("unit", "件");
        set("material", "wood");
        set("armor_prop/armor",45);
        set("armor_prop/dodge", -5);
        set("remove_msg",HIR"$n"HIR"呼的从$N"HIR"身上消失了。\n"NOR);  
        set("wear_msg",HIR"$n"HIR"从虚无中“呼”的出现在$N"HIR"的身上。\n"NOR);
        }
setup();
}

int init()
{
check_owner();
add_action("do_shield","shield");
}


void check_owner()
{
object ob =this_object();
object me =environment(ob);
if ( !wizardp(me) )
        destroy(ob);
return;
}

void destroy(object ob)
{
message_vision(HIY"天空中伸出一只大手,一把抓起$N"HIY"！\n"NOR,ob);
destruct(ob);
return;
}

int query_autoload()
{
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

int do_shield ()
{
int i,k,daHIRe,time;
string *limbs;
object weapon,ob,me,target;
ob=this_object();
me=environment(ob);
target =offensive_target(me);
time=me->query_skill("spells");
time/=100;
time-=10;
time/=2;
if ( time<1 ) time =1;
if ( time>5 ) time =5;

if( !me->is_fighting() || !target  || ! present( target,environment(me)) )
        return notify_fail("你并不在战斗中。\n");
if ( !ob->query("equipped") || !userp(me) )
        return notify_fail("你必须先装备上海王盾。\n");
if ( time()<me->query_temp("shield")+5 ) 
        return notify_fail("你已经祭出海王盾了，还是休息休息吧。\n");

me->set_temp("shield",time());
message_vision(HIR"$N"HIR"将手中$n"HIR"朝天一抛，口中念道：\n
以与战神之契，助我，疾！\n"NOR,me,ob );
message_vision(HIR"\n\n$N"HIR"遵循战神之约，借$n"HIR"的力量使出了前所为有的绝学！\n"NOR,me,ob);
for ( i=0;i<(1+random(3));i++) 
        {
        switch(random(8))
                {
                case 1:
                        {
                        daHIRe = 800+random(800);
                        limbs=target->query("limbs");
                        k=random(60);
                        //************************************************
                        if (k<10) 
                                {
                                if( target->is_busy() )
                                        return 0;
                                message_vision(HIB"$N"HIB"大喝一声：魔鹰之喙。$n眼前一花，$N"+HIB"一跃腾空，仿若恶魔之鹰，往$n"HIB"眼睛啄击而来。\n"NOR,me,target);
                                if( random(3)<2 )
                                        {

                                        message_vision(HIR"$n一个躲闪不及，只觉得眼睛一阵剧痛，什么也看不见了。\n"NOR,me,target);
                                        target->start_busy(2+random(2));
                                        }else{
                                        message_vision(HIR"$n急忙飞身而退，避过夺眼之险。\n"NOR,me,target);
                                        }         
                                }
                        //************************************************
                                else if (k<20)  
                                {
                                message_vision(BLU"$N"BLU"大喝一声：恶狼之牙。$n"BLU"只觉得杀气扑面，$N"BLU"已化做一头巨大恶狼，张着血盆大口往$n"BLU"猛噬过来。\n"NOR,me,target);
                                if( random(3)<3 )
                                        {
                                        message_vision(HIR"$n"HIR"一不疏忽，被恶狼一口咬住咽喉，顿时血流而注，赶忙运劲招架，险被咬破喉咙。\n"NOR,me,target);
                                        daHIRe=500+random(300);
                                        target->receive_daHIRe("kee", daHIRe);
                                        target->receive_wound("kee", daHIRe/2);
                                        COMBAT_D->report_status(target);
                                        }else{
                                        message_vision(HIR"$n急忙抽身而退，避过此招。\n"NOR,me,target);
                                        }
                                }
                        //*************************************************
                                else if (k<30) 
                                {
                                message_vision(HIY"$N"HIY"大喝一声：女王峰之刺。右手戟指往$n"+HIW+limbs[random(sizeof(limbs))]+HIY"猛刺而来。\n"NOR,me,target);
                                if( random(3)<2 )
                                        {
                                        message_vision(HIC"$n"HIC"一个躲闪不及，被刺个正着,身上多了个针孔般的小伤口，伤处不痛不痒。\n"NOR,me,target);
                                        target->apply_condition("fengdu",2+random(3));
                                        }else{
                                        message_vision(HIR"$n深知此招厉害，左躲右闪总算避过了这招。\n"NOR,me,target);
                                        }
                                }
                        //************************************************
                                else if (k<40) 
                                {
                                if (!weapon=target->query_temp("weapon")) return 0;
                                message_vision(HIB"$N"HIB"大喝一声：巨蟒之牙，右手成蛇状，迅疾往$n"HIB"猛攻而来。\n"NOR,me,target);
                                if( random(3)<2 )
                                        {
                                        message_vision(HIR"$n急忙用手中"+weapon->query("name")+HIR"攻去，只见$N"HIR"右手随着"+weapon->query("name")+HIR"来势，一把将其打脱下来。\n"NOR,me,target);
                                        weapon->unequip();
                                        weapon->move(target);
                                        target->reset_action();
                                        }else{
                                        message_vision(HIR"$n深知打蛇随棍上的道理，与$N"HIR"互拼一掌，化去此招。\n"NOR,me,target);
                                        }
                                } 
                        //************************************************
                                else if (k<50) 
                                {
                                message_vision(HIB"$N"HIB"大喝一声：吸血蝙蝠之牙,双手成爪，往$n"HIB"的脖颈抓来。\n"NOR,me,target);
                                if( random(3)<2 )
                                        {
                                        message_vision(HIR"$n"HIR"急忙闪身，$N"HIR"却不知道什么时候来到了身后，对准$n"HIR"的脖子就是一爪。\n"NOR,me,target);
                                        target->add("kee",-500);
                                        me->add("kee",500);
                                        if (me->query("kee")>me->query("max_kee")) me->set("kee",me->query("max_kee"));
                                        }else{
                                        message_vision(HIR"$n急忙一跃，凌空一个翻身，闪过此招。\n"NOR,me,target);
                                        }
                                } 
                        //***********************************************
                                else {
                                message_vision(HIW"$N"HIW"大喝一声，北极熊之爪。$n"HIW"眼前一花，眼前似乎出现了一头巨大的北极熊，猛的一爪打了过来。\n"NOR,me,target);
                                if( random(3)<2 )
                                        {
                                        message_vision(HIR"$n"HIR"一个躲闪不及，被打了个正着，顿时鲜血狂喷。\n"NOR,me,target);
                                        daHIRe=600+random(200);
                                        target->receive_daHIRe("kee", daHIRe);
                                        target->receive_wound("kee", daHIRe/2);
                                        COMBAT_D->report_status(target);
                                        }else{
                                        message_vision(HIR"$n"HIR"急忙运劲招架，硬是架住了这一击。\n"NOR,me,target);  
                                        }
                                }
                        }
                break;  
                        
                case 2:
                        {
                        daHIRe = 700+random(100);
                        message_vision(HIY"$N"HIY"右手虚空一握，手中豁然出现了一把金光闪闪的黄金枪。\n"NOR, me,target);
                        message_vision(HIY"$N"HIY"大喝一声将手中黄金枪脱手掷出，在空中高低左右回旋。\n",me,target);
                        if ( random(3)<2 )
                                {
                                target->receive_daHIRe("kee", daHIRe);
                                target->receive_wound("kee", daHIRe);
                                COMBAT_D->report_status(target);
                                COMBAT_D->report_status(target,daHIRe);
                                }else {
                                message_vision(HIR "$N看得分明，身形一让，避过了这招！\n" NOR, target);
                                }
                        }
                break;

                case 3:
                        {
                        daHIRe = 800;
                        message_vision(HIC"$N"HIC"身体急旋，四周气劲激荡，已然化作一猛烈飓风，卷起千层巨浪，直冲云霄。\n" NOR, me,target);
                        message_vision(HIW"\n$n正暗叹此招威势无匹，飓风突散，"+name+HIW"身形已定，宛若天外飞瀑，携着奔流往$n直击而来。\n",me,target);
                        if ( random(3)<2 )
                                {
                                message_vision(HIR"$n已被此威势所摄，心神大骇下，被轰个正着。\n\n"NOR,me,target);
                                target->receive_daHIRe("sen", daHIRe);
                                target->receive_wound("sen", daHIRe/2);
                                COMBAT_D->report_sen_status(target);
                                COMBAT_D->report_sen_status(target,daHIRe/2);
                                }else{
                                message_vision(HIR"$n面对滔天巨浪，不知如何躲闪，只得使个懒驴打滚，狼狈不堪，却险险躲过此招。\n"NOR,me,target);
                                }
                        }
                break;  

                case 4:
                        {
                        message_vision(name+HIR"一声大吼，付于$N身，对$n发起一阵攻击！\n"NOR,me,target);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                        }
                break;

                case 5:
                        {
                        message_vision(name+HIW "右拳不断晃圈，速度越来越快，只见内劲缓缓聚集在"+name+HIW"右拳之上,形成了一道旋风。\n" NOR,me,target);
                        message_vision(name+HIC"大喝一声：旋风真空拳，右拳猛的击出。\n"NOR,me,target);
                        if ( random(3)>2 || target->is_busy() )
                                {
                                message_vision(HIR "$n乘着风势在旋风之中起起落落，毫发无伤。\n" NOR,me,target);
                                }else {
                                message_vision(HIR"$n一个失神，已被袭来的旋风卷中，身形失控。\n"NOR,me,target);
                                target->start_busy(2+random(2));
                                }
                        }
                break;

                default:
                        {
                        daHIRe=random(800);
                        message_vision(HIC "\n随着"+name+HIC"一声怒喝，$n顿觉天色转暗，仿佛置身于宇宙之中，星光闪闪。\n" NOR,me,target);
                        i=random(20);
                        if( target->is_busy() ) i=5;
                        if (i<10)
                                {
                                message_vision(HIW"\n突然之间，万星陨落，化做万千陨石望$n扑天盖地袭来。\n"NOR,me,target);
                                if( random(3)<2 )
                                        {
                                        message_vision(HIR"$n一时手忙脚乱，不知所措，被撞得鲜血狂喷。\n"NOR,me,target);
                                        target->receive_wound("kee", daHIRe);
                                        COMBAT_D->report_sen_status(target,daHIRe);
                                        }else{
                                        message_vision(HIR "$n心神剧骇，赶忙运气凝神，一声大吼，重重幻象顿时消去。\n\n" NOR, me, target);
                                        }
                                }else{
                                message_vision(HIW "\n忽然眼前出现一个巨大黑洞，巨大的吸力将点点万星全部吞噬，$n亦不由自主被吸扯过去。\n" NOR,me,target);
                                if( random(3)<2 )
                                        {
                                        message_vision(HIR"$n急忙运劲相抗，堪堪稳住身形，却已无法动弹。\n\n"NOR, target,target );
                                        target->start_busy(2+random(2));
                                        }else{
                                        message_vision(HIR "$n心神剧骇，赶忙运气凝神，一声大吼，重重幻象顿时消去。\n\n" NOR, me, target);
                                        }
                                }     
                        }
                break;
                }
        }
if ( target )
        target->set_temp("last_damage_from",me);
return 1;
}


