
inherit "obj/monster";

void setup() {
   set_name("iron golem");
   set_race("golem");
   set_main_plural("golems");
   set_short("Iron Golem");
   set_long(
      "This golem is crafted from blackened iron.  It stands roughly " +
      "twelve feet tall.\n");
   set_level(12);
   set_gender(0);
   set_al(0);
   set_attack_everyone(1);
   //add_attack("poison", 0, 15, 150, 50, 0, "breath");
}

/* wierd non-funtinal stuff..commented out by Greymist
int write_message(int dam, object him, object me, string type, string attack) 
{
   switch(attack) {
      case "poison":
         write("The golem breathes on "+him->query_name()+"!\n");
         tell_object(
            him, "You suffer from the effects of the golem's poisonous breath.\n");
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}
*/
