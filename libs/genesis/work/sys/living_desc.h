/*
 * /sys/living_desc.h
 *
 * Holds all textual descriptions used in /std/living
 *
 * Note that local changes to these are done in
 * /config/sys/living_desc2.h
 */

#ifndef LD_DEFINED
#define LD_DEFINED

#define LD_SAYS 		" says: "
#define LD_UNDERSTANDS(str)     (str)
#define LD_WIZARD 		"wizard"
#define LD_GHOST 		"ghost"
#define LD_SOMEONE		"someone"
#define LD_THE			"the"
#define LD_DARK_LONG		"A dark room.\n"
#define LD_CANT_SEE		"You are lost, you can't see a thing.\n"
#define LD_DARK_ROOM(o)		(o->query_prop(ROOM_I_INSIDE) ? \
    				"A dark room.\n" : "A dark area.\n")

#define LD_SPELL_FAIL 		"Your spell fails.\n"
#define LD_SPELL_CONC_BROKEN	"Your concentration is broken. No spell will be cast.\n"
  
/* Day / Night things */
#define LD_IS_NIGHT(o)		"It's Night.\n" + o->short() + ".\n"

/* combat */
#define LD_FIGHT1(c)		c + (c != "you" ? " is" : " are")
#define LD_FIGHT_MANY(cl)	implode(cl[0..sizeof(ctants)-2], ", ") + \
  				" and " + cl[sizeof(ctants)-1] + " are"

#define LD_FIGHT_DESC(tx, o)	capitalize(tx) + " fighting " +	\
				(o)->query_the_name(this_object()) + ".\n"

/* leftovers */
#define LD_BONES  ({ "skull", "thighbone", "kneecap", "rib", "jaw" })
#define LD_ORGANS ({ "heart", "kidney", "intestine", "ear", "eye", "nose" })

/* scars */
#define LD_SCARS(n)		((n) == 1 ? "a scar on" : "scars on")
#define LD_YOUR_SCARS(n, d)     "You have " + LD_SCARS(n) + " your " + (d)
#define LD_HAS_SCARS(n)		" has " + LD_SCARS(n)

#define SCAR_LEFT_LEG        1
#define SCAR_RIGHT_LEG       2
#define SCAR_NOSE            4
#define SCAR_LEFT_ARM        8
#define SCAR_RIGHT_ARM      16
#define SCAR_LEFT_HAND      32
#define SCAR_RIGHT_HAND     64
#define SCAR_FOREHEAD      128
#define SCAR_LEFT_CHEEK    256
#define SCAR_RIGHT_CHEEK   512

/* longdesc */
#define LD_PRESENT_YOU(o)	"You are " + 				\
  				LANG_ADDART(o->query_nonmet_name()) + 	\
                                ", presenting yourself as:\n" +		\
				o->query_presentation() + ".\n"

#define LD_PRESENT_TO(o)	o->query_name() + " is " + 		\
  				LANG_ADDART(o->query_nonmet_name()) + 	\
  				", presenting " + 			\
  				o->query_objective() + "self as:\n" +	\
				o->query_presentation() + ".\n"

#define LD_NONMET_GHOST(o)	"It is " + LANG_ADDART(o->query_nonmet_name()) + "\n"

#define LD_MET_GHOST(o)		"It is the " + o->query_name() + "\n"

/* drink_eat.c */
#define LD_NOTICE_HEADACHE	"You notice that you have a terrible headache.\n"

#define LD_SUDDEN_HEADACHE	"You suddenly get a headache, making you feel rather miserable.\n"

#define LD_GONE_HEADACHE	"Your headache seems to be gone.\n"

/* gender.c */
#define LD_GENDER_MAP		([ G_MALE : "male", G_FEMALE : "female",\
				   G_NEUTER : "neuter" ])
#define LD_GENDER_REVERSE_MAP	([ "male" : G_MALE, "female" : G_FEMALE,\
				   "neuter" : G_NEUTER ])

#define LD_PRONOUN_MAP		([ G_MALE:"he",G_FEMALE:"she",G_NEUTER:"it"])
#define LD_POSSESSIVE_MAP	([ G_MALE:"his",G_FEMALE:"her",G_NEUTER:"its"])
#define LD_OBJECTIVE_MAP	([ G_MALE:"him",G_FEMALE:"her",G_NEUTER:"it"])

/* heart_beat.c */
#ifdef STATUE_WHEN_LINKDEAD
#define LD_STATUE_TURN(o)	"Suddenly, " + QTNAME(o) + " " + STATUE_TURNS_INTO + ".\n"
#endif STATUE_WHEN_LINKDEAD
 
/* move.c */
#define LD_ALIVE_MSGIN		F_ALIVE_MSGIN
#define LD_ALIVE_MSGOUT		F_ALIVE_MSGOUT
#define LD_ALIVE_TELEIN		F_ALIVE_TELEIN
#define LD_ALIVE_TELEOUT	F_ALIVE_TELEOUT

/*
 * LD_ATTRIB_CATEGORIES  - an array of the player attribute categories.
 * LD_ATTRIBS_BY_CAT(c)  - an array of the attributes with in a category.
 * LD_IS_ATTRIBUTE(a)    - find out if an attribute is a valid attribute.
 * LS_ATTRIB_CATEGORY(a) - find out the category an attribute belongs to.
 */
#ifndef ADVERBS_FILE
#define ADVERBS_FILE "/sys/global/adverbs.lpc"
#endif

#define LD_ATTRIB_CATEGORIES  ((string *)ADVERBS_FILE->query_attribute_categories())
#define LD_ATTRIBS_BY_CAT(c)  ((string *)ADVERBS_FILE->query_attributes(c))
#define LD_IS_ATTRIBUTE(a)    ((int)ADVERBS_FILE->query_is_attribute(a))
#define LD_ATTRIB_CATEGORY(a) ((string)ADVERBS_FILE->query_attribute_category(a))

/* In login, filter for these prefixes and suffices to issue a warning. */
#ifndef LD_UNWANTED_PREFIX
#define LD_UNWANTED_PREFIX	({ "king*" })
#endif  LD_UNWANTED_PREFIX

/* No definitions beyond this line. */
#endif LD_DEFINED
