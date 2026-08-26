/*  -*- LPC -*-  */

inherit COMMAND_BASE;

mixed cmd(object player)
{
#ifdef SURRENDER_ON
  object *victims;
#endif

#ifdef SURRENDER_ON
  victims = this_player()->query_surrenderers();
  if (!player)
    return notify_fail("Sorry, but you have to reject someone's "
      "surrender\n");
  if (member_array(player, victims) == -1)
    return notify_fail("Sorry, but " + player->one_short() +
      " hasn't offered a surrender to you.\n");
  this_player()->remove_surrenderer(player);
  player->refused_surrender(this_player());
  write("Meanie!\n");
  return 1;
#else
  return 0;
#endif
}


mixed *query_patterns()
{
#ifdef SURRENDER_ON
  return ({ "<indirect:living:here>", (: cmd($1[0]) :) });
#endif
}
