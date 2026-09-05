#include <ansi.h>
#include <ansi.h>

inherit SKILL;

mapping *quest = ({
          ([      "quest":                RED"巨莽"NOR,               
                "quest_type":           "杀",
                "time":  		900,
                "score"	:		10
        ]),
        ([      "quest":                "官兵",
                "quest_type":           "杀",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "闻苍松",
                "quest_type":           "杀",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "唐洋",
                "quest_type":           "杀",
                "time":                 900,
                "score" :               10
        ]),       
        ([      "quest":                "游龙剑",
                "quest_type":           "寻",
                "time":                 800,
                "score" :               8
        ]),  
          ([      "quest":                GRN"玉竹杖"NOR,
                "quest_type":           "寻",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "霍都",
                "quest_type":           "杀",
                "time":                 700,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
