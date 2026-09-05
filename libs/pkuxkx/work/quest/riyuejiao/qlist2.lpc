#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":		"岳不群",               
                "quest_type":           "杀",
                "time":  		500,
                "score"	:		10
        ]),
        ([      "quest":                "岳不群",
                "quest_type":           "杀",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "岳不群",
                "quest_type":           "杀",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "韦春芳",
                "quest_type":           "杀",
                "time":                 400,
                "score" :               10
        ]),
        ([      "quest":                "慧真尊者",
                "quest_type":           "杀",
                "time":                 900,
                "score" :               15
        ]),       
        ([      "quest":                "游龙剑",
                "quest_type":           "寻",
                "time":                 500,
                "score" :               8
        ]),  
       ([     	"quest":               	"金花",
                "quest_type":           "寻",
                "time":                 800,
                "score" :               6
        ]),
       ([     	"quest":               	MAG "马屁宝典" NOR,
                "quest_type":           "寻",
                "time":                 300,
                "score" :               6
        ]),
        ([      "quest":                YEL"射雕英雄传"NOR,
                "quest_type":           "寻",
                "time":                 800,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
