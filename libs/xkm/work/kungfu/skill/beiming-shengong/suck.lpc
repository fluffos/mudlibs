//Cracked by Kafei
// 9/18/01 Xuanyuan
// suck.c  北冥神功suck
// modified by xuanyuan to add restrict eunuch use force 10/31/2001
/*
    段誉指着他身后，微笑道：“我一位师父早已站在你的背后……”南海
鳄神不觉背后有人，回头一看。段誉陡然间斜上一步，有若飘风，毛手毛脚
的抓住了他胸口‘膻中穴’，大拇指对准了穴道正中。这一下手法笨拙之极，
但段誉身上蕴藏了无量剑七名弟子的内力，虽然不会运用，一抓之下，劲道
却也不小。南海鳄神只感胸口一窒，段誉左手又已抓住他肚脐上的‘神阙穴’。
‘北冥神功’卷轴上所绘经脉穴道甚多，段誉只练过手太阴肺经和任脉两图，
这‘膻中’、‘神阙’两穴，正是任脉中的两大要穴。
    南海鳄神一惊之下，急运内力挣扎，突觉内力自膻中空急泻而出，全身
便似脱力一般，更是惊慌无已。段誉已将他身子倒举起来，头下脚上的摔落，
腾的一声，他一个秃秃的大头撞在地下。幸好花厅中铺着地毯，并不受伤，
他急怒之下，一个‘鲤鱼打挺’，跳起身来，左手便向段誉抓去。
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp, i;
        int my_max, my_max2, tg_max;
        int ms_factor;

        my_max = me->query("max_neili");
        tg_max = target->query("max_neili");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || target == me 
        || target->query("id") == "mu ren" 
        || target->query("id") == "shangshan"
        || target->query("id") == "mengzhu"
        || target->query("id") == "fae" )
                return notify_fail("你要吸取谁的丹元？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过丹元！\n");

        if( objectp(me->query_temp("weapon"))&& me->query_skill("beiming-shengong",1) < 120)
                return notify_fail("你的北冥神功功力不够，必须空手才能施用北冥神功吸人丹元\n");

        if( !me->is_fighting() || !target->is_fighting() || !living(target) )
                return notify_fail("你必须在战斗中才能吸取对方的丹元！\n");

        if( (int)me->query_skill("beiming-shengong",1) < 90 )
                return notify_fail("你的北冥神功功力不够，不能吸取对方的丹元！n");

		if (me->query_skill("hunyuan-yiqi",1)			//少林
			|| me->query_skill("huntian-qigong",1)		//丐帮
			|| me->query_skill("taiji-shengong",1)		//武当
			|| me->query_skill("zixia-shengong",1)		//华山
			|| me->query_skill("linji-zhuang",1)		//娥眉
			|| me->query_skill("hamagong",1)			//白驼
			|| me->query_skill("huagong-dafa",1)		//星宿
			|| me->query_skill("bitao-xuangong",1)		//桃花
			|| me->query_skill("yunu-xinjing",1)		//古墓
			|| me->query_skill("wudu-xinfa",1)			//古墓
			|| me->query_skill("longxiang-banruo",1)	//雪山
			|| me->query_skill("xiantian-gong",1)		//全真
			|| me->query_skill("dulong-dafa",1)			//神龙
			|| me->query_skill("douzhuan-xingyi",1)		//慕容
			|| me->query_skill("shenghuo-xuanming",1)	//明教
			|| me->query_skill("kurong-changong",1))	//大理
		{
		write("你不先散了别派内功，没法运用北冥神功吸取对方的丹元！\n");
		return 1; }

		if ( me->query("gender") == "无性" )
				return notify_fail("你无根无性，阴阳不调，难以运用北冥护体神功吸人丹元。\n");

        if( (int)me->query("neili",1) < 50 )
                return notify_fail("你的内力不够，不能使用北冥神功。\n");

        if( (int)target->query("max_neili") < 100
         || (int)target->query("max_jingli") < 100
                        || (int)target->query("jingli") < (int)target->query("max_jingli") / 2 )
                return notify_fail( target->name() +
                        "丹元涣散，功力未聚，你无法从他体内吸取任何东西！\n");

         if( (int)target->query("neili") < 100 )
                 return notify_fail( target->name() +
                         "内力涣散，功力未聚，你无法从他体内吸取任何东西！\n");
/*
        if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
                return notify_fail( target->name() +
                        "的内功修为远不如你，你无法从他体内吸取丹元！\n");
*/
        message_vision(
                HIY "$N陡然间斜上一步，有若飘风，大拇指对准了$n胸口‘膻中穴’按了上去！\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query_kar();
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query_kar();
        sp *= me->query("combat_exp")/1000;
        dp *= target->query("combat_exp")/1000;
        
        me->set_temp("sucked", 1);

        if( random(sp) > random(dp) )
        {
                message_vision(
                        HIR "$N一惊之下，急运内力挣扎，突觉内力自膻中空急泻而出，全身便似脱力一般！\n\n" NOR,
                        target );

        if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		{
                tell_object(me, HIG "你觉得" + target->name() + "的内力自手掌源源不绝地流了进来。\n" NOR);

                target->add("neili", -1*(int)me->query_skill("force") );
                me->add("neili", 2*((int)me->query_skill("force")));
        }
          else {
                tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);

                i = random (2);
                  switch (i) {
                  case 0:
                target->add("max_neili",  -1*(1+(me->query_skill("force")-90)/10) );
                me->add("max_neili",       1*(1+(me->query_skill("force")-90)/10) );
        break;
        case 1:
                target->add("max_jingli", -1*(1+(me->query_skill("force")-90)/10) );
                target->add("eff_jingli", -1*(1+(me->query_skill("force")-90)/10) );
                me->add("eff_jingli",       1*(1+(me->query_skill("force")-90)/10) );
                if (me->query("max_jingli") < me->query_skill("force") * 8)
                me->add("max_jingli",       1*(1+(me->query_skill("force")-90)/10) );
        break;
        }
        }
                me->add("potential",  me->query_skill("force", 1)/7);
                me->add("combat_exp", me->query_skill("force", 1)/20);
                if (me->query("potential") > me->query("max_potential"))
                    me->set("potential", me->query("max_potential"));
                me->start_busy(2+random(6));
                target->add("jingli", -random(50));
                target->start_busy(random(3));
                me->add("neili", -25);
                me->add("jingli", -5);
                call_out("del_sucked", 10, me);
        }
        else
        {
                message_vision(HIY "可是$p看破了$P的企图，机灵地溜了开去。\n" NOR, me, target);
                me->add("jingli", -5);
                me->start_busy(6);

                if (target->query("neili") < target->query("jiali")){
                COMMAND_DIR"std/halt"->main(target);
                for (i=0; i<=1+random(5); ++i)
                target->random_move();
                        if (!mapp(environment(target)->query("exits")))
                        target->return_home(target->query("startroom"));
                }

                call_out("del_sucked", 15, me);
        }

// prevent XX dizi's unreasonably high max neili by trying not logout.
// Allow them a little bit higher than limit (*10)
        my_max = me->query_skill("force") * me->query("con") * 4 / 3 ;
        my_max2 = me->query_skill("force") * me->query("con") / 2 ;
        if (me->query("max_jingli") > my_max2)
                me->set("max_jingli", my_max2);
        if (me->query("eff_jingli") > my_max2)
                me->set("eff_jingli", my_max2);
        if (me->query("max_neili") > my_max)
                me->set("max_neili", my_max);

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked") )
        me->delete_temp("sucked");
}

