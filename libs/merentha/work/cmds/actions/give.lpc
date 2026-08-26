// Petrarch
// Merentha Lib 1.0
// <give>

#include <money.h>
#include <objects.h>
 
varargs int command(string str) {
object ob, pl;
string item, player, type, junk;
int amt;
    if(!str) return notify_fail("Drop what?\n");
    if(sscanf(str, "%s to %s", item, player)!=2) return notify_fail("Syntax: give <item> to <player>\n");
    if(sscanf(item, "%d %s coin%s", amt, type, junk)==3) {
      if(member_array(type, __CURRENCY_TYPES)==-1) return notify_fail("That is not a valid type of currency.\n");
      if(!pl=present(player_name(player), environment(this_player()))) return notify_fail("They are not here.\n");
      if(amt>this_player()->query_money(type)) return notify_fail("You do not have that much "+type+".");
      this_player()->add_money(type, -amt);
      pl->add_money(type, amt);
      message("command", "You give "+amt+" "+type+" coins to "+pl->query_cap_name()+".", this_player());
      message("command", this_player()->query_cap_name()+" gives you "+amt+" "+type+" coins.", pl);
      message("command", this_player()->query_cap_name()+" gives some money to "+pl->query_cap_name()+".", environment(this_player()), ({this_player(),pl}));
      return 1;
    }
    if(!ob=present(item, this_player())) return notify_fail("You do have that.\n");
    if(!pl=present(player_name(player), environment(this_player()))) return notify_fail("They are not here.\n");
    if(ob->move(pl)) return 1;
    message("command", "You give "+ob->query_short()+" to "+pl->query_cap_name()+".", this_player());
    message("command", this_player()->query_cap_name()+" gives "+ob->query_short()+" to "+pl->query_cap_name()+".", environment(this_player()), ({this_player(),pl}));
    message("command", this_player()->query_cap_name()+" gives you "+ob->query_short()+".", pl);
    return 1;
}

string help() {
return "Syntax: give <item> to <living>\n\nThis command will move an item from your inventory to another player or a monster.  To transfer money the syntax is 'give 5 gold coins to petrarch' for example.";
}
