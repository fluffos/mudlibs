 inherit "/obj/monster";
  
 void setup()
 {
   set_name("Aokorki");
   add_alias("aokromes");
   add_alias("dummy");
   set_cha(1);
   set_str(1);
   set_con(1);
   set_dex(1);
   set_wis(1);
   set_int(1);
   set_race("human");
   set_short("%^BOLD%^Aokorki%^CYAN%^2002%^RESET%^");
   add_language("common");
   set_language("common");
   set_long("\n%^BOLD%^Aokorki%^CYAN%^2002%^RESET%^\n\n"
      "Se trata del fantastico e innovador Aokorki 2002, una maravilla tecnologica, el ultimo "
      "modelo en dummies de Aokorki's, como siempre con 5 anyos de garantia. Este nuevo modelo "
      "posee unos potentes repulsores de gravedad, que haran que el munyeco no vuele por los "
      "aires con uno de tus potentes golpes. Ademas esta fabricado a conciencia por los mejores "
      "artesanos. Su cara es tan odiosa que no podras resistirte a pegarle. Vizco, con gafas y "
      "sosteniendo dos katanas en actitud estupida mientras se le cae la babilla por la comisura "
      "de los labios y con un ojo mirando a Irlanda y con el otro a Gibraltar. Pegale! No te "
      "cortes! Lo estas deseando eh?\n\n");
   set_align(-500);
   set_max_hp(100000000);
   add_action("ponerseequipo","equipate");
   this_object()->init_equip();
   load_chat(10,
    ({
       1, ":exclama: Oh siii! Dame con mas fuerza, ahi ahi! Ohhhhhh!",
       1, ":gime: Mmmmmmmmmmm! MAS MAS MAS!!! MAS FUERTEEEEEEEEE!",
       1, ":se queja: No! en el ojo sano noooooo! Por favoooooor!",
       1, ":te grita: Atrevete a pegarme y te ganaras un buen BAN!",
       1, "'si me sigues pegando te baneare la IP permanentemente!!",
     }));  
 }
   
 int adjust_hp(int i, object hp_remover,mixed type) 
 {
  if(hp_remover && hp_remover != TO) 
    {
  tell_object(hp_remover,"HACES %^BOLD%^WHITE%^"+save_variable(i)+"%^RESET%^ PVS DE DANYO.\n");
  tell_room(this_object(),hp_remover->query_cap_name()+" hace %^BOLD%^YELLOW%^"+ save_variable(i)+" %^RESET%^Pvs de danyo.\n",hp_remover);
    }
  return ::adjust_hp(i,hp_remover,type);
  }
   
int attack_by()
 {
 return 0;
 }
 void  do_death()
  {
  TO->set_hp(TO->query_max_hp()); 
  }
  int attack_ob()
  {
  return 0;
  }
  int ponerseequipo()
  {
  thisobject()->init_equip();
