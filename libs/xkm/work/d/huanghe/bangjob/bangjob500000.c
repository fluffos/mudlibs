//Cracked by Roath
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "ÓàÓãÍ¬",
                "file"  :  "/d/city/npc/yutong",
                "area"  :  "ÑïÖÝÌá¶½¸®",
                "type"  :  "É±",
                "bonus" :  360,
                "score" :  60,
        ]),

        ([      "name"  :  "¶¡µä",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "ÑïÖÝ³Ç¼àÓü",
                "type"  :  "É±",
                "bonus" :  390,
                "score" :  35,
        ]),

        ([      "name"  :  "Â½¸ßÖ¹",
                "file"  :  "/d/city/npc/gaozhi",
                "area"  :  "ÑïÖÝÌá¶½¸®",
                "type"  :  "É±",
                "bonus" :  390,
                "score" :  85,
        ]),

        ([      "name"  :  "ÕÔÁ¼¶°",
                "file"  :  "/d/city/npc/shi",
                "area"  :  "ÑïÖÝ³Ç±øÓª",
                "type"  :  "É±",
                "bonus" :  360,
                "score" :  80,
        ]),

        ([      "name"  :  "ëøÒ»À×",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "¹Ø¶«",
                "type"  :  "É±",
                "bonus" :  340,
                "score" :  62,
        ]),

        ([      "name"  :  "ÅíÁ¬»¢",
                "file"  :  "/d/huanghe/npc/peng-lianhu",
                "area"  :  "»ÆºÓ°ï",
                "type"  :  "É±",
                "bonus" :  340,
                "score" :  65,
        ]),

        ([      "name"  :  "¶À×ãÍ­ÈË",
                "file"  :  "/d/changbai/obj/tongren",
                "type"  :  "Ñ°",
                "bonus" :  210,
                "score" :  63,
        ]),

        ([      "name"  :  "¸Ö×¦",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  225,
                "score" :  66,
        ]),

        ([      "name"  :  "ÉÕºìµÄÌú´¸",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  225,
                "score" :  66,
        ]),

        /*([      "name"  :  "ÐþÌúÁî",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  6,
        ]),*/

        ([      "name"  :  "ºÚÁú±Þ",
                "file"  :  " ",
                "type"  :  "Ñ°",
                "bonus" :  430,
                "score" :  68,
        ]),

        ([      "name"  :  "Çà¸Õ½£",
                "file"  :  "/d/changbai/obj/qinggang-jian",
                "type"  :  "Ñ°",
                "bonus" :  330,
                "score" :  65,
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "ËÍÀñ",
        ]),

        ([      "type"  :  "»¤¼Ý",
        ]),

        ([      "type"  :  "»¤¼Ý",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
