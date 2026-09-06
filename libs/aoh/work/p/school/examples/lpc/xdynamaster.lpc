/*   Master room for dynamic maze example (Mateese 29-Sep-1992)
**
** This object is not used as a room (though this could be possible),
** but merely serves as a database for the maze rooms.
** The maze is very simple: the only variant data are the exits of the
** several rooms.
**
** Note that there are several ways to realize a dynamic room areal,
** this is just one (of the easiest, though efficient).
** Just the GD assisted variant (see /d/archwiz/common/lpc/exm/xmaze0)
** is even easier and in any case to be preferred.
**
** -- About dynamic rooms --
**   Dynamic rooms are a simple but effective way to reduce the amount of
** diskspace used to implement a certain uniform area, like a maze.
**   A typical maze consists of many rooms which have only few differences
** in description and content. Implementing the maze in a one-file-per-
** room-system is straightforward, simple and ineffective then.
** Its better to concentrate the variant data in one maze-master, which
** then creates the rooms from one basic file on demand. This basic file
** contains the fixed data (and some utility funs), and gets the variant
** data from the maze master upon creation.
**   This way one has just a few room _files_, but is able to create a maze
** consisting of many room _objects_.
**   Moving the player through the maze takes a certain care, though.
** Since the room objects don't know about their neighboured rooms, the
** move-command of one player needs to be executed by the maze master.
**   The maze master itself may be used as a normal room, but needn't.
** Important is, that the master is just loaded, never cloned.
**
** If you`re interested in a big 'real' dynamic maze, take a look at
** Chalamah's quest.
*/

#include <moving.h>

  /* This arrays holds all created room objects.
  ** Since our maze is small, we don't need a true 3-d-array.
  */
object *mazeroom;

  /* Create all we need (it isn't much ;-) */
create() {
  seteuid(getuid(this_object()));
  mazeroom = allocate(8);
}


/*--------------------------------------------------------------------------*/
/* Return the maze room of an specific coordinate.
** If it doesn't exist, it will be created.
*/

object _make_room (int x, int y, int z) {
  int ix;
  string *exits;
  object mroom;

    /* Create index in mazeroom out of new coordinates */
  ix = 4*z + 2*y + x;

    /* Get maze room. If not existing, create it */
  if (!(mroom = mazeroom[ix])) {

      /* Set up list of allowed exits */
    exits = ({ });

      /* Add special exit for first maze room,
      ** the one connected to /d/.../xroom4
      */
    if (!x && !y && !z) exits += ({ "south" });

      /* Add exits depending on position. Since the maze is orthogonal,
      ** this is easily done w/o extra "exits"-array.
      */
    if (!x) exits += ({ "east" });  else exits += ({ "west" });
    if (!y) exits += ({ "north" }); else exits += ({ "south" });
    if (!z) exits += ({ "up" });    else exits += ({ "down" });

      /* Create the room */
    mroom = clone_object ("/d/archwiz/common/lpc/exm/xdynabase");
    if (!mroom) { write ("Uh-Oh!\n"); return 0; }

      /* Init it */
    mroom->init_mroom (exits, x, y, z);

      /* Add it in our roomlist */
    mazeroom[ix] = mroom;
  }

    /* Righto, we have the room, and its inited. */
  return mroom;
}

/*--------------------------------------------------------------------------*/
/* Move a player from one room to another.
** If this other room doesn't exist, create and initialize it.
** We do only minimal error catching in this example.
*/

int _move_in_dyna (object pl, string dir, int fx, int fy, int fz) {
  int x, y, z;
  object mroom;

  x = fx; y = fy; z = fz;

    /* Compute new coordinates */
  switch (dir) {
  case "north": y++; break;
  case "south": y--; break;
  case "east" : x++; break;
  case "west" : x--; break;
  case "up"   : z++; break;
  case "down" : z--; break;
  }

    /* Did we exit the maze into /d/.../xroom4 ? */
  if (y == -1 && !x && !z) {
    pl->player ("/d/archwiz/common/lpc/exm/xroom4", M_GO, dir);
    return 1;
  }

    /* Get maze room. If not existing, create it */
  if (!(mroom = _make_room (x, y, z))) return 0;

    /* Now move the player in it. */
  pl->move(mroom, M_GO, dir);
  return 1;
}


