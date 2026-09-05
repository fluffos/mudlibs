// written by cuer
inherit SKILL;
string *dodge_msg = ({
	"只见$n一招「阴阳箭」，长身而起，身体向上笔直地飘起丈余，躲过了$N这一招。\n",
	"$n一个「凤点头」，身形一矮，向后滑出数丈之远，避开了$N的凌厉攻势。\n",
	"$n使出「天地钩」，往后一仰身，一个漂亮的空翻，飘落在地。\n",
        "$n一声轻笑，使出「风摆柳」,单足点地，身影飘忽不定，闪开了$N的凌厉攻势。\n",
        "$n傲然一笑，使出「鹰爪松」，身子飘逸如松，使$N的攻势落空了。\n",
        "$n一声长啸，一招「日月扣」，旋身而起，避过$N的攻势轻轻落在$N的背后。\n",
});
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }
int valid_learn(object me) 
{ 
  if (me->query("class")!="bonze" 
  	&& me->query("chushi/last_family")!="峨嵋派" 
  	&& (int)me->query_skill("zhutian",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
  return 1; 
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{       
        if (me->query("class")!="bonze" 
        	&& me->query("chushi/last_family")!="峨嵋派" 
        	&& (int)me->query_skill("zhutian",1) >99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练诸天化身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}
