//heijian-jindao 阴阳倒乱刃法
//by fqyy 2003.5.9
/*
左刀横斫，
右剑斜刺。本来刀法以刚猛为主，剑招以轻灵为先，两般兵刃的性子截然相反，一人同使刀
剑，几是绝不可能之事，但公孙谷主双手兵刃越使越急，而刀法剑法却分得清清楚楚，刚柔
相济，阴阳相辅，当真是武林中罕见的绝技。

想到此处，猛地□左刀右攻，右剑左击，使出他平生绝学“阴阳
倒乱刃法”来。黑剑本来阴柔，此时突然硬砍猛斫，变成了阳刚的刀法，而笨重长大的锯齿
金刀却刺挑削洗，全走单剑的轻灵路子，刀成剑，剑变刀，当真是奇幻无方。
*/
#include <ansi.h>
#include <combat.h> 

inherit F_SSERVER;

int perform(object me, object target)
{
	int i,skill;
	object *inv;
	object weapon2;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("阴阳倒乱刃法只能对战斗中的对手使用。\n");

        if( me->query_dex() < 40 )
                return notify_fail("你在身法上先天禀赋不足，不能使用阴阳倒乱刃法！\n");
        
        if( me->query_skill("dodge") < 250 )
                return notify_fail("阴阳倒乱刃法需要超绝的轻功配合，方能有效施展！\n");

        if( me->query_skill("sword") < 250 )
                return notify_fail("你剑法未到炉火纯青之境，还不会使用阴阳倒乱刃法！\n");
        if( me->query_skill("blade") < 250 )
                return notify_fail("你刀法未到炉火纯青之境，还不会使用阴阳倒乱刃法！\n");
        if( me->query_skill("heijian-jindao",1) < 250 )
                return notify_fail("你黑剑金刀未到炉火纯青之境！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用阴阳倒乱刃法！\n");

        if( me->query("jing") <= 500 )
                return notify_fail("你的精力不够使用阴阳倒乱刃法！\n");

        if (!weapon)
                return notify_fail("你手中无剑怎能使用阴阳倒乱刃法？！\n");
        if (me->query_temp("heijian-jindao/luanren",1))
                return notify_fail("你正在使用阴阳倒乱刃法无法再阴阳倒乱刃法！\n");
        if (me->query_temp("heijian-jindao/nizhuan",1)&&me->query_skill("heijian-jindao",1)<300)
                return notify_fail("你这点功夫就想使用阴阳倒乱刃法？！\n");
        if ( me->query_skill_mapped("sword") != "heijian-jindao"
          || me->query_skill_mapped("parry") != "heijian-jindao"
          || me->query_skill_mapped("blade") != "heijian-jindao"
          && userp(me))
             	return notify_fail("你必须先将黑剑金刀相互配合。\n");
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }
	if (!objectp(weapon2)) return notify_fail("你只有一种兵器就想阴阳倒乱刃法？\n");
	if (me->query_temp("heijian-jindao/nizhuan",1)) {
       message_vision(HIC"\n$N猛地□左刀右攻，右剑左击，使出他平生绝学"HIW"“阴阳倒乱刃法”"HIC"来。\n"+
				"剑法本来阴柔，此时突然硬砍猛斫，变成了阳刚的刀法，\n"+
				"而笨重的刀法却刺挑削洗，全走单剑的轻灵路子，刀成剑，剑变刀，当真是奇幻无方。\n\n" NOR, me);
	} else {
       message_vision(HIW"\n$N左刀横斫，右剑斜刺。本来刀法以刚猛为主，剑招以轻灵为先，两般兵刃的性子截然相反，一人同使刀\n"+
				"剑，几是绝不可能之事，但$N双手兵刃越使越急，而刀法剑法却分得清清楚楚，刚柔\n"+
				"相济，阴阳相辅，当真是武林中罕见的绝技。\n\n" NOR, me);
	}
        skill = me->query_skill("heijian-jindao", 1)/4*i;
        me->add_temp("apply/attack", skill/4 );
        me->add_temp("apply/damage", skill/4 );
        me->set_temp("heijian-jindao/yinyang",skill/4);
        me->set_temp("heijian-jindao/luanren",1);
        if( me->is_fighting() && userp(me))
        	me->start_busy(2);
        me->start_perform(1,"阴阳倒乱刃法");
        me->add("neili", -800);
        me->add("jing", -100);
        call_out("remove_effect", 1, me, weapon,weapon2, skill/3);
        return 1;
}

void remove_effect(object me, object weapon,object weapon2, int count)
{
        if ( !me ) return;
        if (objectp(me) && me->query_temp("heijian-jindao/yinyang")) {
          	if (count-- > 0
		&& me->is_fighting()
		&& me->query_skill_mapped("sword") == "heijian-jindao"
		&& me->query_skill_mapped("blade") == "heijian-jindao"
		&& me->query_temp("weapon")
		&& objectp(weapon2)
		&& weapon == me->query_temp("weapon")) {
              		call_out("remove_effect", 1, me, weapon,weapon2, count);
              		return;
          	}
          	me->add_temp("apply/attack", - me->query_temp("heijian-jindao/yinyang"));
          	me->add_temp("apply/damage", - me->query_temp("heijian-jindao/yinyang"));
          	me->delete_temp("heijian-jindao/yinyang");
          	me->delete_temp("heijian-jindao/luanren");
       message_vision(HIR"\n$N知道自己这套阴阳倒乱刃法破绽极大，不敢多用，慢慢收回了攻势。\n\n" NOR, me);
        }
}
