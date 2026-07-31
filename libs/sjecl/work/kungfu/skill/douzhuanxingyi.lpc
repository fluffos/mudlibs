// douzhuan-xingyi 斗转星移
// 1997-2-14
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
YEL"蓦地里一股力道飞来，将$N一引一带，$N身子轻轻越起，身行落在一旁"NOR,
BLU"$N当下一股内力冲向$L，$n击向$N的$L的招数莫名奇妙的溜滑向一旁"NOR,
HIW"$N双手前探，左臂搭上$n右臂，右臂使出$n的招数将$n此招化去"NOR,
HIY"$N星移斗转，$n这招莫名其妙的在中途转了方向，直奔自己袭来"NOR,
YEL"$N作壁上观，双手与对方相交数掌，谈笑间竟使出$n成名技艺，使得$n不知如何是好"NOR,
BLU"$N凝神运气向$n猛攻快打，使出的招数好似$n的成名绝技，把$n的招数化于无行"NOR,
HIW"只见$N身如飘风，恰似漫天星移，诡异地一式，双掌动向无定不可捉摸地拍向$n的$l"NOR,
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

//modify from qiankun-danuoyi
int ob_hit(object ob, object me, int damage)
{
        string msg;
        int p,j,skill, neili, neili1, exp, exp1;
        skill = me->query_skill("douzhuan-xingyi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");

        if(!living(ob)) return damage;
        if(neili < 300) return damage;

	 if(me->query_temp("dzxy")){
           me->delete_temp("dzxy");
           return 1;
           }

      
        if(me->query("jiali") && random(skill)+20 > random(ob->query_skill("parry", 1)) 
         && exp > exp1/2 && skill > 50
         && neili > 300 && living(ob)){
    
   message_vision(GRN"$N立时旁拨侧挑，推气引劲，试图把$n的攻击转向$n自己身上！\n"NOR,me, ob); 

       if(neili >= neili1+random(neili1)+damage){
            message_vision(HIY"结果$n看破了$N的意图，招式忽变，$N这一招却未成功！\n"NOR,me, ob);
            return damage;
            }else{ 
   message_vision(HIR"$n只觉似乎双手不听使唤，招式被$N一带一引，直向$n自己反击过来！\n"NOR,me,ob);
         if(random(2)==1) me->add_temp("dzxy", 1); 
              ob->receive_damage("qi", damage);
              ob->receive_wound("qi", damage/10);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += COMBAT_D->damage_msg(damage, "内伤");
              msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
              j = -(damage*2+skill);
              }
        }else{       
           msg = parry_msg[random(sizeof(parry_msg))];
             if(neili >= random(neili1)+damage){
              msg += "结果基本上卸掉了$n的力道。\n";              
              j = -(damage+skill);
              }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += "结果卸掉了一些$n的力道。\n";
              else msg += "结果卸掉了$n一半的力道。\n";
              j = -j;
              }
           }           
           message_vision(msg, me, ob);
           return j;
          
     
}
     
