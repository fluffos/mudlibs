//	Written by The Inferno

#include <std.h>

inherit DAEMON;

int cmd_breathe(string str) {
    object tp, ob;
    string type, me, you, gen;
    int attack, fin;

    tp = this_player();
    if(tp->query_ghost()) {
         notify_fail("You cannot do that in an immaterial state.\n");
         return 0;
    }
    if (tp->query_race() != "dragon") {
       notify_fail("You breathe in and out and feel light-headed.\n");
        return 0;
    }
    if (tp->query_disable()) return 1;
    if (tp->query_dragon_level() == 1) {
       write("A hatchling does not have the power needed to use their breath..");
       return 1;
    }
    if (tp->query_sp() < 50 || tp->query_mp() < 75) {
	notify_fail("You are too weak.\n");
	return 0;
    }
   if(this_player()->query_casting()) return 1;
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
    if(!str) {
  	ob = (object)tp->query_current_attacker();
	if(!ob) {
	    notify_fail("Syntax: <breathe [living]>\n");
	    return 0;
	}
    }
    else {
	ob = present(str, environment(tp));
	    if(!ob) {
		notify_fail("No "+str+" here!\n");
		return 0;
	    }
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing!\n");
	return 0;
    }
    if(ob==tp) {
	write("Now wouldn't that be fun?");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
	notify_fail("You cannot attack link-dead players.\n");
	return 0;
    }
    if(!tp->kill_ob(ob, 0)) return 1;
   attack = tp->query_stats("strength") + tp->query_stats("constitution")/2;
   attack += (tp->query_stats("dexterity"))/4 +
             tp->query_skill("attack")/2;
   attack -= ob->query_stats("constitution") + ob->query_stats("wisdom")/3;
   attack *= tp->query_dragon_level();
   if (attack < 10) {
      write("%^YELLOW%^"+ob->query_cap_name()+" dodges your breath weapon!");
      tell_room(environment(ob), "%^YELLOW%^"+ob->query_cap_name()+
            " dodges "+tp->query_cap_name()+"'s breathe weapon!", ({ tp, ob }));
      tell_object(ob, "%^YELLOW%^You dodge "+tp->query_cap_name()+"'s breath weapon!");
      return 1;
   }
   fin = random(attack)*2;
   if (fin > attack) fin = attack - random(attack/6);
   if (fin < attack/3) fin = attack - random(attack/4);
   if (tp->query_subclass() == "storm") fin = fin + (fin/2);
   if (random(7) < 5) fin = fin - random(fin/6);
   else fin = fin + random(fin/4);
   ob->add_hp(-fin);
   ob->force_me("hp");
   if (wizardp(this_player())) write("[*] "+fin);
   tp->add_sp(-100+random(30));
 tp->add_mp(-50+random(20));
   type = tp->query_subclass();
   tp->set_disable();
   me = tp->query_cap_name();
   you = ob->query_cap_name();
   gen = this_player()->query_title_gender();
/*
air     cloud   earth   water   ice    mist    fire   wind   lightning
forest  sonic   sand    shadow  storm  faerie
*/
   if (type == "faerie") {
      write("%^RESET%^%^MAGENTA%^You %^BOLD%^breathe%^RESET%^%^MAGENTA%^ "
   "magical%^RESET%^%^MAGENTA%^ %^BOLD%^faerie%^RESET%^%^MAGENTA%^ "
   "dust%^BOLD%^ on%^RESET%^%^MAGENTA%^ your%^BOLD%^ opponent!%^RESET%^");
      tell_object(ob, "%^RESET%^%^MAGENTA%^"+me+" %^BOLD%^breathes%^RESET%^%^MAGENTA%^ "
   "magical%^RESET%^%^MAGENTA%^ %^BOLD%^faerie%^RESET%^%^MAGENTA%^ "
   "dust%^BOLD%^ on%^RESET%^%^MAGENTA%^ you!");
      tell_room(environment(ob), "%^RESET%^%^MAGENTA%^"+me+" %^BOLD%^breathes%^RESET%^%^MAGENTA%^ "
   "magical%^RESET%^%^MAGENTA%^ %^BOLD%^faerie%^RESET%^%^MAGENTA%^ "
   "dust%^BOLD%^ on%^RESET%^%^MAGENTA%^ "+you+"%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "storm") {
      write("%^BOLD%^%^BLACK%^You%^RESET%^%^BLUE%^ crush%^BOLD%^%^BLACK%^ "
            +you+"%^RESET%^%^BLUE%^ under %^BOLD%^%^BLACK%^the%^RESET%^%^BLUE%^ "
            "mighty%^BOLD%^%^BLACK%^ power%^RESET%^%^BLUE%^ of%^BOLD%^%^BLACK%^ "
            "the %^RESET%^%^BLUE%^storm!%^RESET%^");
      tell_object(ob, "%^BLUE%^"+me+"%^BOLD%^%^BLACK%^ crushes%^RESET%^%^BLUE%^ "
            "you%^BOLD%^%^BLACK%^ under%^RESET%^%^BLUE%^ the%^BOLD%^%^BLACK%^ "
            "the%^RESET%^%^BLUE%^ mighty%^BOLD%^%^BLACK%^ power%^RESET%^%^BLUE%^ "
            "of%^BOLD%^%^BLACK%^ the%^RESET%^%^BLUE%^ storm!%^RESET%^");
      tell_room(environment(ob), "%^BLUE%^"+me+"%^BOLD%^%^BLACK%^ "
            "crushes%^RESET%^%^BLUE%^ "+you+"%^BOLD%^%^BLACK%^ "
            "under%^RESET%^%^BLUE%^ the%^BOLD%^%^BLACK%^ "
            "mighty%^BOLD%^%^BLACK%^ power%^RESET%^%^BLUE%^ "
            "of%^BOLD%^%^BLACK%^ the%^RESET%^%^BLUE%^ storm!%^RESET%^",
            ({ ob, tp }));
      return 1;
   }
   if (type == "shadow") {
      write("%^BOLD%^%^BLACK%^You breathe a terrible shadow of pain "
            "over "+you+"!%^RESET%^");
      tell_object(ob, "%^BOLD%^%^BLACK%^"+me+" breathes a terrible shadow "
            "of pain upon your body!%^RESET%^");
      tell_room(environment(ob), "%^BOLD%^%^BLACK%^"+me+" breathes a "
            "terrible shadow of pain upon "+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "sand") {
      write("%^BOLD%^%^ORANGE%^You breathe a blast of burning hot air on your opponent!%^RESET%^");
      tell_object(ob, "%^BOLD%^%^ORANGE%^"+me+" breathes a blast of burning "
            "hot air on you!%^RESET%^");
      tell_room(environment(ob), "%^BOLD%^%^ORANGE%^"+me+" breathes a "
            "blast of burning hot air on "+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "forest") {
      write("%^GREEN%^You let forth a powerful gas upon "+you+"!%^RESET%^");
      tell_object(ob, "%^GREEN%^"+me+" breathes a poisonous gas upon you!%^RESET%^");
      tell_room(environment(ob), "%^GREEN%^"+me+" breathes a poisonous "
            "gas upon "+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "sonic") {
      write("%^ORANGE%^A powerful burst of noise slams into your opponent!%^RESET%^");
      tell_object(ob, "%^ORANGE%^A powerful burst of noise slams into you!%^RESET%^");
      tell_room(environment(ob), "%^ORANGE%^"+me+" lets forth a powerful burst of noise towards "+gen+" opponent!%^RESET%^");
      return 1;
   }
   if (type == "lightning") {
      write("%^YELLOW%^You%^BLUE%^ send%^YELLOW%^ a%^BLUE%^ powerful%^YELLOW%^ "
            "shock%^BLUE%^ at%^YELLOW%^ "+you+"!%^RESET%^");
      tell_object(ob, "%^YELLOW%^Lightning%^BLUE%^ spews%^YELLOW%^ forth%^BLUE%^ "
            "from%^YELLOW%^ "+me+"'s %^BLUE%^mouth%^YELLOW%^ and %^BLUE%^ strikes %^YELLOW%^ "
            "you!%^RESET%^");
      tell_room(environment(ob), "%^YELLOW%^Lightning%^BLUE%^ spews%^YELLOW%^ "
            "forth%^BLUE%^ from%^YELLOW%^ "+me+"'s%^BLUE%^ mouth%^YELLOW%^ "
            "and%^BLUE%^ strikes%^YELLOW%^ "+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "wind") {
      write("%^BLUE%^You send a powerful wind at "+you+"!%^RESET%^");
      tell_object(ob, "%^BLUE%^"+me+" sends a powerful wind at you!%^RESET%^");
      tell_room(environment(ob), "%^BLUE%^"+me+" breathes a powerful wind "
            "at "+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "mist") {
      write("%^BOLD%^%^WHITE%^A scolding mist envelopes "+you+"!%^RESET%^");
      tell_object(ob, "%^BOLD%^%^WHITE%^"+me+" breathes forth a scolding "
            "mist upon you!%^RESET%^");
      tell_room(environment(ob), "%^BOLD%^%^WHITE%^"+me+" breathes "
            "a scolding mist upon "+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "ice") {
      write("%^BOLD%^%^BLUE%^You %^WHITE%^send %^BLUE%^a %^WHITE%^cold "
    "%^BLUE%^blast%^WHITE%^ of %^BLUE%^ice %^WHITE%^at%^BLUE%^ your "
        "%^WHITE%^opponent!%^RESET%^");
      tell_object(ob, "%^BOLD%^%^BLUE%^"+me+"%^WHITE%^ breathes %^BLUE%^ "
        "a %^WHITE%^cold%^BLUE%^ blast %^WHITE%^of %^BLUE%^ice%^WHITE%^ "
        "on %^BLUE%^ you!%^RESET%^");
      tell_room(environment(ob), "%^BOLD%^%^BLUE%^"+me+" %^WHITE%^ breathes %^BLUE%^ "
        "a %^WHITE%^cold%^BLUE%^ blast %^WHITE%^of %^BLUE%^ice%^WHITE%^ "
        "on %^BLUE%^"+you+"!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "water") {
      write("%^BOLD%^%^BLUE%^You breathe a powerful blast of water on "
            +ob->query_cap_name()+"!%^RESET%^");
      tell_object(ob, "%^BOLD%^%^BLUE%^"+tp->query_cap_name()+" breathes "
            "a powerful blast of water down upon you!%^RESET%^");
      tell_room(environment(ob), "%^BOLD%^%^BLUE%^"+me+" breathes a "
            "powerful blast of water on "+you+"!%^RESET%^", ({ tp, ob }));
      return 1;
   }
   if (type == "earth") {
      write("%^ORANGE%^Stone whips shoot forth from your mouth and entangle "+ob->query_cap_name()+"!%^RESET%^");
      tell_object(ob, "%^ORANGE%^Stone whips shoot forth from "+tp->query_cap_name()+"'s mouth and smash you.%^RESET%^");
      tell_room(environment(ob), "%^ORANGE%^Stone whips shoot forth from "
   +tp->query_cap_name()+"'s mouth and entangle "+ob->query_cap_name()+
   "!%^RESET%^", ({ ob, tp }));
      return 1;
   }
   if (type == "air") {
      write("%^WHITE%^%^BOLD%^You send a powerful blast of air at "+ob->query_cap_name()+"!");
      tell_object(ob, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" sends a powerful blast of air at you!");
      tell_room(environment(tp), "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" slams "+ob->query_cap_name()+
                " with a powerful blast of air!", ({ tp, ob}));
      return 1;
   }
   if (type == "cloud") {
      tell_room(environment(ob), "%^BOLD%^%^WHITE%^"
                +ob->query_cap_name()+" is covered "
                "in a thick cloud.%^RESET%^", ({ ob }));
      write("%^BOLD%^%^BLUE%^You send the power of the clouds to harm "+ob->query_cap_name()+"!");
      tell_object(ob, "%^BOLD%^%^WHITE%^You are covered in a thick cloud.\n"
                "%^RESET%^Your skin begins to split and bleed!");
      tell_room(environment(ob), "%^RED%^You hear nothing but screams!", ({ ob, tp }));
      return 1;
   }
      write("%^BOLD%^%^RED%^You breathe forth a terrible blast of fire upon your enemy!");
      tell_object(ob, "%^BOLD%^%^RED%^"+tp->query_cap_name()+" breathes fire down upon you!");
      tell_room(environment(tp), "%^BOLD%^%^RED%^"+tp->query_cap_name()+"breathes down a terrible blast of fire upon "+ob->query_cap_name(), ({ tp, ob }));
    return 1;
}

void help() {
   write("Syntax: <breate [living]>");
   if (this_player()->query_race() != "dragon") {
      write("Not a pleasant experience for the likes of you.");
      return;
   }
   write("This attack sends your breath weapon against your enemy. "
         "this could be anything from a blast of fire to "
         "a mighty wind.");
}
