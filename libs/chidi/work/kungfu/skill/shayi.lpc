// shayi.c 杀意
// 青云(diabio)编于2001年版权所有

inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }

int valid_learn(object me)
{
    int lvl;

    lvl = (int)me->query_skill("shayi", 1);

    if( (int)me->query("shen") < 0 )
   return notify_fail("你的邪气太重，无法领悟杀意。\n");

    if(me->query("gender") == "无性" && lvl > 39)
   return notify_fail("你领悟一会儿，便觉双腿发软，原来你没有阳刚之
气，如何能领悟杀意。\n");

       if(me->query_skill("shayi",1)>100)
        	return notify_fail("你现在只能通过领悟来提高杀意了。\n");

    if ((me->query_skill("poison",1) > 1))
   return notify_fail("哈哈！"+RANK_D->query_respect(me)
      +"已经学了邪道的毒技，何必来领悟杀意？\n");

    return 1;
}

int practice_skill(object me)
{
    return notify_fail("杀意只能靠领悟来提高。\n");
}

