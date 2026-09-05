//xueshan-jian.c
// (C)	pingpang 9.2-1997

inherit SKILL;

mapping	* action=({
    ([	"action":"只见$N使出一招「梅雪争春」，手中$w化作漫天雪影，一时之间
                  $n只见身前身后上上下下如春梅片片，笼罩全身",
        "lian"  :"$N身形展动，手中$w急速颤动，只见剑芒点点，使出的正是一招
                  「梅雪争春」。",
        "sen"   :3,
        "jibie" :5,
        "dodge" :10,
        "parry" :10,
        "wound" :10,
        "zhaoshi" : "「梅雪争春」",
        "damage_type":"刺伤"   ]),
    ([  "action":"剑到中途，$N手腕一转，招式又变为「雪花六出」，$w一晃，六道
                  剑气从不同方向向$n急刺过去",
        "lian"  :"$N手腕一动，使出一招「雪花六出」，$w化为数道剑气。",
        "sen"   :3,
        "jibie" :10,
        "dodge" :15,
        "parry" :5,
        "wound" :15,
        "zhaoshi" : "「雪花六出」",
        "damage_type":"刺伤"    ]),
    ([  "action":"不待$n后退半步，$N身形一折，半空中一招「苍松覆雪」，如黑云
                  压顶击向$n，$n只觉四周如铜墙铁壁一样动弹不得",
        "lian"  :"$N高高跃起，手握$w，使出一招「苍松覆雪」，气势慑人，如西楚
                  霸王在世。",
        "sen"   :2,
        "jibie" :18,
        "dodge" :20,
        "parry" :0,
        "wound" :20,
        "zhaoshi" : "「苍松覆雪」",
        "damage_type":"刺伤"    ]),
    ([  "action":"$N身形展动，只见一团银光围着$n越转越快，越转越快，正在$n眼
                  花缭乱之际，$N一招「雪拥云岭」手中$w朝$n万剑攒刺。",
        "lian"  :"$N脚走阴阳，手捏剑诀，一招「雪拥云岭」，手中$w对空一阵攒刺。",
        "sen"   :2,
        "jibie" :25,
        "dodge" :0,
        "parry" :15,
        "wound" :22,
        "zhaoshi" : "「雪拥云岭」",
        "damage_type":"刺伤"    ]),
    ([  "action": "$N深深的吸了一口气，后退一步，手中$w突然间剑光大盛，剑芒
                   之间传出兹兹之声，显然是内力用到了及至，将$n团团围住。",
        "lian"  : "$N不进反退，手中$w化作点点剑光。",
        "sen"   :5,
        "jibie" :80,
        "dodge" :10,
        "parry" :20,
        "wound" :30,    
        "zhaoshi" : "「阳春白雪」", 
        "damage_type" : "刺伤"  ]),    
});

string *parry_msg = ({
    "$n使出一招「梅雪争春」，手中的$v宛如老梅瘦枝，轻轻一动，便化作片片雪花，
       铺天盖地而来，令$N的招式顿时不攻自破。\n",
    "$n使出一招「雪花六出」，手中的$v一声轻啸，荡起了数道剑气，将$N的$w封了
       回去。\n",
    "$n身形一转，反手一招「雪拥云岭」，整个人消失在一团剑光之中，顿时使得$N
       收$w后退自保。\n",
});

int valid_learn(object me)
{
    if ( (int)me->query("dodge") < 30 )
        return notify_fail("你的身法不够，没有办法练雪山剑法。\n");

    if ( (string)me->query("using_force") != "      " )
        return notify_fail("雪山剑法必须配合木式阴骨功才能练。\n");

    return 1;
}

int valid_lian( object me )
{
    object ob;
    ob = me->query_temp("weapon");
    if ( !ob || (string)ob->query("weapon_type") != "sword" )
        return notify_fail("你必须先找一把剑才能练习剑法。\n");

    return valid_learn( me );
}

string query_xiuwei_type() { return "sword"; }   
string query_weapon_type() { return "sword"; }

int query_dengji() { return 2; }

mapping query_action(int jibie)
{
	int i, size;

	size = sizeof( action );
	for ( i = 0; i < sizeof( action ); i++ )
		if ( action[ i ][ "jibie" ] > jibie )
		{
			size = i;
			break;
		}
    return action[ random( size ) ];
}

string query_parry_msg(object weapon)
{   
    if ( weapon )
        return parry_msg[random(sizeof(parry_msg))];
}

string query_zhaoshi( int jibie )
{
    int i;
    for ( i = 0; i < sizeof(action); i++ )
    {
        if ( action[ i ][ "jibie" ] >= jibie )
            return action[ i ][ "zhaoshi" ];
    }
    return "";
}

int query_youxiao_jibie() { return 10; }

int query_parry_ratio() { return 8 ; }
