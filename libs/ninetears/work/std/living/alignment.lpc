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
#define NOGOD "ninguna"
nosave string *gods = ({NOGOD,"tyrael","barthleby","jade"});
string mygod;
int *godalign;
int *alineamiento=({0,0});
int alignment;

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
        case -100000000 .. -5001:   return " un elegido de ";
        case -5000    .. -2001:   return " amado por ";
        case -2000    .. -1001:   return " favorecido por ";
        case -1000    .. -201:    return " gustado por ";
        case -200     .. 200:     return " neutral para ";
        case 201      .. 1000:    return " no gustado por ";
        case 1001     .. 2000:    return " desgraciado para ";
        case 2001     .. 5000:    return " odiado por ";
        case 5001     .. 100000000: return " un terrible enemigo de ";
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
    if(mygod && capitalize(mygod) != capitalize(NOGOD)) return 0;  // Flode added check for NOGOD
    if(member_array(str,gods) > -1)
    {
        mygod = str;
        return 1;
    }
	tell_object(TP, "Ha ocurrido un error, notificalo como un bug.\n");
    return 0;
}
int queryg()
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
  int j;
  if(!deity) return 0;
   queryg();
  j = member_array(deity,gods);
  if( j == -1) return 0;
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
// Vilat 27.09.2002
int set_alineamiento(int a,int b) {
  if(a<-1||a>1||b<-1||b>1) return 0;
 alineamiento=({a,b});
 return 1;
 }

int *query_alineamiento() { return alineamiento; }

string query_alineamiento_name() {
 string ali;
 switch (alineamiento[0]) {
  case 1:ali="Legal ";break;
  case 0:ali="Neutral ";break;
  case -1:ali="Caotico ";break;
  default:ali="Bug ";
  }
 switch (alineamiento[1]) {
  case 1:ali+="Bueno";break;
  case -1:ali+="Malvado";break;
  case 0:
  if(!alineamiento[0]) ali+="Absoluto";
  else ali+="Neutral";
  break;
default:ali+="Bug";
  }
 return ali;
 }
