 inherit NPC;
void use_poison(); 
void create()
{
        set_name("ÏìÎ²Éß", ({ "snake" }) );
        set("race", "Ò°ÊÞ");
        set("age", 4);
        set("yes_carry", 1);
        set("long", "Ò»Ìõ¾ç¶¾µÄÏìÎ²Éß¡£\n"); 
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Î²°Í", "Æß´ç" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 50);
        set("combat_exp", 5000 + random(50000));
        set("bellicosity", 300 );
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
        if (!random(2)) carry_object("/d/shanliu/npc/obj/xiangweishedan");
} 
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"Äã¾õµÃÁ³ÉÏ¾çÍ´£¬ÉìÊÖÒ»Ãþ·¢ÏÖÁ½¸ö¶¾ÑÀÓ¡ºÛ¡£\n");
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}   
