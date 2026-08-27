object my_player;
int level, save, roll, doomed;
string guild;

void setshadow(object ob)
{
  shadow(ob,1);
  my_player = ob;
  my_player->add_static_property("nocast",1);
  call_out("destruct_hw2_shadow", 60+random(300));
}

void destruct_hw2_shadow()
{
  my_player->remove_property("nocast");
  tell_object(my_player,
    "The deathly silence finally comes to an end.  Sounds of the outside world \n"+
    "slowly begin to filter in.\n");
  destruct(this_object());
}

int query_total_ac()
{
  return my_player->query_total_ac() + 20;
}

int query_damage_bonus()
{
  return my_player->query_damage_bonus() - 2;
}

int query_tohit_bonus()
{
  return my_player->query_tohit_bonus() - 2;
}
void event_person_shout(object ob, string start, string mess, string lang)
{
  return;
}

void event_person_tell(object ob, string start, string mess, string lang)
{
  tell_object(ob, my_player->query_cap_name()+
    " doesn't seem to be able to hear you at the moment.\n");
  return;
}

void event_person_say(object ob, string start, string mess, string lang)
{
  tell_object(my_player, ob->query_cap_name()+" is mouthing some words, "
    "but you are stone deaf at the moment.\n");
  return;
}

int do_loud_say(string str)
{
  tell_room(environment(my_player),
      my_player->query_cap_name()+" loudly says something unintelligible.\n",
      my_player);
    tell_object(my_player, "You loudly say something unintelligible.\n");
    return 1;
}

int do_say(string arg, int no_echo)
{
  tell_room(environment(my_player),
    my_player->query_cap_name()+" says something unintelligible.\n",my_player);
  tell_object(my_player, "You say something unintelligible.\n");
  return 1;
}

int do_tell(string arg, object ob, int silent)
{
  string str,rest,word;
    if (!ob) {
if (sscanf(arg,"%s %s",str,rest)!=2) {
    notify_fail("Syntax: tell <name> something\n");
    return 0;
}
}
str = lower_case(str);
str = (string)this_object()->expand_nickname(str);
ob = find_player(str);
if (!ob)
    ob = find_living(str);
  if(!(ob->query_creator()))
  {
    tell_object(my_player, "Being deaf, you cannot hold a conversation.\n");
    return 1;
  }
  return my_player->do_tell(rest, ob, silent);
}

int do_emote(string str)
{
  tell_object(my_player, "Being deaf, you cannot do that.\n");
  return 1;
}

int do_shout(string str)
{
  tell_object(my_player, "Being deaf, you cannot do that.\n");
  return 1;
}

int do_whisper(string str)
{
  tell_object(my_player, "Being deaf, you cannot bring yourself to whisper.\n");
  return 1;
}

int do_channels(string str)
{
  tell_object(my_player, "Being deaf, you cannot do that.\n");
  return 1;
}
