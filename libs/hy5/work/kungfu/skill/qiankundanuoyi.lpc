// qingkundanuoyi.c 乾坤大挪移
// modified by Venus Jan.1998

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
   if( (int)me->query("shen") < 0 )
   return notify_fail("你的邪气太重，无法修炼乾坤大挪移。\n");

   if(me->query("gender") == "无性")
   return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之
气，无法领会里面的乾坤阴阳变化之道。\n");

   return 1;
}

int practice_skill(object me)
{
    return notify_fail("乾坤大挪移只能学习得来。\n");
}
