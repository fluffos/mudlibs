// Tamedhon Mudlib
//
// Temperaturinfos (c) 2024 Gralkor
// Import und Anpassung Aloy

#include <living/life.h>
#include <armour.h>
#include <environment.h>

int rto; // RandomTemperatureOffset
int max_temp;
int min_temp;
int max_temp_offset;
int min_temp_offset;
int max_temp_prot;
int min_temp_prot;
int max_temp_prot_offset;
int min_temp_prot_offset;
int curr_temp;
int curr_temp_offset;


void temp_offset()
{
  rto=random(2)-random(2)+random(2)-random(2)+random(2)-random(2);
  if (rto> 3) rto= 3;
  if (rto<-3) rto=-3;
}

void reset()
{
  temp_offset();
}

void temp_berechnung()
{

  min_temp=this_player()->QueryProp(P_TEMPERATURE_RANGE)[T_RANGE_MIN];
  min_temp_offset=min_temp+random(rto);
  
  max_temp=this_player()->QueryProp(P_TEMPERATURE_RANGE)[T_RANGE_MAX];
  max_temp_offset=max_temp+random(rto);
  
  min_temp_prot=this_player()->QueryProp(P_TOTAL_TEMPERATURE_PROTECTION)[T_COLD_PROT];
  min_temp_prot_offset=min_temp_prot+random(rto)-random(rto);
  
  max_temp_prot=this_player()->QueryProp(P_TOTAL_TEMPERATURE_PROTECTION)[T_HEAT_PROT];
  max_temp_prot_offset=max_temp_prot+random(rto)-random(rto);
  
  curr_temp=environment(this_player())->QueryProp(P_ENVIRONMENT)[ENV_TEMPERATURE];
  curr_temp_offset=curr_temp+random(rto)-random(rto);

}

// Gibt reale (durch Random angepasste) Grenzen der Wohlfuehltemperatur 
// zurueck

int minmax_temp_return()
{
 write(break_string(
 "Aktuell fühlst Du Dich so richtig wohl, wenn die Außentemperatur "
 "zwischen "+min_temp_offset+" und "+max_temp_offset+" Grad Celsius "
 "liegt. "));

 return 1;
}

// Gibt die gefuehlte Aussentemperatur zurueck (real + Random)

int armour_temp()
{
 string str;

 str="Deine Rüstung dürfte vor Kälte ";

 switch(min_temp_prot_offset) {
  case -9999..-1 : str+="gar nicht ";break;
  case     0     : str+="unmerklich ";break;
  case     1..2  : str+="gering ";break;
  case	   3..4  : str+="etwas ";break;
  case     5..6  : str+="besser ";break;
  case     7..8  : str+="gut ";break;
  case     9..14 : str+="sehr gut ";break;
  case    15..20 : str+="wirklich gut ";break;
  case    21..30 : str+="extrem gut ";break;
  case    31..9999: str+="verboten gut ";break;
  default: str+="illegal ";break;
 }
  str+="schützen. ";
  write(break_string(str));

 str="Deine Rüstung dürfte vor Wärme ";

 switch(max_temp_prot_offset) {
  case -9999..-1 : str+="gar nicht ";break;
  case     0     : str+="unmerklich ";break;
  case     1..2  : str+="gering ";break;
  case	   3..4  : str+="etwas ";break;
  case     5..6  : str+="besser ";break;
  case     7..8  : str+="gut ";break;
  case     9..14 : str+="sehr gut ";break;
  case    15..20 : str+="wirklich gut ";break;
  case    21..30 : str+="extrem gut ";break;
  case    31..9999: str+="verboten gut ";break;
  default: str+="illegal ";break;
 }
  str+="schützen. ";
  write(break_string(str));

 return 1;
}

void temp_return()
{
 write(break_string(
 "So wie Du Dich umsiehst und fühlst, dürften es in etwa "+
 curr_temp_offset+" Grad Celsius sein. "));
 if(curr_temp_offset+min_temp_prot_offset<min_temp_offset) {
    write(break_string(
    "Du solltest Dir etwas Warmes anziehen. "));
 }   
 if(curr_temp_offset+max_temp_prot_offset>max_temp_offset) {
    write(break_string(
    "Du wirst ziemlich schwitzen. "));
 }
} 
