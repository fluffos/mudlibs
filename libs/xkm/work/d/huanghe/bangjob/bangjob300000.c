//Cracked by Roath
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "±¦Ê÷",
                "file"  :  "/d/foshan/npc/baoshu",
                "area"  :  "ÉÙÁÖËÂ",
                "type"  :  "É±",
                "bonus" :  340,
                "score" :  52,
        ]),

        ([      "name"  :  "Áº×ÓÎÌ",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "area"  :  "»ÆºÓ°ï",
                "type"  :  "É±",
                "bonus" :  370,
                "score" :  50,
        ]),

        ([      "name"  :  "»Û½ð×ðÕß",
                "file"  :  "/d/quanzhou/npc/huijin",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  335,
                "score" :  55,
        ]),

        ([      "name"  :  "ÈÕ±¾ÀËÈË",
                "file"  :  "/d/quanzhou/npc/langren",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  330,
                "score" :  58,
        ]),

        ([      "name"  :  "Ê©ÀÅ",
                "file"  :  "/d/quanzhou/npc/shilang",
                "area"  :  "ÈªÖÝ",
                "type"  :  "É±",
                "bonus" :  480,
                "score" :  70,
        ]),

        ([      "name"  :  "ÑîÌúÐÄ",
                "file"  :  "/d/hangzhou/npc/yang",
                "area"  :  "Å£¼Ò´å",
                "type"  :  "É±",
                "bonus" :  330,
                "score" :  70,
        ]),

        ([      "name"  :  "¹ùÐ¥Ìì",
                "file"  :  "/d/hangzhou/npc/guo",
                "area"  :  "Å£¼Ò´å",
                "type"  :  "É±",
                "bonus" :  330,
                "score" :  50,
        ]),

        ([      "name"  :  "»¢¹Ç",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  330,
                "score" :  40,
        ]),

        ([      "name"  :  "ÐÜµ¨",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  340,
                "score" :  42,
        ]),

        ([      "name"  :  "ÌúÅÆ",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  314,
                "score" :  43,
        ]),

        ([      "name"  :  "Ö¸»·",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  425,
                "score" :  10,
        ]),

        ([      "name"  :  "ÀÇÑÀ°ô",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  315,
                "score" :  34,
        ]),

        ([      "name"  :  "»ÕÄ«",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  425,
                "score" :  46,
        ]),

        ([      "name"  :  "½ðËãÅÌ",
                "file"  :  "/d/dali/npc/obj/jinsuanpan",
                "type"  :  "Ñ°",
                "bonus" :  325,
                "score" :  46,
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
        ]),

        ([      "type"  :  "Ê¾Íþ",
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
