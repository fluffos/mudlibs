// Petrarch
// Merentha Lib 1.0
// <drop>

#include <money.h>
#include <objects.h>

varargs int command(string str) {
object ob;
string type, junk;
int amt;
    if(!str) return notify_fail("Drop what?\n");
    if(sscanf(str, "%d %s coin%s", amt, type, junk)==3) {
      if(member_array(type, __CURRENCY_TYPES)==-1) return notify_fail("That is not a valid type of currency.\n");
      if(amt>this_player()->query_money(type)) return notify_fail("You do not have that much "+type+".");
      this_player()->add_money(type, -amt);
      ob=new(MONEY_OB);
      ob->add_money(type, amt);
      ob->move(environment(this_player()));
      message("command", "You drop some money.", this_player());
      message("command", this_player()->query_cap_name()+" drops some money.", environment(this_player()), this_player());
      return 1;
    }
    if(!ob=present(str, this_player())) return notify_fail("You do have that.\n");
    if(ob->move(environment(this_player()))) return 1;
    message("command", "You drop "+ob->query_short()+".", this_player());
    message("command", this_player()->query_cap_name()+" drops "+ob->query_short()+".", environment(this_player()), this_player());
    return 1;
}

string help() {
return "Syntax: drop <item>\n\nDrops the item in question into the room you are currently standing you.  You can reference items by number as well.  If you are carrying three swords and want to drop the second one type 'drop sword 3'.  If you wish to drop money the command is 'drop 5 gold coins' for example.";
}

