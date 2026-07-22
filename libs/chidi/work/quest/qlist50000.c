mapping *quest = ({
     ([      "quest":                "竹剑",
        "diff":                 2,
        ]),
     ([      "quest":                "五香茶叶蛋",
        "diff":                 2,
        ]),
     ([      "quest":                "羊鞭",
        "diff":                 2,
        ]),
     ([      "quest":                "波斯长袍",
        "diff":                 2,
        ]),
     ([      "quest":                "阿拉伯弯刀",
        "diff":                 2,
        ]),
     ([      "quest":                "道德经「第八章」",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
