/*
   subloc.h

   These are some standard names of sublocations
*/

#ifndef SUBL_DEFINED
#define SUBL_DEFINED

#define SUBL_CODE		"/sys/global/subloc"

#define SUBL_PREPOS		"_subl_prepos_"
#define SUBL_CONT_PREP(p) 	(SUBL_PREPOS + (p))


/* Subloc access types.  These are used to determine what access an object
 * has to a particular subloc.
 */

/*
 * SUBLOC_ACCESS_SEE
 * This access type determines whether accessor can see into the subloc
 */
#define SUBLOC_ACCESS_SEE       "see"

/*
 * SUBL_ACS_SEE
 * Maintained for backward compatibility.  Do not use this.
 */
#define SUBL_ACS_SEE		SUBLOC_ACCESS_SEE

/*
 * SUBLOC_ACCESS_MANIP
 * This access type determines whether the accessor can manipulate items
 * in the subloc.
 */
#define SUBLOC_ACCESS_MANIP     "manip"

/*
 * SUBL_ACS_MANIP
 * Maintained for backward compatibility.  Do not use this.
 */
#define SUBL_ACS_MANIP		SUBLOC_ACCESS_MANIP

/*
 * SUBLOC_ACCESS_ENTER
 * This access type determines whether the accessor can enter the subloc
 */
#define SUBLOC_ACCESS_ENTER     "enter"

#endif

