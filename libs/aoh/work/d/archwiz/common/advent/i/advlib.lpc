/* Advent - Library -- Mateese, 04-Aug-96
 *
 * Some useful functions for the Advent area.
 * Most of these deal with the storing/retrieval of the persistant data.
 * Some functions are to be used by external objects, mostly to implement
 * the rewards for true spelunkers.
 */

#include "advent.h"

/*-----------------------------------------------------------------------*/
varargs void SetFlag(int flag, object player)

/* Set the <flag> in the A_ADVDATA attribute of <player> (default 
 * is this_player()).
 */

{
  mixed flags;

  if (!player)
    player = this_player();
  flags = player->QueryAttribute(A_ADVDATA);
  if (!flags)
    flags = "";
  if (intp(flags))
  {
    flags = "";
    flags = set_bit(flags, F_SOLVED);
  }
  player->SetAttribute(A_ADVDATA, set_bit(flags, flag));
}

/*-----------------------------------------------------------------------*/
varargs int QueryFlag(int flag, object player)

/* Query the <flag> in the A_ADVDATA attribute of <player> (default 
 * is this_player()) and return it's status.
 */

{
  mixed flags;

  if (!player)
    player = this_player();
  flags = player->QueryAttribute(A_ADVDATA);
  if (!flags)
    return 0;
  if (intp(flags))
  {
    flags = "";
    flags = set_bit(flags, F_SOLVED);
    player->SetAttribute(A_ADVDATA, flags);
  }
  if (flag < F_NUM_TREASURES && test_bit(flags, F_SOLVED))
    return 1;
  return test_bit(flags, flag);
}

/*-----------------------------------------------------------------------*/
varargs void ClearFlag(int flag, object player)

/* Unset the <flag> in the A_ADVDATA attribute of <player> (default 
 * is this_player()).
 */

{
  mixed flags;

  if (!player)
    player = this_player();
  flags = player->QueryAttribute(A_ADVDATA);
  if (!flags)
    flags = "";
  if (intp(flags))
  {
    flags = "";
    flags = set_bit(flags, F_SOLVED);
  }
  player->SetAttribute(A_ADVDATA, clear_bit(flags, flag));
}

/*-----------------------------------------------------------------------*/
varargs int SolvedAdvent (object player)

/* Return non-zero if <player> (default is this_player()) solved the cave.
 */

{
  return QueryFlag(F_SOLVED, player || this_player());
}

/*************************************************************************/
