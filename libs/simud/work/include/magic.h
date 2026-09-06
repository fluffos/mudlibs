#ifndef _MAGIC_H_
#define _MAGIC_H_

#define MAGIC_DAEMON             "/daemon/magic"
#define MAGIC_DEFAULT_MANA_LEVEL 1000000
#define MAGIC_ABSORB_DELAY       4
#define MAGIC_SPELLS             (MAGIC_DAEMON->query_spells())
#endif
