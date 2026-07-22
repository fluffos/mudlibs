#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "Õı≥«",
                "quest_type":           "…±",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "Ã˙ª§—¸",
                "quest_type":           "—∞",
                "time":                 350,
                "score" :               8
        ]),
        ([      "quest":                "«‡“¬Œ‰ ø",
                "quest_type":           "…±",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "Õ¡∑ÀÕ∑",
                "quest_type":           "…±",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "”Ò÷Ò’»",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               9
        ]),
        ([      "quest":                "“ª—Ù√ÿºÆ",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               9
        ]),
        ([      "quest":                "—≤…Ωµ‹◊”",
                "quest_type":           "…±",
                "time":                 560,
                "score" :               7
        ]),
        ([      "quest":                "”Œ¡˙Ω£",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "‰Ωª®Ω£∆◊",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "∞◊“¬Œ‰ ø",
                "quest_type":           "…±",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "ª’€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "—Ú±ﬁ",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "“¡¿Á¬Ì",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               10
        ]),
        ([       "quest":               "∫Û‘∫",
                "quest_type":           "…®",
                "time":                 200,
                "score" :               5
        ]),
        ([       "quest":               "‘∆ºØ‘∞",
                "quest_type":           "…®",
                "time":                 300,
                "score" :               6
        ]),
        ([       "quest":               "≤ÿæ≠∏Û“ª¬•",
                "quest_type":           "…®",
                "time":                 360,
                "score" :               6
        ]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
