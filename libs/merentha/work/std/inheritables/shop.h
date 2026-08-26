// Petrarch
// Merentha Lib 1.0
// shop.h

#ifndef __SHOP_H__
#define __SHOP_H__

void set_supply_room(string str);
void set_currency(string str);

varargs int cmd_list(string str);
int cmd_show(string str);
int cmd_buy(string str);
int cmd_sell(string str);
int cmd_value(string str);

#endif
