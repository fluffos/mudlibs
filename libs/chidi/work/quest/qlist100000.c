mapping *quest = ({
     ([      "quest":                "–Âª®–¨",
        "diff":                 2,
        ]),
     ([      "quest":                "…ﬂ»‚",
        "diff":                 2,
        ]),
     ([      "quest":                "Õ≠∫≈",
                "diff":                 2,
        ]),
     ([      "quest":                "œ„≤Ë",
        "diff":                 2,
        ]),
     ([      "quest":                "–Âª®’Î",
        "diff":                 2,
        ]),
     ([      "quest":                YEL "ª∆√µπÂ" NOR,
        "diff":                 3,
        ]),
     ([      "quest":                "µ¿µ¬æ≠",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
