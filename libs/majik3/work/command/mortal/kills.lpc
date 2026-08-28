int
main ()
{
  mapping kills;
  int total;
  string *k;

  kills = THIS->query_kexp_map();

  if (!kills) {
    write ("You have not killed anything.\n");
    return 1;
  }

  k = keys(kills);

  write ("You have killed:\n");

  for (int i=0;i<sizeof(kills);i++) {
    total += kills[k[i]][0];
    if (kills[k[i]][0] != 1)
      message ("0", sprintf ("%3d %s (%d xp)\n", kills[k[i]][0], pluralize(k[i]), kills[k[i]][1]), THIS);
    else
      message ("0", sprintf ("%3d %s (%d xp)\n", kills[k[i]][0], k[i], kills[k[i]][1]), THIS);
  }

  write ("\nTotal kills: "+total+"\n");

  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "This command shows the monster races you have killed, and how "
       + "many. More you have killed certain monster races, more easily "
       + "you kill it again.";
}

query_see_also ()
{
  return "score(1), kill(1)";
}

query_position ()
{
  return POS_RESTING;
}

