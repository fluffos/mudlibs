
inherit "obj/monster";

void setup() {
   set_name("clay golem");
   set_race("golem");
   set_main_plural("golems");
   set_short("Clay Golem");
   set_long(
      "This golem is much taller than an average human.  With very " +
      "broad features, the golem appears as a molded piece of clay.\n");
   set_level(8);
   set_gender(0);
   set_al(0);
   set_attack_everyone(1);
   //add_attack("haste", 0, 33, 150, 0, 0, "blunt");
}

int write_message(int dam, object him, object me, string type, string attack) 
{
   switch(attack) {
      case "haste":
         write("The flesh golem swings around and hits "+him->query_name()+" again!\n");
         tell_object(him, "The flesh golem hits you again!\n");
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}

