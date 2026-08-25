#include "move_failures.h"
#define DROP 1
#define GET 2
int move_flag;
private object prev; /* added Mar 3 '93 by Dank to support goback command */

object query_prev() { return prev; }

/* default to being gettable and dropable...
 * modify as you will...
 */
void reset_get() { move_flag |= GET; }   /* can't be gotten */
void set_get() { move_flag &= ~GET; }    /* can be gotten */
void reset_drop() { move_flag |= DROP; }   /* can't be dropped */
void set_drop() { move_flag &= ~DROP; }    /* can be dropped */  

/* these should have been called "query...", but they're not */
int drop() { return move_flag & DROP; }
int get() { return move_flag & GET; }
int gettable() { return !get(); }

void set_move_flag(int i) { move_flag = i; }
int query_move_flag() { return move_flag; }
// the query added by Randor, 20-mar-98

varargs int move(mixed dest, mixed messin, mixed messout) {

  prev = environment();
  if (!dest)
    return MOVE_EMPTY_DEST;
  if (environment() && !environment()->test_remove(this_object(),
                                                  move_flag & DROP))
    return MOVE_NO_DROP;
  if (!dest->test_add(this_object(), move_flag & GET))
    return MOVE_NO_GET;
  if (environment())
    event(environment(), "exit", messout, dest);
  move_object( dest);
  if (objectp(dest))
    event(dest, "enter", messin, prev);
  else if (find_object(dest))
    event(find_object(dest), "enter", messin, prev);
  return MOVE_OK;
}

void dest_me() {
  int i;
  object* obs;
  object ob;
//  object *siblings; /* Hamlet */

  if (environment())
    event(environment(), "dest_me");
  // Destruct shadows of this object, Wonderflug 96
  obs = ({ });
  ob = shadow(this_object(), 0);
  while ( ob )
  {
    obs += ({ ob });
    ob = shadow(ob, 0);
  }
  for ( i=0; i<sizeof(obs); i++ )
    if ( obs[i] )
      destruct(obs[i]);

  /* Hamlet's junk... if this was the last clone of the file,
     discard the file as well.
  if(clonep(this_object())) {
    siblings = children(explode(file_name(this_object()),"#")[0]);
    siblings -= ({ this_object() });

    if((sizeof(siblings) == 1) && !clonep(siblings[0]))
      siblings[0]->dest_me();
  }
*/

  efun::destruct(this_object());
}

/* Do not I repeat do not mask this function.
 * is used when all else fails to dest the object...
 * If we find you masking this function... We will cut you up
 * into little bits... slowly
 */
nomask mixed dwep() {
  efun::destruct(this_object());
  return "Destruct With Extreme Prejuce";
}

