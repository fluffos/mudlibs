#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "ÍõÎå",
                "quest_type":           "É±",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "ÃÜÖ­ÌðÅº",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "°¢×Ï",
                "quest_type":           "É±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "ÊØËÂÉ®±ø",
                "quest_type":           "É±",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "É®¹÷",
                "quest_type":           "Ñ°",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "°ËØÔÍ¤",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "À××æµî",
                "quest_type":           "É¨",
                "time":                 200,
                "score" :               3
        ]), 
        ([      "quest":                "ÑÆÆÍ",
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
        ([      "quest":                "ºìÉÕ¹·Èâ",
                "quest_type":           "Ñ°",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "·Ê·Ê",
                "quest_type":           "É±",
                "time":                 650,
                "score" :               9
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

