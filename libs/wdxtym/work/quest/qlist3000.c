// qlist3000.c
inherit SKILL;

mapping *quest = ({
        ([      "quest":                "Å£Æ¤¾Æ´ü",
                "quest_type":           "Ñ°",
                "time":                 200,
                "exp_bonus":            4,
                "pot_bonus":            2,
                "score" :               20
        ]),
        ([      "quest":                "ÍÃÈâ",
                "quest_type":           "Ñ°",
                "time":                 180,
                "exp_bonus":            4,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "µØÆ¦",
                "quest_type":           "É±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "Ð¡ºï",
                "quest_type":           "É±",
                "time":                 380,
                "exp_bonus":            15,
                "pot_bonus":            7,
                "score" :               20
        ]),
        ([      "quest":                "ÕÅÂè",
                "quest_type":           "É±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "°×ÒÂÉÙÅ®",
                "quest_type":           "É±",
                "time":                 280,
                "exp_bonus":            10,
                "pot_bonus":            4,
                "score" :               20
        ]),
        ([      "quest":                "ÓÎ¿Í",
                "quest_type":           "É±",
                "time":                 450,
                "exp_bonus":            15,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "Á÷Ã¥",
                "quest_type":           "É±",
                "time":                 180,
                "exp_bonus":            12,
                "pot_bonus":            5,
                "score" :               20
        ]),
        ([      "quest":                "Ðå»¨Õë",
                "quest_type":           "Ñ°",
                "time":                 180,
                "exp_bonus":            5,
                "pot_bonus":            3,
                "score" :               20
        ]),
        ([      "quest":                "Ì¨ÒÄ¹ÃÄï",
                "quest_type":           "É±",
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
