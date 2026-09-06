//---------------------------------------------------------------------------
// /p/skills/database.c
//
// The database handling of the skillserver
// (c) Softbyte@OSB 12nov97
// [Softbyte] 12nov97:    Basic skill handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <properties.h>
#include <msgclass.h>
#include <skills.h>

inherit "/lib/config"; // inifile handling

#define TO this_object()

nosave mapping m_classes;
mapping QueryM_Classes() {return m_classes;}

nosave mapping m_internal;
mapping QueryM_Internal() {return m_internal;}

nosave mapping m_skills;
mapping QueryM_Skills() {return m_skills;}


// Guarantees that the internal data arrays are really arrays
private string *CheckArray(mixed s)
{
  if (!s) return ({});
  if (stringp(s))
  {
    if (s=="") return ({});
	return ({s});
  }
  else if (pointerp(s)) return s;
  return ({});
}

// Read in the class information file (classes.ini)
varargs int ReadClasses(string file)
{
string *classes;
string *skills;
string name,info;
mixed v1,s1;
int i;
  m_classes=([]);
  m_internal=([]);
  if (!file) file="classes";

  // Does the inifile exist?
  if (file_size(SK_DATA(file+".ini"))<=0) return 0;

  // Read internal data
  v1=GetKeyValue(SK_DATA(file+".ini"),"internal","room_verbs");
  s1=GetKeyValue(SK_DATA(file+".ini"),"internal","room_skills");
  v1=CheckArray(v1);
  s1=CheckArray(s1);
  m_internal+=(["room_verbs":v1]);
  m_internal+=(["room_skills":s1]);
  
  v1=GetKeyValue(SK_DATA(file+".ini"),"internal","thing_verbs");
  s1=GetKeyValue(SK_DATA(file+".ini"),"internal","thing_skills");
  v1=CheckArray(v1);
  s1=CheckArray(s1);
  m_internal+=(["thing_verbs":v1]);
  m_internal+=(["thing_skills":s1]);
  
  v1=GetKeyValue(SK_DATA(file+".ini"),"internal","living_verbs");
  s1=GetKeyValue(SK_DATA(file+".ini"),"internal","living_skills");
  v1=CheckArray(v1);
  s1=CheckArray(s1);
  m_internal+=(["living_verbs":v1]);
  m_internal+=(["living_skills":s1]);
  
  // classes are all sections but the internal one
  classes=GetSections(SK_DATA(file+".ini"))-({"internal"});
  if (!classes) return 0;
  // loop over all classes
  for (i=0;i<sizeof(classes);i++)
  {
    skills=GetKeyValue(SK_DATA(file+".ini"),classes[i],"skills");
    name=GetKeyValue(SK_DATA(file+".ini"),classes[i],"name");
    info=GetKeyValue(SK_DATA(file+".ini"),classes[i],"info");
    m_classes+=([classes[i]:skills;name;info]);
  }

  return 1;
}

// read the skills for a given class
void ReadSkills(string class)
{
string *skills;
mixed races,guilds;
mixed racestart,racebonus;
string info;
int i;
   if (!class) return 0;
   if (!m_skills) m_skills=([]);

   // Does the inifile exist?
   if (file_size(SK_DATA(class+".ini"))<=0) return 0;

  skills=({string *})TO->QuerySkills(class);  // what are the skills?
  if (!skills) return 0;
  // loop over all skills
  for (i=0;i<sizeof(skills);i++)
  {
    guilds=GetKeyValue(SK_DATA(class+".ini"),skills[i],"guilds");
    races=GetKeyValue(SK_DATA(class+".ini"),skills[i],"races");
    info=GetKeyValue(SK_DATA(class+".ini"),skills[i],"info");
    racestart=GetKeyValue(SK_DATA(class+".ini"),skills[i],"racestart");
    racebonus=GetKeyValue(SK_DATA(class+".ini"),skills[i],"racebonus");
    if (!info) info="No information available.";
    if (!races) races=({"general"});
    if (races=="") races=({});
    if (stringp(races)) races=({races});
    if (!guilds) guilds=({"general"});
    if (guilds=="") guilds=({});
    if (stringp(guilds)) guilds=({guilds});
    if (!racestart || !mappingp(racestart) ) racestart=(["general":0]);
    if (!racebonus || !mappingp(racebonus) ) racebonus=([]);
    m_skills+=([skills[i]:info;guilds;races;racestart;racebonus]);
//   printf("Read skill %s races=%O guilds=%O start=%O bonus=%O\n",
//      skills[i],races,guilds,racestart,racebonus);
  }
 
}


