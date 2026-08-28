int
main ()
{
  switch (THIS->query_position())
    {
      case POS_STANDING:
      case POS_SITTING:
      case POS_RESTING:
        write ("You go to sleep.\n");
        act (THIS, "$n lies down and falls asleep.");
        THIS->set_position (POS_SLEEPING);
        break;
      case POS_SLEEPING:
        write ("You are already sound asleep.\n");
        break;
      case POS_FIGHTING:
        write ("Sleep while fighting? Are you MAD?\n");
        break;
      default:
        write ("You stop floating around and lie down to sleep.\n");
        act (THIS, "$n stops floating around, and lies down to sleep.");
        THIS->set_position (POS_SLEEPING);
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
  return "Using this command you sleep and regenerate A LOT faster "
  + " than when standing.";
}

query_see_also()
{
  return "sit(1), stand(1), rest(1)";
}

query_position()
{
  return POS_SLEEPING;
}
