/* /players/shakedbeer/tools/whatsnew.c */
/* von Samtpfote ans Turithil angepasst */

inherit "/std/thing";

#include <properties.h>
#include <language.h>

#define SAVEDIR  "/p/service/querolin/tools/whatsnew/"
#define WNMASTER "/p/service/querolin/tools/wnmaster"

string envuid();
int    date2sec(string str);

mapping dirs;

void create()
{
  ::create();
  SetProp(P_SHORT, "Ein WhatsNew-Tool");
  SetProp(P_LONG, 
    "Das WhatsNew-Tool beherrscht folgende Befehle:\n"
  + "- whatsnew        : Zeigt alle neuen Files seit dem letzten 'whatsnew'.\n"
  + "- whatsnew <datum>: Zeigt alle neuen Files seit dem Datum. [ttmmjjjj]\n"
  + "- showagain       : Zeigt das Suchergebnis erneut. (ANTI-LAG)\n"
  + "- addpath         : Fügt den aktuellen Pfad als Suchpfad hinzu.\n"
  + "- delpath         : Löscht den aktuellen Pfad als Suchpfad.\n"
  + "- paths           : Zeigt alle Suchpfade.\n"
  + "- rec             : Schaltet rekursives Suchen ein/aus.\n"
  + "- dir             : Schaltet Ausgabe von Directories ein/aus.\n");
  SetProp(P_NEVERDROP, 1);
  SetProp(P_NODROP, 1);
  SetProp(P_AUTOLOADOBJ, 1);
  SetProp(P_NAME, "WhatsNew-Tool");
  SetProp(P_ARTICLE, 1);
  SetProp(P_GENDER, NEUTER);
  AddId(({"\ntools_whatsnew", "whatsnew", "wn", "tool", "whatsnew-tool"}));
  AddCmd( ({"wn", "whatsnew"}), "wn");
  AddCmd( ({"sa", "showagain"}), "sa");
  AddCmd( ({"ap", "addpath"}), "ap");
  AddCmd( ({"dp", "delpath"}), "dp");
  AddCmd( ({"pa", "paths"}), "pa");
  AddCmd( ({"rec"}), "rec");
  AddCmd( ({"dir"}), "dir");
}

int wn(string str)
{
  string *paths, *dir, *oldpaths;
  mixed t;
  int l1, l2, last, err, ti, isdir, shdir, re;

  if(!str) last=WNMASTER->QueryLast(SAVEDIR+envuid());  
  else last=date2sec(str);
  if(!last) return 0;
  paths=WNMASTER->QueryPaths(SAVEDIR+envuid());
  rm(SAVEDIR+envuid()+".txt");
  ti=time();
  re=WNMASTER->QueryRec(SAVEDIR+envuid());
  shdir=WNMASTER->QueryShowDir(SAVEDIR+envuid());
  write_file(SAVEDIR+envuid()+".txt", "WHATSNEW von "+ctime(last)+" bis "+ctime(ti)+"    D="+shdir+" R="+re+"\n");
  write_file(SAVEDIR+envuid()+".txt", "-----------------------------------------------------------------------------\n");
  l1=0;
  while(l1<sizeof(paths))
  {
    err=catch(dir=get_dir(paths[l1]+"/*", 7));
    if(!err)
    {
      l2=0;
      while(l2<sizeof(dir))
      {
        if(dir[l2]!="."&&dir[l2]!="..")
        {
          t=extract(ctime(to_int(dir[l2+2])),4,9);
          if(to_int(dir[l2+1])!=-2) 
          {
            t+=extract(" "+(to_int(dir[l2+1])/1024)+"kB        ",0,7);
            isdir=0;
          }
          else 
          {
            t+=" [DIR]  ";
            isdir=1;
          }
          if(paths[l1]!="/") t+=paths[l1]+"/"+dir[l2]+"\n";
          else t+="/"+dir[l2]+"\n";
          if(to_int(dir[l2+2])>last&&(shdir||(!isdir)))
          {
            write(t);
            write_file(SAVEDIR+envuid()+".txt",t);
          }
          if(re&&isdir)
          {
            oldpaths=paths;
            paths=oldpaths[0..l1];
            if(oldpaths[l1]=="/") paths+=({oldpaths[l1]+dir[l2]});
            else paths+=({oldpaths[l1]+"/"+dir[l2]});
            if(l1<sizeof(oldpaths)) paths+=oldpaths[l1+1..sizeof(oldpaths)];
          }
        }
        l2+=3;
      }
    }
    l1++;
  }
  write_file(SAVEDIR+envuid()+".txt", "-----------------------------------------------------------------------------\n");
  write_file(SAVEDIR+envuid()+".txt", "                                          (c) 1996 by Shakedbeer@MorgenGrauen\n");
  WNMASTER->SetLast(SAVEDIR+envuid(), ti);
  return 1;
}

int sa(string str)
{
  this_player()->more(SAVEDIR+envuid()+".txt",1);
  return 1;
}

int ap(string str)
{
  if(WNMASTER->AddPath(SAVEDIR+envuid(), this_player()->QueryProp(P_CURRENTDIR))) write("OK\n");
  else write("Pfad ist bereits eingefügt worden!\n");
  return 1;
}

int dp(string str)
{
  if(WNMASTER->DelPath(SAVEDIR+envuid(), this_player()->QueryProp(P_CURRENTDIR))) write("OK\n");
  else write("Der Pfad befindet sich nicht in der Liste!\n");
  return 1;
}

int pa(string str)
{
  string *paths;
  int l1;
  
  paths=WNMASTER->QueryPaths(SAVEDIR+envuid());
  l1=0;
  while(l1<sizeof(paths))
  {
    write(paths[l1]+"\n");
    l1++;
  }
  return 1;
}

int rec(string str)
{
  if(WNMASTER->QueryRec(SAVEDIR+envuid()))
  {
    WNMASTER->SetRec(SAVEDIR+envuid(), 0);
    write("Rekursives Suchen AUS.\n");
  }
  else
  {
    WNMASTER->SetRec(SAVEDIR+envuid(), 1);
    write("Rekursives Suchen EIN.\n");
  }
  return 1;
}

int dir(string str)
{
  if(WNMASTER->QueryShowDir(SAVEDIR+envuid()))
  {
    WNMASTER->SetShowDir(SAVEDIR+envuid(), 0);
    write("Directories anzeigen AUS.\n");
  }
  else
  {
    WNMASTER->SetShowDir(SAVEDIR+envuid(), 1);
    write("Directories anzeigen EIN.\n");
  }
  return 1;
}

int date2sec(string str)
{
  int tt, mm, jj, sec, schalt;
  int *dtm, *dpm, *dts, *dps;

  dtm=({0,31,59,90,120,151,181,212,243,273,304,334});
  dpm=({31,28,31,30,31,30,31,31,30,31,30,31});
  notify_fail("Falsches Datumsformat!\n");
  if(strlen(str)!=8) return 0;
  tt=to_int(extract(str,0,1));
  mm=to_int(extract(str,2,3));
  jj=to_int(extract(str,4,7));
  notify_fail("Falsche Monatszahl!\n");
  if(mm<1||mm>12) return 0;
  notify_fail("Jahreszahl muss groesser 1970 sein!\n");
  if(jj<1970) return 0;
  schalt=(jj-1968)/4;
  if(!jj%4)
  {
    dtm=({0,31,60,91,121,152,182,213,244,274,305,335});
    dpm=({31,29,31,30,31,30,31,31,30,31,30,31});
  }
  notify_fail("Falsche Tageszahl!\n");
  if(tt<1||tt>dpm[mm-1]) return 0;
  sec=(jj-1970)*365;
  sec+=dtm[mm-1];
  sec+=(tt-1)+schalt;
  sec*=24*60*60;
  return sec;
}

string envuid()
{
  object e;

  if(!(e=environment())||(!query_once_interactive(e)))
  {
    remove();
    return "";
  }
  return getuid(e);
}

