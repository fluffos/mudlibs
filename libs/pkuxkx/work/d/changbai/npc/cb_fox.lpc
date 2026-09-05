// huli.c

inherit NPC;

void create()
{
        set_name("狐狸", ({ "hu li", "hu", "fox" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只矫健的狐狸，看起来有点惊魂未定。\n");
        set("attitude", "aggressive");
        set("combat_exp", 100000);

        set("str", 40);
        set("dex", 60);

	set("max_qi", 1000 + random(2000));

	set("limbs",({"头部", "身体", "爪子", "尾巴"}));
	set("verbs",({"claw", "bite"}));

        set("gem_level", ({0, 1}));
        set("item_drop_odds", ({984, 5, 5, 0, 5, 1, 0 }));
        set("luding_monster", 1);

	set_temp("apply/attack", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/dexerity", 80);
        set_temp("apply/armor", 20);

        setup();
}

void init()
{
        object me;

        ::init();

        if( interactive(me = this_player()) )
		set_leader(me);
}

void die()
{
	int i;
	object ob, corpse;
	message_vision("$N惨嚎一声，死了。\n", this_object());
    	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	corpse->move(environment(this_object()));

        if (random(4)<1) 
        {
       if (random(2)) GEM_D->drop(this_object(),this_player());
        }

	corpse->set("no_get_from", 1);
	destruct(this_object());
}
