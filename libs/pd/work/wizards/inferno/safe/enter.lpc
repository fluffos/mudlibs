#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Entrance to a large, high-security vault");
   set_long("This one-room high-security chamber looks a lot like "
	"a bank, except that there are no tellers, and probably no "
	"money in the vaults. The room is lavishly decorated. "
	"A sign has been tacked to a wall near the vault.");
   set_items(([
	"sign" : "You should read it for valuable information.",
	"vault" : "Very highly secured."
   ]));
   set_properties(([ "no attack" : 1, "no magic" : 1, "no bump" : 1,
	"no teleport" : 1 ]));
   set_exits(([
	"vault" : "/wizards/inferno/safe/enter"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard"))
     new("/wizards/inferno/safe/guard")->move(this_object());
}

int go_vault() {
   object ob, tr, gr;
   string str;
   ob = this_player();
   if (!present("guard")) {
     write("The guard is not here to let you in.");
     return 1;
   }
   if (!(present("guard")->has_account(ob->query_name(str)))) {
     write("The guard shakes his head.\nYou do not have an "
	"account here.");
     return 1;
   }
   gr = present("guard", this_object());
   tr = new("/wizards/inferno/safe/blank");
   tr->set_guard(gr);
   tr->set_user(ob);
   tr->stock_vault();
   ob->move_player(tr, "vault");
   return 1;
}

int deposit(string str) {
   object ob, new;
   string tf;
   if (!str) return 0;
   if (!present("guard")) return notify_fail("The guard is not here, "
	"so you cannot make deposits.\n");
   if (!present("guard")->has_account(this_player()->query_name()))
	return notify_fail("You do not have an account here.\n");
   if (!(ob = present(str, this_player()))) return notify_fail(
	"You do not have that.\n");
   tf = base_name(ob);
   if (tf == "" || !tf) return notify_fail("You cannot store that.\n");
//   if (this_player()->query_money("gold") < 1000) return notify_fail(
//	"You do not have the gold to do that!\n");
   new = new(tf);
   if (tf->query_weight() != new->query_weight()) return notify_fail(
	"You cannot deposit that. If you feel that there has been an "
	"error, please mudmail Inferno about it.\n");
   if (tf->query_true_name() != new->query_true_name()) return
	notify_fail("You cannot deposit that. If you feel that there "
	"has been an error, please mudmail Inferno about it.\n");
   present("guard")->add_item(this_player()->query_name(), tf);
//   this_player()->add_money("gold", -1000);
   write("You hand "+new->query_name()+" to the guard and have it "
	"stored in the vault.");
   message("info", this_player()->query_cap_name()+" hands "+
	new->query_name()+" to the guard ans has it stored in the "
	"vault.", environment(this_player()), ({ this_player() }));
   ob->remove();
   new->remove();
   return 1;
}

int open_ac(string str) {
   if (!str || str != "account") return 0;
   if (!present("guard")) return notify_fail("You cannot open an "
	"account when the guard is not present.\n");
   if (present("guard")->has_account(this_player()->query_name()))
	return notify_fail("You already have an account here.\n");
   if (this_player()->query_money("gold") < 50000) return notify_fail(
	"You do not have the gold needed to open an account here.\n");
   this_player()->add_money("gold", -50000);
   write("You have a vault opened in your name.");
   message("info", this_player()->query_cap_name()+" has a vault "
	"opened in "+this_player()->query_posessive()+" name.",
	environment(this_player()), ({ this_player() }));
   present("guard")->open_account(this_player()->query_name());
   return 1;
}

int read_sn(string str) {
   if (!str || str != "sign") return 0;
   message("info", this_player()->query_cap_name()+" reads a sign.",
	environment(this_player()), ({ this_player() }));
   write("(*) You may %^BOLD%^%^CYAN%^<open account>%^RESET%^ to open "
	"a vault in your name, this has a one-time fee of 50,000 gold "
	"coins. (*) To put something in your vault, "
	"%^BOLD%^%^CYAN%^<deposit [item]>%^RESET%^ "
	"at the room with the guard. This will cost 1,000 gold coins "
	"per deposit. (*) You may enter your vault at any time and "
	"take any items you see fit. There will be no charge for this "
	"transaction.");
   return 1;
}

void init() {
 ::init();
   add_action("read_sn", "read");
   add_action("go_vault", "vault");
   add_action("open_ac", "open");
   add_action("deposit", "deposit");
}
