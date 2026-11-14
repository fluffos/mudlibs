// mudlib: Fading Summer
// file:   verb.h
// author: Lontau
// date:   22-6-2001

/* Synopsis: This header is meant to be included in the verb
   daemon.  It provides defines that support the saving and
   restoring of data.
*/

#ifndef _H_verb_d_
#define _H_verb_d_

#define VERB_SAVE                DAEMON_DATA_DIR + "/verb"

#define VERB_NO_ACCESS           0
#define VERB_ENTRY_EXISTS        1
#define VERB_ENTRY_NONEXISTANT   2
#define VERB_SUCCESS             3

#endif
