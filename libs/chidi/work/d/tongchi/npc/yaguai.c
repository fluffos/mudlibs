inherit BHNPC;
void create()
{
         set_name("Ö£ÎÞÑÔ", ({ "zheng wuyan", "zheng"}));
        set("nickname", HIC "ÑÆ¹Ö" NOR);
    set("long", 
              "Í¨³Ô°ïÁù¹ÖÖ®Ò»ÑÆ¹ÖÖ£ÎÞÑÔ\n");
    set("gender", "ÄÐÐÔ");
    set("age", 22);
    set("attitude", "peaceful");
          set("shen",0);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
    
        set("qi", 10000);
        set("max_qi", 10000);
          set("jing", 6000);
         set("max_jing", 8000);
          set("neili", 9000);
          set("max_neili", 6000);
        set("jiali", 200);

        set("combat_exp", 3200000);
        set("score", 10000);
        set_skill("force", 320);
        set_skill("dodge", 320);
        set_skill("parry", 320);
        set_skill("sword",330);
    set("shen", 50000);
        set_skill("unarmed",320);
        set_skill("dabei-zhang",320);
        set_skill("fanyun-force",320);
        set_skill("langzi-sword",330);
         set_skill("piaomiao-shenfa",330);

        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "fanyun-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "langzi-sword");

        prepare_skill("sword","guxing-sword");
        create_family("Í¨³Ô°ï",3,"µÜ×Ó");

    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
