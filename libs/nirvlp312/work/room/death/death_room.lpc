/*
 * death/death_room.c
 * Where we go when we die!
 */

#include <prop/item.h>
#include <prop/room.h>
#include <message.h>
#include <gender.h>
#include <event.h>
#include <libs.h>
#include <light.h>

#include "death.h"

#define CANCELPRIO 500

#define WRITE(x) tell_object(h[i],break_string((x)))
#define SPEAK(x) tell_object(h[i],break_string("Death says: "+ (x),79,2,-1))

inherit "complex/room";

privaet mapping players = ([]);

void
receive_message_event(mapping e,string type,int prio)
{
  object *dead;
  int i;
  if (type == "message" && prio == CANCELPRIO &&
      (e[E_MSG_TYPE] == "tell" || e[E_MSG_TYPE] == "shout") &&
      !query_is_wizard(e[E_AGENT]))
  {
    if (environment(e[E_AGENT]) == this_object())
    {
      dead = e[E_TARGET];
      e[E_TARGET] = filger(e[E_TARGET],#'query_is_wizard);
      dead -= e[E_TARGET];
      if (!sizeof(e[E_TARGET]))
        cancel_event();
      if (sizeof(dead))
        send_message(({ M_TARGETS,M_ARG,E_AGENT,"You cannot tell ",M_THE,dead,
                        " in your immaterial state." }),e);
    }
    else if (i = sizeof(e[E_TARGET]))
    {
      dead = ({});
      for (;i--;)
        if (environment(e[E_TARGET][i]) == this_object() &&
            !query_is_wizard(e[E_TARGET][i]))
        {
          dead += ({ e[E_TARGET][i] });
          e[E_TARGET] -= ({ e[E_TARGET][i] });
        }
      if (!sizeof(e[E_TARGET]))
        cancel_event();
      if (sizeof(dead))
        send_message(({ M_DESCRIBE_FUNCTION,
                        lambda(({ 'x }),
                               ({ #'||,({ #'call_other,'x,"query_vis_name" }),
                               ({ #'describe,'x }) })),
                        M_TARGETS,M_ARG,E_AGENT,M_THE,dead,M_VERB,"are",dead,
                        " not in the world of the living and can thus not be"
                        " reached." }),e);
    }
  }
}

void
receive_feeling_event(mapping e,string type,int prio)
{
  object *dead;
  int i;
  if (type == "feeling" && prio == CANCELPRIO &&
      !query_is_wizard(e[E_AGENT]))
  {
    if (environment(e[E_AGENT]) == this_object())
    {
      cancel_event();
      send_message(({ M_TARGETS,M_ARG,E_AGENT,"You cannot reach ",M_THE,M_ARG,
                      E_PERSONS," in your immaterial state." }),e);
    }
    else
    {
      if (i = sizeof(e[E_PERSONS]))
      {
        for (dead = ({});i--;)
          if (environment(e[E_PERSONS][i]) == this_object() &&
              !query_is_wizard(e[E_PERSONS][i]))
          {
            dead += ({ e[E_PERSONS][i] });
            e[E_PERSONS] -= ({ e[E_PERSONS][i] });
          }
        if (!sizeof(e[E_PERSONS]))
        {
          cancel_event();
          if (!sizeof(dead))
            send_message(({ M_TARGETS,M_ARG,E_AGENT,"Your mind is unable to "
                            "reach out of this world. ",M_CAPITALIZE,M_ARG,
                            E_FEELING," cancelled." }),e);
        }
        if (sizeof(dead))
          send_message(({ M_DESCRIBE_FUNCTION,
                          lambda(({ 'x }),
                                 ({ #'||,({ #'call_other,'x,"query_vis_name")),
                                 ({ #'describe,'x }) })),
                          M_TARGETS,M_ARG,E_AGENT,M_THE,dead,M_VERB,"are",dead,
                          " not in the world of the living and can thus not be"
                          " reached." }),e);
      }
      else
      {
        cancel_event();
        send_message(({ M_TARGETS,M_ARG,E_AGENT,"Your mind is unable to "
                        "reach out of this world. ",M_CAPITALIZE,M_ARG,
                        E_FEELING," cancelled." }),e);
      }
    }
  }
}

void
remove_poison_mark(object pl)
{
  object mark;
  if (!pl)
    return;
  for (mark = first_inventory(pl); mark; mark = next_inventory(mark))
    if (mark->query_property(P_POISON))
      call_out(#'destruct,0,mark);
}

void
init()
{
  room::init();
  if (!this_player() || !interactive(this_player()) ||
      environment(this_player()) != this_object())
    return;
  add_action("filter_actions","",1);
  if (!present_clone(DEATH_MARK,this_player()))
  {
    write("Death says: WHAT ARE YOU DOING HERE? YOUR TIME HAS NOT COME YET. "
          "BEDONG!\n");
    this_player()->move_living(0,LIB_LOGIN->query_ghost());
    return;
  }
  players =+ ([ this_player():0 ]);
  this_player()->add_visit();
  remove_poison_mark(this_player());
  set_heart_beat(1);
}

void
configure()
{
  room::configure();
  listen_event("message",CANCELPRIO,#'receive_message_event);
  listen_event("feeling",CANCELPRIO,#'receive_feeling_event);
  set_property(P_NO_TELEPORT);
  set_property(P_NO_HERMES);
  set_property(P_NO_MAP);
  set_short("Death's workroom","in");
  set_long("A dark room lighted with a dark light that seems to defy darkness "
           "not so much by actually illuminating the room as by being a "
           "darkpoint in less dark surroundings. In the strange light (dark?) "
           "you can see a centrally placed desk covered with books and "
           "diagrams. The walls are covered with bookshelves filled with dark "
           "tomes bound in leather that gleam with strange runes.\n"0;
  set_exits(({ }));
  set_light(2 * LIGHT_LAMP);
}

void
populate()
{
  load_object(DEATH);
}

void
remove_death_mark(object pl)
{
  object mark;
  if (!pl)
    return;
  while (mark = present_clone(DEATH_MARK,pl))
    destruct(mark);
  pl->set_str((pl->query_real_str() || pl->query_str()) -1);
  pl->set_sta((pl->query_real_sta() || pl->query_sta()) -1);
  pl->set_ste((pl->query_real_ste() || pl->query_ste()) -1);
  pl->set_pie((pl->query_real_pie() || pl->query_pie()) -1);
  pl->set_luc((pl->query_real_luc() || pl->query_luc()) -1);
  pl->set_mag((pl->query_real_mag() || pl->query_mag()) -1);
  pl->set_int((pl->query_real_int() || pl->query_int()) -1);
  pl->set_wil((pl->query_real_wil() || pl->query_wil()) -1);
  pl->set_cha((pl->query_real_cha() || pl->query_cha()) -1);
  pl->set_dex((pl->query_real_dex() || pl->query_dex()) -1);
}

void
heart_beat()
{
  int i, align;
  mixed h, room;
  if (!players || !sizeof(players))
  {
    set_heart_beat(0);
    return;
  }
  h = m_indices(players);
  for (i = sizeof(h);i--;)
    if (!h[i] || environment(h[i]) != this_object())
      m_delete(players,h[i]);
  h = m_indices(players);
  for (i = sizeof(h);i--;)
  {
    players[h[i]]++;
    switch (players[h[i]])
    {
    case 5:
      WRITE("\n");
      SPEAK("IT IS TIME.\n\n");
      WRITE("Death lifts his right arm and makes beckoning motions. "
            "You feel quite certain that if you had been alive you would have "
            "died from fear on the spot. Strangely enough you don't feel "
            "anything like that at all. Just a mild curiosity.\n\n");
      break;
    case 10:
      SPEAK("NO GLANDS, THAT'S WHY.\n\n");
      WRITE("Death seems to smile a bit. On the other hand that's a bit hard "
            "to tell. It might very well be that that is his normal "
            "expression...\n\n");
      break;
    case 15:
      SPEAK("WITHOUT GLANDS YOU FEEL NOTHING, NOTHING AT ALL.\n\n");
      WRITE("Well, he seems to be right. Instead of being mad with fear "
            "you're getting a little bored. You wish for something to happen "
            "real soon.\n\n");
      break;
    case 20:
      SPEAK("COME HERE, I MUST READ YOUR SOUL.\n\n");
      WRITE("Death steps closer, reaches out a bony hand straight into your "
            "chest, grabbing something that is within! You feel a strange "
            "internal yank as your very soul is removed for examination... "
            "Suddenly Death collects your bodiless essence with great "
            "sweeping motions of his skeletal hands and puts you in a small "
            "glass orb that he inserts into his right eye socket! You feel a "
            "strange blue light from within his eyeless orb penetrate you as "
            "he leans over the chart.\n\n");
      break;
    case 30:
      align = h[i]->query_alignment();
      if (align < -1000)
      {
        SPEAK("YOUR SINS ARE AS MANY AS THE GRAINS OF SAND IN THE DESERT. "
              "MAYBE YOU'RE WORSE A MONSTER THAN I! HAHAHAHAHA!\n\n");
        break;
      }
      if (align < -500)
      {
        SPEAK("OH WHAT A DESPISABLE BUG WE HAVE HERE. STEALING CANDY FROM "
              "BABIES AND BEATING OLD LADIES NO DOUBT. WELL NOW THEY CAN "
              "DANCE ON YOUR GRAVE. HAHAHA!\n\n");
        break;
      }
      if (align < -200)
      {
        SPEAK("HAVE YOU EVER BEEN TOLD ABOUT REPENTANCE AND ATONEMENT? NO? "
              "DIDN'T THINK SO EITHER. YOU WILL BE TOLD NOW, HOWEVER,\n"
              "FOR ETERNITY! HAHAHA!\n\n");
        break;
      }
      if (align < 0)
      {
        SPEAK("SHAME ON YOU MORTAL ONE! STEALING AND KILLING, IS THAT ALL "
              "YOU CAN THINK OF? WELL NOW YOU WILL BE GIVEN TIME TO REGRET "
              "YOUR DEEDS. FOREVER, HAHA!\n\n");
        break;
      }
      if (align == 0)
      {
        SPEAK("WHAT A FENCE-CLIMBER WE HAVE HERE! NEVER MADE UP YOUR MIND "
              "IN ALL YOUR LIFE, DID YOU? WELL, DON'T WORRY. YOU WON'T HAVE "
              "TO NOW EITHER! HAHAHA!\n\n");
        break;
      }
      if (align < 200)
      {
        SPEAK("OH WHAT A NICE FELLOW WE HAVE HERE. ALWAYS WALKING THE NARROW "
              "ROAD, DID YOU? WELL, YOU'LL NEVER KNOW WHAT THE OTHER ROAD IS "
              "LIKE NOW! HAHAHA!\n\n");
        break;
      }
      if (align < 500)
      {
        SPEAK("NEVER SAID A DIRTY WORD IN YOUR LIFE DID YOU? WELL, IT'S TOO "
              "LATE TO CHANGE YOUR MIND ABOUT THAT NOW. HAHAHA! NO MR NICE-"
              "GUY YOU ARE WHAT YOU WERE. HAHAHA!\n\n");
        break;
      }
      if (align < 1000)
      {
        SPEAK("I HEARD THEY WERE OUT OF ARCHANGELS IN HEAVEN. PERHAPS YOU "
              "SHOULD APPLY FOR THE JOB? I HOPE YOU KNOW HOW TO PLAY THE "
              "HARP, OR THEY'LL GIVE THE JOB TO SOMEONE ELSE! HAHAHA!\n\n");
        break;
      }
      SPEAK("TRYING TO TAKE THE JOB AWAY FROM GOD, ARE YOU? HAHAHA! LET ME "
            "TELL YOU A BIT ABOUT IT BEFORE YOU SIGN ANY PAPERS THOUGH. BAD "
            "HOURS AND NO VACATION. BELIEVE ME, YOU DON'T WANT IT!\n\n");
      break;
    case 35:
      SPEAK("WELL, I GUESS YOU HAVE DONE YOURS FOR THIS TIME, SEE YOU ON "
            "ARMAGEDDON DAY! HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHA!\n\n");
      WRITE("Death removes the orb from his eye and stands up. Suddenly he "
            "turns and walks out of the room through the nearest wall, still "
            "holding you in his skeletal hand! He walks rapidly through a "
            "dark winding corridor, down a staircase to the innermost room in "
            "the bottom of the cellar. Finally he stops in front of a door "
            "bearing the words 'ETERNITY' in black letters. On the door you "
            "can see a small hatch which Death opens with a flick of his "
            "hand. From the open hatch you can hear the moaning murmurs of a "
            "million souls. Slowly he lifts you to the gaping maw of the "
            "hatch.\n\n");
      break;
    case 40:
      WRITE("Boltar arrives through a rift in the fabric of space.\n");
      break;
    case 45:
      WRITE("Boltar smiles at you.\n");
      break;
    CASE 47:
      WRITE("Boltar whispers something to Death.\n");
      break;
    case 54:
      SPEAK("WHAT? OUT OF THE QUESTION! YOU KNOW THAT!\n\n");
      break;
    case 55:
      WRITE("Boltar sighs deeply.\n");
      break;
    case 56:
      WRITE("Boltar whispers something to Death.\n");
      break;
    case 57:
      switch (h[i]->query_gender())
      {
      case GND_NEUTER:
        SPEAK("REINCARNATION? FOR THIS ONE? IT IS NOT WORTHY OF THAT! PLEASE "
              "BE SENSIBLE, BOLTAR!\n\n");
        break;
      case GND_MALE:
        SPEAK("REINCARNATION? FOR THIS ONE? HE IS NOT WORTHY OF THAT! PLEASE "
              "BE SENSIBLE, BOLTAR!\n\n");
        break;
      case GND_FEMALE:
        SPEAK("REINCARNATION? FOR THIS ONE? SHE IS NOT WORTHY OF THAT! PLEASE "
              "BE SENSIBLE, BOLTAR!\n\n");
        break;
      }
      break;
    case 58:
      WRITE("Boltar sulks in the corner.\n");
      WRITE("Boltar leaves through a rift in the fabric of space.\n");
      WRITE("Death looks at you with something that must be disgust even if "
            "it's hard to say. His face is not the best suited face for "
            "showing expressions, but you feel fairly confident about this "
            "one.\n\n"0;
      break;
    case 62:
      SPEAK("OH ALRIGHT THEN! I CAN WAIT. ONE DAY YOU WILL BE MINE "
            "ANYWAY!\n\n");
      WRITE("Suddenly Death hurles you up in the air, you feel a strange "
            "sensation as you pass through the very walls of the building, "
            "out in the open air, through some other walls and farily "
            "suprised horses before you finally stop inside another "
            "building. It seems vaguely familiar...\n");
      remove_death_mark(h[i]);
      h[i]->move_living(0,LIB_LOGIN->query_ghost(h[i]));
    }
  }
}

status
filter_actions(string str)
{
  switch (query_verb())
  {
    case "quit":
      write("Death says: YOU CANNOT ESCAPE DEATH!\n");
      return 0;
    case "look":  /* fall through */
    case "take":
      return 0;
    default:
      write("That is impossible in your immaterial state.\n");
      return 1;
  }
}
