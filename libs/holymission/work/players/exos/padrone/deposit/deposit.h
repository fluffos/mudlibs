/*  deposit.h -- config file for the safe-deposit box service.
 *	Thomas Padron-McCarthy (Padrone), padrone@lysator.liu.se, 1990
 *	Share and enjoy! No rights reserved except the right to reserve rights.
 *	This file latest updated January 17, 1991 by Padrone.
 */

#define FEE		3000
#define INSURANCE_LIMIT	1000
#define BOXROOM		"room/boxroom"
			/* BOXROOM has to be in /room or /obj to work in 2.0! */
#define DEPOSIT		"players/padrone/deposit/deposit"
#define COMPLAINTS	"players/padrone/deposit/complaints"
#define DEPOSIT_PLACE	"players/ingis/lane"
#define LOGFILE		"padrone.deposit"

/* These should probably always be compass directions. */
#define ENTER		"west"
#define LEAVE		"east"
#define TO_COMPLAINTS	"north"
#define FROM_COMPLAINTS	"south"
#define TO_BOXROOM	"south"
#define FROM_BOXROOM	"north"
