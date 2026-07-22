#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ð¯Ä¦ÖÇ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ÀîÄª³î",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               16
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                HIG"ÊÖïí"NOR,
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               15
        ]),
        ([      "quest":                "ÉÏ¹ÙÔÆ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               18
        ]),
        ([      "quest":                "Ê¨ºð×Ó",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ºÚ°××Ó",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               20
        ]),
        ([      "quest":                "ÃÉº¹Ò©",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¡ºÐÇËÞ¶¾¾­¡¼ÉÏ²á¡½¡»",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "µÀµÂ¾­¡¸ÏÂ¾í¡¹",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ÌÒ»¨¸â",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "Ãæ¾ß",
                "quest_type":           "Ñ°",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ÕÅÈý",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ºé°²Í¨",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "¶«·½²»°Ü",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

