#include "/players/reflex/lib/lib.h"
#include "/players/reflex/lib/include/ansi.h"
inherit ROOM;

void create() {
::create();
    set_short(BOLD+"First Church of Nirvana"+NORM);
    set_long(BOLD+
        "First Church of Nirvana.\n"+NORM+
        "You are in a very large Cathedral.  There are stained glass\n"+
        "windows up both sides, leading all the way up to the arched\n"+
        "ceiling.  The ceiling is supported by huge arches, curving\n"+
        "majestically above you.  Everything is made of the finest oak,\n"+
        "and the pews are inlaid with gold trim.  At the front stands\n"+
        "a podium, and before it a small platform where weddings are\n"+
        "performed.\n\n"+
        "There is a large set of double doors exiting to the north...\n");
    set_items(([
        "windows" :
        "The stained glass depicts several scenes of Christ from the bible.\n", 
        "ceiling" :
        "There is a large mural of the sermon on the mount depicted with\n"+
        "multi-colored tiles across the length of the ceiling.\n",
        "arches" :
        "Huge arches made of Oak, well polished and decorated with carvings\n"+
        "of Christ and the Virgin Mary.\n",
        "pews" :
        "Oak pews, they are padded and covered in the finest velvet.  The\n"+
        "trim is in the finest gold.\n",
        "podium" :
        "A ornate podium from which a Reverand could deliver a stirring\n"+
        "sermon.  It has two angels depicted in fine carvings, inlaid with\n"+
        "gold.\n",
        "platform" :
        "A raised dias, still lower than the podium, but higher than the\n"+
        "floor level.  It is where weddings are performed.\n",
        "doors" :
        "Two large ornate oak doors, they open north to exit the church.\n"+
        "They are covered in carvings and symbols from the Bible.\n",
        ]));
    set_smells(([
	"default" :
	"You smell incense burning.\n",
	"pews" :
	"Pee-Yew!(what did you expect..?)\n",
	]));
    set_sounds(([
	"default" :
	"You hear the organ playing in the background.\n",
	"organ" :
	"A organ plays quietly in the background...\n",
	]));
    set_chat_frequency(120);
    load_chats(({
	"The organ plays softly...\n",
	"A sense of calm overcomes you...\n",
	"You are at peace here...\n",
	"You feel a "+BOLD+"higher power's"+NORM+" presence...\n",
	}));
    set_exits(([
        "north" : "/players/reflex/realms/weddings/church/yard",
        ]));
    set_light(1);
    replace_program(ROOM);
}
  init() {
    ::init();
    add_action("nokill","kill");
    add_action("nokill","missile");
    add_action("nokill","mi");
    add_action("nokill","shock");
    add_action("nokill","sh");
    add_action("nokill","fireball");
    add_action("nokill","fi");
    add_action("nokill","sonic");
    add_action("nokill","so");
    }

    nokill() {
        write("What?  Kill in a church..?\n");
    return 1; 
    }
