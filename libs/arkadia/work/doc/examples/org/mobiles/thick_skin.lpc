inherit "/std/monster";

create_monster()
{
    int i;

    set_name("goblin");
    set_living_name("goblin");
    set_long("It's very small but it looks back on you and shows its teeth.\n");
    set_race_name("goblin");
    set_adj("small");

    default_config_mobile(10);

/* Set the unarmed attacks and armour classes, an array of three works as well as
   one number to the hitloc_unarmed() */

    set_all_hitloc_unarmed(5); /* also an array like ({ 2, 0, 4 }) */
    set_all_attack_unarmed(10, 10);
}

