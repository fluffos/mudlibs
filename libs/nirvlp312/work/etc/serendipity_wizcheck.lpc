// serendipity_wizcheck, written by Carador, Nov-1996.
// it tells you if 'who' is a wizard in Serendipity

#ifdef TUBMUD

#include <kernel.h>

inherit ACCESS;

mapping wizards;
int last_read;

int query_is_wizard(mixed who)
{
  if (!stringp(who)) who = who->query_real_name();
   
  if (last_read != 
        unguarded(1, #'file_time, "/secret/access_serendipity.o")) {
    last_read = time();
    unguarded(1, #'restore_object, "/secret/access_serendipity");
  }
  return wizards[who];
}

#endif
