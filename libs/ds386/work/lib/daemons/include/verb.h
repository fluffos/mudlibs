#ifndef l_verb_h
#define l_verb_h

nosave void create();

varargs nosave string *SetRules(mixed *args...);
string *GetRules();
varargs nosave string *SetSynonyms(mixed *args...);
string *GetSynonyms();
nosave string SetVerb(string str);
string GetVerb();

#endif /* l_verb_h */
