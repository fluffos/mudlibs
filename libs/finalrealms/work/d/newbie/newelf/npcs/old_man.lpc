//by Taggert
inherit "/obj/monster";
void setup()
{
    set_short("old man");
    set_name("Old Man");
    set_long("\nThe old man looks around as if he is confused."
      " After about a minute of staring into space he looks at you."
      "\n\n");
    set_main_plural("old men");
    add_plural("men");
    add_alias("old");
    add_alias("man");
    set_gender(1);
    init_equip();
    set_aggressive(0);
    set_level(8);
    set_max_hp(25);
}
void init()
{
    add_action("reward_me","tolan");
    ::init();
}
int reward_me(){
    TP->adjust_xp(1000);
    return 1;
}
