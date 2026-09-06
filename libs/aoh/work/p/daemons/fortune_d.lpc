//---------------------------------------------------------------------------
// /p/daemons/fortune_d.c
//
// The OSB fortune server
// (c) Softbyte@OSB 10sep98
// [Softbyte 10sep98]  V1.0:  All standard functions
//
// Usage: call FORTUNE_D->WriteQuote()
//        or   FORTUNE_D->WriteQuote(string player)
//        or quote=FORTUE_D->GetRandomQuote()
//
// If the called has an attribute "Fortune", it is interpreted as
// a mapping of categories with their relative probability of querying
// them, e.g. (["news":50,"love":150,"ascii":25]) will show only
// fortunes from these 3 groups and most often from the "love" group
// !!! If not set everything will work FINE too !!!
//
//---------------------------------------------------------------------------

#include <config.h>
#include <daemons.h>
#include <msgclass.h>
#include <string.h>

inherit "/std/base";
inherit "/lib/string";

private mapping fortune;
mapping QueryFortune() {return fortune;}
/*
  Data structure
  ([name: file; info;date; ({ start1, start2, start3, ...}) ])
  name: Id' for the fortune e.g. computer, love,..
  file: full filename
  date: filedate
  info: unused
  ({}): Array of starting linenumbers
*/
private string *parsing;
/*
  Array of files yet to be parsed
*/


#define M_FORT_FILE  0
#define M_FORT_INFO  1
#define M_FORT_DATE  2
#define M_FORT_START 3

#define SAVEFILE DAEMONSAVEPATH "fortune"
#define DEFAULT_DIR "/p/fortune/data"      /* default fortune directory */

string QueryAuthor() {return "Softbyte, 1998";}
string QueryVersion() {return "V1.0";}

/*
   Save the internal data
*/
void Save()
{
  save_object(SAVEFILE);
}

/*
   Delete everything
*/
int ClearAll()
{
  fortune=([]);
  Save();
  return 1;
}

/*
   Remove fortune file from memory
*/
int RemoveFile(string name)
{
  if (parsing) parsing-=({name});
  if (!member(fortune,name)) return 0;
  fortune=m_delete(fortune,name);
  Save();
  return 1;
}

/*
   Add fortune file to database
   name: fortune id, e.g. computer
   file: full filename
   info: unused
*/
int AddFile(string name,string file, string info)
{
  string s;
  string *p_s;
  int start,chunk;
  int *line_start;
  int i;
  int date;

  // write("AddFile:: name="+name+"...");
  if (parsing) parsing-=({name});

  if (!fortune) fortune=([]);
  if (file_size(file)<=0)
  {
    RemoveFile(name);
    // write(" file not found\n");
    return 0; /* file not found */
  }

  date=file_date(file);
  if (member(fortune,name)
      && date==fortune[name,M_FORT_DATE] ) /* entry already present, but ok */
  {
    // write(" no need to add\n");
    return 2;
  }

  if (member(fortune,name)) /* entry already present, but too old */
  {
    RemoveFile(name);
  }

  chunk=100;
  start=1;
  line_start=({start});
  do
  {
    s=read_file(file,start,chunk);
    if (!s) break;
    p_s=explode(s,"\n");
    for (i=0;i<sizeof(p_s);i++)
    {
      if (p_s[i][0]=='%') /* found new quote */
      {
        line_start+=({ start+i+1 });
      }
    }
    start+=chunk;
  }while(s);

  fortune+=([ name:file;info;file_date(file);line_start ]);
  Save();
  // write(" added\n");
  return 1;
}

/*
   Add all files in the given directory to the database
*/
int AddDir(string dir)
{
  string *files;
  int i;

  if (file_size(dir)!=-2) return 0; /* not a directory */

  files=get_dir(dir+"/*");
  if (!files) return 0; /* error */
  files-=({"."});
  files-=({".."});
  parsing=({});

  for (i=0;i<sizeof(files);i++)
  {
    call_out("AddFile",5*i+1,files[i],dir+"/"+files[i],0);
    parsing+=({files[i]});

  }
  return 1;
}

/*
   Returns all categories available
*/
string *QueryCategories()
{
  if (!fortune) fortune=([]);
  return m_indices(fortune);
}

/*
   Returns TRUE if the given name is a valid and loaded category
*/
int IsCategory(string name)
{
  if (!fortune) fortune=([]);
  if (!name) return 0;
  if (!member(fortune,name)) return 0;
  return 1;
}

/*
   Return the number of data entries for a given category
*/
int QuerySize(string name)
{
  if (!IsCategory(name)) return 0;
  return sizeof(fortune[name,M_FORT_START]);
}
/*
  Returns an array of fiels yet to be processed
*/
string *QueryParsing() {return parsing;}

/*
  Get quote 'no' from category 'name'
*/
string GetQuote(string name,int no)
{
  string file;
  string s;
  int start,len;
  int *line_start;

  if (!IsCategory(name)) return 0;
  if (no<0 || no>=QuerySize(name)) return 0;

  file=fortune[name,M_FORT_FILE];
  line_start=fortune[name,M_FORT_START];
  start=line_start[no];
  if (no==QuerySize(name)-1) len=0; /* last quote */
  else len=line_start[no+1]-start-1;

  s=read_file(file,start,len);
  if (!s ) return 0;
  return s;
}

/*
  Draw random category
  The optinal mapping probability will influence how often a category
  is choose. See in the header for the details of this mapping
*/
varargs string GetRandomCategory(mapping probability)
{
  string *names;
  int no,i,sum;
  mapping prob;
  string *old;


  names=QueryCategories();
  if (!names || !sizeof(names)) return 0;

  if (probability && sizeof(probability) ) /* user defined prob's */
  {
    prob=probability;
  }
  else
  {
    prob=([]);
    for (i=0;i<sizeof(names);i++)
    {
      prob+=([names[i]:10]);  /* All equal probabiliteis per default */
    }
  }

  names=m_indices(prob);     /* now we work only with the user's groups */
  sum=0;
  old=({});
  for (i=0;i<sizeof(names);i++)
  {
    if (!IsCategory(names[i]))   /* delete on the fly */
    {
      old+=({names[i]});
    }
    else sum+=prob[names[i]];    /* Add up prob's */
  }

  for (i=0;i<sizeof(old);i++)    /* delete wrong groups */
  {
    prob=m_delete(prob,old[i]);
  }

  /* Now try to find category according to prob's */
  names=m_indices(prob);         /* !!! */
  no=random(sum);
  sum=0;
  for (i=0;i<sizeof(names);i++)
  {
    sum+=prob[names[i]];    /* Add up prob's */
    if (no<sum)
    {
      return names[i];      /* Found category */
    }
  }

  return 0; /* should NEVER happen */
}

/*
  Draw Random quote in category 'name' or all categories if name==0
  The optinal mapping probability will influence how often a category
  is choose. See in the header for the details of this mapping.
  If maxf is given no fortune with a size greater than that is returned
*/
varargs string GetRandomQuote(string name, mapping probability,int maxf)
{
  int no;
  string s;
  int cnt,flag;

  s=0;

  cnt=35;  /* No more tries than that */
  do
  {
    if (!name)  /* choose category */
    {
      name=GetRandomCategory(probability);
    }
    if (!name) return s; /* error or previous fortune */

    no=random(QuerySize(name));
    s=GetQuote(name,no);
    cnt--;
    flag=0;
    // Return no quotes with len>maxf lines
    if (maxf && sizeof(explode(s,"\n"))>maxf) flag=1;

  }while(cnt>=0 && flag);
  return s;
}

/*
  Write a random quote to this_player (player=0) or player
*/
varargs int WriteFortune(string player)
{
  string s;
  object ob;
  mapping probability;
  int maxf;

  if (player) ob=find_player(player);
  else ob=0;

  if (!ob) ob=this_player();
  if (!ob) return 0;

  probability=({mapping})ob->QueryAttr("Fortune");
  maxf=({int})ob->QueryAttr("FortuneMax");

  s=GetRandomQuote(0,probability,maxf);
  if (!s) s="No fortune!\n";

  tell_object(ob,s);
  return 1;
}

/*
   Load default fortune date
*/
int LoadFortune()
{
  if (file_size(DEFAULT_DIR)!=-2) return 0; /* dir not present */
  AddDir(DEFAULT_DIR);
  return 1;
}
/*
  Check whether there are files deleted or files updated
*/
int CheckFortune()
{
  string *names;
  string file,info,name;
  int i,date;
  string *old;

  names=QueryCategories();
  if (!names || !sizeof(names)) return 0;

  old=({});
  if (parsing) old=parsing; /* reload all former parsed files */
  /* It makes sense to have two loops here ! */
  for (i=0;i<sizeof(names);i++)
  {
    file=fortune[names[i],M_FORT_FILE];
    date=fortune[names[i],M_FORT_DATE];
    info=fortune[names[i],M_FORT_INFO];
    /* deleted or outdated */
    if (file_size(file)<=0 || file_date(file)!=date)
    {
      old+=({names[i]}); /* to be removed */
    }
  }
  /* It makes sense to have two loops here ! */
  for (i=0;i<sizeof(old);i++)
  {
    RemoveFile(old[i]);
  }
  return 1;
}

varargs void create()
{
  ::create();
  if (is_clone())
  {
    destruct(this_object());
    return;
  }
  seteuid(getuid());
  if (file_size(SAVEFILE+".o")>=0)
  {
    restore_object(SAVEFILE);
  }
  else
  {
    fortune=([]);
  }
  CheckFortune(); /* mark old files dirty or remove them */
  LoadFortune();
}

public varargs int remove(int arg)
{
  Save();
  return ::remove(arg);
}

