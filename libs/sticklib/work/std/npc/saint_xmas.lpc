#include <treasure.h>

#define CHANNEL_SERVER       "/bin/daemons/channel_d"

string *chat, *chan;
string *ch_names;

void
create_treasure()
{
    set_name("santa claus");
    set_id(({ "santa", "claus","santa_claus" }));
    set_short("Santa Claus");
    set_long(
      "Santa Claus is an obese, smiling man with a long white beard, moustache and \
hair. His nose and cheeks are red. He is wearing a bright red costume.");

    chat = ({
      "Santa Claus asks: Are there any good kids around here, ho ho ho?",
      "Santa Claus starts singing \"Rudolph\"!",
      "Santa Claus starts singing \"Jingle Bells\"!",
      "Santa Claus hums some christmas song.",
      "Santa Claus exclaims: Ho ho ho!",
      "Santa Claus pats you on the head and smiles.",
      "Santa Claus asks: What would you like to have as christmas presents? Ho ho ho!",
      "Santa Claus yells: Rudolph!!! Where did that #$@!XXX reindeer go?",
    });
    chan = ({
      "Ho ho ho!",
      "Are there any good kids around here, ho ho ho?",
      "Merry Christmas! Meeeeerrrry Christmas! Ho ho ho!",
      ":starts singing \"Jingle Bells\"!",
      ":starts singing \"Rudolph\"!",
    });
    ch_names = CHANNEL_SERVER->query_channel_names();
    ch_names -= ({ "wiz", "fiz", "awiz", "thiefdmn", "thiefgmc" });
    call_out("make_noise", 1);
}

void make_noise() {
    int i;

    if(!environment(this_object())) return 0;
    switch( i = random(5) ) {
    case 0:
	CHANNEL_SERVER->send_channel_message("Santa Claus",
	  ch_names[random(sizeof(ch_names))],
	  chan[random(sizeof(chan))]);

	break;
    default:
	environment(this_object())->tell_here(chat[random(sizeof(chat))]);
	break;
    }
    call_out("make_noise", 60+random(120));
}

void
init()
{
    if (!this_player() || environment() != environment(this_player()))
	return;
    add_action("not_allowed", "knee");
    add_action("not_allowed", "slap");
    add_action("not_allowed", "kill");
    add_action("not_allowed", "missile");
    add_action("not_allowed", "shock");
    add_action("not_allowed", "fireball");
    add_action("not_allowed", "deathball");
    add_action("not_allowed", "db");
    add_action("not_allowed", "shout");
    add_action("not_allowed", "cast");

    // Priest stuff
    add_action("not_allowed", "paralyze");
    add_action("not_allowed", "earthquake");
    add_action("not_allowed", "holocaust");
    add_action("not_allowed", "disease");
    add_action("not_allowed", "demon");
    add_action("not_allowed", "fury");
    add_action("not_allowed", "pwk");
    add_action("not_allowed", "drain");
    add_action("not_allowed", "purify");
}

not_allowed()
{
    this_player()->tell_me(
      "Santa Claus stops you, and says: That is not a nice thing to do!");
    environment()->tell_here("Santa Claus prevents " +
      (string)this_player()->query_name() + " from doing a naughty thing.",
      ({ this_player() }) );
    environment()->tell_here(
      "Santa Claus writes something into a large black book, and says: \"\
Naughty kids such as " +
      this_player()->query_name() + " won't get any presents, ho ho ho!\"");
    return 1;
}
debug() { printf("%O\n", ch_names); }

get() { return 0; }
