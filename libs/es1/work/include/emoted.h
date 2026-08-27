// mudlib:  Basis
// file:    emoted.h
// date:    1992/09/25
// modify by Ruby for chinese ! 1994/8/20

#define e_me       0
#define e_others   1
#define e_target   2
#define e_modifier 3
#define e_verb     4
#define e_verb2    5
#define c_me       6
#define c_others   7
#define c_target   8
#define c_modifier 9
#define FIELDS ({ ".me", ".others", ".target", ".modifier", ".verb",".verb2",".c_me",".c_others",".c_target",".c_modifier" })
#define STOP_FIELDS FIELDS + ({ ".end" })
