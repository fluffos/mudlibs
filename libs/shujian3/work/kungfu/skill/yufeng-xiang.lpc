// yufeng-xiang.c 玉凤翔

inherit SKILL;

string *dodge_msg = ({
    "$n一个「凤凰双飞」，身形随着$N的攻势轻轻飘起，从容躲过这一招。\n",
    "$n使出一招「玉凤穿云」，脚尖一点，身子拔高丈余，结果$N扑了个空。\n",
    "$n身形一摇，幻出无数个人影，一招「百鸟朝凤」躲过了$N的攻势。\n",
    "$n一招「飞凤天翔」纵身跃起，在空中一转，倏忽已落至$N身后。\n",
    "$n左一摇，右一晃，一招「云凤雾凰」已轻松闪过$N的攻击。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge" || usage == "move") ;
}

int valid_learn(object me) 
{ 
  if ( me->query("gender") != "女性")
               return notify_fail("你怎么想来学女子的武功啦？\n");
   return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 35 )
            return notify_fail("你的体力太差了，不能练玉凤翔。\n");       
		me->receive_damage("jingli", 25);
        return 1;
}
