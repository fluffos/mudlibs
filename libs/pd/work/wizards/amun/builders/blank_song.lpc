#include <std.h>

inherit SONG;

void create() {
  ::create();
  // these are the lines that you will sing
  set_verses(({
    "Blah line 1",
    "Blah line 2"
  }));
  set_type("attack");
  // types are attack, beneficial, detrimental, and other
  set_auto(1); // does this song put you in combat?
  set_target_required(1); // do you have to specify a target?
  set_song_name("blank song"); // this and the file name must be the same
                               // (replace spaces with _ for filename)
  set_party_hit(0); // will this non-targetted song hit party members?
}

// this function must be int song(); and returns 1 if they can use it, else 0
// this is the only place you can use this_player()
int song() {
   object o=this_player();
   if ((o->query_subclass() == "bard" || o->query_subclass() == "jester") &&
       o->query_skill("euphony") >= 77 && o->query_skill("entertainment") >= 50)
         return 1;
   return 0;
}

// this function is optional and lets you perform some additional checks
// beyond the basic singing requirements, like checking if you are wielding
// a weapon or something
// you can use query_caster() from here down instead of this_player()
// instead of returning 0, you should use a notify_fail as shown
int check() {

  if (sizeof(query_caster()->query_wielding()))
    return notify_fail("For some reason, your weapons mess up your song.\n");
  
  return 1;
}

// this function is optional, it gets called after each verse is sung
// the int round is the number of rounds of the song, starts at 1
// this does NOT get called after the last line of the song!
void performance(int round) {
  query_caster()->add_sp(-2);
}

// this function is optional, and is called after the last line of the song
void finish() {
   object ob, tp;
   int obi, tpi, val, i, xxx;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", ob);
      return;
   }
}


