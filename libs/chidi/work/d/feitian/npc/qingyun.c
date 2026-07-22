// mei.c
inherit BHNPC;
#include <ansi.h>;
void create()
{
        set_name( "青云" ,({ "qing yun", "yun" }));
        set("nickname", "逍遥自在");
        set("gender", "男性");
        set("age", 21);
        set("long",
            "青云是飞天御剑流的创始人，不过自己的武功到也是稀松平常\n"
            "平生最爱作弄人了，你可要小心点了。\n"
            "他长的普普通通无惊人的样子。\n");
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 32);
        set("con", 35);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "edge.jiu" :),
                (: perform_action, "edge.jiu" :),
                (: perform_action, "edge.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
                (: perform_action, "unarmed.sanchong" :),
                (: perform_action, "unarmed.sanchong" :),
                (: command("unwield niren dao") :),
                (: command("unwield niren dao") :),
                (: command("unwield niren dao") :),
                (: command("unwield niren dao") :),
                (: command("wield niren dao") :),
                (: command("wield niren dao") :),
                (: command("wield niren dao") :),
                (: command("wield niren dao") :),
        }));
        set("max_qi",12500);
        set("max_jing",5000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 100);
        set("shen",-50000);

        set("combat_exp", 5000000);

        set_skill("unarmed", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("dodge", 240);
        set_skill("edge", 280);
        set_skill("literate", 220);
        set_skill("xuanhualiu-quanfa", 290);
        set_skill("feitian-yujianliu",290);
        set_skill("shayi-xinfa", 290);
        set_skill("wuxing-dun", 290);

        map_skill("force", "shayi-xinfa");
        map_skill("parry", "feitian-yujianliu");
        map_skill("edge", "feitian-yujianliu");
        map_skill("dodge", "wuxing-dun");
        map_skill("unarmed", "xuanhualiu-quanfa");

        create_family("飞天御剑流", 1, "开山祖师");

        set("inquiry", ([
           "飞天御剑流":   "去台湾坐船去吧？",
           "铁尸":     "江湖上的人都这么叫我的，你怕不怕？哈哈哈哈。",
           "东邪":     "那是我师父的绰号。",
           "西毒":     "那是与家师齐名的高手之一，是个老毒物，住在白驼山。",
           "南帝":     "段王爷已出家当和尚去了，法名叫一灯。",
           "北丐":     "北丐统领中原的丐帮，势力颇为强大。",
           "洪七公":   "洪七公武功高强，而且教会郭靖那小儿降龙十八掌，可恨！",
           "黄蓉":     "她是我师父的独女，最是刁蛮任性。",
           "郭靖":     "哼，就是这个小子暗算了我师哥，我绝不会放过他！",
           "杨康":     "康儿是我的徒弟，你见过他么？",
           "梅超风":   "不就是我么？你是白痴啊？",
           "陈玄风":   "他是我的师哥，也是我的夫君，可惜被郭靖那小儿暗算了。",
           "黄药师":   "他是我师父。"]) );
        setup();
      carry_object("/clone/cloth/cloth")->wear();
          carry_object("/d/feitian/npc/obj/niren dao")->wield();
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query("shayi-xinfa") > 50) {
                command("say " + RANK_D->query_respect(ob) +
                        "杀意心法在于杀意，你的杀意如此之低只怕会被剑所控制？");
                return;
}
           command("chat 飞天御剑流是拯救乱世所创的剑法。");
       command("chat " + RANK_D->query_respect(ob) + "希望你能将飞天御剑流发扬光大。");
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"【万年不老!永享仙福!寿与天齐!文武仁圣!飞天御剑流祖师青云亲传】"NOR);
       ob->set("class", "yujianliu");
}

