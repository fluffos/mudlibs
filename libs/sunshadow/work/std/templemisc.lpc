#include <std.h>
#include <daemons.h>
inherit CVAULT;

string diety;
int tick;
void trigger_ward();

void create() {
   ::create();
   set_heart_beat(1);
}

void set_temple(string str) {
    diety = str;
    set_property("blessed",({diety}));
}

string query_diety() {
    return diety;
}

int is_temple() { return 1; }

void init() {
   ::init();
    call_out("warning", 2, this_player());
   //if(!present("templewardxxx",TP)) new("/d/magic/obj/templeward")->move(TP);
}

void warning(object who)
{
    tell_object(who, "%^CYAN%^BOLD%^You feel the power of the patron deity protecting this place. Hostile action against the faithful of this deity will be punished.%^RESET%^");
    return;
}

void heart_beat()
{
    object *faithful, *aggressors, *tmp, sickened;
    
    ::heart_beat();
    
    tick++;
    
    if(tick < 3)
        return;
    
    tick = 0;
    
    faithful = ({  });
    
    if(diety == "ashra")
    {
        faithful = filter_array(all_living(this_object()), (: ($1->query_diety() == "khyron" || $1->query_diety() == "nilith" || $1->query_diety() == "lord shadow" || $1->query_diety() == "the faceless one") :));
    }
    else if(diety == "edea")
    {
        faithful = filter_array(all_living(this_object()), (: ($1->query_diety() == "jarmila" || $1->query_diety() == "callamir" || $1->query_diety() == "kreysneothosies") :));
    }
    else
    {
        faithful = filter_array(all_living(this_object()), (: $1->query_diety() == diety :));
    }
    
    if(!sizeof(faithful))
        return;
    
    aggressors = ({  });
    
    foreach(object ob in faithful)
    {
        tmp = ob->query_attackers();
        
        foreach(object dude in tmp)
        {
            if(member_array(dude, aggressors) < 0)
                aggressors += ({ dude });
        }
    }
    
    sizeof(aggressors) && aggressors = filter_array(aggressors, (: userp($1) && $1->query_diety() != diety :));
    
    if(!sizeof(aggressors))
        return;
    
    if(catch(sickened = load_object("/std/effect/status/sickened")))
        return;
    
    foreach(object foe in aggressors)
    {
        if(SAVING_THROW_D->do_save(foe, 85, "will"))
            continue;
        
        tell_room(this_object(), "%^MAGENTA%^" + foe->query_cap_name() + " is struck with a sense of dread!%^RESET%^", foe);
        tell_object(foe, "%^MAGENTA%^You feel a sense of dread from fighting in this holy place!%^RESET%^");
        foe->cause_typed_damage(foe, "torso", roll_dice(5 + foe->query_level() / 10, 6), "divine");
        sickened->apply_effect(foe, 1);
    }   
}

/*
void trigger_ward() {
   object *combatants, destroom;
   int i, flag;
   combatants = all_living(TO);
   for(i = 0;i< sizeof(combatants); i++) {
     if(sizeof(combatants[i]->query_attackers()) || present("templewardxxx",combatants[i])->is_combatant()) {
       if(!flag) {
         destroom = new("/d/magic/room/templeward");
         flag = 1;
       }
       tell_object(combatants[i],"%^BOLD%^%^CYAN%^A s%^WHITE%^p%^CYAN%^ar"
"%^BLUE%^k%^CYAN%^ling orb of azure energy springs into being around you, and "
"the temple disappears from view!%^RESET%^");
       combatants[i]->move(destroom);
     }
   }
   if(flag) tell_room(TO,"%^BOLD%^%^CYAN%^A s%^WHITE%^p%^CYAN%^ar%^BLUE%^k"
"%^CYAN%^ling orb of azure energy springs into being around the combatants, and "
"they disappear from view!%^RESET%^");
}
*/
