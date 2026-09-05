#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "王五",
                "quest_type":           "杀",
                "time":  		600,
                "score"	:		6
        ]),
        ([      "quest":                "长剑",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "阿紫",
                "quest_type":           "杀",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "欧阳克",
                "quest_type":           "杀",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "铁甲",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                GRN"方天画戟"NOR,
                "quest_type":           "寻",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "红烧狗肉",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "李莫愁",
                "quest_type":           "杀",
                "time":                 650,
                "score" :               9
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
