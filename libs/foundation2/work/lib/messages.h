#ifndef __MESSAGES_H__
#define __MESSAGES_H__

nosave void create();

string SetMessage(string msg, string str);
varargs string GetMessage(string msg, mixed arg);
mapping GetMessages();
string GetName();

#endif /* __MESSAGES_H__ */
