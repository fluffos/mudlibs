/*
 * Security Levels
 */

#ifndef LEVELS_H
#define LEVELS_H

#define SEC0  0   /* Player                                   */
#define SEC1  10  /* Aspirant - when you become a wizard      */
#define SEC2  20  /* Apprentice - Wizard powers, no privleges */
#define SEC3  30  /* Creator - 'full wiz' - open area         */
#define SEC4  40  /* Sage    - Multiple areas, guild          */
#define SEC5  50  /* Lord    - Of a domain (theme / guild)    */
#define SEC6  60  /* Senior  - Start of admin level, sponsor  */
#define SEC7  70  /* Elder   - Area chekcing and approving    */
#define SEC8  80  /* Arch    - Whole mudlib working           */
#define SEC9  90  /* Admin   - Policy making, mud control     */
#define SEC10 100 /* Demigod - Rumplemintz                    */
#define SEC11 110 /* Founder of Nirvana - Boltar              */

/* Optional QC's (Quality control) with full read access, except private,
 * write access according to security level
 */
#define QC ({ "none", })

#endif
