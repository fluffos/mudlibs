// Sprite *puke*

inherit "/obj/monster";

void setup() {
    set_name("sprite");
    add_adjective("little");
    set_al(1);
    set_short("sprite");
    set_main_plural("sprites");
    set_random_stats(6, 13);
    set_long("A small 2 foot tall elvish looking creature with wings.\n");
    set_aggressive(0);
    adjust_money(random(10),"copper");
    set_join_fight_mess("A sprite gleefully throws itself into combat.\n");
    set_race("sprite");
    set_level(random(9));
    set_wimpy(0);
    load_chat(10,
      ({
        1, "'Hello, how are you today ?",
        1, "@smile happily at $lname$",
      }));
    load_a_chat(30,
      ({
        1, "'DIE, DIE, DIE!",
        1, "'Grrrrrrrr!!!",
        1, ":tries to stab you."
      }));
        new("/baseobs/armours/cape")->move(this_object());
    this_object()->init_equip();

} /* setup() */
