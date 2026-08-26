// Petrarch 
// Merentha Lib 1.0
// bar.h

#ifndef __BAR_H__
#define __BAR_H__

void set_currency(string str);
void set_menu(mapping menu);
mapping query_menu();

int buy_item(string type, string *item);
int cmd_buy(string str);
int cmd_read(string str);

#endif
