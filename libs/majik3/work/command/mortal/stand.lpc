int
main ()
{
  switch (THIS->query_position())
    {
      case POS_STANDING:
        write ("You are already standing.\n");
        break;
      case POS_SITTING:
        write ("You stand up.\n");
        act (THIS, "$n clambers to "+THIS->query_possessive()+" feet.");
        THIS->set_position (POS_STANDING);
        break;
      case POS_RESTING:
        write ("You stop resting, and stand up.\n");
        act (THIS, "$n stops resting, and clambers on "+
          THIS->query_possessive()+" feet.");
        THIS->set_position (POS_STANDING);
        break;
      case POS_SLEEPING:
        write ("You have to wake up first!\n");
        break;
      case POS_FIGHTING:
        write ("Do you not consider fighting as standing?\n");
        break;
      default:
        write ("You stop floating around and put your feet on the ground.\n");
        act (THIS, "$n stops floating around, and puts "+
          THIS->query_possessive()+" feet on the ground.");
        THIS->set_position (POS_STANDING);
        break;
    }

  return 1;
}


query_author()
{
  return "namhas";
}

query_help()
{
  return "If you are not standing and want to walk or do something which "
  + " requires standing, you need to use this command. When standing you "
  + " regenerate much slower than in other positions.";
}

query_see_also()
{
  return "rest(1), sit(1), sleep(1)";
}

query_position()
{
  return POS_RESTING;
}
