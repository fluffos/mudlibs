// scan.c by dranil, remade by Ondoval

#define pline(x) message("0",x,THIS)

main ()
{
    object enemy=THIS->query_target();
    if(!enemy)
    {
	pline("You are not in combat right now.\n");
	return 1;
    }

    pline("^c1You take a brief look at your opponents:^c0\n");
/*
    for (int i=0; i < sizeof(battle); i++)
    {
      if(battle[i]) {
       pline(battle[i]->query_shapestring(0));
      }
    }
*/
    pline(enemy->query_shapestring(0));
    return 1;
}

query_author()
{
  return"dranil";
}
query_help()
{
  return "If you are in a battle, this tells you the condition of your opponent.";
}
query_synopsis()
{
  return "say <msg>";
}
query_see_also()
{
  return"kill(1), wimpy(1)";
}
query_position ()
{
  return POS_RESTING;
}

