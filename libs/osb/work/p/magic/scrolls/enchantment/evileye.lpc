/* Evil eye=Monster attacks its friends written by Softbyte 4/6/95 */

#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "/obj/scroll";

#define TP this_player()

int killMe (object who)
{
 if (who && who->QueryIsNPC() ) who->Kill(TP);
 return(0);
}
int MyFail() 
{
     if (Repulse(TP,TP)) return CAST_REPULSE;
     Message(({"Everybody attacks you now !\n",
         TP->QueryName()+" is attacked by everybody.\n"}));
     filter(all_inventory(environment(TP)),#'killMe);   
     return CAST_SUCCESS;
}
int MyCast(string str) 
{
object whom,ob;
object *myenemies,*oldenemies;
int dura,ch,i;
string name;

  if (!str) whom=GetEnemy(TP);
  else whom=present(str,environment(TP));
  if (whom==TP) return MyFail();
  if (!whom) {write("I can't see that monster here!\n"); return CAST_FAIL_NOMSG; }
  if (!whom->QueryIsNPC())
  {
    write("You cannot cast this spell on "+str+".\n");
    return CAST_FAIL_NOMSG;
  }
  if (Repulse(whom,TP)) return CAST_REPULSE;

  ch=TP->QueryInt()-whom->QueryLevel();
  ch+=10;            /* shift -10..10 to 0..20 */    
  ch+=random(5) ;    /* give 'em a chance */
  name=whom->QueryName()||whom->QueryShort()||"someone";
  name=capitalize(name);
  if (random(20)>ch)
  {
    Message( ({name+" just laughs about your attempt.\n",
            name+" laughs about "+add_gen(TP->QueryName())+" attempt.\n"}) );
    return CAST_SUCCESS;
  }
  Message(({name+" starts to attack your enemies for a while.\n",
      TP->QueryName()+" gets help from "+name+".\n"}) );

  oldenemies=whom->QueryEnemies() || ({});
  myenemies=TP->QueryEnemies() || ({});
  myenemies-=({whom});   /* TP and itself will not attack itself */
  for (i=sizeof(oldenemies);i--;)
    whom->RemoveEnemy(oldenemies[i]);
  for (i=sizeof(myenemies);i--;)
    whom->AddEnemy(myenemies[i]);
  TP->RemoveEnemy(whom);

  dura=3*TP->QueryAttr("Sta")+TP->QueryAttr("Wis")+TP->QueryInt();
  dura=20+3*random(dura);
 
  ob=clone_object(MAGIC_OBJ_DIR "evilmaster");
  if (ob) ob->SetEvilEye(whom,dura,oldenemies);
  if (ob) ob->move(TP,M_SILENT);
  return CAST_SUCCESS;
}


create()
{
 ::create();
 AddSpell("evileye",ST_INFLUENCE,70,#'MyCast,"evil eye",60);
 SetSpellDesc(
"This spell will confuse a monster so that it attacks your enemies\n"+
"for a while. How long and which monster can be confused\n"+
"depends on your Int and Sta.\n");
 SetSpellUsage("cast evileye <monster>\n");
 SetMemoLevel(GC_SORCERER,4);
 SetMemoLevel(GC_ARCHMAGE,4);
    /* Scroll itself is massivily dependend on PLstats */
 SetFailFn(#'MyFail);
}

