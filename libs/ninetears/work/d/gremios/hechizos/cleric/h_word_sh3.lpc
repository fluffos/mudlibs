object my_player;
int lasttime, thistime;
mixed time;

void setshadow(object ob, object caster)
{
  shadow(ob,1);
  my_player = ob;
  my_player->add_static_property("nocast",1);
  lasttime = time();
  switch((int)my_player->query_level())
  {
    case 0..5:
      call_out("destruct_hw3_shadow", 1800);
      break;
    case 6..8:
      call_out("destruct_hw3_shadow", 120+random(1080));
      break;
    case 13..500:
      call_out("destruct_hw3_shadow", 10 + random(50));
      break;
  }
}

void destruct_hw3_shadow()
{
  my_player->remove_property("nocast");
  tell_object(my_player,
    "You find yourself able to think and act clearly again.  You shake \n"+
    "the cobwebs caused from being exposed to such power.\n");
  destruct(this_object());
}

int query_total_ac()
{
  return my_player->query_total_ac() + 50;
}

int query_damage_bonus()
{
  return my_player->query_damage_bonus() - 5;
}

int query_tohit_bonus()
{
  return my_player->query_tohit_bonus() - 5;
}

varargs mixed move_player(string dir, string dest, mixed message, 
  	                  object followee, mixed enter)
{
  thistime = time();
   if(thistime < (lasttime + 9))
   {
    tell_object(my_player,
      "You slowly stumble in that direction.\n");
    return 1;
    }
  lasttime = thistime;
    return my_player->move_player(dir, dest, message, followee, enter);
}
