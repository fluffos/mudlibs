#ifndef __HELP_H
#define __HELP_H

varargs void help(string topic, string category, int menu);
protected void help_menu(string category, string *topics, int ind);
protected string *query_categories();
protected string *query_topics(string category);
protected void cmd_help(string topic, string category, int menu);
protected int find_help(string topic, string category, int menu);
protected void menu_return(string duh, string category);
void endmore(string category);

#endif /* __HELP_H */
