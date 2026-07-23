// douzhuan-xingyi 斗转星移
// 1997-2-14
#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
int douzhuan(object me, object victim);
string *parry_msg = ({
YEL"蓦地里一股力道飞来，将$N一引一带，$N身子轻轻越起，身行落在一旁"NOR,
BLU"$N当下一股内力冲向$n，$n击向$N的$n的招数莫名奇妙的溜滑向一旁"NOR,
HIW"$N双手前探，左臂搭上$n右臂，右臂使出$n的招数将$n此招化去"NOR,
HIY"$N星移斗转，$n这招莫名其妙的在中途转了方向，直奔自己袭来"NOR,
YEL"$N作壁上观，双手与对方相交数掌，谈笑间竟使出$n成名技艺，使得$n不知如何是好"NOR,
BLU"$N凝神运气向$n猛攻快打，使出的招数好似$n的成名绝技，把$n的招数化于无行"NOR,
HIW"只见$N身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$n"NOR,
HIY"$N身行飘忽不定，在星移斗转之间反用$n的招数击向$n，却令人$n百思不得其解"NOR,
});

int valid_enable(string usage)
{
	return usage == "parry";
}

string query_parry_msg(object weapon)
{
	
		return parry_msg[random(sizeof(parry_msg))] + "。\n";
}

int valid_learn(object me)
{
     return notify_fail("斗转星移只能通过领悟来提高。\n");
}

int practice_skill(object me)
{
	return notify_fail("斗转星移只能通过领悟来提高，无法通过练习来提高。\n");
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        string msg;
        int i,p,j,skill, neili, neili1, exp, exp1;
	int hurt;
        object randomtarget, *rob;

	rob = all_inventory(environment(me));
	i = random(sizeof(rob));
	randomtarget = rob[i];

	hurt = damage;
	if ( me->query_temp("mr_bishen", 1) > (random(2)+2)
	&& me->query_skill_mapped("force") == "shenyuan-gong" ) {
		me->delete_temp("mr_bishen");
		//if (random(3)==0) ob->start_busy(3);
		if( !ob || !ob->is_character() || !me->is_fighting(ob) )
	                return 0;
		call_out("bishen", 0, me, ob);
	}
	damage = hurt;
	me->add_temp("mr_bishen", 1);
        skill = me->query_skill("douzhuan-xingyi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");

if (me->query_skill("shenyuan-gong",1) < 50) return damage;
        if(!living(ob)) return damage;
        if(neili < 300) return damage;

	if ( damage > 0 ) {
		if ( rob[i] && living(rob[i]) && rob[i] != me
		&& rob[i]->is_fighting(me)
		&& me->query_skill_mapped("force") == "shenyuan-gong"
		) {
			if (me->query_skill("douzhuan-xingyi", 1) > 150 && me->query("max_neili") > 2500
			    && me->query("neili") > 1000 && random(me->query("combat_exp")) > me->query("combat_exp")/3 
			    && random(skill)> 100) {
				msg = HIC+BBLU+"$N使出慕容武功精随，$n的招式莫明其妙地击中"+rob[i]->query("name")+HIC+BBLU+"\n"NOR;
				tell_object(rob[i], HIR"突然之间，你居然莫明其妙地被击中。\n"NOR);
				damage = damage * 2 / 3;
if (ob->query("qi")/2 > damage)
				rob[i]->receive_wound("qi", damage);
                                p = rob[i]->query("qi")*100/rob[i]->query("max_qi");
				msg += "( "+rob[i]->query("name") + eff_status_msg(p)+" )\n";

                                message_vision(msg, me, ob);
				if ( random(rob[i]->query("int")) > me->query("int")*2/3 )
					rob[i]->kill_ob(me);
				return -damage;
			}
		}
		else {
			if ( (random(me->query("combat_exp")) > ob->query("combat_exp")/3)
			     && (random(me->query("str", 1)) > ob->query("str", 1)/2)
			     && (random(me->query("dex", 1)) > ob->query("dex", 1)/2)
			     && (me->query_skill("douzhuan-xingyi", 1)>300) 
			     ) {
				msg = HIC"$N使出慕容武功精随，斗转星移! $n被自己的成名绝技击中。\n"NOR;

				damage =damage/2+random(damage/3);
                                if (ob->query("qi")/2 > damage)
				ob->receive_wound("qi", damage);
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				message_vision(msg, me, ob);
				return -damage;
			}		

			else if ( random(me->query("combat_exp")) > ob->query("combat_exp")/3
				  && (random(me->query("dex", 1)) > ob->query("dex", 1)/2)
				  && (me->query_skill("douzhuan-xingyi", 1)>240) )
			{
				msg = HIY"突然间$n的招势在中途转向，击中了自己。\n"NOR;

				if (ob->query("qi")/2 > damage/3)
				ob->receive_damage("qi", damage/3);
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				message_vision(msg, me, ob);
				return -damage;
			}

			if ( random(me->query("combat_exp")) > ob->query("combat_exp")/3
			     && (me->query_skill("douzhuan-xingyi", 1)>120) )
			{
				msg = MAG"$n的招势在$N的带引下中途转向，化为无形。\n"NOR;
				message_vision(msg, me, ob);
				return damage/8;
			}
          }
}

if (damage <10)
{
damage=10;      
}

if (me->query_skill("shenyuan-gong",1) <100)
{
           me->delete_temp("dzxy");
           return 1;
}

	 if(me->query_temp("dzxy")){
           me->delete_temp("dzxy");
           return 1;
           }

        if(me->query("jiali") && random(skill)+20 > random(ob->query_skill("parry", 1)) 
         && exp > exp1/3 && skill > 150
         && neili > 300 && living(ob)){
    
   message_vision(HIG"$N立时旁拨侧挑，推气引劲，试图把$n的攻击转向$n自己身上！\n"NOR,me, ob); 

       if(neili >= neili1+random(neili1)+damage){
            message_vision(HIY"结果$n看破了$N的意图，招式忽变，$N这一招却未成功！\n"NOR,me, ob);
            return damage;
            }else{ 
   message_vision(HIR"$n只觉似乎双手不听使唤，招式被$N一带一引，直向$n自己反击过来！\n"NOR,me,ob);
         msg = "";
         if(random(2)==1) me->add_temp("dzxy", 1); 
if (ob->query("qi")/2 > damage)
              ob->receive_damage("qi", damage);
if (ob->query("eff_qi") > damage/3)
              ob->receive_wound("qi", damage/3);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*2+skill);
              }
        }else{       
           msg = parry_msg[random(sizeof(parry_msg))];
             if(neili >= random(neili1)+damage){
              msg += HIR"\n果基本上卸掉了$n的力道。\n"NOR;              
              j = -(damage+skill);
              }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += HIC"\n结果卸掉了一些$n的力道。\n"NOR;
              else msg += HIB"\n结果卸掉了$n一半的力道。\n"NOR;
              j = -j;
              }
           }           
           message_vision(msg, me, ob);
           return j;
          
     
}

void bishen (object me, object ob)
{
	int damage, p,ran;
	object weapon;
	string msg, menpai;
if (!me) return;
if (!ob) return;
if (!living(ob))return;
if (me->query("neili") <500) return;
if (me->query("jing") <100) return;
if (me->query_skill("shenyuan-gong",1) < 50) return;
	damage = (int)me->query_skill("douzhuan-xingyi", 1);
	damage += damage + random (damage);
	menpai = ob->query("family/family_name");
	weapon = me->query_temp("weapon");
ran=random(24)+1;
	msg = HIW"\n以彼之道，还施彼身。突然之间，$N使出一招绝技。\n\n"NOR;

	switch ( ran ) {
	case 1 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += BLU"\n突然$N大喝一声：「雷动九天」，面色唰的变得通红，须发皆飞，真气溶入" + weapon->name() + BLU"当中，“嗡”的一声，发出"HIW"闪闪光亮"BLU"！\n" NOR;
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/2)
			ob->receive_damage("qi", damage/2);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
		else {
			msg += "$N忽然跃起，左脚一勾一弹，霎时之间踢出一招「"HIY"如"NOR"」字诀的穿心腿，直袭$n前胸！\n";
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
			ob->receive_damage("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg += "\n紧接着$N左腿勾回，将腰身一扭，那右腿的一招「"HIY"影"NOR"」字诀便紧随而至，飞向$n！\n";
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
			ob->receive_damage("qi", damage/3);
			ob->receive_wound("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg += "\n只见$N右脚劲力未消，便凌空一转，左腿顺势扫出一招「"HIY"随"NOR"」字诀，如影而至！\n";
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
			ob->receive_damage("qi", damage/3);
			ob->receive_wound("qi", damage/2);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg += "\n半空中$N脚未后撤，已经运起「"HIY"形"NOR"」字诀，内劲直透脚尖，在$n胸腹处连点了数十下！\n";
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
			ob->receive_damage("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
						msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case 2 :
		if ( objectp( me->query_temp("weapon")) )
			msg += HIW "\n$N飘身而起，使出峨嵋绝技「灭剑」心法，顿时剑意空灵飘逸，似万千柳絮飞舞，又如和风阵阵
拂过。$n惊骇之下，顿时出招散乱，无从招架！\n\n" NOR;
		else
			msg += MAG "\n只见$N面显庄严，一式「"HIY"佛光普照"MAG"」，提一口真气，飘身而上，半空中手掌交错，一股内劲狭带着热
浪，如风如火，似雷似电，这一招拍出，击向$n，招式平平淡淡，一成不变，但却挡无可挡，避无可避！\n"NOR;
		me->add("neili", -10);
		me->add("jing", -10);
if (ob->query("qi")/2 > damage/5)
		ob->receive_wound("qi", damage/5);
		ob->receive_wound("qi", damage/3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 3 :
		if ( objectp( me->query_temp("weapon")) ) 
			msg += BLU"\n $N长笑一声，剑交左手，蹂身而上，施展「风雷四击」绝技,试图快速击伤$n \n"NOR;
		else
			msg += YEL "\n$N凝气于指，一式「阳关三叠」点出，但听得嗤嗤声响，一股纯阳的内力直袭$n胸口！\n" NOR;
		me->add("neili", -10);
		me->add("jing", -10);
if (ob->query("qi")/2 > damage/4)
		ob->receive_wound("qi", damage/4);
		ob->start_busy(1);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 4 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += CYN"\n$N使出太极剑法"RED"「缠」"CYN"字诀，一柄"+weapon->name()+CYN"在画着一个个圆圈，每一招均是以弧形刺出，弧形收回。
神在剑先，绵绵不绝，便如撒出了一张大网，逐步向$n收紧！\n\n"NOR;
			msg += HIY"结果太极剑意散发出的细丝越积越多，似是积成了一团团丝棉，将$n紧紧裹了起来！\n"NOR;
if (!ob->is_busy() && random(2)==0)
			ob->start_busy(6);
		}
		else {
			msg += CYN"太极之意连绵不断，有如自去行空，一个圆圈未完，第二个圆圈已生，喀喇一响，$p一处骨头被绞断！\n"NOR;
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
			ob->receive_wound("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case 5 :
		if ( objectp( me->query_temp("weapon")) ) {
			if ( me->query("gender") == "男性")
				msg += HIC"长啸一声，使出平生绝技，连环三击，正是华山剑宗绝学“"HIY"夺命连环三仙剑"HIC"”！\n"NOR;
			else 
				msg += HIC"$N突然使出华山绝技，一式“无双无对，宁式一剑”，只见$N挺剑
直出，剑式如虹，嗤嗤之声大作，凌厉绝伦，剑力已将$n全身笼罩。\n"NOR;

			msg += "$n怎么也想不到$N能使出自己的成名绝技，一时间不知所措。\n"NOR;
if (!ob->is_busy()&& random(2)==0)
			ob->start_busy(5);
		}
		else {
			msg += MAG"$N使出劈石破玉拳的绝学雷动九天，顿时天空电闪雷鸣！\n"NOR;
			me->add("neili", -10);
			me->add("jing", -10);

if (ob->query("qi")/2 > damage/3)
			ob->receive_wound("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case 6 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += CYN "$N抽出一只玉箫凑到嘴边，吹得两下，从箫筒里突然射出一道青光，直扑$n。\n";
			msg += "$n躲闪不及，正中前胸！\n";
		}
		else
			msg += GRN "$N一声清啸，拳脚齐施，使出桃花「狂风绝技」迅捷无伦地攻向$n！\n"NOR;
		me->add("neili", -10);
		me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
		ob->receive_wound("qi", damage/3);
		
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;			
	case 7 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIG"$N以"+ weapon->name() + HIG"代棒，使出打狗棒法「缠字」诀，只见一团青影往$n身上罩了过去。\n";
			msg += HIY "结果$p被$P攻了个措手不及。\n" NOR;
if (!ob->is_busy()&& random(2)==0)
			ob->start_busy(5);
		}
		else {
			 msg += HIM"\n$N双掌平举前胸，丹田之气凝于膻中，右手缓缓推向$n，看似轻描淡写，\n"+
                HIG"但一遇阻力，便加起无数内劲，一道强过一道，呼啸着向$n而去！\n"NOR;
			me->add("neili", -10);
			me->add("jing", -10);
if (ob->query("qi")/2 > damage/3)
			ob->receive_wound("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case 8 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIW"\n$N悄悄使出《圣火令法》绝学"BLU"阴风刀"HIW"，运起一股无形无质的阴寒之气，直插"+ob->name()+"胸口玉堂穴要穴！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n突然$N眼射精光，朗声念出句似歌非歌、似诗非诗的拳诀：“三焦齐逆兮魂魄飞扬”，接着走上前去，砰的一拳击向$n！\n"NOR;
			msg += HIW"在刚一触到"+ob->name()+"的身体时，你便暗暗发力，将隐藏在在拳内的七种力道送了过去！\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 9 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N乘$n稍稍走神之机，拼尽全力使出洪教主不传之绝技－－「英雄三招」！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n$N忽然猛一吸气，双掌一立，化骨绵掌，向$n轻轻地拍出！$n！\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 10 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIB"\n$N大吼一声，手持玄铁剑挟巨浪潮涌之势,从轻而响，从响而轻，忽寂然无声，忽轰轰之声，反复七次，席卷而去。！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n$N面呈凄苦之色，心下万念俱灰，没精打采的挥袖卷出，倒拍出一掌！$n！\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -200);
		me->add("jing", -10);
if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 11 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIB"\n$N一声阴笑，忽若一团红云般欺身而近，手中细针疾指双目！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n$N面露凝重之色，双手色呈青紫，原本尖锐的掌风竟变得悄无声息！\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -200);
		me->add("jing", -10);
if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 12 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIC"\n$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIC"\n$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;

	case 13 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N一声长笑，只觉世事如意，豪气满胸，哪管什么是非荣辱，反手一刀砍出！！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += CYN"\n$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 14 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N突如起来的从狂风中闪出，对着$n胸前就是一杖！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += BLU"\n$N身子蹲下，左掌平推而出，使的正是$N生平最得意的「蛤蟆功」绝招，掌风直逼$n而去！\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 15 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N伸手搭在法轮上往斜里一拨，法轮在空中划出一道弧线，向$n飞去。\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += RED"\n$N聚气于掌，使出一招「焚心以火」，向$n的胸口击去。\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 16 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIR"\n$N轻描淡写，挥尘如意，一瞬间就已使出夺命十三式，手中的武器轻灵流动 
，就像是河水般的向$n刺出,天地间彷佛充满了杀气！\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		else {
                        msg += RED"\n$N把全身的劲力注入双掌,高高跃起，**凝血神抓**，一抓抓来，势不可挡！\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 17 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += YEL"\n$N使出全真派绝技「一剑化三清」，身法陡然加快,手握剑柄晃成三条白龙！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIR"\n$N怒喝一声，拚尽全力，突然闪电般攻出拳、掌、腿连环三招！\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 18 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += CYN"\n$N突然暴吼一声：“我砸！我砸！我砸砸砸！”，手中巨斧竟然砸向$n手中兵刃！\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		else {
                        msg += HIR"\n$N运起［归元吐纳法］，同时使出［铁掌降龙］一阵一阵的掌力，如潮水般的击向$n！\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 19 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIC"\n$N手中长剑剑芒跃动，剑光暴长，剑尖颤动似乎分左右刺向$n\n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		else {
                        msg += HIG"\n$N深吸一口气，大喝一声，连续击出"HIW+ (random(10)+1) +HIG"掌，后招推着前招，掌力叠合在一起扑向$n！\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 20 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += YEL"\n$N"+RED+"阴侧侧长笑数声，天魔刀法接连出招。\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += RED"\n$N猛地纵起，向$n扑去，手指一弹，细针飞了出去，插向$n右目。\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 21 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIW"\n$N长啸一声,使出「万梅飘零」,手中兵器疾卷,掀起万朵雪花向前铺天盖地的撒去。\n"
    "在白茫茫的一片中,忽然出现万朵梅花形剑花,穿透雪幕,朝四面八方狂射而出。\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIW"\n$N冰雪心法运转一周天，全身只觉一股寒气蒸腾欲出,清啸一声,\n"
"飞身而上,施展出「"+HIW"烟雪春梅」，双手一搓一放,一股凝人气血的\n"
"狂飙向$n铺天盖地席卷而去。\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;

	case 22 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N将发结解开，披头散发，脸色突然变白，手中的"+weapon->name()+"也跟着剧烈抖动着！
突然$N一声狂嚎，如神哭鬼号似的厉啸响自天地，发疯似的将五毒追魂钩狂乱使出！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIR"\n$N一声狞笑飞身纵起，凌空一指向$n的眉心点去。\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 23 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIM"\n$N双目突然泛过怪异绿光,中指在不易察觉间微微一动,一点银星悄无声息打向$n眉心。！\n"NOR;
if (ob->query("qi")/2 > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIM"\n$N突然收掌，然后迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！！\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case 24 :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIM"\n$N使出飞天御剑流的最高剑决的" + HIR "天翔龙闪" +HIW "，$n只见$N身形一闪，咽喉已被对穿而过！ \n"NOR;
if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		else {
                        msg += HIM"\n「三重劲!」$N全身骨骼一阵爆响,拼尽毕生功力使出了喧哗流拳法的终极绝技。\n"NOR;
                if (ob->query("qi")/2 > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -10);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	default :
		msg += HIW"$N使出$n的成名绝技，刹那间一股排山倒海之力击中$n。\n"NOR;
		me->add("neili", -10);
		me->add("jing", -10);
                if (ob->query("qi")/2 > damage/3)
		ob->receive_wound("qi", damage/3);
               if (!ob->is_busy()&& random(2)==0)
		ob->start_busy(3);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	message_vision(msg, me, ob);
}