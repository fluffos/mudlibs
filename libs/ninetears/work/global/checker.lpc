// Coded by Begosh@RotD July '94
// This is the object the filter_array in chat_deamon.c calls in.
 
int check_guild( object element, string extra )
{
    if( (string)element->query_guild_ob() == extra &&
        !element->query_guild() ) return 1;
    else return 0;
}
 
int check_chat( object element ) { return !element->query_chat(); }
 
int check_cre( object element, int extra )
{
    if( extra  ) return 1;
    else return !element->check_earmuffs("creator-tell");
}
 
  int check_lord( object element, int extra )
{
      if( extra ) return 1;
      else return !element->check_earmuffs("lord-tell");
}
 
int check_god( object element, int extra )
{
    if( extra  ) return 1;
    else return !element->check_earmuffs("god-tell");
}
