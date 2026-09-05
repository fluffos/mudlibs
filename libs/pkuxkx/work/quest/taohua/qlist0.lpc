#include <ansi.h>

inherit SKILL;
mapping *quest = ({
        ([      "quest":		"桃花岛内功",               
                "quest_type":           "寻",
                "time":  		200,
                "score"	:		2
        ]),
          ([      "quest":             YEL"铜哨"NOR,
                "quest_type":           "寻",
                "time":                 240,
                "score" :               2
        ]),
        ([      "quest":                "铁手掌",
                "quest_type":           "寻",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "长剑",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               2
        ]),
        ([      "quest":                "珍珠",
                "quest_type":           "寻",
                "time":                 300,
                "score" :               4
        ]),       
        ([      "quest":                "钢刀",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "老农",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               7
        ]),
        ([      "quest":                "民女",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               3
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
