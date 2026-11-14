/*
 * Exit types, for doors, etc.
 */

/*
 * Default states
 */
#define	DOOR_OPEN	"0"
#define	DOOR_CLOSED	"1"
#define	DOOR_LOCKED	"2"
/* door state is obtained from the object on the other side */
#define	DOOR_OTHER	"3"
/* like 3, and door also has no key on this side */
#define	DOOR_BLIND	"4"

/*
 * Exit conditions.  "0:code" means it's a door, and the player
 * must have a key id'ing to it.  "0:" with no code means it has no key,
 * though the door appears (it just doesn't have a keyhole).  If the
 * first character of the code is an integer, that's the default door state.  If
 * it's not, the state is assumed to come from a save file or the other
 * side of the door.  If it's 3, the other side is always queried.
 */

#define	IS_DOOR(conds)		(index(";"+(conds), "0:") >= 0)
