//Last modified by waiwai@2001/05/04

#ifndef __SKILL__
#define __SKILL__

string query_skill_mapped(string skill);
varargs void map_skill(string skill, string mapped_to);
varargs int query_skill(string skill, int raw);
varargs void improve_skill(string skill, int amount, int weak_mode);
//By waiwai@2001/07/06 增加定义
mapping query_skills();
mapping query_skill_prepare();
mapping query_wprepare();

#endif
