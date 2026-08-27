inherit "/std/monster";

create_monster()
{
    int i;

    set_name("goblin");
    set_living_name("goblin");
    set_long("It's very small but it looks back on you and shows its teeth.\n");
    set_race_name("goblin");
    set_adj("small");

    set_gender(2); /* male = 0, female = 1, other = 2 */

    default_config_mobile(20);

    set_alignment(-70);
    set_aggressive(1);
/* This monster is aggressive to all living objects comming close. He will try
 * to make the standard kill command. If the dis is not enough to attack 
 * someone he won't.
 *
 * It's of course possible to make monstyers aggressive only to elves and so
 * on. You just redefine the init_attack() function, or make one on your
 * own.
 */
}

