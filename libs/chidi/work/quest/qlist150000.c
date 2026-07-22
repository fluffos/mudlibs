mapping *quest = ({
     ([      "quest":                "ÁøÒ¶µ¶",
        "diff":                 2,
        ]),
     ([      "quest":                "ÑÃÒÛ·þ",
        "diff":                 2,
        ]),
     ([      "quest":                "±ùÑ©ôä´ä¸â",
        "diff":                 2,
        ]),
     ([      "quest":                "ËáÃ·ÌÀ",
        "diff":                 2,
        ]),
     ([      "quest":                BLK "ºÚÄµµ¤" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "Ë®ºø",
        "diff":                 2,
        ]),
     ([      "quest":                "µÀµÂ¾­¡¸ÉÏ¾í¡¹",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
