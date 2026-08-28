#ifndef __HELP_H
#define __HELP_H

varargs void help(string topic, string category, int menu);
nosave void help_menu(string category, string *topics, int ind);
nosave string *query_categories();
nosave string *query_topics(string category);
nosave void cmd_help(string topic, string category, int menu);
nosave int find_help(string topic, string category, int menu);
nosave void menu_return(string duh, string category);
void endmore(string category);

#endif /* __HELP_H */
