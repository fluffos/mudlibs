#ifndef SYS_INFO_H
#define SYS_INFO_H 1

// Official fields

#define SINFO_LEVEL   0  // the wizlevel (-1 == illegal name)
#define SINFO_DOMAIN  1  // a mapping of domain memberships
#define SINFO_HONORS  2  // an array of strings describing honorifics
#define SINFO_BANISH  3  // 0, or a string describing the reason
#define SINFO_FLAGS   4  // optional bit-flags
#define SINFO_PROMO   5  // Sponsor and time of sponsoring

// Private fields

#define SINFO_PASSWORD  6  // the crypted password
#define SINFO_STAMP     7  // time of the last touch (-1 == permanent)

#define SINFO_NO_FIELDS  8 // Number of fields

// Special levels of SINFO_LEVEL

#define SILEVEL_ILLEGAL  -1  // name is illegal
#define SILEVEL_DOMAIN   -2  // name is a domain name.
#define SILEVEL_RESERVED -3  // name is reserved

// Recognized flags
#define SIFLAG_LORD (1<<0)  // Set for players which are Lords

#define SIFLAG_ALL (SIFLAG_LORD)  // Mask for all flags

// Fields of SINFO_PROMO (needn't exist if not applicable)

#define SIPROMO_LTIME  0  // date of promotion to learnerhood
#define SIPROMO_LNAME  1  // Name of learnerhood sponsor
#define SIPROMO_WTIME  2  // date of promotion to wizardhood
#define SIPROMO_WNAME  3  // Name of wizardhood sponsor


// Pseudodomain SYSTEM and it's SINFO_DOMAIN entries

#define SIDOM_SYSTEM   "system"  // Pseudo domain for various name listings.

#define SIDOM_ADMIN    "admin"     // list of admins
#define SIDOM_ARCH     "arch"      // list of arches
#define SIDOM_BANISH   "banish"    // list of banished users
#define SIDOM_RESERVED "reserved"  // list of reserved names

#endif
