//---------------------------------------------------------------------------
// /p/skills/skillserver.c
//
// The basic skill handling of OSB
// (c) Softbyte@OSB 3oct97 
// V1.0:  Basic skill handling and functions
//---------------------------------------------------------------------------

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <daemons.h>
#include <msgclass.h>
#include <skills.h>

inherit "/std/base";
inherit "/p/skills/std/database";       // file handling

#define TO this_object()
#define TP this_player()

// mapping index for classes 
#define M_C_SKILLS        0   // skills
#define M_C_INFO          1   // class info
#define M_C_HELP          2   // class help

// mapping index for skills
#define M_S_INFO          0   // skill info
#define M_S_GUILDS        1   // guilds
#define M_S_RACES         2   // races
#define M_S_RACESTART     3   // mapping on the startvalues (races)
#define M_S_RACEBONUS     4   // mapping on the startboni (races)


// ========================= Protoypes ======================================
string *QueryClasses();
string *QuerySkills(string class);

// ========================= Variables ======================================
mapping skill_to_class;   // fast access on classes


// ========================= General functions ==============================
// ************************      classes     ********************************
//
// Load the classes from the config file if necessary or forced
varargs int LoadClassData(int force)
{
int i,j;
string *classes;
string *skills;
  if (!m_classes || force)
  {
    seteuid(getuid());
    if (!ReadClasses())  // did not read from inifile
    {
       return -1;  
    }
    skill_to_class=([]);
    classes=QueryClasses();
    for (i=0;i<sizeof(classes);i++)
    {
      ReadSkills(classes[i]); // read in the skills
      skills=QuerySkills(classes[i]);
      for (j=0;j<sizeof(skills);j++)
      {
        skill_to_class+=([ skills[j]:classes[i] ]);
      }
    }
  }
  return 1;
}

// Returns the classname of a skill or 0 if not found
string FindClass(string skill)
{
  return skill_to_class[skill];
}

// Returns the information string for a class
string QueryClassInfo(string class)
{
  if (!m_classes || !member(m_classes,class)) return 0;
  return m_classes[class,M_C_INFO]; 
}

// Returns the ihelp text for a class
string QueryClassHelp(string class)
{
  if (!m_classes || !member(m_classes,class)) return 0;
  return m_classes[class,M_C_HELP]; 
}

// Returns an array of all class names
string *QueryClasses()
{
  if (!m_classes) return 0;
  return m_indices(m_classes);
}
// Compat only ... do not use
string *QuerySkillClasses() {return QueryClasses();}

// ************************      skills      ********************************

// Returns all skills of a class
string *QuerySkills(string class)
{
  if (!member(m_classes,class)) return 0;
  return m_classes[class,M_C_SKILLS];
}

varargs int CanLearnSkill(string skill,object who)
{
string *races;
string *guilds;
  if (!who) who=TP;
  if (!who || !skill) return 0;

  races=m_skills[skill,M_S_RACES]||({});
  if (member(races,"general")!=-1) return 1; // general skill
  if (member(races,({string})who->QueryRace())!=-1) return 1; // correct race 

  guilds=m_skills[skill,M_S_GUILDS]||({});
  if (member(guilds,"general")!=-1) return 1; // general skill
  if (member(guilds,({string})who->QueryGuild())!=-1) return 1; // correct guild 

  return 0;
}

// Returns the start value of a skill for a given race 
// if the race has no specifiic start the general start value is taken
varargs int QuerySkillStart(string skill, object who)
{
mapping map;
int value_general,value_race;
  if (!who) who=TP;
  if (!who || !skill) return 0;

  map=m_skills[skill,M_S_RACESTART];
  value_general=map["general"];
  value_race=map[who->QueryRace()];
  if (value_race) return value_race;
  return value_general;
}

// Returns the bonus value of a skill for a given race 
varargs int QuerySkillBonus(string skill, object who)
{
mapping map;
int value_race;
  if (!who) who=TP;
  if (!who || !skill) return 0;

  map=m_skills[skill,M_S_RACEBONUS];
  value_race=map[who->QueryRace()];
  return value_race;
}

// Returns the skill information string
string QuerySkillInfo(string skill)
{
  if (!skill) return 0;
  if (!member(m_skills,skill)) return "No skill.";
  return m_skills[skill,M_S_INFO]||"No information available.";
}

// Returns the maximum value for the skill (depends on race & guild)
int QuerySkillMax(string skill)
{
  if (!skill) return 0;
  if (!member(m_skills,skill)) return 0;
  return 1000;  // TODO !!!!
}

// Is the skill contained in the skill database ?
int IsSkill(string skill)
{
  if (!skill) return 0;
  if (!member(m_skills,skill)) return 0;
  return 1;
}


// ========================= Skill usage functions ==========================
// Main skill usage...DUMMY only....needs improvement
//
int UseSkill(object who,string skill,int difficulty)
{
int dice1,dice2;
int pl_skill;
int result;

  pl_skill=({int})who->QuerySkill(skill);


  dice1=random(pl_skill)+1;
  dice2=random(difficulty)+1;


  if (dice2<dice1)             // Success
  {
    result=(1000*dice2)/dice1;
  }
  else                         // Failure
  {
    result=(-1000*dice1)/dice2;
  }
  return result;
}

// Like UseSkill but additional properties, like learning and so on can
// be used ... Might vanish...do not use !!!!!!!!!!
varargs int ApplySkill(object who,string skill,int difficulty,mixed props)
{
int value;
  value=UseSkill(who,skill,difficulty);
  return value;
}

// ========================= Room/Obj functions =============================

// Checks whether player can use the skill
string CannotUseSkill(string skill,object who,int difficulty, string id_str,
                      string extra_str)
{
  return 0;
}
string QueryFailString(string skill,object who)
{
  // TODO aus ini file
  if (skill==SK_SEARCH) return "You search but find nothing.\n";
  return "You fail in "+skill+".\n";
}

// ========================= Action handling ================================
// Returns the verbs added via add_action to std/thing
string *QueryThingVerbs()
{
  if (!m_internal) return ({});
  return m_internal["thing_verbs"]||({});
}

// Returns the verbs added via add_action to std/living
string *QueryLivingVerbs()
{
  if (!m_internal) return ({});
  return m_internal["living_verbs"]||({});
}

// Returns the verbs added via add_action to std/room
//  e.g. return ({"climb","swim","jump","search"});
string *QueryRoomVerbs()
{
  if (!m_internal) return ({});
  return m_internal["room_verbs"]||({});
}
// Returns the SK_XXXX for a given verb
// TODO: Do this automatically when loading the skill
string VerbToSkill(string skill_verb)
{
string *ids;
int idx;

  if (!m_internal) return 0;

  // Is it a room action?
  ids=QueryRoomVerbs();
  idx=member(ids, skill_verb);
  if (idx>=0)
  {
    ids=m_internal["room_skills"];
	if (!ids || sizeof(ids)-1 < idx)
	{
	  raise_error("Skillserver: Verb-skill matching error for rooms.\n");
	  return 0;
	}
	return ids[idx];
  }

  // Is it a thing action?
  ids=QueryThingVerbs();
  idx=member(ids, skill_verb);
  if (idx>=0)
  {
    ids=m_internal["thing_skills"];
	if (!ids || sizeof(ids)-1 < idx)
	{
	  raise_error("Skillserver: Verb-skill matching error for things.\n");
	  return 0;
	}
	return ids[idx];
  }

  // Is it a living action?
  ids=QueryLivingVerbs();
  idx=member(ids, skill_verb);
  if (idx>=0)
  {
    ids=m_internal["living_skills"];
	if (!ids || sizeof(ids)-1 < idx)
	{
	  raise_error("Skillserver: Verb-skill matching error for livings.\n");
	  return 0;
	}
	return ids[idx];
  }

  raise_error("Skillserver: Skill not found corresponding to action.\n");
  return 0;

}


// ========================= Auxiliary functions ============================
varargs string ValueToString(int skill,int flag)
{
string s_end;
  if (flag & 1)     // Add the dezimal number as well 
  {
    s_end="("+to_string(skill/10)+"%)";
  }

  switch(skill)
  {
     case 1000:
      return "absolutely perfect"+s_end;
     case 950..999:
      return "perfect"+s_end;
     case 880..949:
      return "nearly perfect"+s_end;
     case 800..879:
      return "very good"+s_end;
     case 700..799:
      return "good"+s_end;
     case 600..699:
     return "quite good"+s_end;
     case 500..599:
      return "good average"+s_end;
     case 400..499:
      return "average"+s_end;
     case 300..399:
      return "ordinary"+s_end;
     case 200..299:
      return "quite ordinary"+s_end;
     case 150..199:
      return "very ordinary"+s_end;
     case 100..149:
      return "bad"+s_end;
     case 40..99:
      return "very bad"+s_end;
     case 0..39:
      return "hopeless"+s_end;
     default:
      return "unknown"+s_end;
  }
  return "unknown"+s_end;
}

  

// ========================= Create function ================================
void create()
{
  ::create();
  if (is_clone())
  {
    destruct(TO);
    return;
  }
  seteuid(getuid());
  LoadClassData(0);
}


// Forwards a call to "fun" to the skill module "module" with the given
// paramters
// TODO: Error checking
varargs mixed RelayCall(string module, string fun, mixed p1, mixed p2,
                        mixed p3, mixed p4,
                        mixed p5, mixed p6, mixed p7, mixed p8)
{
  mixed res;
  string class;
  object ob;

  ob=find_player("softbyte");
  if (ob && ({int})ob->Query("Debug")) tell_object(ob,
    sprintf("RelayCall: %s %s %O %O %O %O\n",module,fun,p1,p2,p3,p4));

  class=FindClass(module);
  // call /p/skills/modules/<class>/<skill>
  res=({mixed})call_other(SK_MOD(class+"/"+module),fun,p1,p2,p3,p4,p5,p6,p7,p8);
  return res;
}
