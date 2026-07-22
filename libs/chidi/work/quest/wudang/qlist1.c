#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "È­Æ××Ü¾÷",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "Àî½ÌÍ·",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "¼Ò¶¡",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "¹Ü¼Ò",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "Ð¡Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "ÌË×ÓÊÖ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "²èÊÒ",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "²Ø¾­¸ó",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "ÎèÉßÈË",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ìú¼×",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "¸ÖÕÈ",
                "quest_type":           "Ñ°",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "¿¾Ñ¼",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "µ¶¿Í",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               7
        ]),
        ([      "quest":                "´óÀÇ¹·",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               7
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
