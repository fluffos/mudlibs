/* Link Death's workroom */
/* New version */
#include <room.h>
#include <areas.h>
#define TP this_player()
#define CHURCH "/room/church"

void wrong_answer(object ob);

object linkdeath, questor;
int riddle, ridnum;

string *riddle_txt;
mixed riddle_answers;

void
create_room()
{
    set_short("Link Death's Workroom");
    set_long(
      "This homely chamber belongs to Death's brother, Mr. Link Death. He is much \
more jolly fellow than Mr. G.Reaper, you can tell that by just seeing this \
nice room. An archway leads back to the dark winding passage.");
    set(PREVENT_TELEPORT);
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_NONE);
    set(PREVENT_SHOUT);
    set(ROOM_ISOLATED);
    set_exits(([ "south" : AREA_TRISTEZA+"death/winding" ]));
    set_commands(([
	"answer" : "answer_cmd",
	"south"  : "allow_cmd",
	"quit"   : "allow_cmd"
      ]));

    /* The Riddles */
    riddle_txt =
    ({
      "What is the capital of Assyria?",
      "What is the air-speed velocity of an unladen swallow?",
      "Who makes it doesn't need it,\n\
who needs it never sees it,\nwho sees it, never asks\nwhat it is for?",
      "Why don't the pigs of a poor house ever walk side by side?",
      "Where you can find the most meat in a finnish cow?",
      "Your father's child, but not your sister?",
      "I was on my way to Angmar,\n\
when I met seven orcs.\n\
Each orc had seven wives,\n\
each wife had seven whepls.\n\
Orcs, wives, and whelps,\n\
how many on their way to Angmar?",
      "   What is tall as a house,\n\
    round as a cup,\n\
      and all the king's horses\n\
        can't draw it up?"
    });

    /* The Answers. DON'T EVER REVEAL THESE TO PLAYERS! */
    riddle_answers =
    ({
      ({ "babylon" }),
      ({ "african", "or", "european" }),
      ({ "coffin" }),
      ({ "only", "one" }),
      ({ "between", "head", "tail" }),
      ({ "me" }),
      ({ "none" }),
      ({ "well" })
    });
}

void
init_room()
{
    if (!linkdeath || linkdeath->query_dead())
    {
	linkdeath = clone_object(AREA_TRISTEZA+"death/linkdeath");
	move_object(linkdeath, this_object());
    }
    else
    if (!present(linkdeath, this_object()))
    {
	move_object(linkdeath, this_object());
	tell_here("Link Death arrives,", ({ linkdeath }));
    }

    if (questor && !present(questor, this_object())) questor = 0;

    if (questor == TP) questor = 0;

    if (TP &&
      interactive(TP) &&
      TP != linkdeath)
    {
	if (TP->query_quests("golem_quest"))
	{
	    TP->tell_me(
	      "Link Death says: How boring, you have already completed the quest...");
	    return;
	}
	else
	{
	    tell_here("Link Death says: " +
	      capitalize((string)TP->query_real_name()) +
	      ", how nice to see you here!", ({ linkdeath }));
	    if (questor)
		TP->tell_me(
		  "Link Death tells you: I'm busy talking with " +
		  capitalize((string)questor->query_real_name()) +
		  ", come again later if you are here for the quest.");
	    else
	    {
		questor = TP;
		questor->tell_me(
		  "Link Death tells you: You are here for the Quest, aren't you? Then you \
must answer my riddles. You must answer by saying \"answer blah\", where \
blah is your answer. Note that all my riddles can not be answered by one \
word. When you are ready to hear riddles, \"answer yes\".");
		riddle = 0;
	    }
	}
    }
}

status
answer_cmd(string arg)
{
    string a, *p;
    int i, j, sp, c;

    if (!arg)
    {
	notify_fail("Answer what?\n");
	return 0;
    }

    if (!questor)
    {
	TP->tell_me("Link Death tells you: I'm resting. Come back later.");
	return 1;
    }

    if (questor != TP)
    {
	TP->tell_me(
	  "Link Death tells you: I'm busy right now. Come back later.");
	return 1;
    }

    a = lower_case(arg);

    if (a == "yes")
    {
	if (riddle != 0)
	{
	    TP->tell_me(
	      "Link Death tells you: That was the answer of the first riddle, definitely \
not the answer for this one. \"answer riddle\" if you need to hear the \
current riddle again.");
	    return 1;
	}
	TP->tell_me("Link Death tells you: Excellent! Now, what is your name?");
	riddle = 1;
	return 1;
    }

    if (riddle == 0)
    {
	TP->tell_me("Link Death tells you: Huh? Answer yes if you wanted to \
try the riddles.");
	return 1;
    }

    if (a == "riddle" && riddle > 2)
    {
	questor->tell_me("Link Death says: " + riddle_txt[ridnum]);
	return 1;
    }

    switch(riddle)
    {
    case 1:
	if (a != lower_case((string)TP->query_real_name()))
	{
	    wrong_answer(questor);
	    break;
	}
	questor->tell_me(
	  "Link Death says: Correct! Now, what is your favourite color?");
	riddle++;
	break;
    case 2:
	if (a == "")
	{
	    wrong_answer(questor);
	    break;
	}
	questor->tell_me("Link Death says: So your favourite color is \""+
	  a + "\"?!? Well, I have to accept that answer.");
	ridnum = random(8);
	riddle++;
	questor->tell_me("Link Death says: " + riddle_txt[ridnum]);
	break;
    case 3:
	if ((ridnum != 5 || (a != "myself" && a != "i")) &&
	  (ridnum != 6 || (a != "0" && a != "zero")))
	{
	    p = explode(a + " ", " ");
	    if ((sp = sizeof(p)) > 10)
	    {
		wrong_answer(questor);
		break;
	    }

	    c = 0;
	    for (i = (sizeof(p) - 1); i >= 0; i--)
		if (member(riddle_answers[ridnum], p[i]) != -1) c++;

	    if (c < sizeof(riddle_answers[ridnum]))
	    {
		wrong_answer(questor);
		break;
	    }
	}
	questor->tell_me("\nLink Death says: CORRECT!\n\n"+
	  "Link Death's black stallion picks you up and carries you away...\n\n");
	questor->move_player("X#"+AREA_TRISTEZA+"death/abyss1");
	questor = riddle = 0;
	break;
    default:
	tell_here("Link Death says: I'm very tired. Come back later.");
	questor = 0;
	break;
    }
    return 1;
}

void
wrong_answer(object ob)
{
    tell_here(
      "Link Death yells: WRONG!, and then presses a large red button. A loud \
BEEEEEEEP echoes in the room!", ({ linkdeath }));
    ob->move_player("disappears#"+CHURCH);
    questor = 0;
}

status
allow_cmd()
{
    if (TP == questor && riddle > 2)
    {
	TP->tell_me(
	  "Link Death tells you: No way, you will answer my riddle first! \
'answer riddle' if you need to hear it again.");
	return 1;
    }
    return 0;
}
