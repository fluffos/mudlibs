/* /players/shakedbeer/tools/wnmaster.c */
/* von Samtpfote ans Turithil angepasst */

// inherit "/std/thing";

#include <properties.h>
#include <new_skills.h>
#include <wizlevels.h>
#include <moving.h>

mapping dirs;
int last;
int sdir;
int recu;

void create()
{        
  seteuid( getuid(this_object())); 
}          

void do_restore(string str)
{
  if( !restore_object(str))
  {
    dirs = ([]);
    last = time();
    return;
  }
  restore_object(str);
}

int AddPath(string swer, string dir)
{
  do_restore(swer);
  if( member( dirs, dir) ) return 0;
  dirs += ([ dir ]);
  save_object(swer);
  return 1;
}

int DelPath(string swer, string dir)
{
  do_restore(swer);
  if( !member( dirs, dir) ) return 0;
  dirs -= ([ dir ]);
  save_object(swer);
  return 1;
}

string *QueryPaths( string swer )
{
  do_restore(swer);
  return sort_array(m_indices(dirs), #'>);
}

int SetLast( string swer, int when)
{
  do_restore(swer);
  if( last<0 ) return 0;
  last=when;
  save_object(swer);
  return 1;
}

int QueryLast( string swer )
{
  do_restore(swer);
  return last;
}

int SetShowDir( string swer, int yn)
{
  do_restore(swer);
  if( yn<0 ) return 0;
  sdir=yn;
  save_object(swer);
  return 1;
}

int QueryShowDir( string swer )
{
  do_restore(swer);
  return sdir;
}

int SetRec( string swer, int yn)
{
  do_restore(swer);
  if( yn<0 ) return 0;
  recu=yn;
  save_object(swer);
  return 1;
}

int QueryRec( string swer )
{
  do_restore(swer);
  return recu;
}

