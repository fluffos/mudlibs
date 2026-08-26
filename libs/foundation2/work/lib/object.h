#ifndef __LIB_ITEM_H__
#define __LIB_ITEM_H__

nosave void create();
nosave void init();
void reset();
int id(string str);
string *parse_command_id_list();
string *parse_command_plural_id_list();
string *parse_command_adjectiv_id_list();

int cmdRead(string str);

nosave int Destruct();

void SetId(mixed val);
string *GetId();
void SetAdjectives(mixed adjs);
string *GetAdjectives();
string SetKeyName(string nom);
string GetKeyName();
string SetCapName(string str);
string GetCapName();
string GetName();
mixed SetShort(mixed val);
string GetShort();
mixed SetLong(mixed val);
varargs string GetLong(string str);
varargs mixed SetRead(string str, string unused);
varargs mixed GetRead(string str);
mapping SetProperties(mapping props);
mapping GetProperties();
mixed SetProperty(string prop, mixed val);
mixed GetProperty(string prop);
mixed AddProperty(string prop, mixed val);
int RemoveProperty(string prop);

#endif /* __LIB_ITEM_H__ */
