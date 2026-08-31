#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
  set_name("ring");
  set_short("%^BOLD%^%^BLACK%^ring of %^YELLOW%^r%^WHITE%^e%^YELLOW%^tr%^WHITE%^i%^YELLOW%^b%^WHITE%^ut%^YELLOW%^i%^WHITE%^o%^YELLOW%^n%^RESET%^");
  set_long("%^BOLD%^A thick, smokey-white band with %^RESET%^%^RED%^red%^WHITE%^, %^RESET%^white%^BOLD%^, and %^BLACK%^grey%^WHITE%^ metal strands set along the outside of it. The %^RESET%^%^RED%^red%^WHITE%^%^BOLD%^ and %^RESET%^white%^BOLD%^ strands lay on the outside of the band, with the %^BLACK%^grey%^WHITE%^ strand in the middle. Strange intricate notches and hallowed passages are cut into the inside of the ring.");
  set_id( ({ "ring of retribution", "retribution ring" }) );
  set_ac(1);
  set_mass(3);
  set_curr_value("gold", 0);
  set_type("ring");
  set_limbs(({"left hand", "right hand"}));
  set_wear("As you slide the ring on, it seems to clench loosely onto your soul.");
  set_remove("The ring releases its soft grip on your soul and slides off.");
}

int query_auto_load() { return 1; }

void notify_die(object killer) {
  if(!this_object()->query_worn()
     || this_object()->query_worn() != environment()) {
    message("info", "%^YELLOW%^Your "+query_short()+"%^YELLOW%^ glows "
      +"%^RESET%^%^WHITE%^vibrantly%^YELLOW%^ for a moment, then "
      +"%^BLACK%^sputters%^YELLOW%^ and goes out.", environment());
    return;
  }

  message("info", "%^BOLD%^%^BLACK%^You feel your soul get sucked into the "
    +query_short()+"%^BOLD%^%^BLACK%^ you are wearing!", environment()
   );
  message("info", "%^BOLD%^BLACK%^As "+environment()->query_cap_name()
    +" breathes "+environment()->query_possessive()+" final breath, "
    +environment()->query_possessive()+" skin begins to pale and "
    +environment()->query_possessive()+" ring glows a %^RESET%^brilliant"
    +" white%^BOLD%^%^BLACK%^.%^RESET%^",
    environment(environment()), environment()
   );

  if(!killer || !present(killer, environment(environment()))) {
    message("info", "%^BOLD%^Lacking a target to focus its attack on, your "
      +"ring releases its grip on your soul and loses its glow.%^RESET%^",
      environment()
     );
    message("info", "%^BOLD%^"+environment()->query_cap_name()+"'s ring "
      +"dims and then goes out as color returns to their body.",
      environment(environment()), environment()
     );
    return;
  }

  if (random(1000) < 600 || wizardp(environment())) {
    int align = environment()->query_alignment();
    message("info", "%^YELLOW%^A brilliant "+(align<-500?
      "%^RESET%^%^RED%^dark red%^BOLD%^":(align>500?"%^WHITE%^bright white"
      :"%^BLACK%^grey"))+" %^YELLOW%^light shoots forth from your ring and strikes "
      +capitalize(killer->query_name())+".", environment()
     );
    message("info", "%^YELLOW%^A brilliant "+(align<-500?
      "%^RESET%^%^RED%^dark red%^BOLD%^":(align>500?"%^WHITE%^bright white"
      :"%^BLACK%^grey"))+"%^YELLOW%^ light shoots forth from "
      +capitalize(environment()->query_name())+"'s ring and strikes you.", killer
     );
    message("info", "%^YELLOW%^A brilliant "+(align<-500?
      "%^RESET%^%^RED%^dark red%^BOLD%^":(align>500?"%^WHITE%^bright white"
      :"%^BLACK%^grey"))+"%^YELLOW%^ light shoots forth from "
      +capitalize(environment()->query_name())+"'s ring and strikes "
      +capitalize(killer->query_name())+".", environment(environment()),
      ({environment(), killer})
     );
    killer->add_hp(-to_int((environment()->query_max_hp()*0.5)
      + random(random(environment()->query_max_hp()*0.25))));
  }
  else {
    int align = environment()->query_alignment();
    message("info", "%^YELLOW%^A brilliant "+(align<-500?
      "%^RESET%^%^RED%^dark red%^BOLD%^":(align>500?"%^WHITE%^bright white"
      :"%^BLACK%^grey"))+" %^YELLOW%^light shoots forth from your ring and just misses "
      +capitalize(killer->query_name())+".", environment()
     );
    message("info", "%^YELLOW%^A brilliant "+(align<-500?
      "%^RESET%^%^RED%^dark red%^BOLD%^":(align>500?"%^WHITE%^bright white"
      :"%^BLACK%^grey"))+"%^YELLOW%^ light shoots forth from "
      +capitalize(environment()->query_name())+"'s ring and just misses you.", killer
     );
    message("info", "%^YELLOW%^A brilliant "+(align<-500?
      "%^RESET%^%^RED%^dark red%^BOLD%^":(align>500?"%^WHITE%^bright white"
      :"%^BLACK%^grey"))+"%^YELLOW%^ light shoots forth from "
      +capitalize(environment()->query_name())+"'s ring and just barely misses "
      +capitalize(killer->query_name())+".", environment(environment()),
      ({environment(), killer})
     );
    killer->add_hp(-10);
  }
  killer->show_status_line();
}
