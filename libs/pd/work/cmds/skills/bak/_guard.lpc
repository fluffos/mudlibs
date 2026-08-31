#include <std.h>
inherit DAEMON;
int spell();
string type() { return "defense"; }
void remove_guard(string tname, object tob);

mapping guarded;

create()
{
    guarded = ([]);
}
 
int cmd_guard(string str) {
    object ob, tp;
    int defense;
    int cost;
    int time;
    
    if (!spell()) {
      write("What?\n");
      return 1;
    }
    
    tp = this_player(); 
    
    if(!str) {
        notify_fail("Cast guard on whom?\n");
        return 0;
    }
    
    ob = present(str, environment(tp));
    
    if(!ob && (str == "me" || str == "myself"))
        ob = tp;
    
    if(!ob) {
        notify_fail(capitalize(str)+" is not here.\n");
        return 0;
    }
    
    if(!living(ob)) {
        notify_fail(capitalize(str)+" could not possibly be safer.\n");
        return 0;
    }
    
    // This is for mobs. I don't use object as the index, that tends to cause
    // problems when players go idle, or disconnect, or whatever. -- Nesoo
    if( guarded[ob->query_name()] && member_array(ob, guarded[ob->query_name()]) != -1 )
        return notify_fail(ob->query_cap_name() + " is already guarded.\n");
    
    if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
       return notify_fail("You are busy.\n");
    
    if(environment(tp)->query_property("no magic"))
        return notify_fail("Something is blocking your concentration.\n");
    
    if(ob == tp)
        cost = 20 + random(40);
    else
        cost = 20 + random(20);
    
    if((int)tp->query_mp() < cost)
        return notify_fail("Too low on magic power.\n");
    
    defense = (int)tp->query_skill("magic defense");
    
    if (defense < 10) {
       write("You mutter words beyond understanding.");
       say(tp->query_cap_name()+" mutters words beyond understanding.", tp);
       return 1;
    }
    
    tp->set_magic_round(1);
    tp->add_mp(-cost);
    write("You cast a magical guard upon "+ob->query_cap_name()+".");
    tell_object(ob, tp->query_cap_name()+
      " casts a magical guard upon you.");
    say(tp->query_cap_name()+" casts a magical guard upon " 
      +ob->query_cap_name()+".", ob);
    time = random(defense/10)+30;
    ob->add_magic_protection( ({ 0, random(defense/15)+3, time}) );
    tp->add_skill_points("magic defense", random(defense/20));
    tp->set_disable();
    if( !guarded[ob->query_name()] )
        guarded[ob->query_name()] = ({ ob });
    else
        guarded[ob->query_name()] += ({ ob });
    call_out("remove_guard", time, ob->query_name(), ob);
    return 1;
}

void remove_guard(string tname, object tob)
{
    if( !tname || !guarded[tname] )
        return;
    
    if( !tob )
        map_delete(guarded, tname);
    else
    {
        guarded[tname] -= ({ tob });
        if( sizeof(guarded[tname]) == 0 )
            map_delete(guarded, tname);
    }
    
    if( !tob )
        tob = find_player(tname);
    
    if( tob )
    {
        message("info", "%^BOLD%^%^CYAN%^The magical guard upon you " 
            + "has worn away.%^RESET%^", tob);
        message("info", "%^BOLD%^%^CYAN%^The magical guard upon "
            + tob->query_cap_name() + " fades away.", environment(tob), tob);
    }
}

void help() {
  write("
Syntax: <guard [target]>
This spell of protection brings a magical guard upon the target.
Although it is weaker than some other protection spells, guard is
a lower-level mage spell.
");
}

int spell() {
   object tp;
   tp = this_player();
   if (tp->query_level() < 1) return 0;
   if (!tp) return 0;
   if (tp->query_skill("magic defense") >= 5 && tp->query_class() == "mage")
   return 1;
}

