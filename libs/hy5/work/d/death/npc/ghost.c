// ghost.c

inherit NPC;

void create()
{
        set_name("¹Â»êÒ°¹í", ({ "ghost", "wandering ghost" }) );
        set("age", 45);
        
        set("str", 24);
        set("cor", 26);

	set("max_jing", 900);
	set("max_qi", 900);
        set("env/wimpy", 70);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
}

int is_ghost() { return 1; }
