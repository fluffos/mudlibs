inherit SKILL;
#include <ansi.h>;
// [lsg 1999/11/20]
mapping *quest = ({
        ([      "quest":                "少林派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "武当派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "峨嵋派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "华山派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "桃花岛",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            80,
                "score" :               20
        ]),
        ([      "quest":                "星宿派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "白驼山派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "神龙教",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "雪山寺",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),

        ([      "quest":                "云龙门",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "明教",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),

        ([      "quest":                "古墓派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            400,
                "pot_bonus":            150,
                "score" :               20
        ]),
        ([      "quest":                "丐帮",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "全真教",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "大理段家",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "逍遥派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "铁掌帮",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "姑苏慕容",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "日月神教",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "凌霄城",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "五毒教",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            300,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "昆仑派",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),
        ([      "quest":                "日月神教",
                "quest_type":           "捉人",
                "time":                 240,
                "exp_bonus":            240,
                "pot_bonus":            50,
                "score" :               20
        ]),


});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
