#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":                "ËÕÐÇºÓ",               
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),
        ([      "quest":                "ÉÆÓÂ",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "ÌìÀÇ×Ó",
                "quest_type":           "É±",
                "time":                 1000,
                "score" :               12
        ]),
        ([      "quest":                "ÎéÇî",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               12
        ]),  
        ([      "quest":                "Å·Ñô¿Ë",
                "quest_type":           "É±",
                "time":                 1200,
                "score" :               14
        ]),
        ([      "quest":                "ÊØÄ¹ÈË",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "ÈýÐ¦åÐÒ£É¢",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "Ò¹Ã÷Öé",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "Ô¿³×",
                "quest_type":           "Ñ°",
                "time":                 800,
                "score" :               12
        ]),
        ([      "quest":                "ÌìÉ½Ñ©Á«",
                "quest_type":           "Ñ°",
                "time":                 1300,
                "score" :               11
        ]),
        ([      "quest":                "·¨ÂÖ",
                "quest_type":           "Ñ°",
                "time":                 1200,
                "score" :               11
        ]),
        ([      "quest":                "»ÆÒ©Ê¦",
                "quest_type":           "É±",
                "time":                 1300,
                "score" :               26
        ]),
        ([      "quest":                "¹¶¶Á",
                "quest_type":           "É±",
                "time":                 1800,
                "score" :               20
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}



