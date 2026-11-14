// SilberLand MUDlib
//
// asynchron.c -- asynchronous command processing
//
// $Date: 1997/03/13 02:07:36 $
/* $Revision: 1.3 $
 * $Log: asynchron.c,v $
 * Revision 1.3  1997/03/13 02:07:36  Woody
 * prepared for revision control
 *
 * Revision 1.2  1994/07/13  17:23:59  Hate
 * added message when going into asynchrone mode
 *
 * Revision 1.2  1994/07/13  17:23:59  Hate
 * added message when going into asynchrone mode
 *
 * Revision 1.1  1994/06/01  15:18:56  Hate
 * Initial revision
 *
*/

#include <defines.h>

// asynchron() -- asynchron process handling
// the cmd will be executed like map, but stopped and reinitiated with
// call_out() when the evaluation time is exceeded
varargs void asynchron(mixed *array, closure cmd, mixed extra, int c)
{
  int i, j; j = sizeof(array);
  while(i < j && get_eval_cost() > 80000)
    apply(cmd, array[i..i++] + (pointerp(extra)?extra:({})));
  if(sizeof(array = array[i..])) 
	{
    if(!c) tell_object(ME, sprintf("%O: entering asynchronous mode\n", cmd));
    call_out(#'asynchron, 1, array, cmd, extra, 1);
  }
  else 
    if(c) tell_object(ME, sprintf("%O: done.\n", cmd));
}
