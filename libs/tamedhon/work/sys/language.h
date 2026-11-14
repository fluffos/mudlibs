// SilberLand MUDlib
//
// sys/thing/language.h -- language handling header
//
// $Date: 1997/03/31 15:54:44 $
/* $Revision: 2.0 $
* $Log: language.h,v $
* Revision 2.0  1997/03/31 15:54:44  Woody
* prepared for revision control
*
* Revision 1.6  1994/09/22  09:43:24  Hate
* Added Prototypes for functionality
*
* Revision 1.3  1994/04/07  10:43:21  Rumata
* RAW added
*/

#ifndef __THING_LANGUAGE_H__
#define __THING_LANGUAGE_H__

// properties
#define P_ARTICLE     "article"
#define P_GENDER      "gender"

// special defines

#define WER 	0
#define WESSEN 	1
#define WEM 	2
#define WEN 	3
#define RAW     99   // name without article

#define NEUTER 		0
#define MALE 		1
#define FEMALE 		2

#define SINGULAR 	0
#define PLURAL 		1

#endif // __THING_LANGUAGE_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_LANGUAGE_H_PROTO__
#define __THING_LANGUAGE_H_PROTO__

// prototypes

// Artikel im passenden Fall sowie demonst. bzw undemonst. zurueck-
// geben. force ueberschreibt das SetArticle-Flag.
varargs string QueryArticle(int casus, int dem, int force);

// Empfehle einen Artikel fuer das Objekt, getestet wird, ob ausser
// diesem Objekt sich ein anderes Objekt mit der id im selben
// Raum befindet.
varargs int SuggestArticle(string id);

// Gib ein Pronomen zurueck, welches ausdrueckt, das ein Objekt diesem
// Objekt gehoert. Dabei ist what das Geschlecht des Objektes.
varargs string QueryPossPronoun(mixed what, int casus, int number);

// Er/Sie/Es u.ae. zurueckgeben.
string QueryPronoun(int casus);

// Du im passenden Fall zurueckgeben.
varargs string QueryDu(int casus,int gender, int zahl);

// Geschlecht in Worten zurueckgeben (maennlich, weiblich, saechlich)
string QueryGenderString();

// Deklination eines Adjektivs
varargs string DeclAdj(string adj, int casus, int demon);

#endif // __THING_LANGUAGE_H_PROTO__

#endif // NEED_PROTOYPES
 