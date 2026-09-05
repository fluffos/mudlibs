//===========================================================================
//  Handling of player connections
//
// See also valid_exec().
//===========================================================================

//---------------------------------------------------------------------------
object connect ()

// Handle the request for a new connection.
//
// Result:
//   A login object the requested connection should be bound to.
//
// Note that the connection is not bound yet!
//
// The gamedriver will call the lfun 'logon()' in the login object after
// binding the connection to it. That lfun has to return != 0 to succeed.
{
  return clone_object(PLAYER);
}

//---------------------------------------------------------------------------
void disconnect (object obj)

// Handle the loss of an IP connection.
//
// Argument:
//   obj: The (formerly) interactive object (player).
{
}


//---------------------------------------------------------------------------
void remove_player (object player)

// Remove a player object from the game.
//
// Argument:
//   player: The player object to be removed.
//
{
  catch(player->quit());
  if (player)
    destruct(player);
}


//---------------------------------------------------------------------------
void stale_erq (closure callback)

// Notify the loss of the erq demon.
//
// Argument:
//   callback: the callback closure set for an erq request.
//
// If the erq connection dies prematurely, the driver will call this lfun for
// every pending request with set callback. This function should notify the
// originating object that the answer will never arrive.
// In our case, we simply reattach the default erq.
{
  attach_erq_demon("", 0);
}

