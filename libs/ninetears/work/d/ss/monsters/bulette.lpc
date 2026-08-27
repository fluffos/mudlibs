
inherit "obj/monster";

void setup() {
   set_name("bulette");
   set_main_plural("bulettes");
   add_adjective("ferocious");
   set_short("ferocious Bulette");
   set_long(
      "The bulette is a cross between an armadillo and a snapping turtle.  " +
      "It's eyes are yellow with blue-green pupils.  Hard plates cover " +
      "the rest of the bulette from the shoulders back.\n");
   set_level(6);
   set_gender(0);
   set_al(0);
   set_aggressive(1);
   set_attack_everyone(1);
   //add_attack("bite", 0, 50, 170, 120, 50, "slash");
}

int write_message(int dam, object him, object me, string type, string attack) 
{
   switch(attack) {
      case "bite":
         write("The bulette bites at "+him->query_name()+"!\n");
         tell_object(him, "The bulette bites you hard!\n");
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}

