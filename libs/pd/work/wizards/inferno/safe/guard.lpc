#include <std.h>
#define DIR "/wizards/inferno/safe/arm/"
inherit MONSTER;

int save_me();

mapping accounts;

string *query_list(string str) {
   return accounts[str];
}

void open_account(string who) { accounts[who] = ({ }); }

int has_account(string str) {
   string *all;
   int i, trig;
   trig = 0;
   all = keys(accounts);
   i = sizeof(all);
   while (i--) {
     if (all[i] == str) trig = 1;
   }
   return trig;
}

void add_item(string name, string fn) {
   accounts[name] += ({ fn });
}

void create() {
 ::create();
   set_name("guard");
   set_short("a Sacron guard");
   set_long("This guard is dressed in a white shirt and blue pants. "
	"All entries must go past him. He is very big and very, "
	"very strong, so dont mess with him.");
   set_level(200);
   set_race("sacron");
   set_gender("male");
   set_body_type("sacron");
   set_id(({ "sacron", "guard", "sacron guard", "big" }));
   new(DIR"2hsword")->move(this_object());
   new(DIR"2hproj")->move(this_object());
   new(DIR"1hflail")->move(this_object());
   new(DIR"1hknife")->move(this_object());
   new(DIR"pants")->move(this_object());
   new(DIR"shirt")->move(this_object());
   restore_object("/wizards/inferno/safe/guard");
   command("wear pants");
   command("wear shirt");
   command("wield sword");
   command("wield whip");
   command("wield spear");
   command("wield knife");
}

void restore() { restore_object("/wizards/inferno/safe/guard"); }

void save_now() { save_object("/wizards/inferno/safe/guard"); }

int save_me(string name, object *all) {
   int i;
   string *strs;
   i = sizeof(all);
   strs = ({ });
  if (i >= 1) {
   while (i--) {
     strs += ({ base_name(all[i]) });
   }
  }
   accounts[name] = strs;
   save_object("/wizards/inferno/safe/guard");
   return 1;
}
