// quanjinfa.c
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("全金发", ({ "quan jinfa", "quan" }));
        set("title", "江南七侠");
        set("nickname", HIW"闹市侠隐"NOR);
        set("long", "他看起来大约20来岁，身材瘦小，以街市买卖为业，善于算计。\n");
        set("gender", "男性");
        set("age", 28);
        set("unique", 1);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
        set("per", 18);
        set("str", 28);
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
        set_skill("spear", 160);
        set_skill("qingmang-jian", 160);
        set_skill("strike", 160);
        set_skill("parry", 160);
        set_skill("kunlun-zhang", 160);
        set_skill("blade", 160);
        set_skill("yangjia-qiang", 160);

        map_skill("force", "taiji-shengong");
        map_skill("strike", "kunlun-zhang");
        map_skill("dodge", "qingmang-jian");
        map_skill("spear", "yangjia-qiang");
        map_skill("parry", "wuchang-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("inquiry", ([
                "郭靖" : "靖儿是我们的乖徒儿！\n",
                "江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
                "江南七怪" : "住嘴！！七怪也是你叫的？！\n",
                "丘处机" : "丘道长豪侠仗义，是条汉子！\n",
                "柯镇恶" : "他是我大哥，你别看他眼睛看不见，你是什么样的人他心里很清楚。\n",
                "朱聪"   : "呵呵，小心你的口袋。\n",
                "韩宝驹"   : "我三哥可有马王神之称。\n",
                  "南希仁"   : "那是我四哥。\n", 	
                "张阿生"   : "可惜五哥已经被黑风双煞害死了。\n",
                "韩小莹"   : "那是我七妹,你想不想试试她的越女剑？\n",
                "梅超风"   : "这婆娘，早晚我要杀了她。\n",
                "陈玄风"   : "你能告诉我他在哪吗？\n",
        ]));

        setup();
        carry_object("/d/quanzhou/npc/obj/cheng")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


int hello(object me)
{
	string name=me->query("name");
	int n=strwidth(name);
	int i=n-2,j=n-1;
	command("say "+name[i..j]+"儿记住，遇到敌人，最重要的是：打不过，逃！");
}

int bye(object me)
{
	command("bye "+me->query("id"));
}