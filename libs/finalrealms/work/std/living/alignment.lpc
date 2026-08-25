/* The "new" alignment system.
 * I am putting all alignment stuff here instead of that over poputaled player.
 * And the meaningof this is to make the whole alignment system more usable.
 * Baldrick, april '94
 * The really difficult stuff will be to implement workable
 * lawful / chaotic stuff, and test on it.
 *
 * Added Taniwha 1995 and God status, thats so we have somewhere to tag players
 * who say kill representatives of the gods etc.
 */
#include "alignment.h"
#define NOGOD "none"
nosave string *gods = ({NOGOD,"baldrick","timion","raisa","taniwha","hokemj","cyrcia","radix","ducky","grimbrand"});
string mygod;
int *godalign;
int alignment;
string playerset_alname;
int playerset_al;
int ethics;

string query_align_name();
// Tanihwa 1995 make it harder to get a wanted alignment VERY high
// but a LOT easier to change it as well
protected int aligna(int old,int adj)
{
    int newa,i;
    if( !old ) return adj;
    i = (adj > 0) ? adj : -adj;
   if ( (old*adj) > 0 ) newa = old + (adj/10);   // same sign
    else newa = old + adj;  // opposite sign or zero
    return newa;
}

int *query_godalign()
{
   return godalign;
}
string query_deity_string(int i)
{
   if(i < -1000000) i = -999999;
   else if(i > 1000000) i = 999999;
    switch(i)
    {
        case -100000000 .. -5001:   return " a chosen one of ";
        case -5000    .. -2001:   return " treasured by ";
        case -2000    .. -1001:   return " favoured by ";
        case -1000    .. -201:    return " liked by ";
        case -200     .. 200:     return " neutral to ";
        case 201      .. 1000:    return " disliked by ";
        case 1001     .. 2000:    return " out of favour with ";
        case 2001     .. 5000:    return " hated by ";
        case 5001     .. 100000000: return " an avowed enemy of ";
        default: return " confuses the hell out of ";
    }
}

string query_deity()
{
    if(!mygod) return NOGOD;
    if( member_array(mygod,gods) == -1) return NOGOD;
    else return mygod;
}
int clear_deity()
{
    mygod = 0;
}
// Like this to save other tests, once set, can't be changed easilly
int set_deity(string str)
{
    if(!str) return 0;
    if(mygod && mygod != NOGOD) return 0;  // Flode added check for NOGOD
    if(member_array(str,gods) > -1)
    {
        mygod = str;
        return 1;
    }
    return 0;
}
protected int queryg()
{
   int i,j;
   i = sizeof(gods);
   j =sizeof(godalign);
   //write("Gods = "+i+" godalign = "+j+"\n");
   if(i != j) godalign = allocate(i);
   return 1;
}
void set_deity_status(int i,string deity)
{
  int j;
  if(!deity) return;
   queryg();
  j = member_array(deity,gods);
  if(j > -1) godalign[j] = i;
  return;
}

int adjust_deity_status(int i,string deity)
{
  int j,align;
  if(!deity) return 0;
   queryg();
  j = member_array(deity,gods);
  if( j == -1) return 0;
   godalign[j] = aligna(godalign[j],i);
   return godalign[j];
}
// yes - is GOOD as for everything else
int query_deity_status(string deity)
{
   int j;
    if(!deity) return 0;
   queryg();
    j = member_array(deity,gods);
    if(j > -1) return godalign[j];
    return 0;
}
// Taniwha 1995, spread it out some
// Prototypes:
int set_playerset_alname(string goof);

void set_align(int i) 
  {
  if(interactive(this_object())&&i<0) i = 0;
  else alignment = i;
  return;
}

void reverse_align() {
  string rev_al, al_str;
  int *al_array,i;
  int time_on,reset_time;
  al_str = query_align_name();
  switch(al_str) {
    case "angelic":
    case "extremely good":
    case "very good":
    case "good":
         rev_al = "evil"; break;
    case "neutral": break;
    case "evil":
    case "very evil":
    case "extremely evil":
    case "diabolical":
         rev_al = "good"; break;
    default: break;
  }
  if(!rev_al) return;

  time_on = this_object()->query_time_on();
  reset_time = this_object()->query_property("alignment_reset2");
  al_array = ALIGN_HAND->query_align_array();
  for(i=0;i<sizeof(al_array);i++) {
    set_align(al_array[i]*(time_on-reset_time)/(-TDIV));
    if(query_align_name() == rev_al) return;
  }
}
    

int adjust_align(int i)
  {
    alignment += i;
  if(alignment<0&&interactive(this_object())) alignment=0;
// aligna isn't needed anymore
    ALIGN_HAND->check_player_al(this_object());
}                        
int query_align() {
  if(interactive(this_object()) || this_object()->query_henchman())
    return ALIGN_HAND->curved_align_num(this_object());
  return alignment;
}

int query_alignment() {
  if(interactive(this_object()) || this_object()->query_henchman())
    return ALIGN_HAND->curved_align_num(this_object());
  return alignment;
}

int query_align_int() { return alignment; }

// Taniwha 1995, spread it out some
string query_align_name() {
  if(alignment < -MAX_ALIGN_INT) alignment = 1-MAX_ALIGN_INT;
  else if(alignment > MAX_ALIGN_INT) alignment = MAX_ALIGN_INT-1;
  if(interactive(this_object()) || this_object()->query_henchman())
    return ALIGN_HAND->curved_align_string(this_object());
// this is now basically usefull for know alignment... Anirudh
  switch (alignment)
    {
    case -MAX_ALIGN_INT .. -100: return "angelic";
    case -99 .. -95   : return "extremely good";
    case -94 .. -70   : return "very good";
    case -69 .. -20    : return "good";
    case -19 .. 0      : return "neutral";
    case 1 .. 69      : return "evil";
    case 70 .. 94     : return "very evil";
    case 95 .. 99     : return "extremely evil";
    case 100 .. MAX_ALIGN_INT  : return "diabolical";
    }
} /* Query alias Name */
// Taniwha 1995 Lawful/Chaotic stuff
void set_ethics(int i)
{
  ethics = i;
  return;
}

int adjust_ethics(int i)
{
   return (ethics = aligna(ethics,i));
}

int query_ethics()
  {
  return ethics;
}

string query_ethical_name()
  {
   if(ethics < -1000000) ethics = -999999;
   else if(ethics > 1000000) ethics = 999999;
  switch (ethics)
    {
    case -1000000 .. -5001: return "Born again righteous";
    case -5000 .. -2001   : return "extremely lawful";
    case -2000 .. -1001   : return "very lawful";
    case -1000 .. -201    : return "lawful";
    case -200 .. 200      : return "neutral";
    case 201 .. 1000      : return "chaotic";
    case 1001 .. 2000     : return "very chaotic";
    case 2001 .. 5000     : return "extremely chaotic";
    case 5001 .. 1000000  : return "Chaos incarnate";
    }
}

int do_alsetting()
  {
  if (playerset_alname)
   {
    notify_fail("Alignment already set, too late!\n");
    return 0;
    } 
 write ("Possible alignments:\n  - evil (e)\n  - neutral (n)\n  - good (g)\n" 
         "Enter choice:");
  input_to("set_playerset_alname");
  return 1;
}

int set_playerset_alname(string goof)
  {
  switch (goof)
    { 
    case "e":
    case "evil":
      playerset_alname = "evil"; 
      playerset_al = 250; 
      break;

    case "n":
    case "neutral":
      playerset_alname = "neutral"; 
      playerset_al = 0; 
      break;

    case "g":
    case "good":
      playerset_alname = "good"; 
      playerset_al = -250; 
      break;
    
    default:
      write ("Not set correctly, try once more:");
      input_to("set_playerset_alname");
    }
  write("Player Alignment set to "+playerset_alname+".\n");
  alignment = playerset_al;
  return 1;
}

string query_playerset_alname()
  {
  return playerset_alname;
} 

/* This is the nice part.. it reutrs 1 if the player plays his alignment..
 * Maybe not needed here, but nice to have..
 */
int compare_alignment(string compstr)
  {
  string name;

  name = query_align_name();
  if (compstr == name || compstr == name[5..8])
    return 1;
  return 0; 
}
