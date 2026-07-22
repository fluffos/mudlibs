mapping *quest = ({
     ([      "quest":                "牢房钥匙",
        "diff":                 3,
        ]),
     ([      "quest":                "碧水剑",
        "diff":                 3,
        ]),
     ([      "quest":                HIC "华山剑谱" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "醉仙茶",
        "diff":                 2,
        ]),
     ([      "quest":                "密宗心经",
        "diff":                 4,
        ]),
     ([      "quest":                HIY"黄色袈裟"NOR,
        "diff":                 3,
        ]),
     ([      "quest":                "道德经「第十八章」",
        "diff":                 2,
        ]),
     ([      "quest":                "香茶",
        "diff":                 3,
        ]),
     ([      "quest":                "道德经「第二章」",
        "diff":                 2,
        ]),
         
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
