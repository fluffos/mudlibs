/*
   obflags.h
   
   This is the GD flags for objects. The 'flag' integer is available to
   LPC objects through: flag = debug("ob_flags", ob);
*/

#define O_HEART_BEAT		0x01  /* Does it have an heart beat ? */
#define O_IS_WIZARD		0x02  /* Should we count commands for score? */
#define O_ENABLE_COMMANDS	0x04  /* Can it execute commands ? */
#define O_CLONE			0x08  /* Is it cloned from a master copy ? */
#define O_DESTRUCTED		0x10  /* Is it destructed ? */
#define O_SWAPPED		0x20  /* Is it swapped to file */
#define O_ONCE_INTERACTIVE	0x40  /* Has it ever been interactive ? */
#define O_APPROVED		0x80  /* Is std/object.c inherited ? */
#define O_RESET_STATE		0x100 /* Object in a 'reset':ed state ? */
#define O_WILL_CLEAN_UP		0x200 /* clean_up will be called next time */
