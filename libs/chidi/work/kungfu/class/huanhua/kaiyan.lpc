// sample master.c code
// xiake island master.c

inherit BHNPC;
inherit F_MASTER;

void heal_ob();
void recover_ob();
int ask_book();

void create()
{
        set_name("萧开雁", ({"xiao kaiyan", "xiao", "kaiyan"}));
        set("gender", "男性");
        set("age", 26);
        set("long", 
"他是一个非常英俊的年轻人，一张略带稚气的脸上露出一丝淡淡的笑容。\n"
"他是浣花现任掌门萧西楼的次子。剑法之强直追其父。\n");
        set("attitude", "peaceful");
        set("str", 15);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("bac", 25);

        set("qi", 12600);
        set("max_qi", 12600);
        set("jingli", 1800);
        set("max_jingli", 1800);
        set("neili", 2100);
        set("max_neili", 2100);
        set("jiali", 50);
        
        set("combat_exp", 80000000);
        set("score", 20000);
        
        set_skill("force", 750);
        set_skill("jiuqu-xinfa", 750); 
        set_skill("strike", 750);
        set_skill("feixu-zhang", 750);
        set_skill("dodge", 750); 
        set_skill("huanhua-shenfa", 750); 
        set_skill("sword", 770); 
        set_skill("parry", 750); 
        set_skill("literate", 750); 
        set_skill("huanhua-jianfa", 770); 
        set_skill("confu", 720); 
        
        map_skill("force", "jiuqu-xinfa");
        map_skill("dodge", "huanhua-shenfa");
        map_skill("strike", "feixu-zhang");
        map_skill("parry", "huanhua-jianfa");
        map_skill("sword", "huanhua-jianfa");

        prepare_skill("strike", "feixu-zhang");
        
        create_family("浣花剑派", 3, "弟子");

        setup();

        set("inquiry", ([
                "book" : (: ask_book :),
                "miji" : (: ask_book :),
        ]) );

        carry_object("/d/huanhua/npc/obj/jinpao")->wear();
        carry_object("/clone/weapon/changjian")->wield();

        set("chat_chance", 3);
        set("chat_msg", ({
                (: heal_ob :),
                "萧开雁突然皱了皱眉头，似乎想到了什么难办的事情。\n",
                "萧开雁轻轻叹了口气：“不知道大哥怎么样了。”\n",
        }));

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mantian" :),
                (: perform_action, "sword.luanhong" :),
                (: perform_action, "strike.fenfei" :),
                (: recover_ob :)
        }) );
}

void heal_ob()
{
        command("yun heal");
        command("yun heal");
        command("yun heal");
        command("yun recover");
        return;
}

void recover_ob()
{
        command("yun recover");
        return;
}

void attempt_apprentice(object ob)
{
        object me;
        mapping my_fam, ob_fam;
        string title;

        me = this_object();

        my_fam = ob->query("family");
        ob_fam = me->query("family");

        title = ob->query("title");

        if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "浣花剑派")
        {
                command("say " + RANK_D->query_respect(ob) +"和我们浣花剑派向无来往，拜师又从何说起呢？");
                return;
        }

        if ((int)ob->query("shen") <= (-100))
        {
                command("say 你身为浣花弟子却不主张正义，甘入魔道，我浣花容不下你！");
                command("kaichu "+ob->query("id"));
                return;
        }

        if ( ob_fam["generation"] == my_fam["generation"] )
        {
                command("say 你我乃同辈弟子，切磋切磋倒是可以，拜师却不敢当。");
                return;
        }

        if (ob->query("shen")<50000)
        {
                command("say 你维护武林正义的义举做得不够，我还不能收你。");
                command("addoil " + ob->query("id"));
                return;
        }
/*
        if (ob->query_bac()<26)
        {
                command("shake " + ob->query("id"));
                command("say 我看你毅力不够，难有大成，我不想收你。");
                return;
        }
*/
        if (ob->query_skill("sword",1)< 90 || ob->query_skill("huanhua-jianfa",1) < 90)
        {
                command("say 我们浣花剑派以剑法为本，你是否应该在剑法方面多下些功夫呢？");
                return;
        }

        command("say 好吧，" + RANK_D->query_respect(ob) +"既然拜我为师，还望努力练功，以期能为武林正义出一份力量。");
        command("recruit " + ob->query("id"));

        return;
}

int ask_book()
{
        object me, ob;
        me = this_player();

        if (!me->query("family") || me->query("family/family_name")!="浣花剑派")
        {
                command("say " +RANK_D->query_respect(me)+
                "你不是浣花弟子，我的《浣花洗剑录》不能给你。");
                return 1;
        }

        if (this_object()->query("no_book"))
        {
                command("say " +RANK_D->query_respect(me)+
                "努力练功，但我的《浣花洗剑录》已经被人拿走了，我帮不了你。");
                return 1;
        }

        if (me->query_skill("sword",1)>60)
        {
                command("say "+RANK_D->query_respect(me)+
                "剑法已有小成，还是向师傅继续学习的好。");
                return 1;
        }

        ob = new("/d/huanhua/npc/obj/xijian");
        ob->move(this_object());

        command("say " +RANK_D->query_respect(me)+
                "努力练功,这本《浣花洗剑录》你拿去熟读，或许有所帮助。");
        command("give " + me->query("id") + " book");
        this_object()->set("no_book",1);
        return 1;
}
