#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "铁甲",
                "quest_type":           "寻",
                 "time":                 30,
                "score" :               6,
                "reason" :              "需要个铁甲作样板，\n"
        ]),
        ([      "quest":                "钢剑",
                "quest_type":           "寻",
                 "time":                 120,
                "score" :               6,
                "reason" :              "需要一柄钢剑. \n "
        ]),
        ([      "quest":                "游龙剑",
                "quest_type":           "寻",
                  "time":                 500,
                 "score" :               9,
                "reason" :              "我需要游龙剑. \n"
        ]),
        ([      "quest":                "水蜜桃",
                "quest_type":           "寻",
                "time":                 400,
                "score" :               3,
                "reason" :              "现在正是水蜜桃成熟的季节，\n"
        ]),
        ([      "quest":                "华山剑谱",
                "quest_type":           "寻",
                 "time":                 200,
                "score" :               5,
                "season" :              "为博采众家之长，我想看看华山的剑法，"
        ]),
        ([      "quest":                "伊犁马",
                "quest_type":           "寻",
                 "time":                 120,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
