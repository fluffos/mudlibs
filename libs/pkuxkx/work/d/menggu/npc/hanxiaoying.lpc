// hanxiaoying.c
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("韩小莹", ({ "han xiaoying", "han" }));
        set("title", "江南七侠");
        set("nickname", CYN"越女剑"NOR);
        set("long", "她是韩宝驹的堂妹，江南七侠排行最小。\n");
        set("gender", "女性");
        set("age", 28);
        set("unique", 1);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
        set("per", 38);
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
        set_skill("sword", 160);
        set_skill("yunu-jianfa", 160);

        map_skill("force", "taiji-shengong");
        map_skill("strike", "kunlun-zhang");
        map_skill("dodge", "qingmang-jian");
        map_skill("sword", "yunu-jianfa");
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
                "全金发"   : "那是我六哥。\n",
                "梅超风"   : "这婆娘，早晚我要杀了她。\n",
                "陈玄风"   : "你能告诉我他在哪吗？\n",
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


int hello(object me)
{
	command("say 五哥……");
}

int bye(object me)
{
	string name=me->query("name");
	int n=strwidth(name);
	int i=n-2,j=n-1;
	command("say "+name[i..j]+"儿,一路保重。");
}