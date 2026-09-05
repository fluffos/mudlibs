// wushuang.c 无双无对，宁氏一剑
// 新增华山pfm Zine
#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int ObtainLayer()
{
    int n = random(100);
    if (n < 50)
        return 1;
    else if (n < 75)
        return 2;
    else if (n < 88)
        return 3;
    else if (n < 95)
        return 4;
    else
        return 5;
}

string pfm_msg(int type, int NoH, int NoT)
{
    string * head,*tail;
    if (type == 1) //continuous attack
    {
        head = ({"$N大喝一声，","突然之间，$N怒吼一声，","刹那之间，$N"});
        tail = ({"招式如泼水般攻出。","剑招连环递出。","已经攻出数招，让人目不暇接。"});
    }
    if (type == 2) //busy
    {
        head = ({"$N默念剑诀，","攻守之间，$N招式突变，","$N左一剑又一剑，看似全无章法，"});
        tail = ({"$n顿时觉得出招格外艰难。","$n神色大变，不知所措。","将$n招式罩得严严实实。"});
    }
    if (type == 3) //chemical
    {
        head = ({"$N潜运剑意，","$N突然神色凝重，招式变慢，","$N一身清啸，"});
        tail = ({"长剑毫不停歇，直刺向$n。","$n被剑意所指，心中微凛。","一剑劈向$n。"});
    }
    return "\n\n" + head[NoH] + tail[NoT] + "\n" + HIC + "正是华山派绝技——『无双无对』。\n"NOR;
}

string Chinese_Desc(int type, int typeNo, int flag, int lv)
{
    string *C_lv = ({"戊","丁","丙","乙","甲","超","超上"}), *C_type = ({"连击","压制","重击"}), *C_subType1 = ({"连击数","提升档次"}),
       *C_subType2 = ({"命中概率","压制时长"}), *C_subType3 = ({"命中概率","击中效果"});
    if (type == 1) //返回类型
        return HIR + C_type[typeNo - 1] + NOR + "类绝技";
    else if (type == 2) //返回层次
        return HIY + C_lv[lv - 1] + "等" + NOR;
    else
    {
        if (typeNo == 1)
            return CYN + C_subType1[flag] + NOR;
        if (typeNo == 2)
            return CYN + C_subType2[flag] + NOR;
        if (typeNo == 3)
            return CYN + C_subType3[flag] + NOR;
    }
}

int increase_wushuang(object me, int inc_TYPE)
{
    int *layers;
    if (!me->query("huashan_newskills/wushuang") || !arrayp(me->query("huashan_newskills/wushuang"))
        || sizeof(me->query("huashan_newskills/wushuang")) != 5)
    {
        tell_object(me, "你根本还不会无双无对，不能提升。\n");
        return 1;
    }
    if (inc_TYPE != 1 && inc_TYPE != 2)
        return 0;
    layers = me->query("huashan_newskills/wushuang");
    if (layers[inc_TYPE] > 6 || (layers[inc_TYPE] > 4 && !me->query("huashan_newskills/wushuang_highStart")))
    {
        tell_object(me, "你的『无双无对』在" + Chinese_Desc(-1, layers[0], inc_TYPE - 1, -1) + "方面已经达到了巅峰。\n");
        return 1;
    }

    layers[inc_TYPE] += 1;
    me->set("huashan_newskills/wushuang", layers);
    me->add("huashan_newskills/wushuang_inc", 1);
    message_vision(HIC"$N" + HIC + "的剑法绝招无双无对获得了提升。\n" + NOR, me);
    tell_object(me, "你的『无双无对』在" + Chinese_Desc(-1, layers[0], inc_TYPE - 1, -1) + "方面提升为" + Chinese_Desc(2, -1, -1, layers[inc_TYPE]) + "。\n");
    return 1;
}

int create_wushuang(object me)
{
    // customized pfm storing in query("huashan_newskills/wushuang")
    // if type=1 ({1,hits,buff,msg1,msg2}) type 1.continuous attack 2.busy 3.chemical
    // if type=2 ({2,busy_rate,busy_time,msg1,msg2})
    // if type=3 ({3,hit_rate,damage_basevalue,msg1,msg2})
    // msg is pfm message.
    // for making clear, layer is used to refer level of customized pfm.
    // hits Range 2-6 , layers 1,2,3,4,5 refer them respectively, buff has an interval of query_skill("sword",1)/10, the buff lvl increases an interval. e.g buff lv 2 will buff player with query_skill("sword",1)/10*2, both on attack and damage but only effect on the instant hit.
    // busy_rate and chemical attack hit_rate all come from feature/kungfu layers 1,2,3,4,5 mean 11,9,7,5,4 hit rates.
    // busy time 1,2,3,4,5, has an interval as query_skill("huashan-jianfa",1)/50, will increase one as busy_time lv increases.
    // chemical attack damage ranges between 1 to 5, the base value should be query_skill("huashan-jian",1)/5+random(query_skill("sword",1)/5),layers 4,3 will be 2 hits and 2 and 1 will be 3 hits.
    // each of all the six parameters retains 6 and 7 layer. increasing by random(2) or 1 lv.
    int type, n = random(100), rate, BaseValue, msg1, msg2; // right here,rate/BaseValue store hits and buff for continuous attack.
    if (n < 40)
        type = 1;
    else if (n < 70)
        type = 2;
    else
        type = 3;
    rate = ObtainLayer();
    BaseValue = ObtainLayer();
    msg1 = random(3);
    msg2 = random(3);
    me->set("huashan_newskills/wushuang", ({type, rate, BaseValue, msg1, msg2}));
    if (rate > 4 || BaseValue > 4 || rate + BaseValue > 7)
        me->set("huashan_newskills/wushuang_highStart", 1);
    me->save();
    tell_object(me, HIC"在战斗中，你忆及先贤，似乎有所悟。\n"NOR);
    CHANNEL_D->do_channel(load_object(CHANNEL_D), "jh", HIR + "听说" + me->query("name") + HIR + "在" + environment(me)->query("short") + HIR + "悟出了华山派前代绝技『无双无对』。\n" + NOR, -1);
    //Chinese_Desc(int type,int typeNo,int flag,int lv)
    tell_object(me, "你的『无双无对』是" + Chinese_Desc(1, type, -1, -1) + "类绝技，" + Chinese_Desc(-1, type, 0, -1) + "：" + Chinese_Desc(2, -1, -1, rate) + "，" + Chinese_Desc(-1, type, 1, -1) + "：" + Chinese_Desc(2, -1, -1, BaseValue) + "。\n");
    return 1;
}

int perform(object me, object target)
{
    int type, rate, BaseValue, msg1, msg2, *rates = ({11,9,7,5,4,4,3}), hitrate, pflv;
    string pfm_msg;
    object weapon = me->query_temp("weapon");
    mapping attack_val = ([
                          "base" : ([ "weapon" : "sword" ]), //基本功夫类型
                           "skill" : ([ "weapon" : "yunushijiu-jian", ]), //高级技能名称
                           ]);

    if (me->query("combat_exp") < 100000000)
        return 0;
	if (me->query("family/family_name")!="华山派"&&me->query("chushi/last_family")!="华山派") return 0;
    if (!me->query("huashan_newskills/wushuang") || !arrayp(me->query("huashan_newskills/wushuang"))
        || sizeof(me->query("huashan_newskills/wushuang")) != 5)
        return create_wushuang(me);

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("『无双无对，宁氏一剑』只能对战斗中的对手使用。\n");

    if (!weapon || weapon->query("skill_type") != "sword" )
/*        || me->query_skill_mapped("sword") != "huashan-jianfa") */
        return notify_fail("你手中无剑怎能使用『无双无对，宁氏一剑』？！\n");

    if ( (int)me->query_skill("huashan-neigong", 1) < 600
        && (int)me->query_skill("zixia-shengong", 1) < 600 )
        return notify_fail("你的华山内功火候未到，无法施展『无双无对，宁氏一剑』！\n");

    if (me->query_skill("dodge") < 600)
        return notify_fail("『无双无对，宁氏一剑』需要超绝的轻功配合，方能有效施展！\n");

    if (me->query("neili") <= 500)
        return notify_fail("你的内力不够使用『无双无对，宁氏一剑』！\n");

    if (me->query("max_neili") <= 8000)
        return notify_fail("你的内力修为不够使用『无双无对，宁氏一剑』！\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "华山派")	pflv = 0;

    type = me->query("huashan_newskills/wushuang")[0];
    rate = me->query("huashan_newskills/wushuang")[1];
    BaseValue = me->query("huashan_newskills/wushuang")[2];
    msg1 = me->query("huashan_newskills/wushuang")[3];
    msg2 = me->query("huashan_newskills/wushuang")[4];
    pfm_msg = pfm_msg(type, msg1, msg2);
    message_vision(pfm_msg, me, target);
    if (wizardp(me))
        tell_object(me, "Type:" + type + "Rate:" + rate + "BaseValue:" + BaseValue + "\n");
    if (type == 1)
    {
        rate += 1;
        BaseValue *= me->query_skill("sword", 1) / 6;
		if (pflv>0)
			BaseValue += BaseValue/10 + random(BaseValue/5);
        message_vision(CYN"$N" + CYN + "一连向$n" + CYN + "攻出" + chinese_number(rate) + "招。\n" + NOR, me, target);
        for (int i = 0; i < rate; i++)
        {
            me->add_temp("apply/attack", BaseValue);
            me->add_temp("apply/damage", BaseValue);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            me->add_temp("apply/attack", -BaseValue);
            me->add_temp("apply/damage", -BaseValue);
        }
        me->start_busy(2);
    }
    if (type == 2)
    {
        if (target->is_busy())
        {
            tell_object(me, "放胆进攻吧，" + target->name() + "正忙着呢。\n");
            return 1;
        }
        hitrate = rates[rate - 1];
        if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), hitrate, me, target))
        {
            message_vision(CYN"$N" + CYN + "被$n" + CYN + "招式所惑，出招渐感凝滞。\n" + NOR, target, me);
            F_KUNGFU->hit_busy("confuse", BaseValue * me->query_skill("yunushijiu-jian", 1) / 85, target);
        }
        else
        {
            message_vision(WHT"$N" + WHT + "丝毫不为$n" + WHT + "所惑。\n" + NOR, target, me);
            me->start_busy(2);
		}
    }
    if (type == 3)
    {
        hitrate = rates[rate - 1];
        BaseValue *= me->query_skill("yunushijiu-jian", 1) / 3 + random(me->query_skill("sword", 1) / 2);
		if (pflv>0)
			BaseValue += BaseValue/10 + random(BaseValue/5);
        if (F_KUNGFU->hit_rate(me->query_skill("sword"), target->query_skill("parry"), hitrate, me, target))
        {
            message_vision(CYN"\n$N" + CYN + "一招正中$n" + CYN + "胸前要穴。\n" + NOR, me, target);
            F_KUNGFU->hit_wound("qi", BaseValue, BaseValue / (3 + random(2)), me, target);
            COMBAT_D->report_status(target);
        }
        else
        {
            message_vision(WHT"\n$N" + WHT + "堪堪避过$n" + WHT + "充满威势的这一招。\n" + NOR, target, me);
        }
        if (rate > 1)
        {
            if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), hitrate, me, target))
            {
                message_vision(CYN"\n$N" + CYN + "一招正中$n" + CYN + "胸前要穴。\n" + NOR, me, target);
                F_KUNGFU->hit_wound("qi", BaseValue * 2 / 3, BaseValue / 3, me, target);
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(WHT"\n$N" + WHT + "堪堪避过$n" + WHT + "充满威势的这一招。\n" + NOR, target, me);
				me->start_busy(random(2));
            }
        }
        if (rate > 3)
        {
            if (F_KUNGFU->hit_rate(me->query_skill("sword"), target->query_skill("parry"), hitrate, me, target))
            {
                message_vision(CYN"\n$N" + CYN + "一招正中$n" + CYN + "胸前要穴。\n" + NOR, me, target);
                F_KUNGFU->hit_wound("qi", BaseValue, BaseValue / 3, me, target);
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(WHT"\n$N" + WHT + "堪堪避过$n" + WHT + "充满威势的这一招。\n" + NOR, target, me);
            }
        }
        if (rate > 5 && (rate == 7 || random(2)))
        {
            if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), hitrate, me, target))
            {
                message_vision(CYN"\n$N" + CYN + "一招正中$n" + CYN + "胸前要穴。\n" + NOR, me, target);
                F_KUNGFU->hit_wound("qi", BaseValue, BaseValue / 2, me, target);
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(WHT"\n$N" + WHT + "堪堪避过$n" + WHT + "充满威势的这一招。\n" + NOR, target, me);
            }
        }
        me->start_busy(2);
    }
	me->add("neili", -(50+BaseValue/40)); //内力基础消耗
    return 1;
}

