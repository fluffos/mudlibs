// assassin demon for the summon spell
// -(Inferno)-
// Epiton Roston Verlin Drannor 
#include <std.h>
#include <sindarii.h>
inherit MONSTER;

 static string owner;
 static object ob, pl;
 int knife_wielded=0;
void create() {
  ::create();
   ob = this_object();
   set_name("assassin");
   set_id( ({ "assassin", "demon", "assassin demon" }) );
   set_gender("male");
   set_short("an assassin demon");
   set("aggressive", 0);
   set_heart_beat(1);
   set_level(20);
   set_long("The assassin demon looks like a human with oil "
            "black skin and blazing white eyes. Two horns jut "
            "out of it's head, leading down it's spine.");
   set_body_type("human");
   set_alignment(-1000);
   set("race", "human");
   set_hp(560);
   set_class("rogue");
   set_sp(600);
   set_spell_chance(40);
   set_spells( ({ "backstab", "stab" }) );
   new(ROOMS"abyss/obj/ak")->move(ob);
   set_skill("murder", 100);
   set_skill("knife", 80);
   set_stats("dexterity", 50);
   set_stats("strength", 40);
}

void init() {
  ::init();
   add_action("command", "command");
}

int command(string str) {
   string order, tm,  victim, val;
   int x;
   object oi;
   if ((string)this_player() != owner) return 0;
   if (random(90) > (int)this_player()->query_skill("conjuring")) {
      x=random(20);
      switch (x) {
         case 1:
            write("Assassin ignores your command!");
            return 1;
            break;
         case 4:
            write("Assassin ignores your command!");
            return 1;
            break;
         case 10:
            write("Assassin breaks out of your control!");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         case 15:
            write("Assassin ignores your command!");
            return 1;
            break;
         case 19:
            write("Assassin breaks out of your control!");
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
   if (order == "reveal powers") {
      ob->force_me("say I know the following spells:");
      ob->force_me("say   missile, stab, and backstab");
      ob->force_me("say I have the following special abilities:");
      ob->force_me("say   <reveal powers>, <assassinate>");
      ob->force_me("say   <assassinate [logged_on_player]>");
      ob->force_me("say I am level 20");
      return 1;
   }
   if (order == "die" || order == "suicide") {
    tell_room(environment(ob), "%^BOLD%^%^BLACK%^Assassin turns a pale grey "+
              "and slumps down dead before you.\n", ({ ob }));
      ob->die();
      return 1;
   }
   if (sscanf(order, "assassinate %s", victim)==1) {
       if (present(victim, environment(this_object()))) {
           val = sprintf("backstab %s", victim);
           ob->force_me(val);
           tell_room(environment(ob), "%^BOLD%^%^GREEN%^Assassin departs.\n", ({ ob }));
           destruct(ob);
           return 1;
       } else {
           if (!(oi=find_living(victim = lower_case(victim)))) {
              write("<assassinate [logged_on_player]>");
              return 1;
           }
           owner = "blah";
           pl = (object)"";
           this_object()->move(environment(oi));
           val = sprintf("backstab %s", victim);
           this_object()->force_me(val);
           tell_room(environment(ob), "%^BOLD%^%^GREEN%^Assassin departs.\n", ({ ob }));
           destruct(ob);
           return 1;
         }
   }
   ob->force_me(order);
   return 1;
}

void set_owner(string str) {
   owner = str;
   pl = present(str, environment(this_object()));
}

void heart_beat() {
 ::heart_beat();
  if (!knife_wielded) 
    {
     this_object()->force_me("wield knife in right hand");
     knife_wielded=1;
    }
  if (owner == "blah") return;
  if (environment(this_object()) != environment(pl)) {
      message("info", "%^BOLD%^%^BLACK%^Assassin follows its master.%^RESET%^\n", environment(ob));
      this_object()->move(environment(pl));
      message("info", "%^BOLD%^%^BLACK%^Assassin enters, with a wicked grin spread across his face.%^RESET%^\n", environment((object)owner));
    }
}

