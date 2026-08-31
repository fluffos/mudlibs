#include <std.h>
#include <amun.h>
inherit SONG;
void create() {
    ::create();
    set_verses(({
	"All creatures come and hear the sound of my voice,",
	"And come with me throughout the day, throughout the night.",
	"Follow me into the wilderness, across the land, across the sea,",
	"Embrace the words, embrace the sounds, embrace your destiny and follow me"
      }));
    set_type("other");
    set_auto(1);
    set_target_required(1);
    set_song_name("discipline");
    set_party_hit(0); 
}
int song() {
    object o=this_player();
    if ((o->query_subclass() == "bard" ) 
      &&
      o->query_skill("euphony") >= 135 && o->query_skill("entertainment") >= 108)
	return 1;
    return 0;
}
int check() {
    if (sizeof(query_caster()->query_wielding()))
	return notify_fail("For some reason, your weapons mess up your song.\n");

    return 1;
}
void performance(int round) {
    query_caster()->add_sp(-5);
}
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
