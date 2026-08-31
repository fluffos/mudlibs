#include <std.h>
inherit ARMOUR;

int uses;
void create() {
::create();
    set_properties((["magic item" : "convert", "no steal" : 1]));
    set_id(({"ring", "worthmark"}));
    set_name("emerald ring");
    set_short("%^RESET%^GREEN%^Emerald %^BOLD%^WHITE%^Ring%^RESET%^");
    set_long("This ring is a circular band of silver with an emerald stone in the shape of a leaf set into the top of it. It is a wondrous thing and should never be given away.");
    set_mass(1);
    set_curr_value("gold", 0);
    set_ac(3);
    set_type("ring");
    set_limbs(({"right hand", "left hand"}));
    set_wear("The Emerald Ring slips gently over your finger.");
    uses = 10;
}

void init() {
   ::init();
     add_action("conversion", "convert");
}

int conversion(string str) {
    int amount;
    object tp;
    string oldp, newp;
    tp = this_player();
    if(!str || str == "")
      return notify_fail("You can <convert [amount] [hp/sp/mp] into [hp/sp/mp]>\n");
    if(uses < 1)
      return notify_fail("The ring has lost it's energy.\n");
    if(sscanf(str, "%d %s into %s", amount, oldp, newp) == 3) {
      if(amount < 1) return notify_fail("The conversion fails.\n");
      if(oldp == newp)
        return notify_fail("You cannot convert into the same type.\n");
      if(call_other(tp, "query_current_"+oldp) <= amount)
        return notify_fail("Not enough "+oldp+" to convert!\n");
        call_other(tp, "add_"+newp, (amount*2/3));
        call_other(tp, "add_"+oldp, (-amount));
        message("info", "You exchange "+amount+" "+oldp+" for "+(amount*2/3)+" "+newp+".", tp, );
      }
    else
      return notify_fail("You can <convert [amount] [hp/sp/mp] into [hp/sp/mp]>\n");
     uses -= 1;
     return 1;
}


int query_auto_load() { return 1; }

int drop() { write("If you don't want it, bury it. I wouldn't though."); return 1; }

int get() { return 1; }

int give() { write("Give this away? Are you insane?"); return 1; }
