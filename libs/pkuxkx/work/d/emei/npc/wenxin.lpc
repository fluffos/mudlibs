//
//create bye cuer

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("文心师太", ({
                "wenxin shitai",
                "wenxin",
                "shitai",
        }));
        set("long",
                "她是一位年轻师太。\n"
        );
        set("gender", "女性");
        set("attitude", "peaceful");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 500);
        set("max_jing", 200);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 40);
        set("combat_exp", 10000);
        set("score", 100);
        set_skill("force", 60);
        set_skill("linji-zhuang", 60);
        set_skill("dodge", 70);
        set_skill("zhutian", 70);
        set_skill("yanxing-dao", 70);
        set_skill("blade", 70);
        set_skill("parry", 60);
        set_skill("mahayana", 70);
        set_skill("literate", 60);
        map_skill("force", "linji-zhuang");
        map_skill("dodge", "zhutian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "yanxing-dao");
        prepare_skill("blade", "yanxing-dao");
        
        create_family("峨嵋派", 5, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/gangdao")->wield();
}


void init()
{
 object ob,me;
 ::init();
 ob = this_player();
 me = this_object(); 
    if (ob->query("special_skill/sociability")) return;
    if (ob->query("combat_exp")<=500000) return;
 if (!wizardp(ob) && (string)ob->query("family/family_name") != "峨嵋派")
   {
    say(RED"文心师太怒喝道：“大胆狂徒，竟敢杀人闯山！！！岂能容你如此撒野！！\n"NOR);
    remove_call_out("kill_ob");
    call_out("kill_ob",1,ob);
   }
} 
