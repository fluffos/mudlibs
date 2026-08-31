#ifndef __ATTRIBUTES_H__
#define __ATTRIBUTES_H__

void init_attributes();
int set_attribute(string key, int value);
varargs int get_attribute(string key, int raw);
int modify_attribute(string key, int value);
mapping get_attributes();

#endif // __ATTRIBUTES_H__
