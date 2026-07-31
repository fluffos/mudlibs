// qlist1000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "≈£∆§æ∆¥¸",
                "quest_type":           "—∞",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "Õ√»‚",
                "quest_type":           "—∞",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "µÿ∆¶",
                "quest_type":           "…±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "–°∫Ô",
                "quest_type":           "…±",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
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
        ([      "quest":                "–Âª®’Î",
                "quest_type":           "—∞",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "–°∫¢",
                "quest_type":           "…±",
                "time":                 300,
                "exp_bonus":            6,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "≈„¥”",
                "quest_type":           "…±",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                " ¢∆§¬ﬁøÕ…Ã",
                "quest_type":           "…±",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "Ã®“ƒ≈©∏æ",
                "quest_type":           "…±",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "µ¿ÕØ",
                "quest_type":           "…±",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
