// hanbaoju.c

#include <ansi.h>;
inherit NPC;
void create()
{
        set_name("韩宝驹", ({ "han baoju", "han" }));
        set("title", "江南七侠");
        set("nickname", HIY"马王神"NOR);
        set("long", "他是个又矮又胖的猥琐汉子，犹如一个大肉团一般。他手短足短，
没有脖子，一个头大的出奇，却又缩在双肩之中。一个酒糟鼻又
大又圆，就如一只红柿子旒在脸上。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
       set("unique", 1);
        set("per", 10);
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
        set_skill("dodge", 160);
        set_skill("qingmang-jian", 160);
        set_skill("strike", 160);
        set_skill("parry", 160);
        set_skill("kunlun-zhang", 160);
        set_skill("whip", 160);
        set_skill("yunlong-bian", 160);

        map_skill("force", "taiji-shengong");
        map_skill("strike", "kunlun-zhang");
        map_skill("dodge", "feitian-shenfa");
        map_skill("whip", "yunlong-bian");
        map_skill("parry", "yunlong-bian");
        prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
         }));


        set("inquiry", ([
                "郭靖" : "靖儿是我们的乖徒儿！\n",
                "江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
                "江南七怪" : "住嘴！！七怪也是你叫的？！\n",
                "丘处机" : "丘道长豪侠仗义，是条汉子！\n",
                "柯镇恶" : "他是我大哥，你别看他眼睛看不见，你是什么样的人他心里很清楚。\n",
                "朱聪"   : "呵呵，小心你的口袋。\n",
                "南希仁"   : "那是我四弟。\n",
                "张阿生"   : "可惜五弟已经被黑风双煞害死了。\n",
                "全金发"   : "那是我六弟。\n",
                "韩小莹"   : "那是我七妹,你想不想试试她的越女剑？\n",
                "梅超风"   : "这婆娘，早晚我要杀了她。\n",
                "陈玄风"   : "你能告诉我他在哪吗？\n",
                
        ]));

        setup();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

int hello(object me)
{
	command("hmm");
}

int bye(object me)
{
	command("say 我们先走，你和大汗辞别过也快跟上。");
}
