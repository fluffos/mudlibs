grab_exit()
{
  string *exits, *rand;
  int    x, y;
  exits = environment()->query_dest_dir();
  y     = sizeof(exits);
  rand = ({ });
  for(x = 0; x < y; x += 2)
  {
    rand += ({ exits[x] });
  }
  return rand[random(sizeof(rand))];
}

throw_special()
{
  string exit;
  
  tell_object(attacker_ob,
    "\n\tJason slams his machete against you, knocking you off your feet!\n\n");
  attacker_ob->hit_player(100+random(50));
  command((exit=grab_exit()) ? exit : "", attacker_ob);
}

heart_beat()
{
  ::heart_beat();
  if(random(100) > 90) /* 10 % chance */
  {
    throw_special();
  }
}
