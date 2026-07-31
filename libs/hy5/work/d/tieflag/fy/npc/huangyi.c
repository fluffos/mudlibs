 inherit NPC;
void create()
{
        set_name("»ÆÒÂÎÀ", ({ "guard", "yellow guard"}) );
        set("gender", "ÄÐÐÔ" );
        set("age", 32);
        set("cor",15);
        set("long", "ÕâÊÇÒ»Î»½ðÇ®°ï×Ü¶æµÄ»ÆÒÂÎÀ¡£\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set_skill("sword", 90+random(100));
        set_skill("dodge", 100);
        set_skill("lefthand-sword", 20+random(20));
        map_skill("sword","lefthand-sword");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duxin" :),
        }) ); 
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "»ÆÒÂÎÀÏòÄãºÈµÀ£º¿ÚÁî£¿£¿\n",
                "»ÆÒÂÎÀÏòÄãºÈµÀ£ºÕ¾×¡£®ÁÁÄãµÄÑüÅÆ£¿\n",
        }) );
        
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/tangfu")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}      
