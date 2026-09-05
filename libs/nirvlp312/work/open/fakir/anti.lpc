inherit "/players/vertebraker/closed/std/monster";

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("mage");
    set_alias("anti-healer");
    set_short("A mage named Anti-Healer");
    set_long("\n\
A black cross adorns his chest and he stands defiantly\n\
against you.  A piercing black glow dims his eyelids\n\
and pulsates against his pale white skin.  A wizened\n\
stream of white jets through his black hair, and\n\
a twisted bone staff rests in his right hand.\n");
    set_race("human");
    set_level(20);
}

void
heart_beat()
{
    object shield, defend;
 
    if(!environment()) return;

    ::heart_beat();
    if(attacker_ob && (shield = present("shielding", attacker_ob)) &&
       (shield->id("field")) && (creator(shield) == "mythos"))
    {
      tell_object(attacker_ob,
"The mage waves a hand and the shield around you\nis destroyed.\n");
      tell_room(environment(),
"The mage waves a hand and the shield around " +
(string)attacker_ob->query_name() + "\nis destroyed.\n",
      ({ attacker_ob }));
      shield->clear();
    }
    if(attacker_ob && 
       (defend = present("defend_spell", attacker_ob)))
    {
      tell_object(attacker_ob, "\
The mage glances at the defensive field around you and\n\
shatters it completely!\n");
      tell_room(environment(), "\
The mage shatters the defensive field surrounding\n"
+ (string)attacker_ob->query_name() + ".\n");
      defend->stop();
    }
}
