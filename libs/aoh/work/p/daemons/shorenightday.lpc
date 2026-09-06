/*
** Nightday-Server for underwater-rooms
**
** The state-messages get expanded by the following descriptions:
**   SWD_UDESC: Description under water (when you enter)
**   SWD_CDESC: Message if it changes to this state
**   SWD_TIDE:  Description above water
**   SWD_CTIDE: Message for changes above water
**
** 25jun95 [t] Creation
** 04dec96 [t] moved to /obj/shorenightday
**
** [t] Thragor
*/

#include <config.h>
#include <nightday.h>
#include <weather.h>
#include <properties.h>

#define SF(x) #'x //'
#define PO previous_object()
#define TP this_player()
#define SWD_UDESC 4
#define SWD_UCDESC 5
#define SWD_TIDE 6
#define SWD_CTIDE 7

inherit "/std/weather";

public void InitStates()
{
  int dawnlen, dawnlen2, daylen, nightmalus;

  (::InitStates());
  dawnlen = DAY_LENGTH / 48;
  dawnlen2 = (3 * dawnlen) / 2;
  daylen = (DAY_LENGTH - 4 * dawnlen - 4 * dawnlen2) / 2;
  nightmalus = daylen / 4;

  SetStateEntry(ND_NIGHT,
    ({daylen-nightmalus, ND_REL_STATE(0, MAX_SUNBRIGHT/2),
      "It is night. The stars reflect on the plain surface of the water.\n",
      "The last glow of the sun fades away. It's fully dark now.\n",
      "It is night. The water is as dark as the dark soul of a drowned.\n",
      "The light completely vanishes. The water is black.\n",
      "It's high tide.\n",
      "Now the water has reached its highest gauge.\n"
    }));
  SetStateEntry(ND_PREDAWN,
    ({dawnlen2, ND_REL_STATE(1, MAX_SUNBRIGHT/2),
      "It is night, but a faint glow is visible in the sky.\n",
      "A faint glow appears at the horizon.\n",
      "It is night but you see a faint glow above you.\n",
      "A faint glow appears above you.\n",
      "It's high tide.\n",
      "",
    }));
  SetStateEntry(ND_DAWN,
    ({dawnlen, ND_REL_STATE(2, MAX_SUNBRIGHT),
      "At the horizon, the glow of a new day strengthens and fights the "
      "night.\n",
      "The glow at the horizon strengthens, announcing dawn. The stars fade "
      "away.\n",
      "Though it's hard to see anything you see that there's some light "
      "above you.\n",
      "The impenetrable darkness vanishes and you see a soft glow above "
      "you.\n",
      "The water draws back into the ocean.\n",
      "The water starts to draw back into the ocean.\n"
    }));
  SetStateEntry(ND_SUNRISE,
    ({dawnlen, ND_REL_STATE(3, MAX_SUNBRIGHT),
      "The sun is partly above the horizon, giving first warm light.\n",
      "Slowly the sun raises out of the water, lighting up the sky.\n",
      "There's some light above you.\n",
      "Slowly the light becomes brighter down here.\n",
      "It's low tide.\n",
      "There are just some sluices filled with water left.\n"
    }));
  SetStateEntry(ND_PRENOON,
    ({dawnlen2, ND_REL_STATE(4, MAX_SUNBRIGHT),
      "It is a nice pleasant morning.\n",
      "The sun fully climbed over the horizon. It is getting brighter now.\n",
      "A soft light comes from above.\n",
      "Now the water appears in a soft green and blue light.\n",
      "The water conquers the landmass.\n",
      "The water starts to conquer the landmass.\n"
    }));
  SetStateEntry(ND_DAY,
    ({daylen+nightmalus, ND_REL_STATE(6, MAX_SUNBRIGHT),
      "It is day.\n",
      "The sun approaches the zenith and shines with full bright now.\n",
      "It seems to be broad daylight above you.\n",
      "Now it seems to be broad daylight above you.\n",
      "It's high tide.\n",
      "Now the water has reached its highest gauge.\n"
    }));
  SetStateEntry(ND_POSTNOON,
    ({dawnlen2, ND_REL_STATE(7, MAX_SUNBRIGHT),
      "The sun is beyond zenith, lighting a warm afternoon.\n",
      "Having passed the zenith, the sun starts falling.\n",
      "You see a warm light coming through the surface of the water.\n",
      "The light gets a soft green and blue tone.\n",
      "The water draws back into the ocean.\n",
      "The water starts to draw back into the ocean.\n"
    }));
  SetStateEntry(ND_PREFALL,
    ({dawnlen, ND_REL_STATE(8, MAX_SUNBRIGHT),
      "The sun dives into the water which glows dark red.\n",
      "The sun approaches the horizon, diving slowly into the water.\n",
      "The water appears in a soft red light.\n",
      "The water dives into a soft red light.\n",
      "It's low tide.\n",
      "There are just some sluices filled with water left.\n"
    }));
  SetStateEntry(ND_FALL,
    ({dawnlen, ND_REL_STATE(10, MAX_SUNBRIGHT),
      "Night falls over the surface of the water.\n",
      "Now the water appears in a dark red light.\n",
      "Night falls over the surface of the water.\n",
      "Now the water appears in a dark red light.\n",
      "It's low tide.\n",
      ""
    }));
  SetStateEntry(ND_PRENIGHT,
    ({dawnlen2, ND_REL_STATE(11, MAX_SUNBRIGHT),
      "It is nearly dark except a fading glow on the horizon.\n",
      "The sun vanishes below the horizon, leaving just the fading sunset.\n",
      "It's nearly dark down here. Only a few sunrays find their way down "
      "here.\n",
      "Now only a few sunrays find their way down here.\n",
      "The water conquers the landmass.\n",
      "The water starts to conquer the landmass.\n"
    }));
}

public status QueryTide()
// Returns -1 for low tide, 0 for changing and 1 for high tide
{
  if (member(({ND_NIGHT,ND_PREDAWN,ND_DAY}),QueryState())!=-1)
    return 1;
  if (member(({ND_SUNRISE,ND_PREFALL,ND_FALL}),QueryState())!=-1)
    return -1;
  return 0;
}

public string QueryStateDesc()
{
  string res;
  if (({int})PO->QueryUnderwater()
      &&!(({int})PO->QueryFlats()&&QueryTide()==-1))
    res = QueryStateEntry(QueryState())[SWD_UDESC];
  else
    res = (::QueryStateDesc());
  if (({int})PO->QueryFlats())
    res+=QueryStateEntry(QueryState())[SWD_TIDE];
  return res;
}

private string GetStateDesc(object env)
{
  string res;
  if (({int})env->QueryUnderwater()
      &&!(({int})env->QueryFlats()&&QueryTide()==-1))
    res = QueryStateEntry(QueryState())[SWD_UDESC];
  else
    res = (::QueryStateDesc());
  if (({int})env->QueryFlats())
    res+=QueryStateEntry(QueryState())[SWD_TIDE];
  return res;
}

private string GetChangeDesc(object env)
{
  string res;
  if (({int})env->QueryUnderwater()
      &&!(({int})env->QueryFlats()&&QueryTide()==-1))
    res = QueryStateEntry(QueryState())[SWD_UCDESC];
  else
    res = (::QueryChangeDesc());
  if (({int})env->QueryFlats())
    res+=QueryStateEntry(QueryState())[SWD_CTIDE];
  return res;
}

public int NotifyClient (object client, mixed *data, int newstate)
{
  object room;

  data = data+({});
  if (room = environment(client))
    {
      data[WD_DESC] = GetStateDesc(room);
      data[WD_CDESC] = GetChangeDesc(room);
    }
  return (::NotifyClient(client,data,newstate));
}
