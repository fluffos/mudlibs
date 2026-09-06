#include <const/talkconst.h>

/** This file will handle some simple verb conjugation in English. It
 * is used by the simul_efun function process_string to do verb
 * conjugation, so you probably will not need to do anything here
 * directly. The reason it is in a separate file is so that you can
 * expand the verb capabilities without major difficulty. The verb
 * codes you should use are:
 *
 * ~Verb (present simple, upper case)
 * ~verb (present simple, lower case)
 * ~Vert (present simple, upper case, for target)
 * ~vert (present simple, lower case, for target)
 *
 * Example: ~Name ~verbpick up the rock.
 *
 * This phrase can be processed to both "You pick up the rock."
 * and "Bob picks up the rock." There are some other useful codes
 * you can use in these phrases. They are:
 *
 * - ~Targ -- The name of the target. If the target is the listener,
 * - then ~Targ will process to 'You' instead.
 * - ~Pron -- A pronoun for the subject of the sentence. Converts to 'you' if
 *   the subject is the listener, and he/she/it if not.
 * - ~Prot -- Same as ~Pron but for the target, not the subject.
 * - ~Poss -- Possessive for the subject, or 'your'.
 * - ~Post -- Same as ~Poss but for the target.
 *
 * All these have a lower case form.
 *
 * This will only handle a few irregulars. If you find an irregular verb
 * which is not handled properly, go ahead and add it in here.
 */

/** Conjugates an English verb in the present tense. This should
 * work for all English verbs; failing on any verb is considered a
 * bug and ought to be fixed.
 *
 * \param verb The verb to be conjugated
 * \param form 0 to conjugate in 3rd person (he, she, it verbs),
 * and 1 to conjugate in second person (you).
 *
 * There could be other useful forms, but given how simple present
 * tense English is, the second person should actually work for
 * basically all of them. If not, time to fix things...
 */
string conjugate_verb(string verb, int form) {
  if(!verb || verb == "") return "<null>";

  // Form 0 = 3rd person (he, she, it)
  if(!form) {
     if(verb == "is") return "is";
     if(verb == "has" || verb == "have") return "has";
     if(verb == "go") return "goes";
     if(verb == "do") return "does";
     if(verb == "don't") return "doesn't";
     if(verb == "can") return "can";
     if(verb[<2..<1] == "gh") return verb + "s";
     if(verb[<2..<1] == "ay") return verb + "s";
     if(verb[<2..<1] == "th") return verb + "s";
     if(verb[<1] == 'h') return verb + "es";
     if(verb[<1] == 'x') return verb + "es";
     if(verb[<1] == 's') return verb + "es";
     if(verb[<1] == 'y') return verb[0..<2] + "ies";
     return verb + "s";
  }
  // Form 1 = 2nd person (you)
  else {
    if(verb == "is") return "are";
    if(verb == "has") return "have";
    return verb;
  }
}

/** Queries the gender of \a ob, and returns an appropriate pronoun: you, it, he, or she.
 *
 * \param ob The object for which you need a pronoun. Uses Living::query_gender() (and assumes
 * neuter if query_gender() fails).
 * \param form If true, then returns "you" instead.
 */
string pronoun_for(object ob, int form) {
   int i;

   if(form) return "you";

   i = ob->query_gender();
   if(i == 0) return "it";
   if(i == 1) return "he";
   if(i == 2) return "she";
}

/** Queries the gender of \a ob, and returns an appropriate possessive pronoun: your, its, her, or his.
 *
 * \param ob The object for which you need a possessive pronoun. Uses Living::query_gender() (and assumes
 * neuter if query_gender() fails).
 * \param form If true, then returns "your" instead.
 */
string possessive_for(object ob, int form) {
   int i;

   if(form) return "your";

   i = ob->query_gender();
   if(i == 0) return "its";
   if(i == 1) return "his";
   if(i == 2) return "her";
}

/** Queries the gender of \a ob, and returns an appropriate reflexive pronoun: yourself, itself, herself, or himself.
 *
 * \param ob The object for which you need a reflexive pronoun. Uses Living::query_gender() (and assumes
 * neuter if query_gender() fails).
 * \param form If true, then returns "yourself" instead.
 */
string reflexive_for(object ob, int form) {
   int i;

   if(form) return "yourself";

   i = ob->query_gender();
   if(i == 0) return "itself";
   if(i == 1) return "himself";
   if(i == 2) return "herself";
}

/** Queries the gender of \a ob, and returns an appropriate object pronoun: you, it, her, or him.
 *
 * \param ob The object for which you need an object pronoun. Uses Living::query_gender() (and assumes
 * neuter if query_gender() fails).
 * \param form If true, then returns "you" instead.
 */
string object_pronoun_for(object ob, int form) {
   int i;

   if(form) return "you";

   i = ob->query_gender();
   if(i == 0) return "it";
   if(i == 1) return "him";
   if(i == 2) return "her";
}

/// A small vocabulary for use by talking NPC's.
mapping noun_list, verb_list, adjective_list, preposition_list, exclamation_list;

/// Initialize the vocabulary lists. This object is never cloned, so I keep them here.
create() {
   noun_list =
// Times of day.
([ "day"      :OTIME,
   "night"    :OTIME,
   "morning"  :OTIME,
   "afternoon":OTIME,
   "evening"  :OTIME,
   "time"     :OTIME,
// Pronouns
   "i"        :NFIRSTP | NSUBJECT,
   "we"       :NFIRSTP | NPLURAL | NSUBJECT,
   "you"      :NSECONDP | NSUBJECT | NOBJECT,
   "he"       :NTHIRDP | NSUBJECT,
   "her"      :NTHIRDP | NOBJECT,
   "she"      :NTHIRDP | NSUBJECT,
   "it"       :NTHIRDP | NSUBJECT | NOBJECT,
   "they"     :NTHIRDP | NPLURAL | NSUBJECT,
   "them"     :NTHIRDP | NPLURAL | NOBJECT,
   "me"       :NFIRSTP | NOBJECT,
// Attributes
   "name"     :NATTRIB,
// Question words
   "what"     :NQUEST,
   "who"      :NQUEST,
   "how"      :NQUEST,
   "why"      :NQUEST,
   "where"    :NQUEST,
   "which"    :NQUEST
]); // End of noun list.
   verb_list =
([ "am"       :VBE,
   "are"      :VBE,
   "is"       :VBE,
   "have"     :VHAVE,
   "got"      :VHAVE,
   "go"       :VGO,
   "use"      :VUSE,
   "do"       :VACT,
   "want"     :VWANT,
   "like"     :VWANT,
   "wish"     :VWANT,
   "desire"   :VWANT,
   "need"     :VWANT,
   "buy"      :VBUY,
   "purchase" :VBUY,
   "give"     :VGIVE
]); // End of verb list.
   adjective_list =
([ "my"       :NFIRSTP | NPOSSESS,
   "our"      :NFIRSTP | NPOSSESS | NPLURAL,
   "your"     :NSECONDP | NPOSSESS,
   "his"      :NTHIRDP | NPOSSESS,
   "her"      :NTHIRDP | NPOSSESS,
   "its"      :NTHIRDP | NPOSSESS,
   "their"    :NTHIRDP | NPOSSESS | NPLURAL,
]);
   exclamation_list =
([ "yes"      :EYES,
   "yup"      :EYES,
   "yeah"     :EYES,
   "nod"      :EYES,
   "nog"      :EYES,
   "ok"       :EYES,
   "okay"     :EYES,
   "okey"     :EYES,
   "sure"     :EYES,
   "no"       :ENO,
   "nope"     :ENO
]); // End of exclamation list.
}

/// Fetch the noun list
mapping query_noun_list() {
   return noun_list;
}

/// Fetch the verb list
mapping query_verb_list() {
   return verb_list;
}

/// Fetch the adjective list
mapping query_adjective_list() {
   return adjective_list;
}

/// Fetch the exclamation list
mapping query_exclamation_list() {
   return exclamation_list;
}
