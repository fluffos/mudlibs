/* 920228 mud@alijku05.edvz.uni-linz.ac.at Herbert Rosmanith */ 

#include "std.h"
#define GUILD		"thief"			/* thieves guild */ 
#define GM		"guild/master"
#define LGF		"GUILD.JOIN"
#define COST_FOR_JOIN	500

inherit "guild/room";

/*-------------------------------------------------------*/
/* All the Advance, Cost, List stuff here		 */
/* All the pretitles, titles and exp levels for a thief. */
/*-------------------------------------------------------*/

/* dagmar strikte_typen */

#define TO		this_object()
#define TP		this_player()
#define TPN		this_player()->query_name()
#define env		environment
#define SAY(x)		tell_room(env(TO),x)
#undef  EXTRA_RESET	
#define EXTRA_RESET	::reset(); extra_reset(arg);
#undef  EXTRA_INIT
#define EXTRA_INIT	::init();
#undef  EXTRA_MOVE1
#define EXTRA_MOVE1	if (!chk_leave())

int	guild;			/* guild # (reset get's it from obj/guild */

ONE_EXIT("room/sunalley2","up",
	 "Thieve's guild",
	 "You have entered the thieves' guild.\n" +
	 "The place is dimly lit and you feel at home.\n" +
	 "Commands: cost, advance,\n" +
	 "          list, list [number],\n" +
	 "          or join.\n",1)

extra_reset(arg) {
  if (arg) return;
  guild=GM->query_number(GUILD);
  set_guild(guild);
}

do_join() {

  if (!::do_join()) return 1; /* Joining not possible */
  
  if (TP->query_money()<COST_FOR_JOIN) {
     write("You don't have enough gold coins.\n" +
	   "Prove that you are a thief, and steal "+COST_FOR_JOIN+" gold coins !\n");
     return 1;
  }
  TP->add_money(-COST_FOR_JOIN);
  TP->set_guild(guild);
  write("You pay your fee for joining.\n");
  write("You now are a thief !\n");
  say(TPN+" has joined the thieves guild.\n");
  log_file(LGF,TPN+" joins the "+GUILD+"'s guild at "+
	   ctime(time())+"\n");
  return 1;

}
