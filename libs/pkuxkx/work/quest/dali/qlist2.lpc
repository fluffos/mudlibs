#include <ansi.h>

inherit SKILL;

mapping *quest = ({
      ([        "quest":                HIG"玄铁剑"NOR,
                "quest_type":           "寻",
                  "time":                 240,
                "score" :               10,
                "reason" :              "希望遍阅天下利刃，\n"
        ]),
          ([      "quest":            GRN"玉竹杖"NOR,
                "quest_type":           "寻",
                 "time":                 180,
                "score" :               6,
                "reason" :              "希望遍阅天下利刃，\n"
        ]),
        ([      "quest":                "金刚罩",
                "quest_type":           "寻",
                "time":                 600,
                "score" :               9,
                "reason" :              "方丈需要金刚罩，"
        ]),
        ([      "quest":                "伏魔刀",
                "quest_type":           "寻",
                "time":                 600,
                "score" :               9,
                "reason" :              "希望遍阅天下利刃，\n"
        ]),
        ([      "quest":                "拂尘",
                "quest_type":           "寻",
                 "time":                 180,
                "score" :               5,
                "reason" :              "希望遍阅天下利刃，\n"
        ]),

        ([      "quest":                "圣火令",
                "quest_type":           "寻",
                "time":                 600,
                "score" :               10,
                "reason" :              "希望遍阅天下利刃，\n"
        ]),

        ([      "quest":                HIY"七星剑"NOR,
                "quest_type":           "寻",
                "time":                 600,
                "score" :               9,
                "reason" :              "希望遍阅天下利刃，\n"
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
