/* basically made mods to the wiz-war guild ob
 * Raskolnikov Oct 96
 */
inherit "std/guild";

int query_skill_cost(string skill)
{
    return 0;
}

void setup()
{
    set_name("shifter");
    set_short("Shapeshifter");
    set_long(
      "Uno de los seres mas misteriosos, el Shapeshifter "
      "es capaz de cambiar su forma arbitrariamente. Esta habilidad "
      "requiere muchos anyos para perfeccionarla, pos lo que el coste "
      "de avanzamiento es bastante alto.\n");
    reset_get();
    set_main_skill("int");
    add_guild_command("shift", 1);
    add_guild_command("unshift", 1);
    add_guild_command("centrar", 1);
    add_guild_command("sigilar", 1);
    add_guild_command("fix", 1);
    add_guild_command("juzgar", 1);
    add_guild_command("esconderse", 1);
}

int query_legal_race(string race)
{
    switch(race)
    {
    case "elf":      return 1;
    case "half-elf": return 1;
    case "drow":     return 1;
    case "human":    return 1;
    default:         return 0;
    }
}

/* since only one form can wield/wear anything let them wield or wear
 * anything in their normal state
 */
int query_legal_armour(string type)
{
    return 1;
}

int query_legal_weapon(string type)
{
    return 1;
}

int query_extr_str()  { return 1; }
//int query_dice()         { return 10; }
int query_hp_dice(object myp) { return 3; }
int query_hp_min(object myp) { return 6; }
int query_gp_dice(object myp) { return 4; }
int query_gp_min(object myp) { return 9; }
int query_advance_cost() { return 1000; }
int query_xp_cost()      { return 3000; }
int query_thac0_step() { return 5; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
    int bon;

    bon=50-(int)me->query_level();
    bon = ( bon<0 ? 0 : bon );

    return bon;
}
mixed query_legal_spheres()
{
    return ({  });
}


void start_player(object ob)
{
    ::start_player(ob);

    //if(ob->query_str() - ob->query_tmp_str() >= 18)
    //return;
    if(ob->query_str() - ob->query_tmp_str() < 17)
	return;

    if(ob->query_extreme_str())  return;

    ob->set_extreme_str(roll(1,10));
    tell_object(ob,"Has tirado fuerza extrema.\n");
}

void init()
{
    this_player()->setmin("@$N llega de $F.");
    this_player()->setmout("@$N se va hacia $T.");
    ::init();
}
