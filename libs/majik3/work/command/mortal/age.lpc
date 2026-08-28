main ()
{
  int e, i;

  e = previous_object()->query_age();

  i = (e*3/5)/(60*24*28*8);

  if (previous_object()->query("security"))
    write ("WIZINFO: Your real age is: "+(previous_object()->query("true_age")/(60*60*24))+" rl days.\n");

  if (!i)
    write ("You are less than one year old.\n");
  else if (i==1)
    write ("You are one year old.\n");
  else
    write ("You are "+i+" years old and feel "+THIS->query_description_age()+".\n");

  return 1;
}

query_author () 
{
  return "namhas";
}

query_help ()
{
  return "This command will give you your relative mud age. Age is "
       + "not calculated by online time but based on your characters "
       + "real age. Thus, when the world ages a year so does your "
       + "character.";
}

query_see_also ()
{
  return "score(1), finger(1)";
}
