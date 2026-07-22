mapping *quest = ({
     ([      "quest":                "大珍珠",
        "diff":                 5,
        ]),
     ([      "quest":                "斗篷",
        "diff":                 2,
        ]),
     ([      "quest":                "布阵箱",
        "diff":                 2,
        ]),
     ([      "quest":                WHT "白茶花" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                HIC "青衣" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "华山剑谱",
        "diff":                 2,
        ]),
     ([      "quest":                "水碗",
        "diff":                 2,
        ]),
     ([      "quest":                "道德经「第十三章」",
        "diff":                 3,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
