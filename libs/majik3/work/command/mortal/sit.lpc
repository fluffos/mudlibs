int
main ()
{
  switch (THIS->query_position())
    {
      case POS_STANDING:
        write ("You sit down.\n");
        act (THIS, "$n sits down.");
        THIS->set_position (POS_SITTING);
        break;
      case POS_SITTING:
        write ("You're sitting already.\n");
        break;
      case POS_RESTING:
        write ("You stop resting, and sit up.\n");
        act (THIS, "$n stops resting.");
        THIS->set_position (POS_SITTING);
        break;
      case POS_SLEEPING:
        write ("You have to wake up first.\n");
        break;
      case POS_FIGHTING:
        write ("Sit down while fighting? Are you MAD?\n");
        break;
      default:
        write ("You stop floating around and sit down.\n");
        act (THIS, "$n stops floating around, sits down.");
        THIS->set_position (POS_SITTING);
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
  return "Using this command you sit down and regenerate slightly faster "
  + " than when standing.";
}

query_see_also()
{
  return "rest(1), stand(1), sleep(1)";
}

query_position()
{
  return POS_RESTING;
}
