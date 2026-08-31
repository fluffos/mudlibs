#include <std.h>
#define SDIR "/wizards/inferno/song/"
inherit DAEMON;

mapping all_songs = ([
"ode to nature"		: "/wizards/inferno/song/my_song",
"song of blades"	: "/wizards/inferno/song/blades",
"song of the ages"	: "/wizards/inferno/song/ages",
"song of darkness"	: "/wizards/inferno/song/dark",
"song of fates"		: "/wizards/inferno/song/fate",
"ballad of blood"	: "/wizards/inferno/song/ballad_blood",
"anathema au vengeance"	: "/wizards/inferno/song/veng",
"curse of venom"	: "/wizards/inferno/song/venom",
"sonata of inebriety"	: "/wizards/inferno/song/drinking",
"fugue of woes"		: "/wizards/inferno/song/woe",
"chaunt du cygne"	: "/wizards/inferno/song/suicide",
"hymn of faeries"	: "/wizards/inferno/song/faeries",
"sinners psalm"		: "/wizards/inferno/song/sinners",
"song of winter"	: "/wizards/inferno/song/winter",
]);

string find_song(string str) {
   if (!all_songs[str]) return 0;
   return all_songs[str];
}

string *query_songs(object tp) {
   int i;
   string *ob = ({ }), *str;
   object song;

   str = keys(all_songs);
   i = sizeof(str);
   while (i--) {
     song = all_songs[str[i]];
     if (song->check_sing(tp))
       ob += ({ song->query_song_name() });
   }
   return ob;
}
