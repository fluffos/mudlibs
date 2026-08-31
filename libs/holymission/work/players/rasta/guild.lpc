/* 920228 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */

#include "std.h"
#define GUILD_NAME      "jedi"			/* thieves guild	*/ 
#define GM		"guild/master"

inherit "guild/room";

/*-------------------------------------------------------*/
/* All the Advance, Cost, List stuff here		 */
/* All the pretitles, titles and exp levels for a jedi . */
/*-------------------------------------------------------*/

/* dagmar strikte_typen */

#define MAXLVL		30
#define TO		this_object()
#define TP		this_player()
#define TPN		this_player()->query_name()
#define env		environment
#define SAY(x)		tell_room(env(TO),x)
#undef  EXTRA_RESET	
#define EXTRA_RESET	::reset(); extra_reset(arg);
#undef  EXTRA_INIT
#define EXTRA_INIT	::init();

int	guild;			/* guild # (reset get's it from obj/guild */

TWO_EXIT("players/kelly/guild/inner","south","players/kelly/guild/road","north",
	 "The Jedis's guild", "You are in the Jedis' guild.\n" +
	 "This room is brightly lit.\n" +
         "To the south lies the guild sactuarium, where only members are allowed.\n"+ 
	 "Commands: cost, advance [levels, stats],\n" +
	 "          spend, points, list, list [number],\n" +
	 "          or join.\n",1)

extra_reset(arg) {
  if (arg) return;
  guild=GM->query_number(GUILD_NAME);
  set_guild(guild);
}

do_join() {

  if (!::do_join()) return 1; /* Joining not possible */
  
  if (TP->query_alignment()<200 && TP->query_alignment()>-200) {
    write("Sorry, but only people with a real alignment are accepted.\n"+ 
	   "Go and get your alignment better or more evil.\n");
     return 1;
  }
  TP->set_guild(guild);
  GM->get_soul(guild);
  write("You're now a memeber of the Jedi.\n");
  say(TPN+" has joined the jedi guild.\n");
  return 1;
} 
