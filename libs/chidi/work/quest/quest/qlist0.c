#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "¹þÃÜ¹Ï",
                "quest_type":           "Ñ°",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "¶Ì½£",
                "quest_type":           "Ñ°",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "°ËØÔÍ¤",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               4
        ]),
        ([      "quest":                "À××æµî",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               2
        ]),
        ([      "quest":                "Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "ÐÇËÞÅÉîàÊÖ",
                "quest_type":           "É±",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                "³¤½£",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               3
        ]),       
        ([      "quest":                "¸Öµ¶",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "ÍõÐ¡¶þ",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "ÏòÎÊÌìÊéÐÅ",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "¾ÉÖñÆ¬",
                "quest_type":           "Ñ°",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "°ü×Ó",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               2
        ]),
         ([      "quest":               "¶Ç´ø",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "²ÝÐ¬",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "ÍÀµ¶",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "½ð´´Ò©",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               10
        ]),
        ([      "quest":                "Ñø¾«µ¤",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "Æ¤±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "È­Æ××Ü¾÷",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "ÍÃÈâ",
                "quest_type":           "Ñ°",
                "time":                 300,
                "score" :               6        
       ]),
        ([      "quest":                "ºóµî",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               6
        ]),
    
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


