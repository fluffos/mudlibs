#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":		"陆大有",               
                "quest_type":           "杀",
                  "time":         240,
                "score"	:		10
        ]),
        ([      "quest":                "官兵",
                "quest_type":           "杀",
                  "time":         200,
                "score" :               10
        ]),
          ([       "quest":              "谷虚道长",
                "quest_type":           "杀",
                "time":                 400,
                "score" :               10
        ]),
        ([      "quest":                "阿紫",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               10
        ]),
            ([     "quest":        "守山弟子",
                "quest_type":           "杀",
                "time":                 500,
                "score" :               10
        ]),       
        ([      "quest":                "游龙剑",
                "quest_type":           "寻",
                 "time":                 400,
                "score" :               8
        ]),  
         ([      "quest":              GRN"玉竹杖"NOR,
                "quest_type":           "寻",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "霍都",
                "quest_type":           "杀",
                "time":                 400,
                "score" :               10
        ]),
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
