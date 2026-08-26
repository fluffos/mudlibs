/*
// File:       _docsim.c
// Mudlib:     TMI-2
// 93-08-10    Written by Pallando
*/
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: docsim\n"

int cmd_docsim( mixed a )
{
  string *not_doc, *not_rof;
  mixed a_sims, a_docs, a_roff;

  a_sims = read_file( "/adm/obj/simul_efun.t" );
  a_sims = replace_string( a_sims, "\n", ".2\n" );
  a_sims = explode( a_sims, "\n" );
  a_docs = get_dir( "/doc/functions/untroffed/simul_efuns/" );
  a_docs -= ({ "subs" }); // a pearl script someone left in that dir.
  a_roff = get_dir( "/doc/functions/simul_efuns/" );

  not_doc = a_sims - a_docs;
  not_rof = a_docs - a_roff;

  if( sizeof( not_doc ) )
    write( "Simulated efunctions existing but not documented:\n" +
      wrap( implode( not_doc, " " ) ) );
  else
    write( "All simulated efuns are documented.\n" );

  write( "\n" );

  if( sizeof( not_rof ) )
    write( "Simulated efunctions documented but not troffed:\n" +
      wrap( implode( not_rof, " " ) ) );
  else
    write( "All documented simulated efuns are troffed.\n" );

  return 1;
}

int help()
{
  write( SYNTAX + @HelpText
Effect: Lists the state of simul_efun documentation.
HelpText
  );
  return 1;
}
