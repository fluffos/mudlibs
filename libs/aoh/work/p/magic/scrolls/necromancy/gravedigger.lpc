/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int CheckGraveyard() {
    object env;
    string *lines, *matches;
    env = environment(this_player());
    if (!env) return 0;
    if (!env->QueryIntLong() || !stringp(env->QueryIntLong())) return 0;
    lines = explode(env->QueryIntLong(), "\n");
    matches = regexp(lines, ".*graveyard.*");
    return (sizeof(matches));
}

int MyCast(string str)
{
object wolf, corp;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("zombie", environment(this_player()))) {
     write("There is already one zombie here!\n");
     return CAST_FAIL_NOMSG; 
  }
  if (!CheckGraveyard()) {
     write("As far as I can tell you're not on a graveyard!\n"); 
     return CAST_FAIL_NOMSG;
  }
  Message( ({"You conjure a zombie from a grave.\n",
     this_player()->QueryName()+" revives a zombie from a grave.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "zombie");
  call_other(wolf,"move",environment(this_player()));
  this_player()->command_me("own zombie");
  return CAST_SUCCESS;
}

int MyFail()
{
 int dam;
   if (Repulse(this_player(),this_player(),DT_PSYCHO)) return CAST_REPULSE;
   Message(({"A giant boot appears and kicks you very hard.\n",
       "A giant boot appears and kicks " + 
       this_player()->QueryName() + " very hard.\n"}) );
   dam=25+random(60);
   dam=this_player()->Defend(ModifyMagic(dam),DT_PSYCHO,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("digger",ST_SUMMON,130,#'MyCast,"grave digger",80);
 SetSpellDesc(
"This spell will allow you to raise a corpse from a grave.\n"+
"You'll have to be on a graveyard to cast it.\n"+
"It will cost you some spellpoints to keep the zombie alive.\n"+
"You can give it a name with the 'name' command.\n"+
"'hit' it if you don't want it any longer.\n");
 SetSpellUsage("cast digger\n");
 SetMemoLevel(GC_NECROMANCER,17);
 SetMemoLevel(GC_ARCHMAGE,17);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

