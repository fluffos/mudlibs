

inherit "/obj/armour"; 

void setup()  
  { 
  set_base_armour("ring");

  set_name("anillo de la tierra");
  set_short("%^BLACK%^BOLD%^Anillo de la %^RESET%^ORANGE%^Tierra%^RESET%^");
  set_main_plural("%^BLACK%^BOLD%^Anillos de la %^RESET%^ORANGE%^Tierra%^RESET%^");
  set_long("Un anillo hecho de raices secas.\nPosee unas runas dificilmente legibles.\n");
  set_read_mess("\n%^ORANGE%^Anillo del Senyor de lo Arboreo\n\n(En construccion)%^RESET%^\n");
  add_alias(({"anillo","tierra"}));
}

int set_in_use(int i, object owner)
{
  if (i) {
    if (owner->query_name() != "xerxes") {
      tell_object(owner, "\nLas raices del anillo se incrustan en tu piel al no "
      "reconocerte como su duenyo legitimo, comienzan a penetrar en tu "
      "organismo y alcanzan tu sistema nervioso, destrozandolo y provocandote "
      "una dolorosa muerte.\n");
      owner->do_death();
    }
    else {
      tell_object(owner, "\nLas raices del anillo se incrustan en tu piel, pero al "
       "poseer una naturaleza arborea, las toleras y canalizas su poder.\n");
      return ::set_in_use(i, owner);
    }
  } else {
    tell_object(owner, "\nLas raices del anillo abandonan tu cuerpo.\n");
    return ::set_in_use(i, owner);
  }
}
