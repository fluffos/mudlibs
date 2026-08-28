#ifndef l_classes_h
#define l_classes_h

nosave void create();

int eventMoralAct(int degree);

int AddSkillPoints(string skill, int x);
string RemoveClass();
nosave string SetSkillModifier(string skill, string stat);
string GetSkillModifier(string skill);
string SetClass(string classes);
string GetClass();
string SetGuild(string guild);
string GetGuild();
int GetBaseStatLevel(string stat);
int SetMorality(int x);
int GetMorality();
string GetMoralityDescription();
varargs string *SetReligion(string *str);
varargs string GetReligion(int flag);
string *GetTitles();
string *RemoveTitle(string);
mapping GetSpellBook();
mapping eventForgetSpell(string);
int GetDevelopmentPoints();
int AddDevelopmentPoints(int);
int GetStatLevel(string);

#endif /* l_classes_h */
