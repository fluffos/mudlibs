// ji.c 纪晓芙

inherit NPC;
inherit F_MASTER;
int ask_jian();

void create()
{
        set_name("纪晓芙", ({ "ji xiaofu","ji","xiaofu"}));
        set("long",
                "她是峨嵋派的第四代俗家弟子。偏心偏听的灭绝抛弃她，\n"
                "她独自在这里苦度光阴。\n");
        set("gender", "女性");
        set("age", 22);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
        set("shen", 10000);

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 30);
        set("inquiry",([
                "倚天剑"  : (:ask_jian:),
                "屠龙刀"  : "这里没有屠龙刀。倚天剑倒是有一柄。",
                "杨不悔"  : "我的女儿啊。她在哪里？你知道么？",
                "杨逍"    : "我这辈子是不指望见到他了。",
                "灭绝"    : "师父就是太偏心。",
        ]));

         set("max_qi", 6000);
        set("max_jing", 6500);
        set("neili", 6500);
        set("max_neili", 6500);
        set("jingli", 1500);
        set("max_jingli", 1500);

        set("combat_exp", 350000);
        set("score", 1000);
        set_skill("persuading", 180);
        set_skill("throwing", 160);
        set_skill("force", 160);
        set_skill("dodge", 170);
        set_skill("finger", 175);
        set_skill("parry", 170);
        set_skill("strike", 160);
        set_skill("sword", 180);
        set_skill("literate", 170);
        set_skill("mahayana", 160);
        set_skill("jinding-zhang", 160);
        set_skill("tiangang-zhi", 165);
        set_skill("huifeng-jian", 160);
        set_skill("zhutian-bu", 160);
        set_skill("linji-zhuang", 160);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        set_skill("yanxing-dao", 380);
        set_skill("bagua-dao", 380);
        set_skill("bagua-zhang", 380);
        map_skill("blade","bagua-dao");
        //map_skill("parry","bagua-dao");
        
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");	
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "blade.feiyan" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.mang" :),
                (: perform_action, "blade.sha" :),                	
                (: perform_action, "blade.tian" :),                	                	                	
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),                		
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
        create_family("峨嵋派", 4, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 0) {
                command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }

        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
int ask_jian()
{
    object ob;
    ob = this_player();
    ob->set("marks/ji",0);
    ob->set("marks/skysword",1);
    say( "纪晓芙微微叹了口气：“倚天剑就在舍身崖下。\n");
    tell_object(ob,"纪晓芙所完这句话，飘然跃下舍身崖去。衣袂飘动，白云荡处，伤感顿生。\n");
    call_out("goway",2);
    return 1;
}
void goway()
{
    destruct(this_object());
}
