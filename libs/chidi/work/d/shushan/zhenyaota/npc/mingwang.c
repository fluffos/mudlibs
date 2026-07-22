//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit BHNPC;

void create()
{
        set_name("镇狱明王", ({ "zhenyu mingwang", "wang" }));
         set("title", HIY"地狱鬼王" +NOR);
        set("age", 1000);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 35);
        set("con", 30);
        set("cor", 40);
        
        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 4000);
        set("max_neili", 2000);
        set("jiali", 6000);
        set("combat_exp", 3000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry",300);
        set_skill("unarmed", 300);
        set_skill("shushan-force", 300);
        set_skill("zuixian-steps",300);
        set_skill("fumozhang",300);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 50);

   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
       carry_object("/clone/cloth/cloth")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", "\n镇狱明王道：“我没办法了...”\n", environment());
        }
        destruct(this_object());
}
