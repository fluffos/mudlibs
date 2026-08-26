// domains.h
// This file holds the array of existing domains and levels of those domains.
// 'help domains' should give info about each one.

#ifndef __DOMAINS_H
#define __DOMAINS_H

// This list is all domains in which wizards can be promoted. A domain
// which doesn't have wizards doesn't need to be in DOMAIN_LIST.
#define DOMAIN_LIST ({ "security", "lima", "game", "teaching", "interface", "network", "knowledge", "ancients", "TMI" })

// This list is the levels available in each domain with wizards.
#define LEVEL_LIST ({ "player", "guest", "staff", "manager" })

// This is the list of all domains with directories. A domain which has
// no files doesn't need to be on DOMAIN_DIRS.
#define DOMAIN_DIRS ({ "lima", "knowledge", "Conf", "Fooland", "grid", "TMI", "std", "teaching", "interface" })

#define ENTRY_LEVEL 2
#define MIN_SPONSOR_LEVEL 3


#endif


/* EOF */
