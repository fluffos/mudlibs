int main ()
{
  if (!THIS->query_money())
    write ("You have no money.\n");
  else
  write("You are carrying money worth "+THIS->query_money()+" copper pieces in total.\n");

  message ("3", THIS->query_cap_name()+" calculates "+THIS->query_possessive()+" money.\n", ENV(THIS), THIS);

  return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "This tells you how much money you are currently carrying.";
}

query_see_also()
{
  return "exp(1)";
}

query_position ()
{
  return POS_RESTING;
}

