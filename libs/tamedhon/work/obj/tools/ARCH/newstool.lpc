/*
** NewsTool
** ---
** 1996/04/04  Woody  Einiges typos bereinigt ("Ok" etc.)
** 1997/12/18  Woody  Bugfix in remover
** 1998/02/11  Feyaria IS_LORD abfrage
*
* $Date: 2001/01/13 13:13:01 $
* $Revision: 1.1 $
* $Log: newstool.c,v $
* Revision 1.1  2001/01/13 13:13:01  Samtpfote
* Initial revision
*
*/

inherit "std/thing";

#include <properties.h>
#include <language.h>
#include <config.h>
#include <news.h>
#include <defines.h>
#include <wizlevels.h>

#define UA PL->_unparsed_args()

void create()
{
  string str;
  if (!clonep(this_object())) return;
  ::create();
  SetProp(P_LONG,"Ein News-Gruppen-Tool.\n\
Befehle: addg      <grname> <ownername>   : Gruppe erzeugen\n\
         removeg   <grname>               : Gruppe löschen\n\
         addw      <grname> <username>    : Schreibberechtigten eintragen\n\
         removew   <grname> <username>    : Schreibberechtigten austragen\n\
         addd      <grname> <username>    : Löschberechtigten eintragen\n\
         removed   <grname> <username>    : Löschberechtigten austragen\n\
         addr      <grname> <username>    : Leseberechtigten eintragen\n\
         remover   <grname> <username>    : Leseberechtigten austragen\n\
         ginfo     <grname>               : Info über Gruppe abfragen\n\
         setexpire <grname> <tage>        : Expiretime setzen\n\
         setmaxmsg <grname> <anz>         : Maxmsg setzen\n\
         setg <grname> <loeschlev> <schreiblev> <leselev> <maxmsg> <expire>\n");
  str=capitalize(((str=getuid(this_player()))[<1]=='s'||str[<1]=='x'||
		  str[<1]=='z')?str+="'":str+="s");
  SetProp(P_SHORT,str+" NewsTool");
  SetProp(P_NAME,str+" NewsTool");
  SetProp(P_GENDER,NEUTER);
  SetProp(P_ARTICLE,0);
  AddId("newstool");
  AddId("newsgruppentool");
  AddId("news-gruppen-tool");
  SetProp(P_AUTOLOADOBJ,1);
  SetProp(P_NODROP,1);
}

void init()
{
  ::init();
  if( !IS_LORD(environment(this_object())))
  {  
    call_out("remove",0);
    return;
  }
  add_action("addg","addg");
  add_action("removeg","removeg");
  add_action("addw","addw");
  add_action("removew","removew");
  add_action("addd","addd");
  add_action("removed","removed");
  add_action("addr","addr");
  add_action("remover","remover");
  add_action("setg","setg");
  add_action("setexpire","setexpire");
  add_action("expire","expire");
  add_action("ginfo","ginfo");
  add_action("setmaxmsg","setmaxmsg");
}

int addr(string str)
{
  mixed *arr;
  string st1, st2;
  
  if ((str=UA)=="" || sscanf(str,"%s %s",st1,st2) !=2){
    write("addr <groupname> <username>\nAnschließend darf der User unabhängig vom Wizlevel die Gruppe lesen.\n");
    return 1;
  }
  
  arr=explode(st2," ")-({""});
  switch ("/secure/news"->AddAllowed(st1,({}),({}),arr)){
    case 0: write("Param err\n"); break;
    case 1: write("Ok.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such board\n"); break;
  }
  return 1;
}

int remover(string str)
{
  mixed *arr;
  string st1, st2;

  if (!(str=UA) || sscanf(str,"%s %s",st1,st2) !=2){
    write("remover <gruppenname> <username>\nDanach darf der User die Gruppe nur noch lesen, wenn sein Wizlevel dies erlaubt.\n");
    return 1;
  }

  arr=explode(st2," ")-({""});
  switch ("/secure/news"->RemoveAllowed(st1,({}),({}),arr)){
    case 0: write("Param err\n"); break;
    case 1: write("Ok.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such board\n"); break;
  }
  return 1;
}

int addd(string str)
{
  mixed *arr;
  string st1, st2;

  if (!(str=UA) || sscanf(str,"%s %s",st1,st2) !=2){
    write("addd <gruppe> <user>\nUser darf Artikel löschen (unabh vom Wizlevel)\n");
    return 1;
  }

  arr=explode(st2," ")-({""});
  switch ("/secure/news"->AddAllowed(st1,arr,({}),({}))){
    case 0: write("Param err\n"); break;
    case 1: write("Ok.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such board\n"); break;
  }
  return 1;
}

int removed(string str)
{
  mixed *arr;
  string st1, st2;

  if (!(str=UA) || sscanf(str,"%s %s",st1,st2) !=2){
    write("removed <gruppe> <user>\nUser darf nur noch Artikel löschen, wenn sein Wizlevel das erlaubt.\n");
    return 1;
  }

  arr=explode(st2," ")-({""});
  switch ("/secure/news"->RemoveAllowed(st1,arr,({}),({}))){
    case 0: write("Param err\n"); break;
    case 1: write("Ok.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such board\n"); break;
  }
  return 1;
}

int addw(string str)
{
  mixed *arr;
  string st1, st2;

  if (!(str=UA) || sscanf(str,"%s %s",st1,st2) !=2){
    write("addw <gruppe> <user>\nUser darf Artikel schreiben (unabh vom Wizlevel)\n");
    return 1;
  }

  arr=explode(st2," ")-({""});
  switch ("/secure/news"->AddAllowed(st1,({}),arr,({}))){
    case 0: write("Param err\n"); break;
    case 1: write("Ok.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such board\n"); break;
  }
  return 1;
}

int removew(string str)
{
  mixed *arr;
  string st1, st2;

  if (!(str=UA) || sscanf(str,"%s %s",st1,st2) !=2){
    write("removew <gruppe> <user>\nUser darf nur noch Artikel schreiben, wenn sein Wizlevel dies erlaubt.\n");
    return 1;
  }

  arr=explode(st2," ")-({""});
  switch ("/secure/news"->RemoveAllowed(st1,({}),arr,({}))){
    case 0: write("Param err\n"); break;
    case 1: write("Ok.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such board\n"); break;
  }
  return 1;
}

int setg(string str)
{
  string name;
  int dlevel, wlevel, rlevel, maxmessages, expire;

  if (!(str=UA) ||
      sscanf(str,"%s %d %d %d %d %d",name,dlevel,wlevel,rlevel,maxmessages,expire) != 6) {
    write("setg <gruppe> <löschlevel> <schreiblevel> <leselevel> <maxmessages> <expire>\nGruppenparameter setzen, Bedeutung (Defaultwerte in Klammern):\n\
    name              : Der Name der Newsgroup\n\
    löschlevel   (20) : Wizlevel, ab dem User Artikel löschen koennen\n\
    schreiblevel ( 0) : Wizlevel, ab dem User Artikel schreiben können\n\
    leselevel    ( 0) : Wizlevel, ab dem User Artikel lesen können\n\
    maxmessages  (40) : Maximale Anzahl Artikel in einer Newsgruppe\n\
    expire       (-1) : Expiretime in Tagen, -1 = nie\n");
    return 1;
  }
  expire=86400*expire;
  switch("/secure/news"->SetGroup(name, dlevel, wlevel, rlevel, maxmessages,expire)){
    case 1: write("Ok.\n"); break;
    case 0: write("Param error.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such group\n"); break;
  }
  return 1;
}

int setexpire(string str)
{
  string name;
  int expire;
  mixed *gr;

  if (!(str=UA)||sscanf(str,"%s %d",name,expire)!=2)
  {
    write("setexpire <gruppe> <tage>\n");
    return 1;
  }
  expire=86400*expire;
  if (!pointerp((gr="/secure/news"->GetGroup(name))))
  {
    write("Get group error\n");
    return 1;
  }
  switch("/secure/news"->SetGroup(name, gr[G_DLEVEL], gr[G_WLEVEL], gr[G_RLEVEL], gr[G_MAX_MSG],expire)){
    case 1: write("Ok.\n"); break;
    case 0: write("Param error.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such group\n"); break;
  }
  return 1;
}

int setmaxmsg(string str)
{
  string name;
  int maxmsg;
  mixed *gr;
  
  if (!(str=UA)||sscanf(str,"%s %d",name,maxmsg)!=2)
  {
    write("setexpire <gruppe> <tage>\n");
    return 1;
  }
  if (!pointerp((gr="/secure/news"->GetGroup(name))))
  {
    write("Get group error\n");
    return 1;
  }
  switch("/secure/news"->SetGroup(name, gr[G_DLEVEL], gr[G_WLEVEL], gr[G_RLEVEL], maxmsg, gr[G_EXPIRE])){
    case 1: write("Ok.\n"); break;
    case 0: write("Param error.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such group\n"); break;
  }
  return 1;
}

int ginfo(string str)
{
  mixed *gr;
  int i;
  
  if (!(str=UA))
  {
    write("Usage: ginfo <gname>\n");
    return 1;
  }
  if (!pointerp((gr="/secure/news"->GetGroup(str))))
  {
    write("Get group error\n");
    return 1;
  }
  for (i=0;i<12;i++)
    printf("%-10s: %O\n",({"Name","Owner","Savefile","Expire","#Deleters",
                      "#Writers","#Readers","DLevel","WLevel",
                      "RLevel","MaxMsg","#Messages"})[i],
	   (i==G_EXPIRE?gr[i]/86400:(pointerp(gr[i])?sizeof(gr[i]):gr[i])));
  return 1;
}
    
int removeg(string str)
{
  if (!(str=UA))
  {
    write("removeg <gruppenname>\nGruppe LOESCHEN.\n");
    return 0;
  }
  switch("/secure/news"->RemoveGroup(str)){
    case 1: write("Ok. Bitte nicht vergessen, das Savefile der Newsgroup von Hand zu entfernen !\n"); break;
    case 0: write("Param error.\n"); break;
    case -1: write("No permission\n"); break;
    case -2: write("No such group"); break;
  }
  return 1;
}

int addg(string str)
{
  string name, owner;

  if (!(str=UA) || sscanf(str,"%s %s",name,owner)!=2)
  {
    write("addg <gruppe> <user>\nGruppe anlegen, <user> wird Besitzer der Gruppe\n");
    return 1;
  }
  switch ("secure/news"->AddGroup(name, owner)){
    case 1: write("Ok.\n"); break;
    case 0: write("Param error.\n"); break;
    case -1: write("No permission.\n"); break;
    case -2: write("Group already there\n"); break;
    case -3: write("Owner not found.\n"); break;
    case -4: write("Savefile already in use.\n"); break;
  }
  return 1;
}
  
int expire()
{
  "/secure/news"->expire_all();
  write("Expiring startet.\n");
  return 1;
}
