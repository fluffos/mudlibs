/*--------------------------------------------------------------------------
 * DAEMONPATH colour_d --  The colour daemon
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * NOTE: if you redefine any vars, you need to delete colour.o from
 *       /save/daemons/, because init_vars is only called if the save-
 *       file is not found.
 */

#include <msgclass.h>

inherit "/obj/lib/daemon_data";

/* Colour defines
 */

#define RESET                    "\e[0m"

#define BOLD                     "\e[1m"
#define UNDERL                   "\e[4m"
#define FLASH                    "\e[5m"
#define INVERS                   "\e[6m"

#define BLACK                    "\e[30m"
#define RED                      "\e[31m"
#define GREEN                    "\e[32m"
#define ORANGE                   "\e[33m"
#define YELLOW                   BOLD ORANGE
#define BLUE                     "\e[34m"
#define MAGENTA                  "\e[35m"
#define CYAN                     "\e[36m"
#define WHITE                    "\e[37m"

#define B_BLACK                  "\e[40m"
#define B_RED                    "\e[41m"
#define B_GREEN                  "\e[42m"
#define B_ORANGE                 "\e[43m"
#define B_YELLOW                 BOLD B_ORANGE
#define B_BLUE                   "\e[44m"
#define B_MAGENTA                "\e[45m"
#define B_CYAN                   "\e[46m"
#define B_WHITE                  "\e[47m"
/* #define B_BLACK                  "\e[49m" */

#if 0
#define CLEARLINE                "\e[L\e[G"
#define INITTERM                 "\e[H\e[2J"
#define ENDTERM                  ""
#define SAVE                     "\e7"
#define RESTORE                  "\e8"
#define HOME                     "\e[H"
#endif

#define ANSI_TRANS ([ "BLACK" : BLACK, "RED" : RED, "GREEN" : GREEN, "ORANGE" : ORANGE, "YELLOW" : BOLD ORANGE, "BLUE" : BLUE, "CYAN" : CYAN, "MAGENTA" : MAGENTA, "WHITE" : WHITE, "B_BLACK" : B_BLACK, "B_RED" : B_RED, "B_GREEN" : B_GREEN, "B_ORANGE" : B_ORANGE, "B_YELLOW" : BOLD B_ORANGE, "B_BLUE" : B_BLUE, "B_CYAN" : B_CYAN, "B_MAGENTA" : B_MAGENTA, "B_WHITE" : B_WHITE, "BOLD" : BOLD, "FLASH" : FLASH, "UNDERL" : UNDERL, "INVERS" : INVERS, "RESET" : RESET, "_RESET_" : RESET ])

#define COLOR_NAMES ({ "BLACK", "RED", "GREEN", "ORANGE", "BLUE", "MAGENTA", "CYAN", "WHITE" })

/* -------------------------------------------------------------------------
 * Global vars
 * -------------------------------------------------------------------------
 */

mapping color_trans;
mapping ident_trans;

/* -------------------------------------------------------------------------
 * Interface
 * -------------------------------------------------------------------------
 */

/* returns the class for a given string
 */

int StringToClass( string what ) {
  int class;

  if ( ( class = member( STRING_CMSG, what ) ) != -1 )
    return class;
  else
    return -1;
}

/* returns the string for a given class, masks out
 */

string ClassToString( int class ) {
  class &= MMSG_MASKOUT;

  if (    class < 0
       || class > sizeof( STRING_CMSG ) )
    return 0;

  return STRING_CMSG[class];
}

/* returns the full tokenstring i.e. %^cmsg_xxx%^ for a integer class number
*/
string ClassToToken( int class) {
  string c;
  c=ClassToString(class);
  return "%^cmsg_"+c+"%^";

}

/* transforms a numberic array of classes to ansi
 */

mapping QueryClassTrans( mapping pClassColors, string tty ) {
  mapping res;
  int i;
  string * cn;

  cn = STRING_CMSG;
  res = ([]);

  for( i = 0; i < sizeof( cn ); i ++ ) {
    switch ( tty ) {
    case "ansi":
      if ( mappingp( pClassColors ) && pClassColors[i] ) {
	res["cmsg_"+cn[i]] =
	  RESET[0..<2] + ";" +
	  ANSI_TRANS[COLOR_NAMES[pClassColors[i][0]]][2..<2] + ";" +
	  ANSI_TRANS["B_"+COLOR_NAMES[pClassColors[i][1]]][2..<2] +
	  (pClassColors[i][2]?(";"+BOLD[2..]):"m");
      }
      else if ( mappingp( pClassColors ) && pClassColors[-1] ) {
	res["cmsg_"+cn[i]] =
	  RESET[0..<2] + ";" +
	  ANSI_TRANS[COLOR_NAMES[pClassColors[-1][0]]][2..<2] + ";" +
	  ANSI_TRANS["B_"+COLOR_NAMES[pClassColors[-1][1]]][2..<2] +
	  (pClassColors[-1][2]?(";"+BOLD[2..]):"m");
      }
      else
	res["cmsg_"+cn[i]] = "";
      break;
    case "vt100":
      if ( mappingp( pClassColors ) && pClassColors[i] ) {
	res["cmsg_"+cn[i]] =
	  RESET[0..<2] +
	  (pClassColors[i][2]?(";"+BOLD[2..]):"m");
      }
      else if ( mappingp( pClassColors ) && pClassColors[-1] ) {
	res["cmsg_"+cn[i]] =
	  RESET[0..<2] +
	  (pClassColors[-1][2]?(";"+BOLD[2..]):"m");
      }
      else
	res["cmsg_"+cn[i]] = "";
      break;
    default:
      res["cmsg_"+cn[i]] = "";
      break;
    }
  }

  return res;
}


/* returns the foreground-colour names mapping indexed by ansi-numeric value
 */

string * QueryColourNames() { return COLOR_NAMES; }

/* returns the translation table for the given terminal type
 */

mapping QueryTTYTrans( string tty ) {
  /* if we do not have own codes for a terminal type, return those
   * for the dumb terminals
   */

  if ( ! color_trans[tty] )
    return copy( color_trans["dumb"] );
  else
    return copy( color_trans[tty] );
}

/* returns the translation table to trip all color-macros
 * currently this just returns the codes for the dumb terminal
 */

mapping QueryNullTrans() {
  return copy( color_trans["dumb"] );
}

/* returns the translation table to identically transform the color-macros
 * using that table does actually nothing, but with it one might use the
 * terminal_colour-efun for wrapping purpose
 */

mapping QueryIdentTrans() {
  return copy( ident_trans );
}

private void init_vars() {
  string * cn;
  int i;

  /* initialize our data variables
   */

  color_trans = ([]);
  ident_trans = ([]);

  cn = COLOR_NAMES;

  color_trans["dumb"] = ([]);
  color_trans["vt100"] = ([]);
  color_trans["ansi"] = ([]);

  for( i = 0; i < sizeof( cn ); i ++ ) {
    color_trans["dumb"][cn[i]] = "";
    color_trans["dumb"]["B_"+cn[i]] = "";
    color_trans["vt100"][cn[i]] = "";
    color_trans["vt100"]["B_"+cn[i]] = "";
    ident_trans[cn[i]] = "%^"+cn[i]+"%^";
    ident_trans["B_"+cn[i]] = "%^B_"+cn[i]+"%^";
  }
  color_trans["dumb"]["BOLD"] = "";
  color_trans["dumb"]["FLASH"] = "";
  color_trans["dumb"]["UNDERL"] = "";
  color_trans["dumb"]["INVERS"] = "";
  color_trans["dumb"]["RESET"] = "";
  color_trans["dumb"]["_RESET_"] = "";

  color_trans["vt100"]["BOLD"] = BOLD;
  color_trans["vt100"]["FLASH"] = "";
  color_trans["vt100"]["UNDERL"] = "";
  color_trans["vt100"]["INVERS"] = "";
  color_trans["vt100"]["RESET"] = RESET;
  color_trans["vt100"]["_RESET_"] = RESET;

  ident_trans["BOLD"] = "%^BOLD%^";
  ident_trans["FLASH"] = "%^FLASH%^";
  ident_trans["UNDERL"] = "%^UNDERL%^";
  ident_trans["INVERS"] = "%^INVERS%^";
  ident_trans["RESET"] = "%^RESET%^";
  ident_trans["_RESET_"] = "%^_RESET_%^";

  color_trans["ansi"] = ANSI_TRANS;

  cn = STRING_CMSG;
  for( i = 0; i < sizeof( cn ); i ++ )
    ident_trans["cmsg_"+cn[i]] = "%^cmsg_"+cn[i]+"%^";
}

/* Initialize us
 */

void create() {
  if (clonep()) {
    destruct( this_object() );
    return;
  }
  seteuid(getuid());

  /* load our savefile */
  daemon_data::create();

  /* if there was no save-file, init vars and create one */
  if ( ! mappingp( color_trans ) ) {
    init_vars();
    save_me(); /* daemon_data provides this */
  }
}

