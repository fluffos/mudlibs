//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

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
        
        set("max_qi", 40000);
        set("max_jing", 40000);
        set("neili", 400000);
        set("max_neili", 2000);
        set("jiali", 600);
        set("combat_exp", 80000000);

        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("parry", 1500);
        set_skill("unarmed", 1500);
        set_skill("shushan-force", 1500);
        set_skill("zuixian-steps", 1500);
        set_skill("fumozhang",1500);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 50);
/*
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :),
        }) );
*/
   set_temp("apply/damage", 200);
   set_temp("apply/armor", 200);

        setup();
//        carry_object("/d/obj/cloth/jinjinyi")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", "\n镇狱明王道：“我没办法了...”\n", environment());
        }
        destruct(this_object());
}
