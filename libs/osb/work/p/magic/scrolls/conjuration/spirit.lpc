/* Written by Softbyte August 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
int num;
object wolf;
  if (str)
  {
    if (str!=this_player()->QueryName())
       write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("spirit", environment(this_player()))) {
     write("There is already a spirit here!\n");
     return CAST_FAIL_NOMSG; 
  }
  num=this_player()->QueryAttr("Sta");
  num=num/2+random(num/2);
  num=num/4+1;
  
  Message( ({"You concentrate your mental forces and "+num+" small spirits materialize.\n",
     this_player()->QueryName()+" concentrates and some small spirits appear.\n"}) );
  seteuid(getuid(this_object()));
  while(num>0)
  {
    wolf=clone_object(MAGIC_NPC_DIR "spirit");
    wolf->move(environment(this_player()));
    wolf->Own(this_player());
    num--;
  }
  return CAST_SUCCESS;
}
int MyFail()
{
object wolf;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({"You concentrate your mental forces and a small spirits materialize.\n",
     this_player()->QueryName()+" concentrates and a small spirits appear.\n"}) );
  seteuid(getuid(this_object()));
  wolf=clone_object(MAGIC_NPC_DIR "spirit");
  wolf->move(environment(this_player()));
  wolf->Kill(this_player());
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("spirit",ST_SUMMON,130,#'MyCast,"conjure spirit",40);
 SetSpellDesc(
"This spell will allow you to summon a couple of small spirits.\n"+
"How many spirits will appear will depend on your stamina.\n"+
"The spirits will attack your enemies and they will vanish\n"+
"if all your enemies are dead or you leave the room.\n");
 SetSpellUsage("cast spirit\n");
 SetMemoLevel(GC_CONJURER,15);
 SetMemoLevel(GC_ARCHMAGE,15);
 
 SetFailFn(#'MyFail);

}

