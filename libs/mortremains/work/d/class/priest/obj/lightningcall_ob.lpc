

#include <mudlib.h>
#include <m_spells.h>

inherit OBJECT;
inherit SPELL;



int lightning_delay = 1;

void create() {
    set("id", ({ "#LIGHTNINGCALL_OB#" }) );

}
void init(){
    add_action("bolt", "bolt");
}
void begin_spell (object ob) {
    int str_curr;
    string c_str;

    call_out("countdown", 10);
    call_out("remove" , (ob->query_level() * 12) );

    return;
}

void countdown(){
    lightning_delay = 0;
    return;
}


int bolt (string str){
    object caster = environment(this_object());
    object target, room;
    int lvl, dmg, i, dmglvl, x;
    string name;

    if (!str) str = "NONE";
    if (str=="NONE") target = caster->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write("You dont see that here!\n");
	return 1;
    }     

    if (!check_valid_targ(caster, target)) return 0;

    if (lightning_delay){ 
	write("You must wait to build more power!\n");
	return 1;
    }

    lvl = caster->query_level("priest");
    dmglvl = lvl+2;
    if (dmglvl > 12) dmglvl = 12;
    target->kill_ob(this_object());
    target->set("last_attacker", caster);
    room = environment(target);

    for (i=0;i<dmglvl;i++){
	dmg += (random(8)+1);
    }
    name = target->query("cap_name");
    lightning_delay = 1;
    call_out("countdown", 10);
    tell_room(room, caster->query("cap_name")+" calls a lightning strike upon "+name+"!\n",
      target);
    tell_object(target,  caster->query("cap_name")+" calls a lightning strike upon you!\n");

    if (!check_magic_resist(lvl,target,20,dmg)) return;
    //    x = query_save_mod(caster,target, ({"evocation"}) );
    x = target->save_throw(x);

    if (x){
	if (target->query_skill("Evasion")){
	    tell_room(room, name+" Dodges the lightning strike!\n",
	      target);
	    tell_object(target, "You dodge the lightning strike!\n");
	}
	dmg = (dmg/2);
    }

    dmg - target->receive_damage(dmg, "electricity", caster);

    switch(dmg) {
    case -1000..-1 :
	tell_room(room, "The lightning actually heals "+name+"!\n",
	  target);
	tell_object(target, "The lightning actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" just laughs at the spell's puny energies.\n",
	  target);
	tell_object(target, "The spell leaves you unscathed.\n"+
	  "You just laugh.\n");
	break;
    case 1..25 :
	tell_room(room, name+" escapes most of the lightning strike.\n", target);
	tell_object(target, "You escape most of the lightning strike.\n");
	break;

    case 26..50 :
	tell_room(room, wrap(name+" is electrified by the lightning!\n"));
	tell_object(target, wrap("You are electrified a bit by the lightning!\n"));
	break;
    default :
	tell_room(room, wrap(name+" is electrocuted mightily!\n"));
	tell_object(target, wrap("You are electrocuted mightily!\n"));
	break;

    }

    target->set("last_attacker", caster);
    return 1;
}
int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your call lightning spell ends.\n");
    }
    ::remove();
    return 1;
}   

/* EOF */
