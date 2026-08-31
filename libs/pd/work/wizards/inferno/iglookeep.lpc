#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("iglookeep");
   set_short("%^BOLD%^%^CYAN%^a%^WHITE%^n%^CYAN%^ i%^WHITE%^c%^CYAN%^e "
    "%^WHITE%^t%^CYAN%^a%^WHITE%^l%^CYAN%^i%^WHITE%^s%^CYAN%^m%^WHITE%^a"
    "%^CYAN%^n%^RESET%^");
   set_long("A talisman of blue-tinted silver with twirls of ice "
     "magically embeded into it. Leviathas: <restore igloo>");
   set_id(({"talisman", "ice talisman"}));
   set_value(0);
}

int query_auto_load() { if (this_player()->query_name() == "leviathas") return 1; }

int restore(string str) {
   if (!str || str != "igloo") return 0;
   if (file_name(environment(this_player())) != "/d/standard/square")
    return notify_fail("You must be in Sindarii square.\n");
   if (this_player()->query_name() != "leviathas" && !wizardp(this_player()))
    return 0;
   if (!present("igloo", environment(this_player())))
     new("/wizards/inferno/igloo")->move(environment(this_player()));
   write("%^CYAN%^Igloo restored.");
   return 1;
}

void init() {
 ::init();
   add_action("restore", "restore");
}
