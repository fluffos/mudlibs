// fmquest.c

inherit SKILL;
#include <ansi.h>;

mapping *quest = ({
        ([      "quest_num":            "1",
                "opp_name":             "迷天七圣",
                "file_env":             "华阳西口",
                "mudi_env":             "龙门东路口",
                "file_name":            "/d/huayang/hyroad2",
                "mudi_name":            "/d/longmen/dexit",
        ]),
        ([      "quest_num":            "2",
                "opp_name":             "权力帮",
                "file_env":             "华阳东口",
                "mudi_env":             "龙门南路口",
                "file_name":            "/d/huayang/hyroad6",
                "mudi_name":            "/d/longmen/sexit",
        ]),
        ([      "quest_num":            "3",
                "opp_name":             "温家",
                "file_env":             "华阳东口",
                "mudi_env":             "龙门南路口",
                "file_name":            "/d/huayang/hyroad6",
                "mudi_name":            "/d/longmen/sexit",
        ]),
        ([      "quest_num":            "4",
                "opp_name":             "六分半堂",
                "file_env":             "华阳镇中心",
                "mudi_env":             "龙门东路口",
                "file_name":            "/d/huayang/hycs",
                "mudi_name":            "/d/longmen/dexit",
        ]),
        ([      "quest_num":            "5",
                "opp_name":             "浣花剑派",
                "file_env":             "华阳镇中心",
                "mudi_env":             "龙门南路口",
                "file_name":            "/d/huayang/hycs",
                "mudi_name":            "/d/longmen/sexit",
        ]),
        ([      "quest_num":            "6",
                "opp_name":             "飞鱼帮",
                "file_env":             "华阳西口",
                "mudi_env":             "龙门镇中心",
                "file_name":            "/d/huayang/hyroad2",
                "mudi_name":            "/d/longmen/sqare",
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

