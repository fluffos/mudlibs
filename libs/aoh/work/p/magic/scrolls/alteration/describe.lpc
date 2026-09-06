/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
string desc;

int MyCast(string str)
{
  string des;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  write("Type description line by line. Give '.' to stop.\n");
  write("#");
  desc = "";
  input_to("get_desc");
  return CAST_SUCCESS;
}

int get_desc(string str) {
  object book;
  if (str == "**" || str == ".") {
     write("You change your own look.\n");
     say(this_player()->QueryName()+" changed the way "+
         this_player()->QueryPronoun()+" looks.\n");
     if (!book = present("spellbook", this_player())) 
        this_player()->SetLong(desc);
     else book->SetExtralook(desc);
     remove();
     return 1;
  }
  if (str && str!= "") desc += str+"\n";
  write("#");
  input_to("get_desc");
}

int MyFail() {
  string des, race, x;
  race=this_player()->QueryRace()||"beeing";
  x="That "+race+" is not able to cast spells!\n";
  des=this_player()->QueryName()+" is "+add_a(race)+".\n"+x+"\n";
  this_player()->SetLong(des);
  return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("describe",ST_CHANGE,175,#'MyCast,"change description",15);
 SetSpellDesc(
"This spell will allow you to change the way you look.\n\
After you casted the spell, type the wanted description line by line.\n\
Type '.' and return when finished.\n");
 SetSpellUsage("cast describe\n");
 SetMemoLevel(GC_SORCERER,7);
 SetMemoLevel(GC_ARCHMAGE,7);
 SetFailFn(#'MyFail);

 NoMemorize();
 NoDestruct();
}

