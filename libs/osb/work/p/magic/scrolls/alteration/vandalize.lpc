/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) {
  object envi;
  if (!str) str=this_player()->QueryName()+" was here!";
  envi=environment(this_player());
  if (envi->QueryIndoors()==0) {
     write("There is no wall here!\n"); return CAST_FAIL_NOMSG; }
  Message(({"A notice appears on the wall.\n",
     this_player()->QueryName()+" sprays some graffity on the walls.\n"}));
  envi->SetIntLong(envi->QueryIntLong() +
       "There is a graffity on the wall. It reads:\n"+str+"\n");
  return CAST_SUCCESS;
}

int MyFail() {
  object envi;
  envi=environment(this_player());
  if (envi->QueryIndoors()==0) {
     write("There is no wall here!\n"); return CAST_SUCCESS; }
  Message(({"A notice appears on the wall.\n",
     this_player()->QueryName()+" sprays some graffity on the walls.\n"}));
  envi->SetIntLong(envi->QueryIntLong()+
       "There is a graffity on the wall. It reads:\n"+
       this_player()->QueryName()+" failed to cast a spell.\n");
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("notice",ST_CHANGE,10,#'MyCast,"notice",20);
 SetSpellDesc(
 "This spell will write a notice on a wall. There have to be walls\n"+
 "if you want to cast it!\n");
 SetSpellUsage("cast notice <note>\n");
 SetMemoLevel(GC_CONJURER,3);
 SetMemoLevel(GC_ARCHMAGE,3);
 
 SetFailFn(#'MyFail);
}

