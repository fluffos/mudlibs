/* 08/31/06 Earwax: removed this from wiz soul and player.c */

#include <security.h>

int cmd_snoop(string str)
{
  string who, reason;
  int level;
  object ob, snooper;
  
  level = (int)this_player()->query_level();
  
  if (!str)
  {
    write("Clearing snoop.\n");
#ifndef __LDMUD__
    snoop();
#else
    efun::snoop( this_player() );
#endif
    return 1;
  }
  
  if (level < SNOOP)
  {
    write("Insufficient level to snoop.\n");
    return 1;
  }
  
  if ( level >= GOD && (ob = find_player(str)) )
  {
    write("Attempting to snoop "+str+".\n");
#ifndef __LDMUD__
    snoop(ob);
#else
    snoop( this_player(), ob);
#endif
    return 1;
  }
  
  if ( sscanf(str, "%s %s", who, reason) != 2 )
  {
    printf("SNOOP: Improper number of arguments.\n");
    printf("Syntax: snoop <playername> <reason>\n");
    return 1;
  }
  
  if ( !(ob = find_player(who)) )
  {
    printf("SNOOP: Player not found: %s\n", who);
    return 1;
  }
  
  if ( level <= (int)ob->query_level() )
  {
    printf("SNOOP: You cannot snoop anyone of greater or equal level.\n");
    return 1;
  }
  
  if ( (snooper = query_snoop(ob)) )
  {
    if ( (int)snooper->query_level() > level )
      write("SNOOP: Failed.\n");
    else
      printf("SNOOP: %s already being snooped by %s.\n", capitalize(who)
        , capitalize((string)snooper->query_real_name()));
    
    return 1;
  }
  
  printf("SNOOP: Now snooping %s.\n", capitalize(who));
  log_file("secure/SNOOP", sprintf("%s: %s snooped %s for: %s\n"
    , ctime(), capitalize(who), capitalize((string)this_player()->query_real_name())
    , reason));
#ifndef __LDMUD__
    snoop(ob);
#else
    snoop( this_player(), ob);
#endif
  return 1;
}
