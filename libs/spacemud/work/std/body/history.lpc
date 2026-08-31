/* Do not remove the headers from this file! see /USAGE for more info. */

/* Do not remove headers from this file! see /USAGE for more info. */

/*
 * Object to be inherited by the body object.
 * The purpose of this is to store various histories that are to be associated
 * with the body that don't fit better in other places.  For example 'say
 * history
 *
 * Say history size is based upon the CHANNEL_HISTORY_SIZE (see <config.h>)
 *
 * Written by Tigran 05-08-2000
 */

nosave private string *say_history = ({});

void add_say_history(string add)
{
   int size;

   // Strip trailing \n's
   if (add[ < 1] == '\n')
      add = add[0.. < 2];

   // Add the history item to the end of the array in plain text
   say_history += ({XTERM256_D->substitute_colour(add, "plain")});

   // Trim the end of the history if larger than CHANNEL_HISTORY_SIZE.
   size = sizeof(say_history);
   if (size > CHANNEL_HISTORY_SIZE)
      say_history = say_history[(size - CHANNEL_HISTORY_SIZE)..];
}

string *list_say_history()
{
   return copy(say_history);
}
