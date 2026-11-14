//** Einige Grundfunktionen die an vielen Stellen benoetigt werden *********//
//-- Int-Begrenzer -----------------------------------------------------------
int limit(int i, int min, int max)
{
  if(i<min) {i=min;}
  if(i>max) {i=max;}
  return i;
}

#include "./functions_extern.h"

//-- GildenZugehoerigkeit ----------------------------------------------------
int IsRanger(object pl) 
{
  if(pl->QueryProp(P_GUILD)==GUILD) { return 1; }
  return 0;
}

//--Gesinnung-----------------------------------------------------------------
string GetAlign(int i)
{
  string align;
  
  if(!intp(i)) i = 0;
  
  if(i> 999) {i=1000;}
  if(i< -999) {i= -1000;}
  switch(i) {
    case -1000:         align="Satanisch";         break;
    case  -999 .. -801: align="Teuflisch";         break;
    case  -800 .. -601: align="Extrem boese";      break;
    case  -600 .. -401: align="Verdorben";         break;
    case  -400 .. -201: align="Boese";             break;
    case  -200 ..  -51: align="Durchtrieben";      break;
    case   -50 ..   50: align="Neutral";           break;
    case    51 ..  200: align="Freundlich";        break;
    case   201 ..  400: align="Hilfsbereit";       break;
    case   401 ..  600: align="Gut";               break;
    case   601 ..  800: align="Sehr gut";          break;
    case   801 ..  999: align="Fast Heilig";       break;
    default:            align="Heilig";            break; }
   
  return align;
}

//-- (Kampf)Begleiter ermitteln (Summons/Pets) -------------------------------
mixed FindHelpPet(object owner)
{
  mixed env, ob;
  
  if(!objectp(env=ENV(owner))) { return 0; }
  if(objectp(ob=present("\n"+getuid(owner)+"_ranger_pet",env))) { return ob; }
  //if(objectp(ob=present(SUMMON_ID, env)) && (ob->get_owner() == owner) ) 
  { return ob; }
  return 0;
}

//-- Log fuer jedes Member ---------------------------------------------------
void log_member(mixed caster, string msg)
{
  int i;
  mixed str;
  
  if(objectp(caster)) { caster=getuid(caster); }
  if(!stringp(caster)) { return; }  
  caster=lower_case(caster);
  str=explode(break_string(msg, 47), "\n");
  for(i=0;i<sizeof(str);i++)
  { write_file(MEMBERS_LOG+caster+".log", 
               sprintf("%-27s | %s\n", (i?"":dtime(time())), str[i]) ); }
  return;
}
//**************************************************************************//