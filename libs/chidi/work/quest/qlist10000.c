mapping *quest = ({
        ([      "quest":                "Í­îà",
                "diff":                 2,
        ]),
        ([      "quest":                "Ìú¹÷",
                "diff":                 1,
        ]),
     ([      "quest":                "´Ö²¼ÒÂ",
                "diff":                 2,
        ]),
     ([      "quest":                "ÑòÈâ´®",
        "diff":                 2,
        ]),
     ([      "quest":                "´óµ¶",
        "diff":                 2,
        ]),  
    ([      "quest":                "¾ü·þ",
        "diff":                 2,
        ]),
    ([      "quest":                "¸Öµ¶",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
