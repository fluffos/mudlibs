//npc by yushu 2000.11
inherit NPC;
void create()
{
        set_name("ÄÐµÜ×Ó", ({"di zi"}));
        set("long","ËûÊÇÊñÉ½ÅÉµÄµÜ×Ó¡£\n");
        set("title", "ÊñÉ½ÅÉµÜ×Ó");
        set("gender", "ÄÐÐÔ");
        set("attitude", "friendly");
        set("class", "xiake");
        set("age", 20);
        set("per", 23);
        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 40);
        set("combat_exp", 80000);
        set("max_jingli", 1000);
          set("max_neili", 1000);
        set("jingli", 1000);
          set("neili",1000);
         set("jiali",1000);
        set("str", 530);
        set("con", 30);
        set("int", 10);
        set("dex", 530);
        set_skill("force", 40);
         set_skill("zuixian-steps", 40);
        set_skill("sword", 40);
        set_skill("dodge", 40);
         set_skill("yujianshu", 40);
        set_skill("parry", 40);
         set_skill("shushan-force", 40);
        map_skill("force", "shushan-force");
        map_skill("sword", "yujian-shu");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry","yujian-shu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: perform_action, "sword", "fumo" :),

       }) );
            setup();
         carry_object("/clone/cloth/cloth")->wear();
 carry_object("/clone/weapon/changjian")->wield();
            
}

ÿ
