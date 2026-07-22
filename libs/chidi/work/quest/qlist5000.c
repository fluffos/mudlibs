mapping *quest = ({
     ([      "quest":                "¸¯ÀÃµÄÊ¬Ìå",
                "diff":                 3,
        ]),
     ([      "quest":                "É³³æ¿Ç",
                "diff":                 3,
        ]),
        ([      "quest":                "Í­¹Ä",
                "diff":                 2,
        ]),
        ([      "quest":                "Ñò±Þ",
                "diff":                 1,
        ]),
     ([      "quest":                "Î¬Îá¶û×å³¤ÅÛ",
                "diff":                 2,
        ]),
     ([      "quest":                "Å£Æ¤´ü",
        "diff":                 2,
        ]),
     ([      "quest":                "ÇàïýÃæ",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
