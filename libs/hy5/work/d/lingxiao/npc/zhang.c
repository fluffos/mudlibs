//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;
string ask_jiu();

void create()
{
        set_name("张万风",({"zhang wanfeng","zhang"}));
        set("gender", "男性");
        set("age", 20);
        set("long", 
               "他是凌霄城第六代弟子张万风,正在这喝酒喝得高兴。\n");
        set("attitude", "peaceful");

        set("str", 25);
        set("con", 30);
        set("int", 24);
        set("dex", 30);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("qi", 1200);
        set("max_qi", 1200);
        set("inquiry", ([
            "jiu" :    (: ask_jiu :), 
            "参阳玉酒" :    (: ask_jiu :), 
        ]) ); 
        set("jiu_count", 5);

        set("combat_exp", 50000);
        set("shen_type", 1);
        set("score", 20000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("literate", 40);

        set_skill("xueshan-sword", 60);
        set_skill("bingxue-xinfa", 60);
        set_skill("snow-zhang", 60);
        set_skill("snowstep", 60);

        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("凌霄城", 6, "弟子");
        setup();

        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

string ask_jiu()
{
        object ob;
        
        if (this_player()->query("family/family_name") != "凌霄城")
                return RANK_D->query_respect(this_player()) + 
                "阁下非我凌霄弟子，我为什么要给你参阳玉酒?";

        if (  present("shenyang yujiu", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "你身上就有一壶,还想要,别那么贪心！"; 
        if (query("jiu_count") < 1) return "哎呀呀！最近好酒的人还真不少！对不起,参阳玉酒已经发完了";

        ob = new("/d/lingxiao/obj/jiu");
        ob->move(this_player());

        add("jiu_count", -1);

        message_vision("$N接过一壶参阳玉酒。\n",this_player());
        return "拿去吧,不要当酒喝呀。";

}

