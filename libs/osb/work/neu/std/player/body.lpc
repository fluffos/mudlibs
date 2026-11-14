public void Die()
{
  if (query_once_interactive(this_object()) && !interactive()) {
    /* This player is linkdead. */
    write(QueryName()
          +" is not here. You cannot kill a player who is not logged in.\n");
    hit_point = 20;
    StopAllHunting();
    return 0;
  }
  /* Don't damage wizards too much ! */
  if (IS_IMMORTAL( /*this_object()*/ QueryRealName())) {
    tell_object(this_object(), "Your wizardhood protects you from death.\n");
    return 0;
  }
  /* Do not kill ghosts! */
  if ((dummy=find_player(QueryRealName()||QueryName())) &&
      dummy->QueryGhost()) {
    tell_object(this_object(),"Your dead state protects you from being"+
                " killed again!\n");
    return 0;
  } /* invented by Jhary on Sept 5th, bugfixed by Pumuckel, Sept 6th */

  ::Die();
}

public int AddXP (int amount) { 
  if (   IS_WIZARD(this_player()) 
      || (   (this_object() == this_player() 
              || previous_object()->QueryHP() == -31415)
          && (!this_interactive() || this_interactive() == this_player())
         )
     ) {
    reallevel = 0;
    return ::AddXP(amount);
  }
}

