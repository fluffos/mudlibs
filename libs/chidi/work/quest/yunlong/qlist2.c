#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "Àî½ÌÍ·",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "÷¡°Ý",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "¼ÆÎÞÊ©",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "ÓñÖñÕÈ",
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                HIW"·üÄ§µ¶"NOR,
                "quest_type":           "Ñ°",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "Ê¨ºð×Ó",
                "quest_type":           "É±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "ÓÎÁú½£",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "Á½ÒÇ½£Æ×<ÏÂ¾í>",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "Ì«¼«Ê®ÈýÊÆ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               9        ]),
        ([       "quest":               "»ðÕÛ",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "Ò©³ú",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "¿µ¹ãÁê",
                "quest_type":           "É±",
                "time":                 300,
                "score" :               7
        ]),
        ([       "quest":               "¿µÇ×Íõ",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               6
        ]),
        ([       "quest":               "ÇúÑó",
                "quest_type":           "É±",
                "time":                 180,
                "score" :               5
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
