#include <std.h>
inherit DAEMON;
int spell();

int cmd_metamorphase(string str) {
   object tp;
   string st, gen;
    st = (string)this_player()->query_cap_name();
    if (this_player()->query_gender() == "male") gen = "his";
    if (this_player()->query_gender() == "female") gen = "her";
    if (this_player()->query_gender() == "neuter") gen = "it's";
    tp = this_player();
    if (str) write("Syntax: <metamorphase>");
    tp = this_player();
    if (tp->query_guild() != "dragon") return 0;
    if(tp->query_casting()) {
	notify_fail("Your mind is occupied.\n");
	return 0;
    }
    if (tp->query_ghost()) {
       notify_fail("You have no body!");
       return 0;
    }
    if (tp->query_dragon_level() == 1 && tp->query_exp() >= 30000) {
       write("Your body begins to shift in it's shape.\n"
             "Short stubs of wings sprout forth from along your spine, "
             "as it stretches. Your lizard-like legs begin to thicken "
             "and small claws form along your hands and feet. Your face "
             "elongates further, so it looks like a strange cross "
             "between a dog and a lizard. Your blunt teeth sharpen, to "
             "short fangs. Your body has changed from that of a "
             "hatchling to that of a small wyrm.");
       tp->set_dragon_level(2);
       tp->add_exp(-30000);
       tell_room(environment(tp),
             st+"'s body is suddenly engulfed in a strange, golden light.\n"
             "Short stubs of wings sprout forth from along "+gen+" spine, "
             "as it stretches. "+st+"'s lizard-like legs begin to thicken "
             "to look more like that of a dragon, and small claws form "
             "along "+gen+" hands and feet. "+st+"'s face elongates into "
             "a strange cross between a dog and a lizard. Small, sharp "
             "fangs jut forth from "+gen+" jaw. "+st+" Is now a small wyrm.", ({ tp }));
       return 1;
    }
    if (tp->query_dragon_level() == 2 && tp->query_exp() >= 300000) {
       write("Your body begins to change shape!\n"
             "Your spine stretches and forms into a small arch, about "
             "ten feet long. Your fangs thicken into a much larger and "
             "deadly form. Your claws, too, grow into wicked dagger "
             "sized weapons. Your nose grows into your snout and you "
             "find you no longer have any body hair, including eyebrows. "
             "You no longer resemble a dog nor human in any way. "
             "Your body has changed from that of a wyrm to that of a "
             "drake.");
       tp->set_dragon_level(3);
       tp->add_exp(-300000);
       tell_room(environment(tp),
             st+" is suddenly engulfed in a strange golden light!\n"
             +st+"'s spine stretches and forms into a small arch, about "
             "ten feet long. "+gen+" fangs thicken into a much larger and "
             "deadly form. "+st+"'s claws, too, grow into wicked dagger "
             "sized weapons and "+gen+" nose grows into a snout and you "
             "find "+st+" no longer has any body hair, including eyebrows. "
             +st+" no longer resemble a dog nor human in any way. "
             +st+"Is now a drake.", ({ tp }));
       return 1;
    }
    if (tp->query_dragon_level() == 3 && tp->query_exp() >= 1000000) {
       write("Your body begins to change shape!\n"
             "Your tail, spine, and claws grow greatly in length "
             "and power. Your eyes form into thin slits and your "
             "legs as thick as the trunks of a great oak. Your fangs "
             "grow sharper than a knife and a flame burns deep "
             "in your blood. "
             "Your body has changed from that of a drake to that of a "
             "Great Wyrm!");
       tp->set_dragon_level(4);
       tp->add_exp(-1000000);
       tell_room(environment(tp), "%^YELLOW%^"+
             st+" is suddenly engulfed in a strange golden light!\n"
             +st+"'s back and tail stretch the length of the room, "
             "and "+gen+" claws and teeth become sharper than any "
             "assassin's knife. "+st+"'s eyes thin to small slits, "
             "and "+gen+" legs thicken to the size of the mighty "
             "and ancient oak. A burst of flame and heat suddenly "
             "floods your every sense, as "+st+"'s body forms into "
             "that of a Great Wyrm, the highest rank in the order "
             "of the dragon!", ({ tp }));
       return 1;
    }
    return 1;
}

void help() {
    write("Syntax: <metamorphase>\n"
          "Allows a hatchling, wyrm, or drake to advance to the "
          "next rank of dragon, morphing their body to suit their "
          "new rank, Great Wyrm being the final stage of the dragon. "
          "Each stage will drain the dragon of a certain ammount of "
          "their experience points.");
}

int spell() { if (this_player()->query_guild() == "dragon") return 1; }
