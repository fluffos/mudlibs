//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("ÊØÉ½½£Í¯", ({ "jian tong", "tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 10000);
        set("jiali", 30);
        set("combat_exp", 3000000);
          set("max_neili", 300);
            set("max_jingli", 300);
          set("jingli", 300);
          set("neili", 300);
          set("jiali", 300);

        set_skill("force", 70);
        set_skill("shushan-force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("unarmed", 70);
        set_skill("fumozhang", 70);
        set_skill("yujianshu", 70);
        set_skill("zuixian-steps", 70);    

        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
   	add_temp("apply/damage", 15);
   	add_temp("apply/armor", 15);
        setup();
          carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

