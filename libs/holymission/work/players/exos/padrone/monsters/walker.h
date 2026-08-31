/*  players/padrone/walker/walker.h
 *	-- some definitions for the walking castle
 */

#define WALKER_VERSION	"4.15 (with demon) (April 9, 1991)"

/*  Where the walking castle starts.
 *  This you can change to whatever you want.
 */
#define DEST		"room/plane2"

/*  Seconds between automatic moves.
 *  Change this if you want, but it probably
 *  shouldn't be less than 5.
 */
#define MOVE_DELAY	20

/*  On LPmuds with American spelling:
 *	Change this #define from "armour" to "armor"!
 */
#define ARMOUR "armour"

/*  Define this if the cell with the demon should be present.
 *  If not, the room "walker/cell.lpc" can be removed.
 *  NOTE: The demon in the cell can only be killed with a very
 *        special weapon, and you need a special key to enter,
 *        so if you don't have the rest of Padrone's castle on
 *        your Mud, you should NOT define DEMON!
 *  The stand-alone version, without the demon, is not supported any more.
 */
#define PATH "/players/padrone/walker/"
#define DEMON

/*  Usually, all restarts after crashes
 *  are logged on the file "padrone.walker".
 *  This log can help find problems in different rooms,
 *  but on a poorly debugged mud it can grow rather quickly
 *  (some lines every hour).
 *  If you don't want this log, define WALKER_LOG(x) as nothing:
 *	#define WALKER_LOG(x)
 */
#define WALKER_LOG(x) log_file("padrone.walker", x);

/*  These room name definitions are used in call_other
 *  and tell_room, but not in (most) move_player calls.
 *  I strongly suggest that you don't change them.
 */
#define CASTLE			"players/padrone/walker/castle"
#define CASTLE_MOVER		"players/padrone/walker/mover"
#define CASTLE_RESTARTER	"players/padrone/walker/restarter"
#define BRIDGE			"players/padrone/walker/bridge"
#define ROPE_LADDER		"players/padrone/walker/rope_ladder"
#define GATE_ROOM		"players/padrone/walker/gate_room"
#define GATE_CONTROL		"players/padrone/walker/gate_control"
