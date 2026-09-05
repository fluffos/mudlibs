// kezhene.c
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("柯镇恶", ({ "ke zhene", "ke" }));
        set("title", "江南七侠");
        set("nickname", HIM"飞天蝙蝠"NOR);
        set("long", "他是一个衣衫褴褛的瞎子，右手握着一根粗大的铁杖。只见他
尖嘴削腮，脸色灰扑扑地，颇有凶恶之态。\n");
        set("gender", "男性");
        set("age", 44);
       set("unique", 1);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
        set("per", 12);
        set("str", 38);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 3500);
        set("max_jing", 500);
	set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 20);
        set("combat_exp", 1400000);
        set("score", 6000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 160);
        set_skill("qingmang-jian", 160);
        set_skill("strike", 160);
        set_skill("parry", 160);
        set_skill("kunlun-zhang", 160);
        set_skill("staff", 160);
        set_skill("wuchang-zhang", 160);
        set_skill("throwing", 160);

        map_skill("force", "taiji-shengong");
        map_skill("strike", "kunlun-zhang");
        map_skill("dodge", "qingmang-jian");
        map_skill("staff", "wuchang-zhang");
        map_skill("parry", "wuchang-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("inquiry", ([
                "郭靖" : "靖儿是我们的乖徒儿！\n",
                "江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
                "江南七怪" : "住嘴！！七怪也是你叫的？！\n",
                "丘处机" : "丘道长豪侠仗义，是条汉子！\n",
                "柯镇恶" : "就是瞎子我，你想怎么样？！\n",
                "朱聪"   : "呵呵，小心你的口袋。\n",
                "韩宝驹"   : "我三弟可有马王神之称。\n",
                "南希仁"   : "那是我四弟。\n",
                "张阿生"   : "那是我五弟，他那双屠牛的手比你的脸都大。\n",
                "全金发"   : "那是我六弟。\n",
                "韩小莹"   : "那是我七妹,你想不想试试她的越女剑？\n",
                "梅超风"   : "这婆娘，早晚我要杀了她。\n",
                "陈玄风"   : "你能告诉我他在哪吗？\n",
        ]));

        setup();

        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


