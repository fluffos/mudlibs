// Arma con bonus al bs. Xerxes '02
 inherit "/obj/weapon";
 void setup() {
   set_base_weapon("dagger");
   set_name("aspid");
   set_short("%^BOLD%^Aspid%^RESET%^");
    set_long("Se cuenta que este arma fue forjada antanyo por artesanos ofideos, "
             "una antiquisima raza que se supone extinta. Consiste en un enorme "
             "colmillo de color marfil, que emana un aura verdosa, engastado con "
             "joyas de la misma tonalidad. La empunyadura es de un metal plateado, "
             "con un gran numero de grabados.\n");
   set_main_plural("%^GREEN%^BOLD%^Aspid%^RESET%^");
   add_alias("aspid");
   add_plural("aspids");   
   add_plural("aspides");   
 }

int query_damage_roll()
{
  if (TP->query_guild_name() == "ladron" && TP->query_property("apunyalando")) {
    return ((4*random(8)+4)+(2* (random(TP->query_level())/2) ));
  }
    return (random(13) + 1) * ((random(20) <= 1) ? 2:1);
}
int set_in_use(int i, object miamo)
{
  object *weap;
  int k;
  weap = miamo->query_weapons_wielded();
  if (i) {
    if (miamo->query_level() < 32) {
      tell_object(miamo, "El %^GREEN%^BOLD%^Aspid%^RESET%^ es un arma "
                         "demasiado complicada como para que puedas "
                         "manejarla.\n");
      return 0;
    }
    for (k=0;k<sizeof(weap);k++){
      if(weap[k]->query_name() == "aspid")
      {
        tell_object(miamo,"Al intentar empunyar dos Aspid, los espiritus "
                    "de las armas se enfrentan.\n");
        return 0;
      }
    }
  }
  return ::set_in_use(i);
}
