query_messu (int i)
{
  switch (i)
    {
      case -50..-20:
        return "very angry";
      case -19..-10:
        return "angry";
      case -9..9:
        return "you have no idea";
      case 10..19:
        return "pleased";
      case 20..50:
        return "very pleased";
      default:
        return "very angry";
    }
}

int
main ()
{
  string *k;  
  mapping religions = ([ ]);
 
  religions = THIS->query("religions");

  if (!religions || sizeof(religions) == 0) {
     write ("You are not religious.\n");
     return 1;
  }

  
     
   k = keys(religions);
   
   
   for (int i=0;i<sizeof(k);i++)
     {
        printf ("%-20s: %-30s\n", k[i], query_messu(religions[k[i]]));
     }
        
   return 1;
   
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "Lists all religious you are currently professing and how the"
  + " Gods think of you.";
}
query_position ()
{
  return POS_RESTING;
}

