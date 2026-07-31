// poison.c 基本毒技
// Modified by Java Mar.1998
inherit SKILL;

void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
        if (!myfam)
return notify_fail("你不是星宿，或五毒教弟子，不能修炼毒技。\n");
    if (!myfam || (myfam["family_name"] != "星宿派") && (myfam["family_name"] != "五毒教"))
       return notify_fail("你不是星宿，或五毒教弟子，不能修炼毒技。\n");

    if ((me->query_skill("taoism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1) ||
        (me->query_skill("buddhism",1) > 1))
        return notify_fail("哈哈！"+RANK_D->query_respect(me)
      +"已经学了名门正派的心法，怎么却来学你们不耻的毒技？\n");

    return 1;
}
void skill_improved(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
        if (!myfam)
return notify_fail("你不是星宿，或五毒教弟子，不能修炼毒技。\n");
    if ((me->query_skill("poison",1) == 50) ||
        (me->query_skill("poison",1) == 60) ||
        (me->query_skill("poison",1) == 70) ||
        (me->query_skill("poison",1) == 80) ||
        (me->query_skill("poison",1) == 90) ||
        (me->query_skill("poison",1) >= 100))
    {
if (myfam["family_name"] == "星宿派")
{
        me->apply_condition("poison_sandu",300);
        tell_object(me, "你体内的毒质开始反噬自身了，得找人散毒了。\n");
}
    }
}

