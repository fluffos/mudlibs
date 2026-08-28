int
main ()
{
  switch (THIS->query_position())
    {
      case POS_STANDING:
        write ("You sit down and rest your tired bones.\n");
        act (THIS, "$n sits down and rests.");
        THIS->set_position (POS_RESTING);
        break;
      case POS_SITTING:
        write ("You rest your tired bones.\n");
        act (THIS, "$n rests.");
        THIS->set_position (POS_RESTING);
        break;
      case POS_RESTING:
        write ("You are already resting.\n");
        break;
      case POS_SLEEPING:
        write ("You have to wake up first.\n");
        break;
      case POS_FIGHTING:
        write ("Rest while fighting? Are you MAD?\n");
        break;
      default:
        write ("You stop floating around and stop to rest your tired bones.\n");
        act (THIS, "$n stops floating around, and rests.");
        THIS->set_position (POS_RESTING);
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
  return "Using this command you rest and regenerate a lot faster "
  + " than when standing.";
}

query_see_also()
{
  return "sit(1), stand(1), sleep(1)";
}

query_position()
{
  return POS_RESTING;
}
