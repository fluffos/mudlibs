object my_player;

int test_add() { return 0; }

void attack() 
{
 write("You can't attack anyone in your wispy form");
}

void adjust_hp() 
{
}

void setup_shadow(object ob) 
{
  shadow(ob,1);
  my_player = ob;
  call_out("dest_shadow", 100);
}

attack_by(object ob) {
  tell_object(ob, this_player()->query_cap_name()+" is not material. "
   "You can't harm "+this_player()->query_objective()+".\n");
  ob->stop_fight(my_player);
  return 1;
}

attack_ob(object ob) 
{
  notify_fail("Your hand passes right through it! You are immaterial!\n");
  return 0;
}

string short() 
{
  if (!my_player)
    return "Windwalk shadow";
  return "A whispy immaterial shape resembling "+my_player->short();
}

void dest_death_shadow() 
{
  destruct(this_object());
}

int cast() 
{
  notify_fail("You can't cast spells while you're immaterial!\n");
  return 0;
}

int do_shout() 
{
  notify_fail("Your immaterial form don't have a strong enough voice.\n");
  return 0;
}

int do_echo() 
{
  notify_fail("Echoing is an impossible feat for an immaterial shape.\n");
  return 0;
}

int do_emote()
{
  notify_fail("Emoting is not possible for immaterial beings like yourself.\n");
  return 0;
}

int do_guild_command() 
{
  notify_fail("You are immaterial!\n");
  return 0;
}

int do_race_command() 
{
  notify_fail("You are immaterial!\n");
  return 0;
}

int score()
{
  notify_fail("You are a disembodied whisp of wind."); 
  return 0;
}

void dest_shadow()
{
  tell_object(my_player, "You return to your normal form.\n");
  tell_room(environment(my_player), my_player->query_cap_name()+ 
   "returns to "+my_player->query_possessive()+" normal form.\n");

  destruct(this_object());
}

