#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":		"铁手掌",               
                "quest_type":           "寻",
                "time":  		60,
                "score"	:		2,
                
        ]),
        ([      "quest":                "旧竹片",
                "quest_type":           "寻",
                "time":                 360,
                "score" :               4
        ]),
        ([      "quest":                "后殿",
                "quest_type":           "扫",
                "time":                 100,
                "score" :               4,
                "reason" :              "现在后殿比较的脏，扫地僧又都很忙，" 
        ]),
        ([      "quest":                "法华经",
                "quest_type":           "寻",
                "time":                 120,
                "score" :               4
        ]),
        ([      "quest":                "程药发",
                "quest_type":           "送",
                "time":                 150,
                "score" :               4,
                "reason" :              "我派在扬州的俗家弟子需要得到官府的照顾，" 
        ]),       
        ([      "quest":                "金刚经",
                "quest_type":           "寻",
                "time":                 150,
                "score" :               5
        ]),  
        ([      "quest":                "武器库",
                "quest_type":           "扫",
                "time":                 150,
                "score" :               5,
                "reason" :              "听道尘禅师说武器库现在需要人打扫，" 
        ]),
        ([      "quest":                "薄绢",
                "quest_type":           "寻",
                "time":                 210,
                "score" :               6
        ]),
        ([      "quest":                "和尚院四部",
                "quest_type":           "扫",
                "time":                 210,
                "score" :               6,
                "reason" :              "现在和尚院四部没有人打扫，" 
        ]),
           

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
