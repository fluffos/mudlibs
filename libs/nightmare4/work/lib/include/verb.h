#ifndef l_verb_h
#define l_verb_h

protected void create();

varargs protected string *SetRules(mixed *args...);
string *GetRules();
varargs protected string *SetSynonyms(mixed *args...);
string *GetSynonyms();
protected string SetVerb(string str);
string GetVerb();

#endif /* l_verb_h */
