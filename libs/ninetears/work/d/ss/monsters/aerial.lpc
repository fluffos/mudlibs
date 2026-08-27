
inherit "obj/monster";

void setup() {
   set_name("aerial servant");
   add_alias("servant");
   set_main_plural("aerial servants");
   set_short("");
   set_long("Honestly!  It's invisible for crying out loud!\n");
   set_level(16);
   set_gender(0);
   set_al(0);
   set_attack_everyone(1);
   //add_attack(    "grab", "strangle",  20, 100,  20,  0, "blunt");
   //add_attack("strangle",          0, 100, 150, 100, 40, "hands");
}

int write_message(int dam, object him, object me, string type, string attack) 
{
   switch(attack) {
      case "grab":
         write("An invisible force grabs "+him->query_name()+"!\n");
         tell_object(
            him, "The aerial servant grabs you and begins to strangle you.\n");
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}

