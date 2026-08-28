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

string palkki(int orig,int max) {
  int a,b,bb;
  int perc;
  string str;
  perc = ((orig*100) / max);
  b = perc/3;
  bb = perc;
  if(b > 33) b = 33;
  str = " [";
  for(a = 0; a < b; a++) str += "#";
  b = 33 - b;
  for(a = 0;a < b; a++)  str += ".";
  str += "]";
  return str;
}

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

*/

  buf += "Statistics on: "+THIS->short()+"\n";
  buf += repeat_string("=", 78) + "\n";
  buf += sprintf ("Strength     (STR) %|17s | Race          : %s\n",
    query_statd(stat[S_STR]), race);
  buf += sprintf ("Dexterity    (DEX) %|17s | Subrace/tribe : %s\n",
    query_statd(stat[S_DEX]), subrace);
  buf += sprintf ("Agility      (AGI) %|17s | Alignment     : %s\n",
    query_statd(stat[S_AGI]), "");
  buf += sprintf ("Constitution (CON) %|17s | Title         : %s\n",
    query_statd(stat[S_CON]), title);
  buf += sprintf ("Sturdiness   (STU) %|17s | Gender        : %s\n",
    query_statd(stat[S_STU]), g);
  buf += sprintf ("Intelligence (INT) %|17s | Carried money : %d gps\n",
    query_statd(stat[S_INT]), THIS->query_money());
  buf += sprintf ("Wisdom       (WIS) %|17s | Explore count : %d rooms\n",
    query_statd(stat[S_WIS]), THIS->query_explore());
  buf += sprintf ("Willpower    (POW) %|17s | Age           : %d years\n",
    query_statd(stat[S_POW]),(age*3/5)/(60*24*28*8));
  buf += sprintf ("Charisma     (CHA) %|17s |\n",
    query_statd(stat[S_CHA]));
  buf += repeat_string("-", 78) + "\n";

  buf += sprintf("%+6s",""+sprintf ("Hit points       : %3.1f%% ",
    THIS->query_hp() * 100.0 / THIS->query_max_hp()));
  buf += palkki(THIS->query_hp(),THIS->query_max_hp())+"\n";

  buf += sprintf("%+6s",""+sprintf ("Spell points     : %3.1f%% ",
    THIS->query_sp() * 100.0 /THIS->query_max_sp()));
  buf += palkki(THIS->query_sp(),THIS->query_max_sp())+"\n";

  buf += sprintf("%+6s",""+sprintf ("Endurance points : %3.1f%% ",
    THIS->query_ep() *100.0/THIS->query_max_ep()));
  buf += palkki(THIS->query_ep(),THIS->query_max_ep())+"\n";

  buf += "\nYou are "+query_alxs(THIS->query_alignx())+" and "+query_alys(THIS->query_aligny())+".\n";
  buf += repeat_string("=", 78) + "\n";

  pline (buf);

  return 1;
}
