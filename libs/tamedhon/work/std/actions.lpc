// SilberLand MUDlib
//
// std/actions.c -- restricted action handler
//
// $Date: 1997/03/13 02:48:05 $
/* $Revision: 1.1 $
 * $Log: actions.c,v $
 * Revision 1.1  1997/03/13 02:48:05  Woody
 * prepared for revision control
 *
 * 30.08.1995	16:00	Mupfel
 * 08.03.1996	03:00	Mupfel	UndoAction
 *
 */

private mapping playerlist;
private int     max_actions, max_resets, reset_counter;
private status  created;

void create(int actions, int resets)
{
  max_actions = (!actions ? 1 : actions);
  max_resets = (!resets ? 1 : resets);
  reset_counter = 0;
  created = 1;
  playerlist = ([]);
}

void reset()
{
  reset_counter++;
  if (reset_counter == max_resets)
  {
    playerlist = ([]);
    reset_counter = 0;
  }
}
    
int ActionAllowed(object player)
{
  if (!created) raise_error("actions::ActionAllowed: create() missing");
  if (!player) return 0;
  // Wenn der Spieler noch nicht in der Liste steht:
  // Spieler eintragen, Erfolg zurueckgeben
  if (!playerlist[player])  // das geht weil der 'value' > 0 ist
  {
    playerlist += ([player:1]);
    return 1;
  }
  // Wenn der Spieler in der Liste steht:
  // pruefen, ob die maximale Anzahl erlaubter Aktionen
  // erreicht ist.
  if (playerlist[player] < max_actions)
  {
    playerlist[player]++;
    return 1;
  }
  return 0;
}

void UndoAction(object player)
{
  if (!created) raise_error("actions::ActionAllowed: create() missing");
  if (objectp(player) && playerlist[player] > 0)
    playerlist[player]--;
}

