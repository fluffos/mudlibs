// skeleton for the raise spell
// a dungeonware.net production
#include <std.h>
#include <daemons.h>
inherit UNDEAD;
 static string owner;
 static object ob, pl;
void create() {
  ::create();
   ob = this_object();
   set_name("skeleton");
   set_id( ({ "skeleton undead", "skeleton", "undead" }) );
   set_gender("male");
   set_short("a skeleton");
   set("aggressive", 0);
   set_heart_beat(1);
   set_level(9);
   set_long("The skeletal remains of some creature, the bones seems to be held "
            "together by magic. The skeleton appears to have been human at one time.");
   set_body_type("human");
   set_alignment(-700);
   set("race", "undead");
   set_hp(query_max_hp());
   set_mp(query_max_mp());
   set_sp(query_max_sp());
   set_class("mage");
   set_subclass("necromancer");
   set_exp(1);
   set_spell_chance(50);
   set_spells( ({ "absorb", "missile" }) );
}
void init() {
  ::init();
   add_action("command", "command");
}
int command(string str) {
   string order, tm;
   object oi;
   int x;
   if ((string)this_player() != owner) return 0;
   if (random(50) > (int)this_player()->query_skill("necromancy")) {
      x=random(20);
      switch (x) {
         case 1:
            write("The skeleton ignores your command!");
            return 1;
            break;
         case 4:
            write("The skeleton ignores your command!");
            return 1;
            break;
         case 10:
            write("The skeleton breaks out of your control!");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         case 15:
            write("The skeleton ignores your command!");
            return 1;
            break;
         case 19:
            write("The skeleton breaks out of your control!");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         default:
            break;
      }
   }
   if (!str || sscanf(str, "%s to %s", tm, order)!=2) {
      write("Syntax: <command [monster] to [command]>\n");
      return 0;
   }
   oi = present(tm, environment(this_player()));
   if (oi != this_object()) return 0;
    if (present("gagger12345",this_player()) &&
        member_array(order[0..strsrch(order," ")-1],
        ({"say","yell","whisper","shout","tell","emote","emoteto","speak","reply"})) != -1 ||
        (int)sizeof(load_object(SOUL_D)->query_atmos(order[0..strsrch(order," ")-1])) >= 1) return 1;
   if (order == "reveal powers") {
      ob->force_me("say I know the following spells:");
      ob->force_me("say   absorb and missile");
      ob->force_me("say I have the following special abilities:");
      ob->force_me("say   <reveal powers> and <return>");
      ob->force_me("say I am level 9");
      return 1;
   }
   if (order == "die" || order == "suicide") {
   tell_room(environment(ob), "The skeleton falls %^RED%^dead%^RESET%^ before you.\n"
                              "The bones turn to dust.\n", ({ ob }));
      ob->remove();
      return 1;
   }
   if (order == "return") {
    tell_room(environment(ob), "%^BOLD%^The skeleton claws it's way into the ground!%^RESET%^\n", ({ ob }));
      ob->remove();
      return 1;
   }
   ob->force_me(order);
   return 1;
}
void set_owner(string str) {
   owner = str;
   pl = present(str, environment(this_object()));
   set_exp_share(pl, to_float(1/2));
}
void heart_beat() {
  object *shade;
 ::heart_beat();
  if (owner == "blah") return;
  if (this_object() && pl)
  if (environment(this_object()) != environment(pl)) {
      message("info", "A skeleton leaves following it's master.\n", environment(ob));
      this_object()->move(environment(pl));
      message("info", "A skeleton enters following it's master.\n",
environment((object)owner));
    }
  if(pl != (object)"")
    for(int i=0;i<sizeof(shade);i++)
      if((shade[i]->id("skeleton undead")) && (shade[i] != this_object())) {
        message("info", "The skeleton cackles and attacks it's
owner!",environment(ob));
        this_object()->kill_ob(pl, 0);
        pl = (object)"";
        owner = "blah";
      }
}
