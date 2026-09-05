#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "渡难",
                "quest_type":           "杀",
                "time":  		700,
                "score"	:		20
        ]),
        ([      "quest":                HIG"玄铁剑"NOR,
                "quest_type":           "寻",
                "time":                 450,
                "score" :               12
        ]),
        ([      "quest":                "丁春秋",
                "quest_type":           "杀",
                "time":                 560,
                "score" :               14
        ]),
        ([      "quest":                "黎生",
                "quest_type":           "杀",
                "time":                 550,
                "score" :               11
        ]),
        ([      "quest":                "叫化鸡",
                "quest_type":           "寻",
                "time":                 550,
                "score" :               16
        ]),       
        ([      "quest":                "老鼠肉",
                "quest_type":           "寻",
                "time":                 550,
                "score" :               11
        ]),  
        ([      "quest":                "灭绝师太",
                "quest_type":           "杀",
                "time":                 670,
                "score" :               15
        ]),
        ([      "quest":                "护法袈裟",
                "quest_type":           "寻",
                "time":                 600,
                "score" :               9
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
