mapping *quest = ({
     ([      "quest":                "军服",
        "diff":                 2,
        ]),
     ([      "quest":                "桃花糕",
        "diff":                 4,
        ]),
     ([      "quest":                "桃木剑",
        "diff":                 5,
        ]),
     ([      "quest":                "云龙经「上卷」",
        "diff":                 2,
        ]),
     ([      "quest":                RED "红枚瑰" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                MAG "紫罗兰" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "道德经「第一章」",
        "diff":                 2,
        ]),
        
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
