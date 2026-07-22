#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               " È…˙",
                "quest_type":           "…±",
                "time":                 300,
                "score" :               4
        ]),
        ([      "quest":                "≥§Ω£",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "Ô⁄Õ∑",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               5
        ]), 
        ([      "quest":                "¡÷∆Ω÷Æ",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               5
        ]),
        ([      "quest":                "≤º“¬",
                "quest_type":           "—∞",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "Ω¯œ„øÕ",
                "quest_type":           "…±",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "µ¿ÕØ",
                "quest_type":           "…±",
                "time":                 200,
                "score" :               3
        ]),
         ([      "quest":                "ª®ª®π´◊”",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "Ã˙º◊",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               6
        ]),       
        ([      "quest":                "∏÷’»",
                "quest_type":           "—∞",
                "time":                 400,
                "score" :               7
        ]),  
        ([      "quest":                "∫Ï…’π∑»‚",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "—√“€",
                "quest_type":           "…±",
                "time":                 350,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


