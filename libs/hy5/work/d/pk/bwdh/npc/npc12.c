//xln.c 小龙女
#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name("小小龙女", ({ "xiao longnu", "xiao", "longnu" }));
        set("title","古墓侠侣");
        set("nickname",HIC"玉女素心"NOR);
        set("long", "她清丽异常，但也许是长居古墓之故，面色略白。\n");
        set("gender", "女性");
        set("age", 39);
        set("attitude", "friendly");
        set("per", 40);
        set("str", 24);
        set("dex", 23);
        set("con", 20);
        set("int", 24);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),

        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "小龙女幽幽地道：“不知过儿现在在哪里？可有看到我刺在玉蜂翅上的字？”\n", 
                "小龙女喃喃道：“玉女剑与全真剑合壁，是可天下无敌。可是...哪里去找这一个人呢？”\n",
                "小龙女深深地叹了口气，转过头去。\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));

        set("qi", 6500);
        set("max_qi", 6500);
        set("jing", 6600);
        set("max_jing", 6600);
        set("neili", 14000);
        set("max_neili", 24000);
        set("jiali", 200);

        set("combat_exp", 2000000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("throwing", 300);
        set_skill("whip", 260);
        set_skill("yinsuo-jinling", 260);
        set_skill("yangyanshu", 300);
        set_skill("yunv-xinfa", 250);    //玉女心法
        set_skill("sword", 150);
        set_skill("yunv-jian", 250);     //玉女剑
        set_skill("quanzhen-jian",130);  //全真剑
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 260);   //玉女身法
        set_skill("parry", 150);
        set_skill("hubo", 120);          //双手互搏
        set_skill("unarmed",150);
        set_skill("meinv-quan", 260);    //美女拳法
        set_skill("literate",120);
        set_skill("qufeng",250);         //驱蜂之术
        set_skill("wuzhan-mei",150);
        set_skill("strike",200);
        set_skill("tianluo-diwang",300);         //驱蜂之术

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");


        setup();

        carry_object(__DIR__"obj/ys")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/rsg");
        carry_object(__DIR__"obj/badan");
}
