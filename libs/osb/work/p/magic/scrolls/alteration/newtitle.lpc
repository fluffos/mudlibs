/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";
#define MAX_TITLE_LEN  80

int MyCast(string str) 
{
  if (!str || strlen(str)>MAX_TITLE_LEN) {
     write("That's no title.\n");
     return CAST_FAIL_NOMSG;
  }

  this_player()->SetTitle(str);
  Message(({"You change your title.\n",
            this_player()->QueryName()+" makes some magical gestures.\n"}) );
  return CAST_SUCCESS;
}

int MyFail() {
  this_player()->SetTitle("the one who is too stupid to change titles");
  Message(({"You change your title.\n",
            this_player()->QueryName()+" makes some magical gestures.\n"}) );
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("title",ST_CHANGE,175,#'MyCast,"change title",10);
 SetSpellDesc("This spell allow you to change your title.\n");
 SetSpellUsage("cast title <new title>\n");
 SetMemoLevel(GC_SORCERER,14);
 SetMemoLevel(GC_ARCHMAGE,14);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

