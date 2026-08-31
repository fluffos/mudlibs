#include <std.h>
inherit OBJECT;

object owner;

void create() {
    ::create();

    set_name("shield_object_duh_001");
    set_heart_beat(1);
    set_short("");
    set_long("psiblades shield blah");
    set_weight(0);
    set_value(0);
    set_id(({"psiblades_shield_object_001"}));
}

void object_gone()
{
    this_object()->remove();
}

void heart_beat()
{
    if(!environment(this_object())) return;
    if((!owner) && (environment(this_object())->is_living()))
        owner = environment(this_object());

    if( !owner )
    	return;
    
	if(sizeof(owner->query_attackers()) > 0) {
        int i, dmg;
        object *mob;
        mob = owner->query_attackers();
        i = sizeof(mob);
        while(i--)
        {
         if( !mob[i] ) continue;
            if(environment(owner)->query_property("safe")) break;
            if(environment(owner)->query_property("no attack")) break;
//if(mob[i]->query_rest_type()) continue;
            
            message("info", "%^BOLD%^%^CYAN%^The shards of energy spark as they slice into "+mob[i]->query_cap_name()
                +"!%^RESET%^", owner);
            message("info", "%^BOLD%^%^CYAN%^Shards of energy spark as they slice into "
                 +mob[i]->query_cap_name()+"!%^RESET%^",
                environment(owner), ({ mob[i], owner }));
            message("info", "%^BOLD%^%^CYAN%^You pass through shards of energy before you attack "
                +owner->query_cap_name()+ "!%^RESET%^", mob[i]);
            dmg = 10 + random((owner->query_skill("psionics") / 25));
            if(dmg < 10) dmg = 10;
            mob[i]->damage(dmg);
        }
               
    }
}


int drop()
{
    return 1;
}
