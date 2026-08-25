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
   if (str == "quit" || str == "yawn" || str == "snore")
      return 0;
   write("You are sleeping, and can but dream of doing anything.\n");
    return 1;
}

attack_by(object ob) 
{
  tell_object(ob, "You kill "+my_player->query_cap_name()+" in "+
    my_player->query_possessive()+" sleep.\n");
  tell_object(my_player, "You were killed in your sweetest sleep by the "
    "infamous "+ob->query_cap_name()+".\n");
  my_player->do_death();
  return 1;
}

string short() 
{
  if (!my_player)
    return "Sleep shadow";
  return my_player->short()+" [sleeping]";
}

void dest_shadow() 
{
  remove_action("do_suppress", "*");
  tell_object(my_player, "You wake from a recuperative sleep.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+" wakes from "+
   my_player->query_possessive()+" sleep.\n", my_player);
  destruct(this_object());
}
