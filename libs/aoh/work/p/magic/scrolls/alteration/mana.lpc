/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object gem;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  gem=present("harmonic gem", this_player());
  if (!gem) { write("You don't have a gem.\n"); return CAST_FAIL_NOMSG; }
  if (gem->QueryFull()) {
      write("The gem is not empty.\n");
      return CAST_FAIL_NOMSG;
    }
/* message is already in the gem - softbyte
  Message( ({"You transfer magic energy into the harmonic gem.\n",
    add_gen(this_player()->QueryName())+
     " harmonic gem glows as it is refilled with magic energy.\n"}) );
*/
  gem->RefillGem();
  return CAST_SUCCESS;
}

int MyFail() 
{
    Message(({"Pooof...Nothing happens.\n",
       "Pooof.\n"}) );
    return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("mana",ST_HEAL,65,#'MyCast,"restore mana",25);
 SetSpellDesc(
"If you have an empty harmonic gem you can refill it using this spell.\n");
 SetSpellUsage("cast mana\n");
 SetMemoLevel(GC_SORCERER,11);
 SetMemoLevel(GC_ARCHMAGE,11);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

