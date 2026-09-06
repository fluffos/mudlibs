// A room which uses night/day in several different ways
// Originally written for NF by Tune [Mar97]
// slightly edited for OSB school

// Includes:
//  - a detail which is time dependent (people)
//  - sets an extra entry in the room long at night
//  - another detail which changes at night (lamps)
//  - a room message at twilight and another at dawn

#include <nightday.h>
#include <config.h>
#include <properties.h>
#include <msgclass.h>

inherit "/std/room";

string look_people();


create() 
{
  ::create();
  SetIntShort("a street in the village of Limerick");
  SetIntLong("A pleasant street in the village of Limerick.\n");
  
  AddDetail( ({"street", "road", "streets", "roads"}),
    "A quiet road in the midst of Limerick. The streets here are "
    "free from the usual garbage which covers most large city streets.\n"
    "The mayor of Limerick especially prides himself on the modern "
    "state of all his streets - the whole town of Limerick is paved "
    "with cobblestones.\n");
  
  AddDetail( ({ "cobbles", "cobblestones", "paving", "paving stones" }),
    "Meticulously quarried in the Dwarven Mountains north of Crescent "
    "Lake, the oblong, uneven paving stones cover the streets of the "
    "village, protecting pedestrians from swamps of mud when it rains.\n");
    
  AddDetail( ({ "limerick", "Limerick", "village", "town" }),
    "A very pleasant, quiet village in the heart of the isle of Ireland. "
    "Offers all modern conveniences and amenities for the modern "
    "adventurer. Rated 5 Shamrocks by the Irish Geographers' and "
    "Spelunkers' Association.\n");

  AddDetail( ({"people", "inhabitants", "townspeople" }),
    #'look_people);
    
  AddDetail("city",
    "Limerick has been accorded the legal status of 'village' by the "
    "Irish Geographers' and Spelunkers' Association. If you're looking for "
    "a city, we can recommend Nightfall City, El Essamon or Lorinia.\n");
    
  AddDetail("forest",
    "The forest is west of the village. Please take care when visiting "
    "there, as due to Article 23 Paragraph IV of the Irish Geographers' "
    "and Spelunkers' Codice Pertaining to Rights and Regulations of "
    "Visiting Adventurers, 'Limerick cannot assume any liability for "
    "accidents incurred while visiting the Great Forest'.\n");
    
  AddDetail("mayor",
    "He isn't usually to be found wandering the streets, since he is "
    "such a hard-working mayor. (Actually, he is usually hard at work "
    "on a pint of Guinness in the Roisin Dubh, but please don't tell "
    "anyone...).\n");
  
  SetIndoors(0);
  
  is_night_or_day();
}

void is_night_or_day()
{
  //  if nighttime, adds lamps to street rooms & set brightness
  
  if( ! NIGHTDAY->IsDay() )   // nighttime
  {
    // sets the room to same brightness as dawn
    Set(P_BRIGHT, ND_REL_STATE(ND_DAWN, MAX_SUNBRIGHT) );
    
    SetExtraEntry("lamp_desc", P_INT_LONG,
      "Flickering lanterns dimly light the way.\n");
      
    AddDetail( ({ "lamp", "lamps", "streetlights" }),
      "Tall wooden posts line the roads in the village. Atop each "
      "post is a lamp, which has been lit for the night. The lamps "
      "cast a flickering yellow light along the streets of the "
      "village.\n");
  }
  else   // daytime
  {
    RemoveExtraEntry("lamp_desc", P_INT_LONG);
      
    AddDetail( ({ "lamp", "lamps", "streetlights" }),
      "Tall wooden posts line the roads in the village. Atop each "
      "post is a lamp, which is lit at night.\n");
  }
}

// This changes the lamp descriptions automatically.
// When the time state changes, FilterWeatherData() is called in every
// room where a player is standing. Use it to send messages based on
// time changes. Client is the room object. If you call the next higher
// with ::FilterWeatherData() the room will also get the normal state
// messages. Don't call it if you want to block those.

mixed FilterWeatherData (object client, mixed *data, int newstate)
{
  if(newstate == ND_TWILIGHT)
  { 
    is_night_or_day();     
 
    msg_room(this_object(), CMSG_ROOM,
      "A woman enters and lights the lamps which line the roads.\n");
  }
  else if(newstate == ND_SUNRISE)
  {
     is_night_or_day();
       
     msg_room(this_object(), CMSG_ROOM,
       "A man enters and extinguishes the street lamps.\n");
  }
  return ::FilterWeatherData(client, data, newstate);
}


string look_people()
{
  switch( NIGHTDAY->QueryState() )
  {
     case ND_NIGHT..ND_EARLY_MORNING:
       return
         "There aren't many people abroad during the wee hours of the "
         "morning. Well, except for robbers, thieves and bandits.\n";
     
    case ND_LATE_MORNING..ND_LATE_AFTERNOON:
       return
         "Many people are walking about, shopping, sightseeing "
         "or visiting.\n";
     case ND_SUNSET..ND_TWILIGHT:
       return
         "As the shadows lengthen into night, most people are either "
         "headed for home or the local pub.\n";
     default:
       return
         "The streets are normally quite busy with townspeople "
         "and tourists during the daylight hours.\n";
  }
}
