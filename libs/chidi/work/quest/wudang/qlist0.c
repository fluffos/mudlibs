#include <ansi.h>
inherit SKILL;
mapping *quest = ({
        ([       "quest":               "´óÀíÑ©Àæ",
                "quest_type":           "Ñ°",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "Í·¿ø",
                "quest_type":           "Ñ°",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "³¯Ìì¹¬",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               4
        ]),
        ([      "quest":                "Ê®¶þÁ«Ì¨",
                "quest_type":           "É¨",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "µØÆ¦",
                "quest_type":           "É±",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "°×ÒÂÉÙÅ®",
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
        ([      "quest":                "´ä»¨",
                "quest_type":           "É±",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "Ð¡Ã«Â¿",
                "quest_type":           "Ñ°",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "º£¿Ú´óÍë",
                "quest_type":           "Ñ°",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "°ü×Ó",
                "quest_type":           "Ñ°",
                "time":                 120,
                "score" :               2
        ]),
         ([      "quest":               "Æ¤±³ÐÄ",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "¾ÉÖñÆ¬",
                "quest_type":           "Ñ°",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "Ìú´¸",
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
        ([      "quest":                "Ðå»¨Õë",
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
        ([      "quest":                "½ðµî",
                "quest_type":           "É¨",
                "time":                 300,
                "score" :               6
        ]),
    
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
