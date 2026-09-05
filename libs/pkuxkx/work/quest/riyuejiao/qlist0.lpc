inherit SKILL;

mapping *quest = ({
        ([      "quest":		"小鸡",               
                "quest_type":           "寻",
                "time":  		200,
                "score"	:		5
        ]),
        ([      "quest":                "蜂王蜜",
                "quest_type":           "寻",
                "time":                 240,
                "score" :               4
        ]),
          ([      "quest":                "风筝",
                "quest_type":           "寻",
                "time":                 300,
                "score" :               3
        ]),
        ([      "quest":                "小毛驴",
                "quest_type":           "寻",
                "time":                 400,
                "score" :               6
        ]),
        ([      "quest":                "小孩",
                "quest_type":           "杀",
                "time":                 300,
                "score" :               2
        ]),  
        ([      "quest":                "店小二",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               4
        ]),
        ([      "quest":                "小流氓",
                "quest_type":           "杀",
                "time":                 600,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
