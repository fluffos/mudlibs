/*--------------------------------------------------------------------------
 * /obj/lib/more.c -- multiuser/message aware more
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * It is possible to inherit more.c, but the normal usage should be:
 * "/obj/lib/more"->...
 *
 * TODO: more always assumes that chunk lines have been written
 */

#include <secure/wizlevels.h>
#include <properties.h>
#include <msgclass.h>
#include <driver/input_to.h>

#define MORE_QUIET 0
#define MORE_REGEXP 1
#define MORE_FILE 2
#define MORE_LINE 3
#define MORE_CHUNK 4

mapping data;

/*---------------------------------------------------------------------------
 * Some helpfuns to handle the data mapping
 *---------------------------------------------------------------------------
 */

/* just for debuggin purpose */
public mapping query_data() { return data; } 

private void add_data( int quiet, string regexp, string file, 
		       int line, int chunk ) {
  if ( ! data )
    data = ([]);
  
  data[this_player()->Query(P_REALNAME)] =
    ({
      quiet,             /* quiet flag */
      regexp,            /* more reqexp */
      file,              /* file to more */
      line,              /* more line */
      chunk              /* more chunk */
    }); 
}

private void remove_data() {
  if ( ! data )
    return;
  m_delete( data, this_player()->Query(P_REALNAME) );
  if ( ! sizeof( data ) )
    data = 0;
}

private mixed get_data( int type ) {
  if ( ! data )
    return 0;

  return data[this_player()->Query(P_REALNAME)][type];
}

private void set_data( int type, mixed v ) {
  if ( ! data )
    return;

  data[this_player()->Query(P_REALNAME)][type] = v;
}

/*--------------------------------------------------------------------------
 * write the more prompt
 *--------------------------------------------------------------------------
 */

public void more_prompt (int m_line, int m_chunk) {
  msg_write( CMSG_GENERIC|MMSG_DIRECT|MMSG_NOWRAP,
	     "=== More: Lines "+m_line+".."+(m_line+m_chunk-1)
       +" [CR,u,f,l,q,/<regexp>,<line>,?] " );
  this_player()->print_eor();
}

/*--------------------------------------------------------------------------
 * skip to the end of file
 *  we need call_out here to prevent too long evals for large files
 *--------------------------------------------------------------------------
 */

void skip_to_end_of_more( int itrans ) {
  string foo;
  int step, nline;

  step = 0;
  while ((foo = read_file( get_data( MORE_FILE ),
			   get_data( MORE_LINE ),
			   get_data( MORE_CHUNK ) )) && foo != "" ) {
    set_data( MORE_LINE, get_data( MORE_LINE ) + get_data( MORE_CHUNK ) );
    step++;
    if (step >= 50) {
      msg_write( CMSG_GENERIC|MMSG_DIRECT,
		 ".. Line "+get_data(MORE_LINE)+" ..\n");
      call_out("skip_to_end_of_more", 0, itrans );
      return;
    }
  }

  set_data( MORE_LINE, get_data(MORE_LINE)-get_data(MORE_CHUNK));
  if ( get_data(MORE_LINE) < 1)
    set_data( MORE_LINE, 1 );

  if ( ! foo = read_file( get_data( MORE_FILE ),
			  get_data( MORE_LINE ),
			  get_data( MORE_CHUNK ) ) ) {
    msg_write( CMSG_GENERIC|MMSG_DIRECT, "=== EOF\n" );

    if (! get_data( MORE_QUIET ) ) {
      msg_say( CMSG_ROOM,
	       this_player()->Query(P_NAME)+
	       "'s view focuses again on this reality.\n" );
    }
    remove_data();
    return;
  }
  if ( foo[<1] != '\n' )
    foo += "\n";
  msg_write( CMSG_GENERIC|MMSG_DIRECT|MMSG_NOWRAP|itrans, foo );

  /* here is chunk the incorrect value too */
  more_prompt( get_data( MORE_LINE ), get_data( MORE_CHUNK ) );
  input_to("even_more", 0, itrans );
}

/*--------------------------------------------------------------------------
 * start the more for this_player()
 *  fname : filename to more
 *  quiet : do not write 'looks at a complete different reality'
 *  chunk : chunks to more the file, if not given, P_PAGESIZE is assumed
 *--------------------------------------------------------------------------
 */

varargs int more( string fname, int quiet, int chunk, int itrans ) {
  int nline;
  string tmp;

  if ( this_player()->Query(P_EDITING) ) {
    msg_write( CMSG_GENERIC|MMSG_DIRECT, 
	       "Error: more cannot be used while editing.\n" );
    return 0;
  }
  if ( ! fname ) {
    msg_write( CMSG_GENERIC,
	       "Error: no filename for more given.\n" );
    return 0;
  }

  if (!chunk) 
    chunk = this_player()->Query( P_PAGESIZE );

  if ( itrans )
    itrans = MMSG_IDENT_TRANS;

  fname = this_player()->get_path( fname, 0, this_player() );

  if ( file_size( fname ) < 0 ) {
    msg_write( CMSG_GENERIC,
	       "Error: \""+fname+"\" isn't a file.\n" );
    return 0;
  }

  if ( IS_IMMORTAL( this_player() ) )
    msg_write( CMSG_GENERIC,
	       "--- "+fname+" ("+file_size(fname)+" Bytes) ---\n" );

 /* Short files are written directly */
  if ( (!read_file(fname, chunk+1, 1)) &&
       ( tmp = read_file( fname ) ) ) {
    if ( tmp[<1] != '\n' )
      tmp += "\n";
    msg_write( CMSG_GENERIC|MMSG_NOWRAP|itrans, tmp );
    return 1;
  }

  if ( ! tmp = read_file( fname, 1, chunk ) ) {
    msg_write( CMSG_GENERIC,"No such file.\n" );
    return 0;
  }

  add_data( quiet, 0, fname, 1, chunk );
  if ( tmp[<1] != '\n' )
    tmp += "\n";
  msg_write( CMSG_GENERIC|MMSG_NOWRAP|MMSG_DIRECT|itrans, tmp );

  if ( ! quiet ) {
    msg_say( CMSG_ROOM,
	     this_player()->Query(P_NAME)+
	     " looks at a completely different reality.\n" );
  }

  more_prompt( 1, chunk ); /* chunk should be replace by real number */
  input_to("even_more", 0, itrans );
  return 1;
}

/*--------------------------------------------------------------------------
 * output the next chunk of lines
 *--------------------------------------------------------------------------
 */

public void even_more( string str, int itrans ) {
  int nline, display;
  string foo;

  display = 0;

  switch( str ) {
    case "a":
      display = 1; /* do nothing but redisplay */
      break;
    case "":
    case "d":
      set_data( MORE_LINE, get_data(MORE_LINE)+get_data(MORE_CHUNK) );
      display = 1;
      break;
    case "q":
      msg_write( CMSG_GENERIC|MMSG_DIRECT, "== Ok.\n" ); 
      remove_data();
      return;
    case "u":
    case "b":
      set_data( MORE_LINE, get_data(MORE_LINE)-get_data(MORE_CHUNK) );
      display = 1;
      break;
    case "f":
      set_data( MORE_LINE, 1 );
      display = 1;
      break;
    case "l":
      msg_write( CMSG_GENERIC|MMSG_DIRECT, "..wait..\n"); 
      skip_to_end_of_more( itrans ); 
      return;
    case "?":
      msg_write( CMSG_GENERIC|MMSG_DIRECT, 
	       "Accepted commands are:\n"
	       + "  [CR], d  : next page\n"
	       + "  u   , b  : last page\n"
	       + "  f        : go to the first page\n"
	       + "  l        : go to the last page\n"
	       + "  <nr>     : go to line <nr>\n"
	       + "  /<regexp>: scan forward until line matching <regexp>\n"
	       + "  /        : repeats last /<regexp> command\n"
	       + "  a        : redisplay current page\n"
	       + "  ?        : this help\n"
	       + "  q        : quits more.\n"
	       + "Each page is by "+get_data(MORE_CHUNK)+" lines long.\n"
         );
      break;
    default:
      if (str[0] == '/') {
        if (sizeof(str) < 2 && sizeof( get_data(MORE_REGEXP) || "") < 1)
	        msg_write( CMSG_GENERIC|MMSG_DIRECT, "No previous regular expression.\n" );
        else {
	        if (sizeof(str) > 1)
	          set_data( MORE_REGEXP, str[2..] );
	        if (!regexp(({"dummy"}), get_data(MORE_REGEXP) )) {
	          msg_write( CMSG_GENERIC|MMSG_DIRECT, "*** Bad regular expression.\n");
	          set_data( MORE_REGEXP, 0 );
	        }
	        else {
	          nline = get_data(MORE_LINE)+get_data(MORE_CHUNK);

	          msg_write( CMSG_GENERIC|MMSG_DIRECT, "..searching..\n" );

	          while (   (foo = read_file( get_data(MORE_FILE), nline++, 1)) 
                    && !sizeof(regexp(({foo}), get_data(MORE_REGEXP))));

	          if (foo) {
	            set_data( MORE_LINE, nline-1 );
	            display=1;
	          }
	          else
	            msg_write( CMSG_GENERIC|MMSG_DIRECT, "*** Pattern not found.\n" );
	        }
        }
      }
      else if ( sscanf(str, "%d", nline) == 1 ) {
        set_data( MORE_LINE, nline );
        display = 1;
      }
      break;
  }
  if ( get_data( MORE_LINE ) < 1)
    set_data( MORE_LINE, 1 );
  if ( display ) {
    if ( ! foo = read_file( get_data( MORE_FILE ),
	                          get_data( MORE_LINE ),
		                        get_data( MORE_CHUNK ) ) ) {
      msg_write( CMSG_GENERIC|MMSG_DIRECT, "=== EOF\n" );
      
      if (! get_data( MORE_QUIET ) ) {
	      msg_say( CMSG_ROOM,
	      this_player()->Query(P_NAME)+ "'s view focuses again on this reality.\n" );
      }
      remove_data();
      return;
    }
    if ( foo[<1] != '\n' )
      foo += "\n";
    msg_write( CMSG_GENERIC|MMSG_NOWRAP|MMSG_DIRECT|itrans, foo );
  }
  /* here is chunk the incorrect value too */
  more_prompt( get_data( MORE_LINE ), get_data( MORE_CHUNK ) );
  input_to("even_more", 0, itrans );
  return;
}
