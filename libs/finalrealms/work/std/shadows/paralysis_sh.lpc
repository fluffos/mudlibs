object my_player;

void dest_shadow();

int test_add() { return 0; }
void setup_shadow(object ob, int length) 
{
  if(!length)
     length = 100;
  shadow(ob,1);
  my_player = ob;
  add_action("do_suppress", "");
  call_out("dest_shadow", length);
}

int do_suppress(string str)
{
   if (str == "wake")
      dest_shadow();
   if (str == "quit" || str == "l" || str == "look")
      return 0;
   write("You are paralyzed, and can do nothing.\n");
    return 1;
}

attack_by(object ob) 
{
  tell_object(ob, "You kill the paralyzed "+my_player->query_cap_name()+".\n");
  tell_object(my_player, "You were killed while paralyzed by the "
    "infamous "+ob->query_cap_name()+".\n");
  my_player->do_death();
  return 1;
}

string short() 
{
  if (!my_player)
    return "Paralyze shadow";
  return my_player->short()+" [paralyzed]";
}

void dest_shadow() 
{
  remove_action("do_suppress", "*");
  tell_object(my_player, "You are released from you paralysis.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" regains "+
   my_player->query_possessive()+" mobility.\n", my_player);
  destruct(this_object());
}
