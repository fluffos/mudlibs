void init()
{
  object *obs;
  ::init();

  if(!mi_player || !environment())
    return;

  if(!mi_player&&!this_object()->query_timed_property("recien_invocado"))
  {
    tell_room(environment(this_object()),this_object()->query_cap_name()+
    " se da cuenta de que su amo no esta por aqui"
    "y regresa al Plano del Abismo.\n");
    this_object()->dest_me();
  }
}

int test_add(object ob, int i) { return 0; }

object make_corpse() { return 0; }

void do_death(object att)
{
  object *obs;
  if(!mi_player)
  {
    tell_room(ENV(this_object()),"Con un grito desgarrador, "
    +this_object()->query_cap_name()+" explota en millones de "
    "pequeñas partículas que se difuminan suavemente en el aire "
    "conforme regresan al Plano del Abismo.\n");
    this_object()->do_dest();    
  }

  obs=this_object()->query_attacker_list();
  for(int i=0;i<sizeof(obs);i++)
  {
    if(obs[i]==mi_player)
      mi_player->add_timed_property("MALDICION_INVOCAR",1,500);
  }
  mi_player->remove_static_property("criatura_invocada");
  tell_room(ENV(this_object()),"Con un grito desgarrador, "
  +this_object()->query_cap_name()+" explota en millones de "
  "pequeñas partículas que se difuminan suavemente en el aire "
  "conforme regresan al Plano del Abismo.\n");

  ::do_death(att);
}


