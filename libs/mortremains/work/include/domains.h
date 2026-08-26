// domains.h
// This file holds the array of existing domains and levels of those domains.
// 'help domains' should give info about each one.

#ifndef __DOMAINS_H
#define __DOMAINS_H

// This list is all domains in which wizards can be promoted. A domain
// which doesn't have wizards doesn't need to be in DOMAIN_LIST.
#define DOMAIN_LIST ({ "Law", "Prime", "Guest", "Ancients",  \
"WWW", \
   "Teaching", "Training", "Theme", "Ocean", "Arctic", "Planar" })

// This list is the levels available in each domain with wizards.
#define LEVEL_LIST ({ "Player", "Domainless", "Neophyte", "Builder", \
   "Speaker", "Domain Lord", "Elder", "Administrator" })

// This is the list of all domains with directories. A domain which has
// no files doesn't need to be on DOMAIN_DIRS.
#define DOMAIN_DIRS ({ "Law", "Prime", "Ancients", "Balance",  \
   "Planar", "Theme", "Ocean", "Arctic" })

#define ENTRY_LEVEL 2
#define MIN_SPONSOR_LEVEL 5


#endif


/* EOF */
