#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "铁手掌",
                "quest_type":           "寻",
                "time":                 60,
                "score" :               2,

        ]),
        ([      "quest":                "旧竹片",
                "quest_type":           "寻",
                 "time":                 120,
                "score" :               4
        ]),


        ([      "quest":                "金创药",
                "quest_type":           "寻",
                 "time":                 60,
                "score" :               4
        ]),
        ([      "quest":                "长剑",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               2
        ]),
        ([      "quest":                "钢刀",
                "quest_type":           "寻",
                "time":                 200,
                "score" :               2
        ]),
        ([      "quest":                "小流氓",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               7
        ]),



});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
