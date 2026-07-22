// guofu.c 郭芙
// Lklv modify 这个贱人 at 2001.10.21

inherit NPC;
void create()
{
        set_name("郭芙", ({"guo fu", "guo", "fu"}));
        set("long","她就是郭靖、黄蓉的女儿郭芙。\n");

        set("gender", "女性");
        set("attitude", "peaceful");
        set("unique", 1);

        set("age", 25);
        set("shen_type", 1);
        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 32);
        set("max_qi", 5500);
        set("max_jing", 5500);
        set("neili", 5500);
        set("max_neili", 5500);
        set("max_jingli", 5500);
        set("eff_jingli", 5500);
        set("jiali", 50);
        set("combat_exp", 1200000);
        set("chat_chance_combat", 40);

        set_skill("bihai-chaosheng", 165);
        set_skill("jieshou-jiushi", 165);
        set_skill("yuxiao-jian", 165);
        set_skill("luoying-zhang", 165);
        set_skill("anying-fuxiang", 165);
        set_skill("lanhua-shou",180);

        set_skill("hand", 165);
        set_skill("literate", 5);
        set_skill("strike", 165);
        set_skill("sword", 165);
        set_skill("parry", 165);
        set_skill("dodge", 165);
        set_skill("force", 165);

        map_skill("force", "bihai-chaosheng");
        map_skill("sword", "yuxiao-jian");
        map_skill("parry", "huifeng-jian");
        map_skill("dodge", "anying-fuxiang");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
        prepare_skill("hand", "lanhua-shou");
        set("inquiry", ([
                "郭靖" : "呀！你也知道我爹爹的名字？\n",
                "黄蓉" : "她是我娘，最疼我了。\n",
                "耶律齐" : "他……不就是……\n",
                "杨过" : "唉，我一直不知道，其实我应该是喜欢他的。\n",
                "小龙女" : "她是杨过的师父。\n",
                "贱人" : "贱人就是我，你骂得没错。我真是该死，竟然砍断了杨过的手臂……\n",
                "郭襄" : "她是我妹妹，最近又不知道跑哪里去了。\n",
        ]));

        setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object(ARMOR_D("changqun"))->wear();
        carry_object(ARMOR_D("xiupao"))->wear();
}
