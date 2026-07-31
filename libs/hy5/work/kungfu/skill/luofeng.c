// 落风六式    luofeng.c
//   created by qyz on Feb 4, 1997

inherit SKILL;
string *dodge_msg = ({
    "$n纵身一跃，一个「鹞子翻身」，闪身躲了开去。\n",
    "$n猛的一个「神龙摆尾」，向后跳开数尺。\n",
    "$n双脚轻点，一个「白鹤冲天」，身形向上蹿起数尺。\n",
    "$n轻飘飘地向旁边一闪，$N的凌厉攻势尽数落在了空里。\n",
    "$n向高空里一纵身，跃起五尺来高。\n",
    "$n跃向空中，一招「蜻蜓点水」，从$N头上跃了过去。\n",
    "只见$n身随意转，一招「浮云无定」，倏地往一旁挪开了三尺，避过了$N这一招。\n",
    "$n使出一招「轻舟泛月」，向一旁飘然纵出，轻轻着地。\n",    
    "$n身形微晃，一招「落日浮云」，有惊无险地避开了$N这一招。\n",    
    "$n漫不经心的向左一个「日落沙明」，刚好避过$N的凌厉攻势。\n",   
    "$n身形向后一纵，使出一招「落叶秋风」，避过了$N的攻击。\n",  
    "可是$n使一招「风飘落日」，身子轻轻飘了开去。\n",           
});
mapping *action = ({
  ([ "action":"$n纵身一跃，一个「鹞子翻身」，闪身躲了开去。",
       "lian"  :"$N提气在胸，收腹提肩，一个「鹞子翻身」，高高跃起。",
       "jibie" :5,
       "sen"   :2, ]),
    ([ "action":"$n猛的一个「神龙摆尾」，向后跳开数尺。",
       "lian"  :"$N足下一蹬，一个「神龙摆尾」向后退去，险些扭伤了足踝。",
       "jibie" :10,
       "sen"   :2, ]),
    ([ "action":"$n双脚轻点，一个「白鹤冲天」，身形向上蹿起数尺。",
       "lian"  :"$N双足一点，一个「白鹤冲天」，蹿起三尺来高。",
       "jibie" :20,
       "sen"   :2, ]),
    ([ "action":"$n轻飘飘地向旁边一闪，$N的凌厉攻势尽数落在了空里。",
       "lian"  :"$N把握住身体的平衡，借着踢腿的力量，向旁边一跃。",
       "jibie" :30,
       "sen"   :3, ]),
    ([ "action":"$n向高空里一纵身，跃起五尺来高。",
       "lian"  :"$N向高空里一纵身，跃起五尺来高。",
       "jibie" :40,
        "sen"  :3, ]),
    ([ "action":"$n跃向空中，一招「蜻蜓点水」，从$N头上跃了过去。",
       "lian"  :"$N跃起五尺，一招「蜻蜓点水」，轻轻落下地来。",
       "jibie" :50,
       "sen"   :3, ]),
        ([     
                "action":               
"只见$n身随意转，一招「浮云无定」，倏地往一旁挪开了三尺，避过了$N这一招。",
                "lian" :
"$N身随意转，一招「浮云无定」，倏地往一旁挪开了三尺。",
                "jibie":          8,
                "sen"  :      5,
        ]),
        ([      "action":
"$n使出一招「轻舟泛月」，向一旁飘然纵出，轻轻着地。",
                "lian" :
"$N使出一招「轻舟泛月」，向一旁飘然纵出，轻轻着地。",
                "jibie":15,
                "sen"  :5,
        ]),
        ([      
                "action":               
"$n身形微晃，一招「落日浮云」，有惊无险地避开了$N这一招。",
                "lian" :
"$N身形微晃，一招「落日浮云」，向一边闪去。",
                "jibie":25,
                "sen"  : 5,
        ]),
        ([    
                "action":               
"$n漫不经心的向左一个「日落沙明」，刚好避过$N的凌厉攻势。",
                "lian" :
"$N漫不经心的向左一个「日落沙明」飘了过去。",
                "jibie":33,
                "sen"  : 5,
        ]),
        ([      
                "action":               
"$n身形向后一纵，使出一招「落叶秋风」，避过了$N的攻击。",
                "lian" :
"$N身形向后一纵，使出一招「落叶秋风」，退后丈馀。",
                "jibie":40,
                "sen"  : 6,
        ]),
        ([      
                "action":               
"可是$n使一招「风飘落日」，身子轻轻飘了开去。",
                "lian" :
"$N使一招「风飘落日」，身子轻轻向后飘了开去。",
                "jibie":50,
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
            return notify_fail("你的体力太差了，不能练翩仙步法。\n");

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
        return __DIR__"luofeng/" + action;
}