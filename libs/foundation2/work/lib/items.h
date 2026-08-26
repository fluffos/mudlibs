#ifndef __ITEMS_H__
#define __ITEMS_H__

nosave void create();
int id(string str);

string *GetId();
mapping SetItems(mapping items);
mixed AddItem(string item, mixed val);
mapping RemoveItem(string item);
mixed GetItemDescription(string item);
varargs string GetLong(string item);

#endif /* __ITEMS_H__ */
