//	/std/virus.c
// 	Viruses to unleash on the mortals!
//	::Inferno(03/20/01);
//	Make sure there is a:  hit_me() { }  function.. will call when
//	virus hits.
//	Notice that viruses are not contagious in no-attack zones

#include <std.h>
inherit OBJECT;
/*********
  Duration of a 1,000 halflife virus: (in rounds) :
	1,000 -> 500 -> 250 -> 125 -> 62 -> 31 -> 15 -> 6 -> 3 -> 1
*********/
mapping stats = ([ "halflife" : 0, "lives" : 0, "contagious" : 0,
	"life_count" : 0, "half_count" : 0 ]);
// virus will 'hit' every [lives] rounds
// contagious is a percent chance (out of 100)

string query_short(string str) { return ""; }

string query_long(string str) { return ""; }

void create() {
 ::create();
   set_name("virus");
   set_heart_beat(1);
}

void heart_beat() {
   string st, trash;
   int trig = 0;
   int i, a;
   object *all, *ppl = ({ }), env, virus;
   if ((int)stats["half_count"] >= (int)stats["halflife"]) {
     stats["halflife"] = (stats["halflife"]/2);
     stats["half_count"] = -1;
   }
   if (stats["halflife"] <= 1) { remove(); return; }
   if (stats["life_count"] >= stats["lives"]) {
     stats["life_count"] = -1;
     trig = 1;
   }
   a = stats["life_count"];
   a++;
   stats["life_count"] = a;
   a = stats["half_count"];
   a++;
   stats["half_count"] = a;
   if (!environment(this_object()) ||
	!environment(this_object())->is_living())
		{ remove(); return; }

   if (!trig) return;
   this_object()->hit_me();

   if (random(99) <= stats["contagious"]) {
     if (!(env = environment(this_object()))) return;
     all = all_inventory(environment(env));
     i = sizeof(all);
     while (i--) {
	if (all[i]->is_living() && all[i] != env) ppl += ({ all[i] });
     }
     if (sizeof(ppl) <= 0) return;
     i = random((sizeof(ppl) - 1));
     if (present(this_object()->query_name(), ppl[i])) return;
     if (environment(env)->query_property("no attack")) return;
     sscanf(file_name(this_object()), "%s#%s", st, trash);
     virus = new(st);
     if (!virus) { stats["contagious"] = 0; return; }
     virus->move(ppl[i]);
     tell_object(env, "You cough all over "+ppl[i]->query_cap_name()+
	", spreading your disease.");
     tell_object(ppl[i], env->query_cap_name()+" coughs all over you "
	"in a disease spreading way.");
     tell_room(environment(env), env->query_cap_name()+" coughs all "
	"over "+ppl[i]->query_cap_name()+" in a disease spreading way.",
	({ env, ppl[i] }));
   }
}

void set_halflife(int x) { stats["halflife"] = x; }

void set_lives(int x) { stats["lives"] = x; }

void set_contagious(int x) { stats["contagious"] = x; }

int query_half_count() { return stats["half_count"]; }

int query_life_count() { return stats["life_count"]; }

int query_contagious() { return stats["contagious"]; }

int query_lives() { return stats["lives"]; }

int query_halflife() { return stats["halflife"]; }

int is_virus() { return 1; }
