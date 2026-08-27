// Arma con bonus al bs. Xerxes '02
 inherit "/obj/weapon";
 void setup() {
   set_base_weapon("dagger");
   set_name("filo de wyrm");
   set_short("Filo de Wyrm");
    set_long("El Filo de Wyrm es un arma construida con las garras de dichos "
             "seres. El veneno que en ellos habita se conserva con las mismas "
             "propiedades mortiferas. La garra, de unos 20 centimetros de largo, "
             "tiene un color ennegrecido, y la empunyadura, bastante sencilla, "
             "esta construida con metal\n");
   set_main_plural("Filos de Wyrm");
   add_alias("filo");
   add_alias("wyrm");
   add_plural("filos"); 
   add_plural("wyrms");
 }

int query_damage_roll()
{
  if (TP->query_guild_name() == "ladron" && TP->query_property("apunyalando")) {
    tell_object(TP,"%^GREEN%^BOLD%^Notas como el veneno de tu arma fluye por las venas de tu enemigo.%^RESET%^\n");
    return ((2*random(8)+2)+(2* (random(TP->query_level())/2) ));
  }
    return (random(6) + 1) * ((random(15) <= 1) ? 2:1);
}
int set_in_use(int i, object miamo)
{
  object *weap;
  int k;
  weap = miamo->query_weapons_wielded();
  if (i) {
    if (miamo->query_level() < 24) {
      tell_object(miamo, "El Filo de Wyrm es un arma "
                         "demasiado complicada como para que puedas "
                         "manejarla.\n");
      return 0;
    }
    for (k=0;k<sizeof(weap);k++){
      if(weap[k]->query_name() == "filo de wyrm")
      {
        tell_object(miamo,"No eres capaz de manejar dos armas de este calibre.\n");
        return 0;
      }
    }
  }
  return ::set_in_use(i);
}
