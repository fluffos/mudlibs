// zhao.c 赵志敬
// By Lgg,1998.10

inherit NPC;

void create()
{
        set_name("申志凡", ({"qz dizi", "qzdizi"}));
        set("gender", "男性");
        set("age", 26);
        set("class", "taoist");
        set("long",
                "他就是全真教第三代弟子中的好手。 \n"
                "他相貌端正，但眉宇间似乎隐藏着一丝狡猾的神色。\n"
		"他是一个长须道人，看起来却有些煞气。\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianzhen" :),
                (: perform_action, "sword.jianqi" :),
        }));

        set("qi", 15500);
        set("max_qi", 15500);
        set("jing", 18000);
        set("max_jing", 18000);
        set("neili", 13000);
        set("max_neili", 13000);
        set("jiali", 60);

        set("combat_exp", 560000);
        set("score", 100000);
set_skill("qixing-jian",190);
set_skill("qixing-shou",190);
set_skill("qixing-array",180);
set_skill("hand", 199);
        set_skill("force", 80);
        set_skill("xiantian-qigong", 80);    //先天气功
        set_skill("sword", 80);
        set_skill("quanzhen-jian",180);  //全真剑
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);   //金雁功
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("strike",80);
        set_skill("haotian-zhang", 80);    //昊天掌
        set_skill("literate",60);
        set_skill("taoism",60);
set_skill("array",190);
set_skill("qixing-array",190);
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );
          set_temp("apply/attack", 100);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
               setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

