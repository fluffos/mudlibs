///////////////////////////////////////////////////
// Lib:  Headerfile fuer Oekosystem
// Silberlandmudlib
// Autoren: Angel@SL / Khory@GL
// File:  <path>+oekosystem.h
// Datum: 31.07.2002
///////////////////////////////////////////////////

#include <wizlevels.h>
#include <language.h>
#include <properties.h>

#ifndef __OEKOSYSTEM_H__
#define __OEKOSYSTEM_H__

// Properties
#define P_UNIDENTIFIED_NAME     "unidentified_name"     // string: name returned if the object isn't known
#define P_UNIDENTIFIED_PLURAL   "unidentified_plural"   // string: plural returned if object isn't known
#define P_UNIDENTIFIED_LONG     "unidentified_long"     // string: long returned if the object isn't known
#define P_UNIDENTIFIED_SHORT    "unidentified_short"    // string: short returned if the object isn't known
#define P_UNIDENTIFIED_NAME_ADJ "unidentified_name_adj" // array: adjectives of the unid. object
#define P_UNIDENTIFIED_GENDER   "unidentified_gender"   // integer: gender of the unknown object
#define P_UNIDENTIFIED_ARTICLE  "unidentified_article"  // integer: does the unknown object have an article?
#define P_ID_SKILL              "id_skill"              // string: skill used to identify the object
#define P_LORE_DIFFICULTY       "lore_difficulty"       // integer: Difficulty for the ID skill
#define P_HIDDEN		"hidden"                // integer: Difficulty to see a thing

string custom_query_pronoun(int casus, int numerus, int gender)
{
  if (numerus)
  {
    if (casus==WEM) return "ihnen";
    else return "sie";
  }

  switch(casus)
  {
    case WER:
    switch(gender)
    {
      case MALE  : return "er";
      case FEMALE: return "sie";
      case NEUTER: return "es";
    }
    break;
    case WEM: if(gender == FEMALE) return "ihr"; else return "ihm";
  }
  switch(gender)
  {
    case MALE: return "ihn";
    case FEMALE: return "sie";
  }
  return "es";
}

#endif // #ifndef __OEKOSYSTEM_H__