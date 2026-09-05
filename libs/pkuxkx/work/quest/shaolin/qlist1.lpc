#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":		"铁甲",               
                "quest_type":           "寻",
                "time":  		300,
                "score"	:		6,
                "reason" :              "听武器库道尘禅师说，现在需要个铁甲作样板，"
        ]),
        ([      "quest":                "钢剑",
                "quest_type":           "寻",
                "time":                 360,
                "score" :               6,
                "reason" :              "听武器库道尘禅师说，现在需要一柄钢剑来仿制武器，"
        ]),
        ([      "quest":                "牧羊鞭",
                "quest_type":           "寻",
                "time":                 400,
                "score" :               5,
                "reason" :              "我少林鞭法虽精，但是在长鞭的制造上\n却不行，道尘禅师说需要一柄长鞭作样板，\n"
        ]),
        ([      "quest":                "水蜜桃",
                "quest_type":           "寻",
                "time":                 400,
                "score" :               3,
                "reason" :              "现在正是水蜜桃成熟的季节，药品库道象禅师禅师要配置药物，\n"
        ]),
        ([      "quest":                "华山剑谱",
                "quest_type":           "寻",
                "time":                 450,
                "score" :               5,
                "season" :              "为博采众家之长，我想看看华山的剑法，"
        ]),       
        ([      "quest":                "伊犁马",
                "quest_type":           "寻",
                "time":                 450,
                "score" :               5
        ]),  
        ([      "quest":                "石板",
                "quest_type":           "寻",
                "time":                 480,
                "score" :               7,
                "reason" :              "我少林记载武学精华的石板不见了，"
        ]),
        ([      "quest":                "含羞草",
                "quest_type":           "寻",
                "time":                 410,
                "score" :               6
        ]),
        ([      "quest":                "广场",
                "quest_type":           "扫",
                "time":                 410,
                "score" :               6,
                "reason" :              "现在广场没有人打扫，"
        ]),
        ([      "quest":                "勤修场",
                "quest_type":           "扫",
                "time":                 410,
                "score" :               6,
                "reason" :              "听说勤修场现在比较脏，"
        ]),
        ([      "quest":                "西侧殿",
                "quest_type":           "扫",
                "time":                 410,
                "score" :               6,
                "reason" :              "听说西侧殿现在比较脏，"
        ]),
        ([      "quest":                "李莫愁",
                "quest_type":           "送",
                "time":                 410,
                "score" :               6,
                "reason" :              "现在李莫愁危害武林，但是念在她也是为情所困，方丈特地修书一封，劝她悔过，\n"
        ]),


           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
