
inherit "obj/monster";

void setup() {
   set_name("umber hulk");
   add_alias("hulk");
   set_main_plural("umber hulks");
   set_short("Umber hulk");
   set_long(
      "Umber hulks are powerful subterranean predators.  They have four " +
      "eyes and two large mandibles.\n");
   set_level(6);
   set_gender(0);
   set_al(-100);
   set_aggressive(1);
   //add_attack("scare", 0, 30, 0, 0, 0, "magic");
   //add_attack("bite", 0, 50, 150, 100, 100, "slash");
}

int write_message(int dam, object him, object me, string type, string attack) 
{
   switch(attack) {
      case "bite":
         write("The umber hulk crushes "+him->query_name()+" with its mandibles!\n");
         tell_object(him, "The umber hulk crushes you with its mandibles!\n");
         break;
      case "scare":
         write("The umber hulk looks directly at "+him->query_name()+"!\n");
         tell_object(him, "Your eyes meet those of the umber hulk.\n");
         tell_object(him, "You run away.\n");
         him->run_away();
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}

