// SUNNY MESSAGES

/*
 *  Night            (2:23 hrs.)     (0% light) 
 *  Predawn          (:15 mins.)    (10% light)
 *  Dawn             (:10 mins)     (20% light)
 *  Sunrise          (:10 mins)     (40% light)
 *  Early morning    (:44 mins)     (80% light)
 *  Late morning     (1:06 hrs)    (100% light)
 *  Noon             (:44 mins)    (100% light)
 *  Early afternoon  (1:06 hrs)    (100% light)
 *  Late afternoon   (:44 mins)     (80% light)
 *  Sunset           (:10 mins)     (40% light)
 *  Twilight         (:10 mins)     (20% light)
 *  Evening          (:15 mins)     (10% light) 
 *
 */


#include <nightday.h>
#include <weather.h>

/*------------------------------------------------------------------
** Gets the relative sunbrights for this weather type.
** 
*/

/*GetWeatherAttributes()
{

}
*/
/*------------------------------------------------------------------
** Grabs a random weather chat message for this weather type.
** These msgs are not bound to any time period.
*/

string GetTransitionMessage()
{
  string *data;

  data = 
   ({ "The .\n",
      "The fog is clearing.\n",
      "The fog is getting thinner now.\n"
   });
  return data[random(sizeof(data))];
}

/*------------------------------------------------------------------
** Grabs a random weather chat message for this weather type.
** These msgs are not bound to any time period.
*/

string GetRandomMessage()
{
  string *data;

  data =
   ({ "The sun beats down upon you without mercy.\n",
      "The fog clings wetly to your face.\n"
   });
  return data[random(sizeof(data))];
}

/*------------------------------------------------------------------
** Grabs a random sky message for this weather type. (sunny & hot)
** Each time period can have a limitless number of msgs.
*/

string GetSkyMessage(int state)
{
  string *msgs;
  
  if(!intp(state)) return 0;
  
  switch(state)
  {
    case ND_NIGHT:
      msgs = ({ "The velvet black of night is broken only by the shimmer of the stars.\n",
                "The endless expanse of the multiverse is broken only by the "
                "twinkle and shine of the stars.\n"
      });
      break;
    case ND_PREDAWN:
      msgs = ({ "It is night, but a faint glow is visible in the sky.\n"
      });
      break;
    case ND_DAWN:
      msgs = ({ "At the horizon, the glow of a new day strengthens and fights the night.\n"
                
      });
      break;
    case ND_SUNRISE:
      msgs = ({ "The rising sun fills the eastern sky, spilling light and warmth "
                "across the land.\n",
                "The sun hangs low in the eastern sky, chasing back the blackness of "
                "the night.\n"
      });
      break;
    case ND_EARLY_MORNING:
      msgs = ({ "The early morning spills light across a hazy blue sky.\n"
      });
      break;
    case ND_LATE_MORNING:
      msgs = ({ "A few lazy clouds float across the bright blue morning sky.\n"
      });
      break;
    case ND_NOON:
      msgs = ({ "The sun sits high in a hazy blue sky.\n"
      });
      break;
    case ND_EARLY_AFTERNOON:
      msgs = ({ "The sun is beyond zenith, lighting a warm afternoon.\n"
      });
      break;
    case ND_LATE_AFTERNOON:
      msgs = ({ "Fluffy white clouds scuttle across the afternoon sky.\n"
      });
      break;
    case ND_SUNSET:
      msgs = ({ "The setting sun paints the eastern sky in hues of reds and purples.\n"
      });
      break;
    case ND_TWILIGHT:
      msgs = ({ "The sky grows dark as the sun sinks over the western horizon.\n"
      });
      break;
    case ND_EVENING:
      msgs = ({ "The last glimmer of sunset has mostly faded from the horizon "
                "as night chases away the last vestiges of day.\n"
      });
      break;
    default:
      msgs = ({ "Predawn and foggy.\n"
      });
      break;
  }
  return msgs[random(sizeof(msgs))];
}

/*------------------------------------------------------------------
** Grabs a random state change message for this weather type.
** Each time period can have a limitless number of msgs.
*/

public string GetChangeMessage(int state)
{
  string *msgs;
  
  if(!intp(state)) return 0;

  switch(state)
  {
    case ND_NIGHT:
      msgs = ({ "The last fading glow of the sun slips beneath the horizon as "
                "darkness blankets the land.\n"
      });
      break;
    case ND_PREDAWN:
      msgs = ({ 
                "A faint golden glow is building in the eastern sky.\n",
                "The dawn begins gathering low on the eastern horizon.\n"
      });
      break;
    case ND_DAWN:
      msgs = ({ "Shades of red and gold build along the horizon as the sun begins rise.\n",
                "The sun breaks out above the eastern horizon, spilling light "
                  "into the world.\n",
                "A rosy golden glow fills the eastern sky as the sun peeks over "
                  "the horizon.\n"
      });
      break;
    case ND_SUNRISE:
      msgs = ({ "Golden light spills across the land as the sun rises higher "
                  "above the horizon.\n"
                
      });
      break;
    case ND_EARLY_MORNING:
      msgs = ({ "The birds sing to one another, bathing in the light of the early morning.\n"
      });
      break;
    case ND_LATE_MORNING:
      msgs = ({ "The sun gains strength, burning the last traces of dew from the grass.\n"
      });
      break;
    case ND_NOON:
      msgs = ({ "The firey sun reaches the zenith, spreading heat and light across "
                  "the land.\n",
                "The sun approaches the zenith and shines with full brightness.\n"
      });
      break;
    case ND_EARLY_AFTERNOON:
      msgs = ({ "Having passed the zenith, the sun starts falling westward.\n",
                "The shadows grow longer in the late afternoon light.\n"
      });
      break;
    case ND_LATE_AFTERNOON:
      msgs = ({ "Long shadows tilt at an angle across the land "
                  "as the afternoon sun slides westward.\n",
                "The shadows begin to lengthen into deeper shades of blue and grey, as "
                  "the sun slides gently back towards the land.\n",
                "The heat of the day lessens as the sun begins its descent towards evening.\n"
      });
      break;
    case ND_SUNSET:
      msgs = ({ "The sun begins to disappear over the horizon. It is getting "
                  "darker now.\n"
      });
      break;
    case ND_TWILIGHT:
      msgs = ({ "A firey glow shimmers on the western horizon.\n",
                "Night falls slowly across the western sky, streaked with red.\n"
      });
      break;
    case ND_EVENING:
      msgs = ({ "The silvery glow of twilight dissolves into the velvety black of "
                  "night as the shimmer of the setting sun fades away.\n"
      });
      break;
  }
  return msgs[random(sizeof(msgs))];
}


/* ----------------------------------------------------------------------
 * GetWindowMessage
 * Gets messages for indoor rooms with windows when the light or
 * weather outside changes
 * ----------------------------------------------------------------------
 */

string GetWindowMessage(int state)
{
  string *msgs;
  
  if(!intp(state)) return 0;

  switch(state)
  {
    case ND_NIGHT:
      msgs = ({ "Outside you can see the last fading glow of the sun slip "
                "beneath the horizon.\n"
      });
      break;
    case ND_PREDAWN:
      msgs = ({ 
                "The sky outside begins to become lighter as dawn approaches.\n",
                "Outside you see dawn gathering low on the eastern horizon.\n"
      });
      break;
    case ND_DAWN:
      msgs = ({ "Outside you see shades of red and gold building along the "
                  "horizon as the sun begins rise.\n",
                "Through the window you can see the sun breaking out above "
                  "the eastern horizon, spilling light into the world.\n",
                "Through the window you can see a rosy golden glow filling "
                  "the eastern sky as the sun peeks over the horizon.\n"
      });
      break;
    case ND_SUNRISE:
      msgs = ({ "Outside the sky lightens as the sun climbs higher.\n"
                
      });
      break;
    case ND_EARLY_MORNING:
      msgs = ({ "Early morning light shines in through the windowpanes.\n"
      });
      break;
    case ND_LATE_MORNING:
      msgs = ({ "The morning sun shines brightly through the windowpanes.\n"
      });
      break;
    case ND_NOON:
      msgs = ({ "The hot noon sun fills the room with light through the window.\n"
                "Outside you see the sun approach the zenith.\n"
      });
      break;
    case ND_EARLY_AFTERNOON:
      msgs = ({ "Through the window you see the sun start falling westward.\n",
                "Outside, the shadows grow longer in the late afternoon light.\n"
      });
      break;
    case ND_LATE_AFTERNOON:
      msgs = ({ "Through the window you see the long shadows of afternoon.\n"
                "Outside the shadows begin to lengthen into deeper shades of "
                  "blue and grey, as "
                  "the sun slides gently back towards the land.\n",
      });
      break;
    case ND_SUNSET:
      msgs = ({ "Outside the sun begins to disappear over the horizon. It is getting "
                  "darker now.\n"
      });
      break;
    case ND_TWILIGHT:
      msgs = ({ "Through the window you see twilight thickening.\n"
      });
      break;
    case ND_EVENING:
      msgs = ({ "Outside you see twilight dissolve into the black of night.\n"
      });
      break;
  }
  return msgs[random(sizeof(msgs))];
}
