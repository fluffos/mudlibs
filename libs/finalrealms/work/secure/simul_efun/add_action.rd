/*

     Mordred @ Realms of the Dragon
     ------------------------------
     Due to the way that the history system here works, and how it is
     intertwined with the rest of the mud and the operations of how
     security is handled, this has become somewhat of a risk. However
     small that may be is irellavent.

 */
#include <commands.h>

varargs void add_action( mixed fun, string cmd, int pri )
{
   if( pri >= A_P_SOMETHING )
    {
    }
   efun::add_action( fun, cmd, pri ) ;
}
