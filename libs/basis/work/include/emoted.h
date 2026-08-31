// mudlib:  Basis
// file:    emoted.h
// date:    1992/09/25

#define e_me       0
#define e_others   1
#define e_target   2
#define e_modifier 3
#define e_verb     4
#define e_verb2    5

#define FIELDS ({ ".me", ".others", ".target", ".modifier", ".verb", ".verb2" })
#define STOP_FIELDS FIELDS + ({ ".end" })
