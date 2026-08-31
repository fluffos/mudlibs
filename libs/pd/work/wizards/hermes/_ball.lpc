#include <std.h>
inherit DAEMON;
int spell();
int spell_hit(object ob);
int cmd_ball(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, para,i;
    string what, *strengths, *weaknesses;
    object *inv;
para = 5;   
 
if (!spell()) {
      write("What?\n");
      return 1;
   }
    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if(environment(tp)->query_property("no magic")) {
        notify_fail("Something seems to be blocking your
concentration.\n");
        return 0;
    }
     if((int)tp->query_mp() < 550) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("To whom do you wish to cast this at?\n");
            return 0;
        }
    }
    else {
        ob = present(str, environment(tp));
        if(!ob) {
            sscanf(str, "%s %d", what, which);
            inv = all_inventory(environment(tp));
            for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
                if(inv[i]->id(what)) {
                    skip++;
                    if(skip == which) ob = inv[i];
                }
            }
            if(!ob) {
                notify_fail("No "+str+" here!\n");
                return 0;
            }
        }
    }
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    if(ob == tp) {
        notify_fail("You have to be kidding me.\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    if(ob->query_property("no bolt")) {
        notify_fail(sprintf("%s is immune to electrical attacks.\n", 
          ob->query_cap_name()));
        return 0;
    }
    if(!ob->kill_ob(tp, 0)) return 1;
tp->force_me("say %^GREEN%^%^BOLD%^Power of %^RED%^N%^BLUE%^a%^RED%^t%^BLUE%^u%^RED%^r%^BLUE%^e%^GREEN%^. Heed my call. Help me destroy my current foe!\n");
tp->set_paralyzed(para, "You are recovering from the shock of such a powerful spell.");       
attack = ((int)tp->query_stats("wisdom") * 5 +
(int)tp->query_skill("nature")*(5) + (int)tp->query_skill("magic attack")* 4);
    wisdom = ((int)ob->query_stats("wisdom")/3 +
(int)ob->query_skill("magic defense")/4);
    attack -= wisdom;
	if(attack > (tp->query_level() * 20) && !ob->is_monster())
	attack = (tp->query_level() * 30);    
weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses))
        weaknesses = ({ });
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths))
        strengths = ({ });
    if(member_array("electricity", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("electricity", strengths) != -1)
            attack -= random( (wisdom/2) +5);
    }
    if(member_array("magic", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("magic", strengths) != -1)
            attack -= random( (wisdom/2) + 5);
    }
    if(attack < 1) attack = 0;
    if((string)tp->query_class() == "clergy") attack++;
 
write("A ball of %^BOLD%^l%^YELLOW%^i%^WHITE%^g%^YELLOW%^h%^WHITE%^t%^YELLOW%^n%^WHITE%^i%^YELLOW%^n%^WHITE%^g%^RESET%^ swells up and %^ORANGE%^%^BOLD%^shoots%^RESET%^ out of your outstreched hand, heading %^RED%^%^BOLD%^straight%^RESET%^ towards the target.");
tell_room(environment(tp), ""+tp->query_cap_name()+
              " unleases a giant ball of l%^YELLOW%^i%^WHITE%^g%^YELLOW%^h%^WHITE%^t%^YELLOW%^n%^WHITE%^i%^YELLOW%^n%^WHITE%^g%^RESET%^ at 
"+(string
)ob->query_cap_name()+"!", 
              ({ ob, tp }));
    tell_object(ob, ""+tp->query_cap_name()+
                " casts a giant %^RED%^%^BOLD%^ball%^RESET%^ of %^BOLD%^l%^YELLOW%^i%^WHITE%^g%^YELLOW%^h%^WHITE%^t%^YELLOW%^n%^WHITE%^i%^YELLOW%^n%^WHITE%^g%^RESET%^ at you!");
    tp->set_casting(attack + (random(tp->query_level())/2));
 
tp->add_skill_points("nature", (10 + random(20)));
    tp->add_mp(-(600) + random(100));
call_out("spell_hit", para, ob);
return 1;
}
void help() {
    write("Syntax: <ball [(living)]>\n"
        "The best Druids obtain mastery over nature itself "
        "with this attack, a Druid can summon the force of "
        "a great ball of lightning to strike his "
        " current opponent.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_subclass() != "druid") return 0;
   if (tp->query_level() < 50) return 0;
   return 1;
}
int spell_hit(object ob) {
tell_object(ob, "%^BOLD%^You are %^RED%^hit%^WHITE%^ by a %^BLUE%^giant%^WHITE%^ ball of %^YELLOW%^e%^WHITE%^l%^YELLOW%^e%^WHITE%^c%^YELLOW%^t%^WHITE%^r%^YELLOW%^i%^WHITE%^c%^YELLOW%^a%^WHITE%^l might!");
write("%^YELLOW%^%^BOLD%^The small %^BLUE%^smile%^YELLOW%^ on your face is %^WHITE%^illuminated%^YELLOW%^ by the electrical "
"discharge as the ball of lightning hits its target.");   	
return 1;
}
