mapping *quest = ({
     ([      "quest":                "青蛇胆",
        "diff":                 2,
        ]),
     ([      "quest":                "铁甲",
        "diff":                 2,
        ]),
     ([      "quest":                "粗布袍",
        "diff":                 2,
        ]),
     ([      "quest":                "云龙经",
        "diff":                 2,
        ]),
     ([      "quest":                "米饭",
        "diff":                 2,
        ]),
     ([      "quest":                HIC "青色袈裟" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "道德经「第十六章」",
        "diff":                 2,
        ]),
        
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
