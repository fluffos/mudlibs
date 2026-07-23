//Cracked by Roath
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "余鱼同",
                "file"  :  "/d/city/npc/yutong",
                "area"  :  "扬州提督府",
                "type"  :  "杀",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "name"  :  "丁典",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "扬州城监狱",
                "type"  :  "杀",
                "bonus" :  90,
                "score" :  35,
        ]),

        ([      "name"  :  "陆高止",
                "file"  :  "/d/city/npc/gaozhi",
                "area"  :  "扬州提督府",
                "type"  :  "杀",
                "bonus" :  90,
                "score" :  45,
        ]),

        ([      "name"  :  "赵良栋",
                "file"  :  "/d/city/npc/shi",
                "area"  :  "扬州城兵营",
                "type"  :  "杀",
                "bonus" :  60,
                "score" :  30,
        ]),

        ([      "name"  :  "滕一雷",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "关东",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "彭连虎",
                "file"  :  "/d/huanghe/npc/peng-lianhu",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  15,
        ]),

        ([      "name"  :  "独足铜人",
                "file"  :  "/d/changbai/obj/tongren",
                "type"  :  "寻",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "钢爪",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "烧红的铁锤",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "玄铁令",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  6,
        ]),

        ([      "name"  :  "黑龙鞭",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  30,
                "score" :  8,
        ]),

        ([      "name"  :  "青刚剑",
                "file"  :  "/d/changbai/obj/qinggang-jian",
                "type"  :  "寻",
                "bonus" :  30,
                "score" :  15,
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "护驾",
        ]),

        ([      "type"  :  "护驾",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
