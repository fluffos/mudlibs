// tao.c 道家思想
// By Star

inherit FORCE;

int valid_learn(object me)
{
	if ( me->query_skill("buddha",1)
	|| me->query_skill("confu",1))
		return notify_fail("儒、释、道三家互不相容，你还在信仰别家思想，怎么学习道家理论？！\n");

	return 1;
}