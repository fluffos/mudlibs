//Cracked by Roath
// /d/huanghe/changle/bangjob5000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "回回",
                "file"  :  "/d/quanzhou/npc/huihui",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  218,
                "score" :  54,
        ]),

        ([      "name"  :  "塘工",
                "file"  :  "/d/hangzhou/npc/tbbz",
                "area"  :  "杭州湾海堤",
                "type"  :  "杀",
                "bonus" :  215,
                "score" :  53,
        ]),

        ([      "name"  :  "海沙派盐枭",
                "file"  :  "/d/hangzhou/npc/hsbz",
                "area"  :  "杭州湾盐田",
                "type"  :  "杀",
                "bonus" :  218,
                "score" :  55,
        ]),

        ([      "name"  :  "天鹰教众",
                "file"  :  "/d/hangzhou/npc/tyjz",
                "area"  :  "杭州湾海神庙",
                "type"  :  "杀",
                "bonus" :  220,
                "score" :  35,
        ]),

        ([      "name"  :  "野菊花",
                "file"  :  "/d/city/obj/juhua",
                "type"  :  "寻",
                "bonus" :  123,
                "score" :  41,
        ]),

        ([      "name"  :  "狗皮",
                "file"  :  "/d/city/obj/goupi",
                "type"  :  "寻",
                "bonus" :  133,
                "score" :  51,
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "买卖",
        ]),

        ([      "type"  :  "摊费",
        ]),

        ([      "type"  :  "摊费",
        ]),
 
        ([      "type"  :  "伙计",
        ]),

        ([      "type"  :  "伙计",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}


