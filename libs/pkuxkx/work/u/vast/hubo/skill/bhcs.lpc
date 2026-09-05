// bhcs.c 碧海潮声曲

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage;
          if (me->query_skill_mapped("force") != "bihai-shengong"
|| me->query_skill("force",1)/2 + me->query_skill("bihai-shengong",1) < 150 )
                return notify_fail("你瞎吹了一通，自己倒搞得头晕脑胀。\n");
     if (me->query_skill("music",1)<100 )
          return notify_fail("你的音律水平还没到家，无法吹奏「碧海潮生曲」。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

        if( environment(me)->query("no_fight") )//防止玩家利用ask huang about bhcs来达到NK的目的---vast注
                return notify_fail("你怎么好意思在如此清静之处吹箫呢？\n");
        if (!objectp(me->query_temp("weapon"))
        || (string)me->query_temp("weapon")->query("id") != "yu xiao")
          return notify_fail("你必须使用玉箫才能吹奏「碧海潮生曲」。\n");
        skill = me->query_skill("force",1)+me->query_skill("music",1);
        me->add("neili", -100);
        me->start_busy(random(5));
        message_vision(
                HIR "突然之间，半空中如鸣琴，如击玉。\n"NOR + HIC "发了几声后，接着悠悠扬扬，飘下一阵清亮柔和的洞箫声来。\n" NOR, me);

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                 if( (skill/2 + random(skill/2))/8 < random((int)ob[i]->query_con() * 2)||random(ob[i]->query("combat_exp"))/3>random(me->query("combat_exp")) ) continue;
                damage = skill+me->query_skill("bihai-shengong",1);
                        ob[i]->receive_wound("qi", damage/3);
                        ob[i]->receive_damage("qi", damage);
                        ob[i]->receive_damage("jing", damage/2);
                        ob[i]->receive_wound("jing", damage/6);
                        ob[i]->start_busy(random(me->query_skill("music",1)/20));
                        tell_object(ob[i],
"你心头一荡，脸上不自禁的露出微笑，只感全身热血沸腾，就只想手舞足蹈的乱动一番，方才舒服。\n");

                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me->query("id")) ) ob[i]->kill_ob(me);
        }

		if(target && target->query_temp("zyhb/bhcs0"))
		{
			target->set_temp("zyhb/bhcs", 1);
			target->delete_temp("zyhb/bhcs0");
			tell_object(target, CYN"这套曲子模拟大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其后洪涛汹涌，白浪
连山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，再加上水妖海怪，群魔弄潮，忽而冰山飘至
，忽而热海如沸，极尽变幻之能事，而潮退后水平如镜，海底却又是暗流湍急，于无声处
隐伏凶险，更令聆曲者不知不觉而入伏，尤为防不胜防。其声由“宫”音起，转而为“角、
羽”之音，最后以“徵”音结尾，你仔细聆听心中暗暗记住了音律的变化。\n\n"NOR);
		}

        return 1;
}
//modify by gudu
/*
这套曲子模拟大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其后洪涛汹涌，白浪
连山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，再加上水妖海怪，群魔弄潮，忽而冰山飘至
，忽而热海如沸，极尽变幻之能事，而潮退后水平如镜，海底却又是暗流湍急，于无声处
隐伏凶险，更令聆曲者不知不觉而入伏，尤为防不胜防。
*/