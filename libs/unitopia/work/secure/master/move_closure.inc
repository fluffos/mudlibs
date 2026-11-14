// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/move_closure.inc
// Description:	Die Closure die bei einem set_environment() aufgerufen wird
// Author:	
// Modified by:	
//
// $Log: move_closure.inc,v $
// Revision 1.5  2002/07/30 21:24:47  gnomi
// Letzten Patch rueckgaengig gemacht. Resistent gegen Zerstoerungen ueber eine
// extra Abfrage implementiert.
//
// Revision 1.4  2002/07/30 00:55:10  gnomi
// Etwas vereinfacht und damit resistenter gegen Zerstoerungen im init()
// gemacht.
//
// Revision 1.3  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#pragma strict_types

    set_driver_hook(
      H_MOVE_OBJECT1,
      unbound_lambda( ({'item, 'dest}), ({#',,

	/* Low-Move aufrufen (set_environment) */
	({#'efun::set_environment, 'item, 'dest}),

	/* wenn item ein living ist, im neuen Raum init aufrufen */
	({#'?, ({#'living, 'item}), ({#',,
	  ({#'efun::set_this_player, 'item}),
	  ({#'call_other, 'dest, "init"}),
#if 0
	  ({#'?, ({#'!, 'item}), ({#',,
		({#'write_file, "/log/sys/MOVE_ERR",
			({#'sprintf, "item:%O dest:%O\n", 'item, 'dest}) }),
		({#'return}) }) }),
#endif
	  /* Falls das set_environment nicht geklappt hat, return */
	  ({#'?, ({#'!=, ({#'environment, 'item}), 'dest}), ({#'return})}),
	}) }),

	/* others=all_inventory(dest) */
	({#'=, 'others, ({#'all_inventory, 'dest}) }),

	/* item aus der 'others'-Liste rausschmeissen */
	({#'=, ({#'[, 'others, ({#'member, 'others, 'item}) }), 0}),
	({#'-=, 'others, '({0}) }),

	/* Alle livings in dest rufen in item init auf */
	({#'filter, 'others,
	  ({#'bind_lambda,
	    unbound_lambda( ({'ob, 'item}),
	      ({#'?, ({#'living, 'ob}), ({#',,
		({#'efun::set_this_player, 'ob}),
		({#'call_other, 'item, "init"}),
	      }) })
	    )
	  }),
	  'item,
	}),

	/* item ruft, wenn es ein Lebewesen ist, in allen Objekten
	   init auf (aber in umgekehrter Reihenfolge) */
	({#'?, ({#'living, 'item}), ({#',,
	  ({#'efun::set_this_player, 'item}),
	  ({#'=, 'i, ({#'sizeof, 'others }) }),
	  ({#'while, 'i, 0,
	    ({#'&&,
	      ({#'=, 'ob, ({#'[, 'others, ({#'-=, 'i, 1 }) }) }),
	      ({#'call_other, 'ob,  "init"}),
	    })
	  }),
	}) }),

	/* Wenn dest ein living ist, ruft dest in item init auf */
	({#'?, ({#'living, 'dest}), ({#',,
	  ({#'efun::set_this_player, 'dest}),
	  ({#'call_other, 'item, "init"}),
	}) }),

      }) )
    );
