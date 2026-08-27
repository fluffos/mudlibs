object my_player;

void dest_shadow();

int test_add() { return 0; }
void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
  my_player->add_alias("wolf");
}

string *query_languages() 
{
 return ({ "werewolf", "grunt" }); 
}

string query_current_language()
{
  return "werewolf";
}

string query_short() 
{
 string path = file_name(previous_object());
  if (!my_player)
    return "Werewolf hide";
  if((path[20..23] == "look") || (path[20..24] == "glance"))
    return "A wolf";
  if((path[0..18] == "/global/player/cmds")||
       (!previous_object()->is_player()))
    return my_player->short();
  return "A wolf";
}

string query_cap_name() 
{
  return capitalize(query_short());
}


void remove_werewolf_shadow()
{
  tell_object(my_player, "You return to your previous form.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" returns "+
   my_player->query_possessive()+" normal form.\n", my_player);
   my_player->remove_alias("wolf");
  destruct(this_object());
}

int adjust_hp(int i, object hp_remover) {

    if(!previous_object()) 
        return my_player->adjust_hp(i, hp_remover);
     if(previous_object()->query_weapon()) 
       {
        if(previous_object()->query_property("SILVER") ||
           previous_object()->query_property("SILVER_BLADE"))

           i = i * 1.5;
        else 
        if(previous_object()->query_enchant() < 1) 
           i = 0;
        }
    return my_player->adjust_hp(i, hp_remover);
    
 }

