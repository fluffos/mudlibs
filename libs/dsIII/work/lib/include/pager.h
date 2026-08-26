#ifndef l_pager_h
#define l_pager_h

varargs mixed eventPage(mixed val, string msg_class, function f,mixed args...);
nosave void Page(mapping file);
nosave void cmdPage(string str, mapping file);
varargs nosave private void RazzleDazzle(mixed args...);
nosave private string GetPagerPrompt(mapping file);
string GetHelp(string str);
/* pure virtual */ varargs int eventPrint(string msg, mixed arg2, mixed arg3);
/* pure virtual */ int *GetScreen();
#if 0
/* pure virtual */ string *wild_card(string str);
#endif

#endif /* l_pager_h */
