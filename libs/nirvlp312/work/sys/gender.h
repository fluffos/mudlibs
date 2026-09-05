#ifndef _gender_h
#define _gender_h

#define GND_NEUTER 0
#define GND_MALE 1
#define GND_FEMALE 2
#define GND_PLURAL 3

#define GND_LIB "lib/gender"

#define OBJECTIVE_TO_PRONOUN(o) (GND_LIB->objective_to_pronoun(o))
#define OBJECTIVE_TO_POSSESSIVE(o) (GND_LIB->objective_to_possessive(o))
#define POSSESSIVE_TO_PRONOUN(o) (GND_LIB->possessive_to_pronoun(o))
#define POSSESSIVE_TO_OBJECTIVE(o) (GND_LIB->possessive_to_objective(o))
#define PRONOUN_TO_POSSESSIVE(o) (GND_LIB->pronoun_to_possessive(o))
#define PRONOUN_TO_OBJECTIVE(o) (GND_LIB->pronoun_to_objective(o))
#define GND_PRONOUN(o) (GND_LIB->get_pronoun(o))
#define GND_POSSESSIVE(o) (GND_LIB->get_possessive(o))
#define GND_OBJECTIVE(o) (GND_LIB->get_objective(o))

#define GND_DESCRIPTIONS ({ "neuter","male","female","plural" })
#define GND_PRONOUNS ({ "it","he","she","they" })
#define GND_POSSESSIVES ({ "its","his","her","their" })
#define GND_OBJECTIVES ({ "it","him","her","them" })

#endif
