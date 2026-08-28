#define S_STR           0
#define S_DEX           1
#define S_AGI           2
#define S_CON           3
#define S_INT           4
#define S_WIS           5
#define S_POW           6
#define S_CHA           7
#define S_SIZ           8
#define S_STU           9

#define PREV            previous_object()

#define pline(x)        message("0", x, PREV)

string *good = ({ "charitable", "kind", "empathic", "caring",
                  "compassionate", "unsullified", "purehearted",
                  "beatific", "saintly" });

string *evil = ({ "apathetic", "selfish", "cruel", "malicious",
                  "despicable", "corrupt", "wicked", "demonic",
                  "diabolical" });

string *order = ({ "disciplined", "honorable", "responsible",
                   "trustworthy", "altruistic", "lawful", "structured",
                   "patterned", "ordered" });

string *chaos = ({ "undisciplined", "carefree", "uninhibited",
                   "free-spirited", "anarchistic", "individualistic",
                   "innovative", "spontaneous", "chaotic" });

string
query_alxs (int i)
{
  if (i<-1500)
    i = -1500;

  if (i>1500)
    i = 1500;

  if (i>-50)
    return good[i/175];
  else {
    i = -(i);
    return evil[i/175]; 
  }
}

string
query_alys (int i)
{
  if (i<-1500)
    i = -1500;

  if (i>1500)
    i = 1500;

  if (i>-50)
    return order[i/175];
  else {
    i = -(i);
    return chaos[i/175];
  }
}

string
query_statd (mixed meep)
{	
  switch (meep)
    {
      case 1..2:
        return "very bad";
      case 3..5:
        return "bad";
      case 6..8:
        return "poor";
      case 9:
        return "decent";
      case 10:
        return "meager";
      case 11:
        return "mediocre";
      case 12..13:
        return "average";
      case 14:
        return "fair";
      case 15:
        return "good";
      case 16..17:
        return "very good";
      case 18:
        return "great";
      case 19..21:
        return "excellent";
      case 22..24:
        return "superb";
      case 25..30:
        return "awesome";
      case 31..38:
        return "legendary";
      case 39..45:
        return "massive";
      case 46..70:
        return "monstrous";
      case 71..150:
        return "unearthly";
      case 151..1000:
        return "Godly";
    }
  return "non-existent";
}

int
main ()
{
  string name = "-", race = "-", subrace = "-", buf = "";
  string *stat, *max, title, aly, alx, al, g;
  int gender, age;

  if (PREV->query_race() == "raceless" || !PREV->query_race())
  {
    pline("You haven't selected a race yet.\n");
    return 1;
  }

  stat    = PREV->query_stats();
  max     = PREV->query_max_stats();
  gender  = PREV->query_gender();
  race    = PREV->query_race();
  subrace = PREV->query_subrace();
  age     = PREV->query_age();
  name    = PREV->query_cap_name();
  title   = PREV->query("title");

  if (THIS->query_alignx() < -500)
    alx = "evil";
  else if (THIS->query_alignx() > 500)
    alx = "good";
  else
    alx = "neutral";

  if (THIS->query_aligny() < -500)
    aly = "chaotic";
  else if (THIS->query_aligny() > 500)
    aly = "lawful";
  else
    aly = "neutral";

  if (alx == aly)
    aly = "true";

  al = aly + " " + alx;

  if (!subrace)
    subrace = "-";

  if (gender == 1)
    g = "male";
  else if (gender == 2)
    g = "female";
  else
    g = "neuter";
/*

================================================================================
CHARACTER INFORMATION

Character name : Namhas Luuska      Race           : Troll
Subrace/Tribe  : none               Age            : 17 years
Gender         : male               Religion(s)    : none
Guild(s)       : none               Homeland       : perkele
Current title  : adventurer
--------------------------------------------------------------------------------
ATTRIBUTES

Strength       : pathetic           Intelligence   : perkeleeeee
Dexterity      : extremely good     Wisdom         :
Agility        : something else     Willpower      :
Constitution   :                    Charisma       :
Sturdiness     :                    Size           :
--------------------------------------------------------------------------------
Your physical 



Statistics on: Namhas Luuska, the no-life coder
============================================================================
Strength     (STR)  50/ 89 (pathetic       ) | Race          : human
Dexterity    (DEX)  40/ 34 (extremely good ) | Subrace/tribe : -
Agility      (AGI)  30/ 67 (meep           ) | Alignment     : chaotic evil
Constitution (CON)  60/ 34 (poks           ) | Title         : adventurer
Sturdiness   (STU)  70/ 55 (plah           ) | Gender        : male
Intelligence (INT)  10/ 13 (hmm            ) |
Wisdom       (WIS)  20/ 34 (humm           ) |
Willpower    (POW)  30/ 35 (meep           ) |
Charisma     (CHA)  60/ 37 (eek            ) | 
----------------------------------------------------------------------------
Hit points       :  341/ 434 (56.0)
Endurance points : 3441/3141 (34.0)
Spell points     :  341/ 434 (78.0)

You are invisible.
You are dead.
============================================================================

                      Namhas, the male elven warrior
----------------------------------------------------------------------------
     Strength: very good              Hit points: 100%
    Dexterity: very good            Spell points: 100%
      Agility: very good        Endurance points: 100%
 Constitution: very good         
   Sturdiness: very good         Explore percent: 34%
 Intelligence: very good                     Age: 34 (young)      
       Wisdom: very good
    Willpower: very good                    Race: human
     Charisma: very good           Subrace/tribe: moraki

You were born on 17th of Month in year -33.
You are seen as charitable and disciplined.
You have been killed 3 times.
You are unconscius.
You are dead.
--------------------------------------------------------------------------

*/

  buf += sprintf ("^cY%|78s^c0\n", THIS->short());
  buf += "^cp" + repeat_string("-=", 78/2) + "^c0\n";
  buf += sprintf ("     Strength: ^c1%-17s^c0       Hit points: ^c1%d^c0%%\n",
    query_statd(stat[S_STR]), THIS->query_hp() * 100 /
    THIS->query_max_hp());

  buf += sprintf ("    Dexterity: ^c1%-17s^c0     Spell points: ^c1%d^c0%%\n",
    query_statd(stat[S_DEX]), THIS->query_sp() * 100 /
    THIS->query_max_sp());

  buf += sprintf ("      Agility: ^c1%-17s^c0 Endurance points: ^c1%d^c0%%\n",
    query_statd(stat[S_AGI]), THIS->query_ep() * 100 /
    THIS->query_max_ep());

  buf += sprintf (" Constitution: ^c1%-17s^c0\n",
    query_statd(stat[S_CON]));

  buf += sprintf ("   Sturdiness: ^c1%-17s^c0  Explore percent: ^c1%d^c0%%\n",
    query_statd(stat[S_STU]), THIS->query_explore_percent());

  buf += sprintf (" Intelligence: ^c1%-17s^c0              Age: ^c1%d^c0 years\n",
    query_statd(stat[S_INT]), (THIS->query_age()*3/5)/(60*24*28*8));

  buf += sprintf ("       Wisdom: ^c1%-17s^c0\n",
    query_statd(stat[S_WIS]));

  buf += sprintf ("    Willpower: ^c1%-17s^c0             Race: ^c1%s^c0\n",
    query_statd(stat[S_POW]), race);

  buf += sprintf ("     Charisma: ^c1%-17s^c0    Subrace/tribe: ^c1%s^c0\n",
    query_statd(stat[S_CHA]), subrace);

  buf += "\nYou are seen as "+query_alxs(THIS->query_alignx())+" and "+query_alys(THIS->query_aligny())+".\n";
  buf += "You are "+THIS->query_height()+" cm tall and weigh "
      +(THIS->query_weight()/1000)+" kg.\n";

  if (THIS->query_dexp() == 1)
    buf += "You have been killed once.\n";
  else if (THIS->query_dexp() == 2)
    buf += "You have been killed twice.\n";
  else if (THIS->query_dexp())
    buf += "You have been killed "+THIS->query_dexp()+" times.\n";
  else
    buf += "You have never died.\n";

  buf += "You feel ";

  switch (THIS->query_thirst()*100/THIS->query_max_thirst())
    {
      case 25..0:
        buf += "thirsty";
        break;
      default:
        buf += "refreshed";
        break;
    }

  buf += " and ";

  switch (THIS->query_hunger()*100/THIS->query_max_hunger())
    {
      case 25..0:
        buf += "hungry";
        break;
      default:
        buf += "satiated";
        break;
    }

  buf += ".\n";

  if(THIS->query_is_unconscious()) buf += "You are unconscious.\n";
  if(THIS->query_is_dead()) buf += "You are dead.\n";
  buf += "^cp" + repeat_string("-=", 78/2) + "^c0\n";

  pline (buf);

  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Shows your character's complete stats and other information.";
}

query_see_also()
{
  return"exp(1), money(1), religions(1)";
}
query_position()
{
  return POS_RESTING;
}

