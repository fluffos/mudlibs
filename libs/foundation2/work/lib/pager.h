#ifndef l_pager_h
#define l_pager_h

class page_file {
    string Name;
    function Callback;
    mixed *Args;
    string MessageClass;
    string *Lines;
    int CurrentLine;
    mapping Marks;
    string LastSearch;
    int Size;
}

varargs mixed eventPage(mixed val, string msg_class, function f,mixed args...);
protected void Page(class page_file file);
protected void cmdPage(string str, class page_file file);
varargs private void RazzleDazzle(mixed args...);
private string GetPagerPrompt(class page_file file);
string GetHelp(string str);
/* pure virtual */ int *GetScreen();
/* pure virtual */ string *wild_card(string str);

#endif /* l_pager_h */
