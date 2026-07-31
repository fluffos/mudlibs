//npc by yushu 2000.11
inherit NPC;
void create()
{
        set_name("ÊñÉ½µÜ×Ó", ({"di zi"}));
        set("long","ËûÊÇÊñÉ½ÅÉµÄµÜ×Ó¡£\n");
        set("title", "ÊñÉ½ÅÉµÚÈı´úµÜ×Ó");
	 if(random(10)<7)
	    set("gender", "ÄĞĞÔ" );
	  else
	    set("gender", "Å®ĞÔ" );
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
        set("max_jingli", 300);
        set("max_neili", 300);
        set("jingli", 300);
        set("neili",300);
         set("jiali",100);
        set_skill("force", 120);
         set_skill("zuixian-steps",120);
        set_skill("sword", 120);
        set_skill("dodge", 120);
         set_skill("yujianshu",120);
        set_skill("parry", 120);
         set_skill("shushan-force", 120);
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
       carry_object("clone/weapon/changjian")->wield();
}

ÿ
