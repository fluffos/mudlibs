/*
   sys/living_desc.h

   Holds all textual descriptions used in /std/living
   
   Note that local changes to these are done in
   /config/sys/living_desc2.h
*/

#ifndef LD_DEFINED
#include "/config/sys/living_desc2.h"
#endif

#ifndef LD_DEFINED
#define LD_DEFINED

#define LD_SAYS 		" mowi: "
#define LD_UNDERSTANDS(str)     (str)
#define LD_WIZARD 		"czarodziej"
#define LD_CZARODZIEJ           ({ "czarodziej", "czarodzieja", \
				   "czarodziejowi", "czarodzieja", \
				   "czarodziejem", "czarodzieju" })
#define LD_GHOST 		"duch"
#define LD_DUCH                 ({ "duch", "ducha", "duchowi", "ducha",	\
				   "duchem", "duchu" })
#define LD_DUCHY		({ "duchy", "duchow", "duchom", 	\
				   "duchy", "duchami", "duchach" })
#define LD_SOMEONE		"ktos"
#define LD_KTOS			({ "ktos", "kogos", "komus", "kogos",\
		 		   "kims", "kims" })
#define LD_THE			"the"
#define LD_DARK_LONG		"Ciemne miejsce.\n"
#define LD_CANT_SEE		"You are lost, you can't see a thing.\n"

#define LD_APPRAISE(w, v)	"You appraise that the weight is " + 	\
  				w + " and you guess " + \
				this_object()->query_possessive() + \
				" volume is about " \
  				+ v + ".\n"

#define LD_SPELL_FAIL 		"Your spell fails.\n"
#define LD_SPELL_CONC_BROKEN	"Your concentration is broken. " + 	\
  				"No spell will be cast.\n"
  
/* Day / Night things
*/
#define LD_IS_NIGHT(o)		"Jest noc.\n" + o->short() + ".\n"

/* combat
*/
#define LD_FIGHT1(c)		c + (c != "you" ? " is" : " are")
#define LD_FIGHT_MANY(cl)	implode(cl[0..sizeof(ctants)-2], ", ") + \
  				" and " + cl[sizeof(ctants)-1] + " are"

#define LD_FIGHT_DESC(tx, o)	capitalize(tx) + " fighting " +		\
		  		o->query_the_name(this_object()) + ".\n"

/* scars
 */
#define LD_SCARS(n)		(n == 1 ? "a scar on" : "scars on")
#define LD_YOUR_SCARS(n, d)     "You have " + LD_SCARS(n) + " your " + d
#define LD_HAS_SCARS(n)		" has " + LD_SCARS(n)

/* drink_eat.c
*/
#define LD_NOTICE_HEADACHE	"Zauwazasz, ze raczej boli cie glowa.\n"

#define LD_SUDDEN_HEADACHE	"Powoli zaczyna cie bolec glowa. " + \
				"Czujesz sie raczej niewyraznie.\n"

#define LD_GONE_HEADACHE	"Bol glowy przechodzi.\n"

/* gender.c
*/
#define LD_GENDER_MAP		([ G_MALE : "male", G_FEMALE : "female",\
				   G_NEUTER : "neuter"])
				   
#define LD_HUM_GENDER_MAP 	([ G_MALE : ({ "mezczyzna", "mezczyzny",\
				"mezczyznie", "mezczyzne", "mezczyzna",\
				"mezczyznie" }), G_FEMALE : ({\
				"kobieta", "kobiety", "kobiecie", "kobiete",\
				"kobieta", "kobiecie" }), G_NEUTER : ({\
				"obojniak", "obojniaka", "obojniakowi",\
				"obojniaka", "obojniakiem", "obojniaku" }) ])
				
#define LD_HUM_PGENDER_MAP      ([ G_MALE : ({ "mezczyzni", "mezczyzn",\
				"mezczyznom", "mezczyzn", "mezczyznami",\
				"mezczyznach" }), G_FEMALE : ({\
				"kobiety", "kobiet", "kobietom", "kobiety",\
				"kobietami", "kobietach" }), G_NEUTER : ({\
				"obojniacy", "obojniakow", "obojniakom",\
				"obojniakow", "obojniakami", "obojniakach" }) \
				])
				
#define LD_PRONOUN_MAP		([ G_MALE:"he",G_FEMALE:"she",G_NEUTER:"it"])
#define LD_POSSESSIVE_MAP	([ G_MALE:"his",G_FEMALE:"her",G_NEUTER:"its"])
#define LD_OBJECTIVE_MAP	([ G_MALE:"him",G_FEMALE:"her",G_NEUTER:"it"])

/* heart_beat.c
*/
#ifdef STATUE_WHEN_LINKDEAD
#define LD_STATUE_TURN(o)	"Suddenly, " + QTNAME(o) + " " +	\
			        STATUE_TURNS_INTO + ".\n"
#endif
 
/* move.c
*/
#define LD_ALIVE_MSGIN		F_ALIVE_MSGIN
#define LD_ALIVE_MSGOUT		F_ALIVE_MSGOUT
#define LD_ALIVE_TELEIN		F_ALIVE_TELEIN
#define LD_ALIVE_TELEOUT	F_ALIVE_TELEOUT

/* savevars.c
*/
#define LD_MADWAND_TITLE(t, d)	"the Madwand of " + d + 		\
  				(strlen(t) ? (" " + t) : "")


#endif
