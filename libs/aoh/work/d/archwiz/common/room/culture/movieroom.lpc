/*
** Culture Center in Nightfall City - Movieroom
** Author: Thragor@Nightfall, 04apr97
** Update:
*/

#include "path.h"
#include <moving.h>
#include <properties.h>
#include <rooms.h>
#include <config.h>

#define P_CHAIR "CultureChair"
#define P_SIT "ChairSit"

#define ME this_object()
#define TP this_player()
#define CHAIR OBJ("culture/cc_chair")
#define SF(x) #'x //'

inherit "/std/room";

public string QueryIntLong()
{
  return sprintf("This room looks like an archive at Warner Brothers or "
		 "MGM. No walls are visible. Everything is lined with "
		 "shelves filled with tons of film reels.\n"
		 "%s"
		 "Behind some shelves to the north you have a presentiment "
		 "of an exit.\n",
		 ((Query(P_CHAIR)&&environment(Query(P_CHAIR))==ME)
		  ?("In front of a board in the middle of the room is a "
		    "folding chair where you may take a seat.\n")
		  :("There's a board in the middle of the room.\n")
		 )
		);
}

public void refresh_chair(mixed ob,int refresh,int num)
{
  object old_ob,pl;
  if (Query(P_CHAIR)==ob) return;
  if (old_ob = Query(P_CHAIR))
    if (   !living(environment(old_ob))
	&& !old_ob->Query(P_SIT)
       )
      {
	old_ob->remove();
	if (old_ob) destruct(old_ob);
      }
  
  if (!old_ob)
    tell_room(ME,("Steven Spielberg arrives and places a folding chair in "
		  "front of the board. The he vanishes in a puff of "
		  "movie.\n"));
  else
    {
      if (pl = old_ob->Query(P_SIT))
	ob->Set(P_SIT,pl);
      if (environment(old_ob)==ME)
	{
	  old_ob->remove();
	  if (old_ob) destruct(old_ob);
	}
    }
  Set(P_CHAIR,ob);
  ob->Set(P_CHAIR,1);
}

private void remove_chair(object ob)
{
  if (!ob || environment(ob)!=ME) return;
  if (ob->Query(P_CHAIR))
    if (      Query(P_CHAIR)
	   && environment(Query(P_CHAIR))==ME
	   && Query(P_CHAIR)!=ob
       )
      {
	ob->remove();
	if (ob) destruct(ob);
	show_room(ME,("An assistant director arrives and removes the second "
		      "chair.\n"));
      }
    else
      Set(P_CHAIR,ob);
}

public void notify_enter(mixed from,int method,mixed extra)
{
  object ob;
  (::notify_enter(from,method,extra));
  if (ob = previous_object())
    call_out(SF(remove_chair),2,ob);
}

public void create()
{
  (::create());
  SetIntShort("Movieroom - Culture Center");
  // SetIntLong() done by QueryIntLong()
  Set(P_CANSEE,1);
  AddDetail("room","This room looks like a film archive.\n");
  AddDetail(({"no walls","walls"}),
	    "The walls are hidden behind lots of shelves.\n");
  AddDetail("shelves",
	    "The shelves are filled with hundreds of film reels.\n");
  AddDetail(({"film reels","reels","films"}),
	    "This is a collection of hundreds of film reels. You see "
	    "5 labels which are readable.\n");
  AddDetail(({"5 labels","labels"}),
	    "Label 1 reads: Independance Day\n"
	    "Label 2 reads: Casablance\n"
	    "Label 3 reads: Star Wars - Return of the Jedi\n"
	    "Label 4 reads: Lion King\n"
	    "Label 5 reads: Schindler's List\n");
  AddReadMsg(({"5 labels","labels"}),
	     "Label 1 reads: Independance Day\n"
	     "Label 2 reads: Casablance\n"
	     "Label 3 reads: Star Wars - Return of the Jedi\n"
	     "Label 4 reads: Lion King\n"
	     "Label 5 reads: Schindler's List\n");
  AddDetail(({"label","label 1"}),"Label 1 reads: Independance Day\n");
  AddDetail("label 2","Label 2 reads: Casablance\n");
  AddDetail("label 3","Label 3 reads: Star Wars - Return of the Jedi\n");
  AddDetail("label 4","Label 4 reads: Lion King\n");
  AddDetail("label 5","Label 5 reads: Schindler's List\n");
  AddReadMsg(({"label","label 1"}),"Label 1 reads: Independance Day\n");
  AddReadMsg("label 2","Label 2 reads: Casablance\n");
  AddReadMsg("label 3","Label 3 reads: Star Wars - Return of the Jedi\n");
  AddReadMsg("label 4","Label 4 reads: Lion King\n");
  AddReadMsg("label 5","Label 5 reads: Schindler's List\n");
  AddDetail("exit","It must be somewhere to the north.\n");
	    
  AddExit("north","./culture");
  AddItem("/std/board",
	  REFRESH_HOME,
	  ([
	    P_SHORT:"The Movie Board",
	    P_LONG:("Here you can leave notes about the latest movies, and "
		    "classic films of the past.\nTry \"help board\"!\n"),
	    "Groups":({"rec.movies"})
	  ]) );
  AddItem(CHAIR,REFRESH_REMOVE|REFRESH_FUNC,SF(refresh_chair));
}
