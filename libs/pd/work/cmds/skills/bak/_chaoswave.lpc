#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_chaoswave(string str)
{
    int i, x;
    string party;
    object *per=({}), *mobs=({});
    if(str) return 0;
    if (!spell()) {
        return 0;
    }
    if(this_player()->query_ghost())
        return notify_fail("You howl.\n");
    if (this_player()->query_disable())
        return notify_fail("You are busy.\n");
    if (this_player()->query_mp() < 70)
        return notify_fail("Your spell fails, due to lack of magic.\n");
    if (environment(this_player())->query_property("no attack") || environment(this_player())->query_property("no magic") )
    {
        write("Greater powers prevent your malice.");
        return 1;
    }
    write("%^BOLD%^%^GREEN%^You flood your the area with waves of chaos!%^RESET%^\n");
    say("%^BOLD%^%^GREEN%^"+this_player()->query_cap_name()+" floods the area with the negative energies of chaos!%^RESET%^\n");
    this_player()->add_mp(-(random(25)));
    
    
    if (this_player()->query_party())
    party = this_player()->query_party();
    else party = "AdkIl898-FL00Jn-neInfe_ron";
    
    per = all_inventory(environment(this_player()));

    for(x = 0; x < sizeof(per); x++)
    {
        if( per[x]->is_living() && per[x]!= this_player() &&
            per[x]->query_party() != party && !wizardp(per[x]) &&
            !per[x]->query_ghost())
        {
            mobs = mobs + ({ per[x] });
        }
    }

    this_player()->set_paralyzed(1+random(2), "You are concentrating creating waves of chaos.");
    
    for(x = 0; x < sizeof(mobs); x++)
    {
        if (this_player()->query_mp() < 70) {
            write ("%^BOLD%^%^GREEN%^The energy dissapates into nothingness.%^RESET%^");
            break;
        }
        i = BALANCE_D->get_damage( this_player(), mobs[x], 3, ({ "magic attack", "necromancy" }),
          ({ "wisdom" }), ({ "wisdom", "intelligence" }) );

        i = i * (((2.0 / (sizeof(mobs) + 1)) + (1.0 / (x + 1.0))) / 2);
        i = i * 4 / 3;
        if(mobs[x]->query_skill("magic defense") + mobs[x]->query_stats("wisdom") > i) {
            write("%^BOLD%^%^GREEN%^The waves of chaos flow around "+mobs[x]->query_cap_name()+" doing no harm.%^RESET%^\n");
            say("%^BOLD%^%^GREEN%^Waves of chaos flow around "+mobs[x]->query_cap_name()+ " doing no harm.%^RESET%^\n");
            tell_object(mobs[x], "%^BOLD%^%^GREEN%^The waves of chaos flow around you doing no harm!%^RESET\n");
            continue;
        }
        if(!this_player()->kill_ob(mobs[x])) {
            write(mobs[x]->query_cap_name()+" can't be attacked by you yet.");
            return 1;
        }
        mobs[x]->damage(i);
        this_player()->kill_ob(mobs[x]);
        tell_object(mobs[x], "%^BOLD%^%^GREEN%^The waves of chaos cause you great pain!%^RESET%^\n");
        tell_room(environment(mobs[x]), "%^BLUE%^The waves greatly wound "
            +mobs[x]->query_cap_name()+" with negative engergy!%^RESET%^\n", ({ mobs[x] }));
        this_player()->add_mp(-i/9);
        this_player()->add_skill_points("magic attack", i/30 + 2);
        this_player()->add_skill_points("necromancy", i/30 + 2);
        this_player()->set_disable();        
    }
    return 1;
}

void help() {
    message("help", "Syntax: <chaoswave>\n"
      "\n"
      "A necromancer spell that sends waves of negative energy known\n"
      "as chaos towards everything in the immediate area.\n",
      this_player());
}
int spell() {
    object tp;
    tp = this_player();
    if (tp->query_subclass() != "necromancer")
        return 0;
    if (tp->query_level() < 30) return 0;
    return 1;
}
