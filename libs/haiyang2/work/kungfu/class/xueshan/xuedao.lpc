// /kungfu/class/xueshan/xuedao.c  血刀老祖
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
void create()
{
        set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
        );
        set("title",HIR"血刀门第四代掌门"NOR);
        set("gender", "男性");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 22000);
        set("max_neili", 22000);
        set("jiali", 50);
        set("combat_exp", 8500000);
        set("score", 180000);

        set_skill("lamaism", 250);
        set_skill("literate", 280);
        set_skill("force", 280);
        set_skill("parry", 280);
        set_skill("blade", 250);
        set_skill("sword", 220);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 380);
        set_skill("hand", 280);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 280);
        set_skill("xue-dao", 380);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );
        set("inquiry",([
                "还俗"  :  (: ask_for_quit :),
        ]));

        set_temp("apply/attack", 300);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

        create_family("雪山寺", 4, "弟子");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性")
        {
                command("say 我不收女徒弟。\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "雪山寺")
        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本门弟子，还是请回吧！\n");
                return;
        }
        if ((int)ob->query("shen") > -100000)
        {
                command("say 你是不是向着侠义道，连杀人都不会！\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 60)
        {
                command("say 入我血刀门，修习龙象功法是首要的。\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "血刀门第五代弟子" NOR);
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "雪山寺")) 
        return ("你和雪山寺没有渊源，我不敢给你还俗。\n");
    if (me->query("combat_exp")< 1000000)
        return ("你就这点本事，我可不敢给你还俗。\n");

    if ((int)me->query_skill("lamaism", 1) < 180) 
                command("say 你修习的密宗心法不足,我可不敢给你还俗。");

    if ((int)me->query_skill("longxiang", 1) < 180) 
                command("say 你修习的龙象般若功不足,我可不敢给你还俗。");

    if (me->query("combat_exp")< 1000000)
        return ("你就这点本事，我可不敢给你还俗。\n");

    if( (string)me->query("class")!="bonze" )
        return "你已经是俗家人了。\n";

        command ("say 你一心要还俗，看来和我是同道中人。\n");
        command ("haha");
        command ("say 以后昨们有酒同吃，有女人一起。。。。。。\n");
        me->set("class", "xueshan");
}
