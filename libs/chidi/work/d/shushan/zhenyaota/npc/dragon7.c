//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
// modified by vikee 2000.11
inherit BHNPC;

void create()
{
        set_name("ÊØÖù¾ŞÁú", ({ "dragon", "long" }));
               set("title",HIB "ÀîÁúµÄ·ÉÌì×øÆï" +NOR);
        set("race","Ò°ÊŞ");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 20000);
        set("combat_exp", 3000000);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "Î²°Í", "¶ÇÆ¤", "ºó×¦"}) );
        set("verbs", ({ "bite", "claw"}) );

        set_skill("force", 300);
        set_skill("dodge",300);
        set_skill("parry",300);
        set_skill("unarmed", 300);

        map_skill("dodge", "dragonstep");
        map_skill("parry", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("unarmed", "dragonfight");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "shield" :),
        }) );
   add_temp("apply/damage", 50);
   add_temp("apply/armor", 50);
        setup();
}

