// qlist8000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "≈£∆§æ∆¥¸",
                "quest_type":           "—∞",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "¿Ó√˜œº",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "µÿ∆¶",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "…Ÿ≈Æ",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "¡‘»À",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "Œ⁄“ƒ…Ã∑∑",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "…Ò≈©∞Ôµ‹◊”",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "Œﬁ¡øΩ£µ‹◊”",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "’≈¬Ë",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "∞◊“¬…Ÿ≈Æ",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "”ŒøÕ",
                "quest_type":           "…±",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "Õ√»‚",
                "quest_type":           "—∞",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "¡˜√•",
                "quest_type":           "…±",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "–Âª®’Î",
                "quest_type":           "—∞",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                " Ã’ﬂ",
                "quest_type":           "…±",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "Ωı“¬Œ¿ ø",
                "quest_type":           "…±",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "Àÿ“¬Œ¿ ø",
                "quest_type":           "…±",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
