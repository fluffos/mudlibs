/*
 * /basic/plural.c
 *
 * A short version of basic/gender
 * This version only implements the functions for neuter and plural
 */

#include <gender.h>

private int gender; 

varargs int query_gender(string str) { 
  return gender; 
}

varargs int query_neuter(string str) { 
  return query_gender(str) == GND_NEUTER; 
}

varargs int query_plural(string str) { 
  return query_gender(str) == GND_PLURAL; 
}

varargs void set_gender(int g,string str) {
  if (g>=GND_NEUTER && g<=GND_PLURAL)
    gender = g;
}

varargs void set_neuter(string str) { 
  set_gender(GND_NEUTER,str);
}

varargs void set_plural(string str) {
  set_gender(GND_PLURAL,str);
}

varargs string query_gender_string(string str) {
  return GND_DESCRIPTIONS[query_gender(str)];
}

varargs string query_pronoun(string str) {
  return GND_PRONOUNS[query_gender(str)];
}

varargs string query_possessive(string str) {
  return GND_POSSESSIVES[query_gender(str)];
}

varargs string query_objective(string str) {
  return GND_OBJECTIVES[query_gender(str)];
}

