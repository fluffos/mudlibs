#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":		HIR"日月神刀"NOR,               
                "quest_type":           "寻",
                "time":  		600,
                "score"	:		20
        ]),
        ([      "quest":                HIG"日月神剑"NOR,
                "quest_type":           "寻",
                "time":                 600,
                "score" :               20
        ]),
        ([      "quest":                "灭绝师太",
                "quest_type":           "杀",
                "time":                 1000,
                "score" :               20
        ]),
        ([      "quest":                "菩提子",
                "quest_type":           "寻",
                "time":                 1000,
                "score" :               25
        ]),
        ([      "quest":                "《广陵散》",
                "quest_type":           "寻",
                "time":                 1200,
                "score" :               15
        ]),       
        ([      "quest":                "玄难大师",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               18
        ]),  
        ([      "quest":                "渡厄",
                "quest_type":           "杀",
                "time":                 1200,
                "score" :               22
        ]),
        ([      "quest":                "宋远桥",
                "quest_type":           "杀",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "岳不群",
                "quest_type":           "杀",
                "time":                 700,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
