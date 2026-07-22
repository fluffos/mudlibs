#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "»¨»¨¹«×Ó",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "Ìú»¤Ñü",
                "quest_type":           "Ñ°",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "ÇàÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "ÍÁ·ËÍ·",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),
        ([      "quest":                "ËÄÊ®¶þÕÂ¾­Æß",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),
        ([      "quest":                "Ñ²É½µÜ×Ó",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "ä½»¨½£Æ×",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "°×ÒÂÎäÊ¿",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "»ðÕÛ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "Ñò±Þ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "ÒÁÀçÂí",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "Ê¯Áº",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               5
        ]),
        ([       "quest":               "Ì«×ÓÆÂ",
                "quest_type":           "É¨",
                "time":                 500,
                "score" :               6
        ]),
        ([       "quest":               "ÓöÕæ¹¬",
                "quest_type":           "É¨",
                "time":                 360,
                "score" :               6
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

