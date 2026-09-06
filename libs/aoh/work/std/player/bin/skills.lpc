/*
	A basic output screen for standard skills.  Most of this
        is just for example, to get something to test with.
        Change is inevitable.

	Still need a way to include specific guild skills.  This
 	file simply covers the utmost basics.

	July 1997

        V1.1: Softbyte     05oct97
        [Softbyte] 12nov97 Slight output changes
        [Softbyte] 19dec97 Suppressed zero skill output
*/

#include <properties.h>
#include <daemons.h>
#include <msgclass.h>
#include <skills.h>

#define TP this_player()
#define SLIB "/lib/string"


private string skillfun( string skill ) {
  int val;

  val = ({int})TP->QuerySkill( skill );
  if (val==0) return sprintf("%15.15s: unknown",capitalize(skill));
  return sprintf("%15.15s: %-d",capitalize(skill),val);
}
private string simple( string class ) {

  return sprintf("----- %s (%s)",
        capitalize(class),({string})SKILLSERVER->QueryClassInfo(class));
}



public int main( string arg ) {
  string s;
  string * classes;
  string * s_classes;
  string * skills;
  string * s_skills;
  int i,j;

  seteuid(getuid());
  if (arg) arg=lower_case(arg);

  if (arg=="all" || arg=="full")
    arg=0;

  classes = ({string *})SKILLSERVER->QueryClasses();
  s_classes = map( classes, #'simple /*'*/ );

  s="";
  s+=({string})SLIB->cadjust(" "+({string})TP->QueryShort()+"'s skills ",75,"-=")+"\n";

  for (i=0;i<sizeof(classes);i++)
  {

    if (arg && arg!=classes[i]) continue; // show only a certain class

    s+=s_classes[i]+"\n";
    skills = ({string *})SKILLSERVER->QuerySkills(classes[i]);
	if (!skills || !sizeof(skills)) continue;
    s_skills=map( skills, #'skillfun /*'*/ );
    for (j=0;j<sizeof(skills);j+=3)
    {
      if (j+2<sizeof(skills))
          s+=sprintf("%-25.25s %-25.25s %-25.25s\n",
             s_skills[j],s_skills[j+1],s_skills[j+2]);
      else if (j+1<sizeof(skills))
          s+=sprintf("%-25.25s %-25.25s\n",s_skills[j],s_skills[j+1]);
      else
          s+=sprintf("%-25.25s\n",s_skills[j]);
    }
    if (i+1<sizeof(classes)) s+="\n";
  }
  s+=({string})SLIB->mkstr(75,"-=")+"\n";
  msg_write( CMSG_GENERIC|MMSG_MORE,s);
  seteuid(0);

  return 1;
}
