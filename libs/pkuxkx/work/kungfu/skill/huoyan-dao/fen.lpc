// fen.c 焚
// by iceland
// modefied by emnil@sj 2/3/2k

#include <ansi.h>
#include <char.h>
#include <armor.h> 
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object *inv;
		object ash;
        int hskill, lskill, ap, dp, i, makeash, pflv, rate;
        int neili_wound, qi_wound=0 , stradd, armor, fail;

        hskill = me->query_skill("huoyan-dao",1);
        lskill = me->query_skill("longxiang-boruo",1);

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("「焚」只能对战斗中的对手使用。\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("你只能空手运用「焚」的绝技。\n");

        if( hskill < 120)
                return notify_fail("你的「火焰刀」等级不够, 不能使出「焚」的绝技！\n");

        if( lskill < 120)
                return notify_fail("你的「龙象般若功」功力不够, 不能使出「焚」的绝技！\n");

        if( me->query("neili") < 1200 )
                return notify_fail("你的内力即将用尽，发不出「焚」了！\n");

        if( me->query("jingli") < 300 )
                return notify_fail("你的精力即将用尽，发不出「焚」了！\n");

        if( me->query("max_neili") < 2000 )
                return notify_fail("你的内力不够，不能催动内力发出「焚」绝技！\n");

/*        if( me->query_skill_mapped("strike") != "huoyan-dao"
         || me->query_skill_prepared("strike") != "huoyan-dao")
                return notify_fail("你必须使用「火焰刀」，才能使出「焚」的绝技！\n"); */

        if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
            me->query_skill_mapped("force") != "longxiang-boruo")
                return notify_fail("你现在所使用的内功同「龙象般若功」相抵触，不能使出「焚」的绝技！\n");

		pflv = (int)me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "大轮寺") 
			pflv=0;
		if (pflv>5) pflv=5;

		msg = HIR "\n$N死死盯住$n，双掌聚气连连擦动，突然大喝声中双掌推出，\n发出两道烈焰瞬间将$n裹在火中。\n"NOR;

        message_vision(msg, me, target);

        if(me->query_temp("xs/fail")
         && me->query_temp("xs/failed") == target->query("id"))
            fail = me->query_temp("xs/fail");
        else {
            fail = 0;
            me->set_temp("xs/fail",0);
            me->delete_temp("xs/failed");
        }
        ap = me->query_skill("strike") + me->query_skill("force")/6;
        dp = target->query_skill("dodge")+ target->query_skill("parry")/6;

        if( dp < 1 )
          dp = 1;

        if( F_KUNGFU->hit_rate( ap, dp, 9-(pflv>=3?1:0), me, target)
         || ap/2 > dp
         || fail >= 4 ){
           msg = HIR "\n$n身上衣衫毛发尽皆着火，皮肤头发被烧得吱吱做响，滚倒在地，不住翻滚号哭！\n"NOR;
           if(me->query_temp("xs/longxiang")){
              stradd = lskill/20*3;
              msg += MAG"$N更以龙象之内力侵入$n筋脉，使$n伤上加伤！\n"NOR;
           }
           else
              stradd = 0;
              if(lskill >=140 )
                neili_wound = (me->query_str()+ stradd)*3 + (hskill+lskill)/2;
              else
                neili_wound = (me->query_str()+ stradd)*2 + (hskill+lskill)/2;

              neili_wound += random(neili_wound/2);

              qi_wound = neili_wound * 4;

              if(neili_wound > target->query("neili"))
                neili_wound = target->query("neili");

              armor = 0;
			  makeash = 0;
              inv = all_inventory(target);
              if(sizeof(inv)){
                  for (i=0;i<sizeof(inv);i++) {
					if (!inv[i]->query("equipped")) continue; // 穿着的衣服才被烧
					if (inv[i]->query("no_burn_destroy")) // 允许具备特殊属性的衣服不被烧毁
					{
						if (stringp(inv[i]->query("no_burn_destroy")))
							msg += "\n" + inv[i]->query("no_burn_destroy") + "\n" NOR;
						else
							msg += "\n" HIW + inv[i]->query("name") + HIW "抵挡住了烈火的灼烧！\n" NOR;
						continue; 
					}
                    if(inv[i]->query("armor_prop/armor") > 0) {
                       armor = 1;
                       if (inv[i]->query("armor_prop/armor") > 150){
                           qi_wound=qi_wound/5*4;
                           neili_wound=neili_wound/5*4;
                       }
						if (inv[i]->query("armor_type")==TYPE_CLOTH && inv[i]->query("equipped") && !inv[i]->query("fire_burned"))
							makeash = 1;
                       if( !inv[i]->query("unique") ){
						   if (!inv[i]->query("fire_burned"))
							msg+=HIG"\n$n身上的"+inv[i]->query("name")+HIG"被火焰刀所焚，象片片破布般飘落。\n"NOR;
						   else 
							msg+=HIG"\n$n身上的"+inv[i]->query("name")+HIG"早被烧得只剩下几块破布，再受此一击，顿时化为了飞灰。\n"NOR;
                           inv[i]->unequip();
                           destruct(inv[i]);
                       }
                    }
                 }
              }
			  if (makeash)
			  {
				ash = new("/clone/cloth/ash-cloth");
				ash->move(target);
				ash->wear();
			  }			  
              if(armor) {
                   qi_wound=qi_wound*4/5;
                   neili_wound=neili_wound*4/5;
              }
              if(neili_wound > 2000) neili_wound = 2000 + (neili_wound -2000)/10;
			  if(neili_wound > target->query("neili")) neili_wound = target->query("neili");
              target->add("neili", -neili_wound);
              if(qi_wound > 4800) 
			  {
				  if (pflv >= 3) rate = 10 + pflv*2 + random(pflv*2);
				  else rate = 10;
				  qi_wound = 4800 + rate * (qi_wound-4800)/ 100;				  
			  }
              F_KUNGFU->hit_wound("qi", qi_wound, random(qi_wound*3/4), me, target);

              target->set_temp("death_cond_origin/hyd_condition", me);
			  target->apply_condition("hyd_condition", (me->query_skill("huoyan-dao")/20)
                    + 1 + target->query_condition("hyd_condition"));
              me->add("neili",-300-random(200));
              if(me->query("neili") < 0)
              me->set("neili",0);
              me->start_busy(random(3)+1);
              if ( !target->is_busy() )
                target->start_busy(1);
              me->set_temp("xs/fail",0);
              me->start_perform(5,"「焚」");
        }
        else {
              msg = HIC "\n$n急忙忙从火中跃起，嗤的一声，头发还是被掌风带到，削断了几百根，被吓得脸色苍白\n"NOR;
              me->add("neili",-150);
              me->start_busy(random(3)+1);
              me->start_perform(3,"「焚」");
              me->add_temp("xs/fail",1);
              me->set_temp("xs/failed", target->query("id"));
        }
        message_vision(msg, me, target);
        if(qi_wound > 0){
                msg = COMBAT_D->damage_msg(qi_wound,"割伤");
                msg = replace_string( msg, "$l", "胸口" );
                msg = replace_string( msg, "$w", "掌气" );
                message_vision(msg,me,target);
        }
        COMBAT_D->report_status(target);
        return 1;
}

