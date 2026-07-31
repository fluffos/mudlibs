// 杀意心法
// 青云(diabio)编于2001年版权所有
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
          int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("shayi", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("shayi-xinfa", 1);

	if ( me->query("gender") == "无性" && nh > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的杀意心法。\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("你的杀意不够，无法体会更高深的杀意心法。\n");

	if ( nf < 20)
		return notify_fail("你的基本内功火候还不够，无法领会杀意心法。\n");

if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("mizong-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1) )
		return notify_fail("杀意心法最忌讳一心两用！\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("杀意心法只能用学(learn)的来增加熟练度。\n");
}

void skill_improved(object me)
{
        switch (me->query_skill("shayi-xinfa",1))
        {
                case 50:
                {
                        message_vision(HIY "$N眼中精过一闪，看来杀意心法又有所提高了。\n" NOR, me);
      tell_object(me, HIY "由于你的勤学苦练，你可以发出神足的内息了！！\n\n" NOR);
                        me->set("shayi-xinfa",1);
                        break;
                }
                case 100:
                {
                        message_vision(HIC "$N眼中寒光不停的闪动，杀意弥漫你简直无法呆在这里了。\n" NOR, me);
      tell_object(me, HIC "由于你对杀意心法的领悟，你可以随心所欲的使出[杀意]了！！\n\n" NOR);
                         me->set("shayi-xinfa/2",1);
                        break;
                }
                case 200:
                {
                        message_vision(HIW "$N身上散发出一阵又一阵的杀意，令人心头一颤，看来$N的杀意心法已经到了最高境界了。\n" NOR, me);
                        tell_object(me, HIW "由于你的勤学苦练，你的杀意心法可以用来救人了！！\n\n" NOR);
                         me->set("shayi-xinfa/3",3);
                        break;
                }

        }
        return;
}

string exert_function_file(string func)
{
        return __DIR__"shayi-xinfa/" + func;
}

