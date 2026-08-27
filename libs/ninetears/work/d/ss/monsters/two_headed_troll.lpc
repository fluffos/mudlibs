
inherit "obj/monster";

void setup() {
   set_name("troll");
   add_adjective("two headed");
   add_adjective("two-headed");
   set_race("troll");
   set_main_plural("two-headed trolls");
   set_short("Two-headed troll");
   set_long(
      "This giant two-headed troll is a cross between an Ettin and a " +
      "normal troll.\n");
   set_level(4);
   set_gender(0);
   give_money(30, 20, "silver");
   set_al(-100);
   set_attack_everyone(1);
   //add_attack("bite", 0, 100, 100,  20,  0, "slash");
}

int write_message(int dam, object him, object me, string type, string attack) 
{
   switch(attack) {
      case "bite":
         write("The two-headed troll bites "+him->query_name()+"!\n");
         tell_object(him, "The two-headed troll bites you!\n");
         break;
      default:
         ::write_message(dam, him, me, type, attack);
         break;
   }
}

