//sata-shenfa.c.飒沓身法
//date:1997.9.11
//by dan

inherit SKILL;
string *dodge_msg = ({
"$n一式「银鞍照白马」，身体向上笔直纵起丈余，闪过了$N的凌厉\n",
"$n一式「飒沓如流星」，身形如电，向后纵出数丈远，$N这招扑空了\n",
"$n一式「千里不流行」，足不动，手不抬，倏地往一旁挪开了三尺\n",
"$n一式「事了拂衣去」，拔地而起，在半空中一转，已落到几丈远\n",
"$n身形一转，使出一招「深藏身与名」，一转眼间便绕到了$N的身后\n",
});
mapping *action = ({
        ([     
                "action":               
"$n一式「银鞍照白马」，身体向上笔直纵起丈余，闪过了$N的凌厉",
                "lian" :
"$N一式「银鞍照白马」，身体向上笔直纵起丈余",
                "jibie":10,
                "sen"  :5,
        ]),
        ([      "action":
"$n一式「飒沓如流星」，身形如电，向后纵出数丈远，$N这招扑空了",
                "lian" :
"$N一式「飒沓如流星」，身形如电，向后纵出数丈远，却滑了一下，险些摔倒。",
                "jibie":30,
                "sen"  :5,
        ]),
        ([      
                "action":               
"$n一式「千里不流行」，足不动，手不抬，倏地往一旁挪开了三尺",
                "lian" :
"$N一式「千里不流行」，足不动，手不抬，倏地往一旁挪开了三尺",
                "jibie":50,
                "sen"  :5,
        ]),
        ([    
                "action":               
"$n一式「事了拂衣去」，拔地而起，在半空中一转，已落到几丈远",
                "lian" :
"$N一式「事了拂衣去」，拔地而起，在半空中一转，已落到几丈远",
                "jibie":70,
                "sen"  :5,
        ]),
        ([      
                "action":               
"$n身形一转，使出一招「深藏身与名」，一转眼间便绕到了$N的身后",
                "lian" :
"$N身形一转，使出一招「深藏身与名」，一转眼间便原地绕了一圈",
                "jibie":100,
                "sen"  : 6,
        ]),
});

int valid_learn(object me)
{
    return 1;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("你的体力太差了，不能练飒沓身法。\n");

        return 1;
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}
string perform_action_file(string action)
{
        return __DIR__"sata-shenfa/" + action;
}