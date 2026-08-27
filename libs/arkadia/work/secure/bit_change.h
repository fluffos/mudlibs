/*
 * bit_change.h
 *
 * Copyright (C) Stas van der Schaaf - August 19 1995
 *               Mercade @ Genesis
 *
 * This header file contains the actual bits to modify.
 */

/*
 * DOMAIN is the name of the domain of which the bits are manipulated.
 * When bits are moved, SOURCE can be the domain where the bits are moved
 * from. When it is undefined, the bits are moved within DOMAIN.
 * LOGFILE is the file in which to log the changes.
 */
#define SOURCE  ("Rhovanion")
#define DOMAIN  ("Shire")
#define LOGFILE ("/d/Shire/log/BIT_CHANGE")

/*
 * Due to the trickyness of manipulating bits only one person can do this
 * at one time. ALLOWED contains his/her name.
 */
#define ALLOWED ("mercade")

/*
 * CHANGE contains the actual changes that have to be made to the bits of
 * the players. The format is an array or arrays as follows:
 *
 * CHANGE ({ ({ "remove", a, b }),
 *           ({ "move", c, d, e, f }) })
 *
 * "remove" removes bit 'b' from group 'a'.
 * "move" moves bit 'd' in group 'c' to bit 'f' in group 'e'.
 */
#define CHANGE  ({ \
                   ({ "move", 0,  4, 3,  9 }), \
                   ({ "move", 0, 10, 3, 10 }), \
                   ({ "move", 0,  6, 3, 11 }), \
                   ({ "move", 0,  5, 3, 13 }), \
                   ({ "move", 0,  9, 3, 14 }), \
    })

/*
 * These are the indices to the CHANGE definition array.
 */
#define INDEX_COMMAND      (0)
#define INDEX_SOURCE_GROUP (1)
#define INDEX_SOURCE_BIT   (2)
#define INDEX_DEST_GROUP   (3)
#define INDEX_DEST_BIT     (4)
