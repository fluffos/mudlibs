// Jay 3/17/96
inherit NPC;
void create()
{
        set_name("计老人", ({ "ji laoren", "ji"}));
        set("gender", "男性");
        set("age", 70);
        set("long", 
"满头白发，竟无一根是黑的，身材甚是高大，只是弓腰曲背，衰老已极。\n"
"手里端着根旱烟袋，正“吧、吧、”地抽着烟。\n");
        set("attitude", "friendly");
        set("combat_exp", 10000);
        set("shen_type", 1);
        set("shen", 1000);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 24);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 10);
        set_skill("unarmed", 50);
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 15);
        set("inquiry", ([
            "李文秀" : "这孩子真命苦。\n",
            "哈萨克人" : "哈萨克人最爱喝又香又烈的美酒。\n",
            "烟草" : "想要烟草？你也要拿点东西来换吧！\n"
                     "唉，我太老了，连马都骑不了了。\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/ycloth")->wear();
        carry_object(__DIR__"obj/hanyan")->wield();
}
int accept_object(object who, object ob)
{
        if ((string)ob->query("id")=="maotan") {
        message_vision(
        "计老人点点了头, 说道：谢谢! 这根金针是我从江南带来的, 就送给你吧。\n计老人把金针交给了$N。\n", who);
        new(__DIR__"obj/jinzhen")->move(who);
        call_out("destroy", 1, ob);
        return 1;
        }

        if ((string)ob->query("id")=="youtan flower") {
        message_vision(
        "计老人点点了头, 说道：谢谢! 想不到这位" + RANK_D->query_respect(who)+ "也是同好, 这烟草就送给你吧。\n计老人把烟草交给了$N。\n", who);
        new(__DIR__"obj/yancao")->move(who);
        return 1;
        }
        return 0;
}

