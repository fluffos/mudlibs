// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/skill.h
// Description: Makros fuer die Skill-Pfade.
// Author:	Pulami     02.08.2002
//
// $Log: skill.h,v $
// Revision 1.2  2005/11/18 21:48:06  gnomi
// Ein paar Defines fuer /apps/skill_checker.
//
// Revision 1.1  2003/02/20 01:08:49  gnomi
// Defines fuer die Skillpfade von Pulami.
//

#ifndef SKILL_H
#define SKILL_H 1

/*
FUNKTION: EQUAL_SKILL_PATHS
DEKLARATION: int EQUAL_SKILL_PATHS(string *pfad1, string *pfad2)
BESCHREIBUNG:
Liefert 1, wenn die beiden Skill-Pfade gleich sind, ansonsten 0.
VERWEISE: set_skill_path, query_skill_path, SP_LISTE
GRUPPEN: skill
*/
// Hinweis: Die Felder werden aus Performance-Gruenden nicht komplett
//          verglichen.
#define EQUAL_SKILL_PATHS(pfad1, pfad2)         \
    funcall((:                                  \
        pointerp($1) && pointerp($2) &&         \
        sizeof($1)==sizeof($2) &&               \
        sizeof($1) &&                           \
        $1[<1]==$2[<1]                          \
        :), pfad1, pfad2)

/*
FUNKTION: SP_LISTE
DEKLARATION: SP_LISTE
BESCHREIBUNG:
Liste der in UNItopia verwendeten Skill-Pfade:

Nahkampf-Waffen:
    SP_AXT          ({"skill", "offensiv", "scharf", "axt"})
    SP_DEGEN        ({"skill", "offensiv", "scharf", "degen"})
    SP_KEULE        ({"skill", "offensiv", "stumpf", "keule"})
    SP_KURZSCHWERT  ({"skill", "offensiv", "scharf", "schwert", "kurzschwert"})
    SP_LANGSCHWERT  ({"skill", "offensiv", "scharf", "schwert", "langschwert"})
    SP_MESSER       ({"skill", "offensiv", "scharf", "messer"})
    SP_PEITSCHE     ({"skill", "offensiv", "stumpf", "peitsche"})
    SP_SAEBEL       ({"skill", "offensiv", "scharf", "saebel"})
    SP_STOCK        ({"skill", "offensiv", "stumpf", "stock"})

Wurf-Waffen:
    SP_SPEER        ({"skill", "offensiv", "scharf", "speer"})
    SP_WURFMESSER   ({"skill", "offensiv", "scharf", "wurfmesser"})

Schuss-Waffen:
    SP_BLASROHR     ({"skill", "offensiv", "scharf", "blasrohr"})
    SP_BOGEN        ({"skill", "offensiv", "scharf", "bogen"})
    SP_SCHLEUDER    ({"skill", "offensiv", "stumpf", "schleuder"})

Handkampf:
    SP_HAENDE       ({"skill", "offensiv", "haende"})

Defensiv-Waffen:
    SP_GROSSSCHILD  ({"skill", "defensiv", "schild", "gross"})
    SP_KLEINSCHILD  ({"skill", "defensiv", "schild", "klein"})

Zauber:
    SP_ABWEHR       ({"skill", "zauber", "abwehr"})
    SP_BEWERTEN     ({"skill", "zauber", "bewerte"})
    SP_LICHT        ({"skill", "zauber", "licht"})
    SP_NEHMEN       ({"skill", "zauber", "nehmen"})
    SP_SICHT        ({"skill", "zauber", "sicht"})
    SP_TARNEN       ({"skill", "zauber", "tarnen"})

Getoetet:
    SP_GROSSWILD    ({"skill", "getoetet", "grosswild"})
    SP_KLEINGETIER  ({"skill", "getoetet", "kleingetier"})

Wissen:
    SP_ERFORSCHT    ({"skill", "wissen", "erforscht"})
    SP_NAVIGATION   ({"skill", "wissen", "navigation"})
    
Handwerk:
    SP_STEHLEN      ({"skill", "handwerk", "stehlen"})

Magie:
    SP_DEFENSIV     ({"skill", "magie", "defensiv"})
    SP_ILLUSION     ({"skill", "magie", "illusion"})
    SP_INFORMATION  ({"skill", "magie", "information"})
    SP_MANIPULATION ({"skill", "magie", "manipulation"})
    SP_OFFENSIV     ({"skill", "magie", "offensiv"})
VERWEISE: set_skill_path, query_skill_path, EQUAL_SKILL_PATHS
GRUPPEN: skill
*/
#define SP_KURZSCHWERT  ({"skill", "offensiv", "scharf", "schwert", \
    "kurzschwert"})
#define SP_LANGSCHWERT  ({"skill", "offensiv", "scharf", "schwert", \
    "langschwert"})
#define SP_MESSER       ({"skill", "offensiv", "scharf", "messer"})
#define SP_SAEBEL       ({"skill", "offensiv", "scharf", "saebel"})
#define SP_DEGEN        ({"skill", "offensiv", "scharf", "degen"})
#define SP_AXT          ({"skill", "offensiv", "scharf", "axt"})
#define SP_SPEER        ({"skill", "offensiv", "scharf", "speer"})
#define SP_WURFMESSER   ({"skill", "offensiv", "scharf", "wurfmesser"})
#define SP_BOGEN        ({"skill", "offensiv", "scharf", "bogen"})
#define SP_BLASROHR     ({"skill", "offensiv", "scharf", "blasrohr"})
#define SP_SCHLEUDER    ({"skill", "offensiv", "stumpf", "schleuder"})
#define SP_KEULE        ({"skill", "offensiv", "stumpf", "keule"})
#define SP_PEITSCHE     ({"skill", "offensiv", "stumpf", "peitsche"})
#define SP_STOCK        ({"skill", "offensiv", "stumpf", "stock"})
#define SP_HAENDE       ({"skill", "offensiv", "haende"})
#define SP_KLEINSCHILD  ({"skill", "defensiv", "schild", "klein"})
#define SP_GROSSSCHILD  ({"skill", "defensiv", "schild", "gross"})
#define SP_LICHT        ({"skill", "zauber", "licht"})
#define SP_ABWEHR       ({"skill", "zauber", "abwehr"})
#define SP_SICHT        ({"skill", "zauber", "sicht"})
#define SP_NEHMEN       ({"skill", "zauber", "nehmen"})
#define SP_BEWERTEN     ({"skill", "zauber", "bewerte"})
#define SP_TARNEN       ({"skill", "zauber", "tarnen"})
#define SP_GROSSWILD    ({"skill", "getoetet", "grosswild"})
#define SP_KLEINGETIER  ({"skill", "getoetet", "kleingetier"})
#define SP_NAVIGATION   ({"skill", "wissen", "navigation"})
#define SP_ERFORSCHT    ({"skill", "wissen", "erforscht"})
#define SP_STEHLEN      ({"skill", "handwerk", "stehlen"})
#define SP_OFFENSIV     ({"skill", "magie", "offensiv"})
#define SP_DEFENSIV     ({"skill", "magie", "defensiv"})
#define SP_INFORMATION  ({"skill", "magie", "information"})
#define SP_MANIPULATION ({"skill", "magie", "manipulation"})
#define SP_ILLUSION     ({"skill", "magie", "illusion"})

// Defines fuer den Skill-Checker
#define SCT_RENAME	1	// Skillname umbenennen
#define SCT_CHANGE	2	// Wert aendern

#define SC_TYPE		0
#define SC_PATH		1
#define SC_ARGS		2
#define SC_TIME		3

#endif // SKILL_H
