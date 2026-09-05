status cmd_suicide(string str)
{
 if(str) return 0;
 
 if(this_player()->query_ghost()) return 0;

 write("\n\
Warning: Suicide will result in a death to your character.\n\
         You will lose experience per a \"normal\" death.\n\
         Absolutely NO character restorations are given\n\
         if you change your mind, ever.\n\n\
Type 'I want to die' if you really do.\n");

  this_player()->load_suicide();
  return 1;
}
