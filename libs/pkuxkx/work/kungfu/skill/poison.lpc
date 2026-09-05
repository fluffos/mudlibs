//Cracked by Roath
// poison.c 基本毒技
//modified by vast 2003.2
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)  
{   
  //待添加
 }

int valid_learn(object me)
{
	int lv;
	lv = (int)me->query_skill("poison", 1);

       if ((me->query_skill("taoism",1) > 0) ||
        (me->query_skill("mahayana",1) > 0) ||
        (me->query_skill("daoxue-xinfa",1) > 0) ||
        (me->query_skill("buddhism",1) > 0))
        return notify_fail("哈哈！"+RANK_D->query_respect(me)
      +"已经学了名门正派的心法，怎么却来学你们不耻的毒技？\n");
/*	
	if (me->query("family/family_name") == "白驼山") {
		if ( lv > 100 && me->query("baituo/breed") < lv )
			return notify_fail("你对毒术缺乏实际应用，难以继续提高。\n");
	}

	else {
		if (lv < 101 && lv > 50 && me->query("body_poison") < lv/10)
			return notify_fail("你体内聚毒过多，难以继续提高。\n");
		if (lv > 100 && me->query("body_poison") < lv)
			return notify_fail("你体内聚毒过多，难以继续提高。\n");
	}
*/
	return 1;
}
