object *madesave, *failsave;
object my_player;

void setshadow(object ob) 
{
  object *outed, *attlist;
  int i;
  outed = ob->query_call_outed();
  for(i=0;i<sizeof(outed);i++)
  {
    if(!madesave)
      madesave = ({ outed[i] });
    else
      madesave += ({ outed[i] });
  }
  attlist = ob->query_attacker_list();
  for(i=0;i<sizeof(attlist);i++)
  {
    if(!madesave)
      madesave = ({ attlist[i] });
    else
      madesave += ({ attlist[i] });
  }
   shadow(ob,1);
   my_player = ob;
}

void destruct_sanct_shadow()
{
  destruct(this_object());
}

int query_sanc() { return 1; }

void attack_by(object ob)
{
  object guild;
  int save, level;

  guild = ob->query_guild_ob();
  level = ob->query_level();
// save = guild->query_saving_throw("spell", level);
  save = 15 - (level / 3);

  if(member_array(ob, madesave) > -1)
     return my_player->attack_by(ob);
  
  if(member_array(ob, failsave) > -1)
  {
     tell_object(my_player, ob->query_cap_name()+" starts to attack "
                "but turns away abruptly.\n");
     tell_object(ob, "You cannot seem to bring yourself to attack "+
                 my_player->query_cap_name()+" right now.\n");
     tell_room(environment(my_player), ob->query_cap_name()+
             " tries another attack on "+my_player->query_cap_name()+
             " but turns away abruptly.\n", ({ob, my_player}));
     ob->stop_fight(my_player);
    my_player->stop_fight(ob);
    return;
  }
  
  if((random(19) + 1) >= save)
  {
   tell_object(my_player, ob->query_cap_name() + " has broken "
                 "through your Sanctuary and attacked you!\n");
   if(sizeof(madesave))
      madesave += ({ ob });
   else
      madesave = ({ ob });
   return my_player->attack_by(ob);
  }
  else
  {
     tell_object(my_player, ob->query_cap_name() + " has attempted "
                 "to attack you, but is repelled by your Sanctuary.\n");
     tell_object(ob, "You try to attack "+my_player->query_cap_name()+
                 " but you're suddenly compelled to stop.\n");
     tell_room(environment(my_player),
               ob->query_cap_name() + " attempts to attack "+
               my_player->query_cap_name()+", but cannot continue.\n",
               ({ ob, my_player }));
     if(sizeof(failsave))
        failsave += ({ ob });
     else
        failsave = ({ ob });
     ob->stop_fight(my_player);
     my_player->stop_fight(ob);
     return ;
  }
}

void attack_ob(object ob)
{
  if(member_array(ob,madesave) > -1)
    return my_player->attack_ob(ob);
  else
  {
    tell_object(my_player,
      "You cannot instigate an attack on another while under Sanctuary.\n");
    return;
  }
}
