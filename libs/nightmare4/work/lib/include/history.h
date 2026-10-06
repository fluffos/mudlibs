#ifndef l_history_h
#define l_history_h

protected string eventHistory(string str);
nomask private string Push(string cmd);
private string GetHistory(mixed val);

/* pure abstract */ varargs int eventPrint(string msg, int cl);
/* pure abstract */ string GetKeyName();

#endif /* l_history_h */
