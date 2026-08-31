#include <std.h>
#define SDIR "/cmds/song/"
inherit DAEMON;

mapping all_songs = ([
"ode towards nature"         : "/cmds/song/my_song",
"song of blades"	: "/cmds/song/blades",
"song of the ages"	: "/cmds/song/ages",
"song of darkness"	: "/cmds/song/dark",
"song of fates"		: "/cmds/song/fate",
"ballad of blood"	: "/cmds/song/ballad_blood",
"anathema au vengeance"	: "/cmds/song/veng",
// "curse of venom"        : "/cmds/song/venom",
"sonata of inebriety"	: "/cmds/song/drinking",
"fugue of woes"		: "/cmds/song/woe",
"chaunt du cygne"	: "/cmds/song/suicide",
"hymn of faeries"	: "/cmds/song/faeries",
"sinners psalm"		: "/cmds/song/sinners",
"song of winter"	: "/cmds/song/winter",
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
