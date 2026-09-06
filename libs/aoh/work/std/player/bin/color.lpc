/*--------------------------------------------------------------------------
 * /std/player/bin/color.c  --  The player's color command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * [Softbyte] 04feb98      Minor color improvements and vt100 bold mode
 *
 * TODO: Full vt100 support
 *
 *--------------------------------------------------------------------------
 */

#include <properties.h>
#include <msgclass.h>
#include <daemons.h>

#define VALID_CLASSES ({ "default", "tell", "channel", "fun", "emote", "say", "combat_self", "combat", "combat_others", "room_exit" })
#define VALID_COLORS ({ "black", "red", "green", "orange", "blue", "magenta", "cyan", "white" })
#define VALID_MODES ({ "bold" })

private int string_to_class( string what )
{
  return ({int})COLOUR_D->StringToClass(what);
}

private void set_color( int class, string str, string tty )
{
  string s1, s2;
  mapping c;
  int fg, bg, hgl;

  if ( ! c = ({mapping})this_player()->QueryClassColors() )
  {
    c = ([ -1 : ({ 7, 0, 0 }) ]);
    this_player()->AddClassColor( -1, 7, 0, 0 );
  }

  if ( str == "clear" ) {
    this_player()->RemoveClassColor( class );
    msg_write( CMSG_GENERIC, "Color removed.\n" );
    return;
  }

  switch(tty)
  {
    case "ansi":
      if ( sscanf( str, "bright %s on %s", s1, s2 ) == 2 )
      {
        if ( ( fg = member( VALID_COLORS, s1 ) ) == -1 ) {
          msg_write( CMSG_GENERIC, "Invalid foreground color \""+s1+"\".\n" );
          return;
        }
        if ( ( bg = member( VALID_COLORS, s2 ) ) == -1 ) {
          msg_write( CMSG_GENERIC, "Invalid background color \""+s2+"\".\n" );
          return;
        }
        hgl = 1;
      }
      else if ( sscanf( str, "%s on %s", s1, s2 ) == 2 )
      {
        if ( ( fg = member( VALID_COLORS, s1 ) ) == -1 ) {
          msg_write( CMSG_GENERIC, "Invalid foreground color \""+s1+"\".\n" );
          return;
        }
        if ( ( bg = member( VALID_COLORS, s2 ) ) == -1 ) {
          msg_write( CMSG_GENERIC, "Invalid background color \""+s2+"\".\n" );
          return;
        }
        hgl = 0;
      }
      else if ( sscanf( str, "bright %s", s1 ) )
      {
        if ( ( fg = member( VALID_COLORS, s1 ) ) == -1 ) {
          msg_write( CMSG_GENERIC, "Invalid foreground color \""+s1+"\".\n" );
          return;
        }
        bg = c[-1][1];
        hgl = 1;
      }
      else
      {
        if ( ( fg = member( VALID_COLORS, str ) ) == -1 ) {
          msg_write( CMSG_GENERIC, "Invalid foreground color \""+str+"\".\n" );
          return;
        }
        bg = c[-1][1];
        hgl = 0;
      }

      if ( ( fg == bg ) && ( ! hgl ) )
      {
        msg_write( CMSG_GENERIC,
               "Foreground and background color are identical.\n" );
        return;
      }
    break;
    case "vt100":
      if (member(c,class))
      {
        fg=c[class][0];
        bg=c[class][1];
      }
      else
      {
        fg=c[-1][0];
        bg=c[-1][1];
      }
      if (str=="bold")
      {
        hgl=1;
      }
      else if (str=="normal")
      {
        hgl=0;
      }
      else
      {
        msg_write( CMSG_GENERIC,
               "Invalid mode \""+str+"\".\n" );
        return;
      }
    break;
    default:
        msg_write( CMSG_GENERIC,
          "Color not supported for that terminal type.\n");
      return ;
  }

  this_player()->AddClassColor( class, fg, bg, hgl );
  this_player()->InitColourTranslation();

  if (tty=="ansi")
    msg_write( CMSG_GENERIC,
	     "Color set to "+(hgl?"bright ":"")+VALID_COLORS[fg]+" on "+
	     VALID_COLORS[bg]+".\n" );
  else
    msg_write( CMSG_GENERIC,
         "Mode set to "+(hgl?"bold":"normal")+".\n");

}

private void print_color( int class, int * cs, string tmp, string tty ) {
  string tx;

  switch( class ) {
  case -1:
    tx = "default";
    break;
  default:
    if ( sizeof(STRING_CMSG) > class )
      tx = STRING_CMSG[class];
    else
      tx = sprintf( "<class %d>", class );
    break;
  }
  if (cs)
  {
    if (tty=="ansi")
      tmp += sprintf( "%-15s : %s\n", tx,
		  (cs[2]?"bright ":"")+VALID_COLORS[cs[0]]+" on "+
		  VALID_COLORS[cs[1]] );
    else
      tmp += sprintf( "%-15s : %s\n", tx,
               cs[2]?"bold":"normal");

  }
  else
  {
    tmp += sprintf( "%-15s : %s\n", tx,"not defined");
  }
}

public int main( string arg ) {
  string what, how, tmp, tty;
  int class,i;
  int *cls,*vcls, *res;
  mapping c;

  seteuid(getuid());
  tty=({string})this_player()->Query( P_TTY );
  if ( tty != "ansi" && tty != "vt100" )
    return notify_fail( "Coloring is only supported for vt100 and ansi.\n" ), 0;

  if ( ! arg ) {
    /* show current color settings */
    if ( c = ({mapping})this_player()->QueryClassColors() ) {
      tmp = "Current color settings:\n";
      walk_mapping( c, #'print_color /*'*/, & tmp, tty  );
      // intersect_alist works only on sorted arrays properly
      cls=sort_array(m_indices(c)||({}),#'> /*'*/);
      vcls=map(VALID_CLASSES,"StringToClass",COLOUR_D);
      vcls=sort_array(vcls,#'> /*'*/);
      res = vcls - (cls & vcls);
      for (i=0;i<sizeof(res);i++)
      {
        print_color(res[i],0,&tmp,tty);
      }
      msg_write( CMSG_GENERIC, tmp );
    }
    else
      msg_write( CMSG_GENERIC, "No colors defined.\n" );
    return 1;
  }
  else if ( ( sscanf( norm_id(arg), "%s %s", what, how ) == 2 ) &&
	    ( how != "" ) &&
	    ( what != "" ) )
  {
    /* user wants to color something */
    if ( member( VALID_CLASSES, what ) != -1 )
    {
      class = string_to_class( what );
      set_color( class, how, tty );
    }
    else
    {
      msg_write( CMSG_GENERIC,
		 "Invalid class given for coloring.\n"+
		 "Valid classes are "+implode(VALID_CLASSES[0..<2],",")+
		 " and "+VALID_CLASSES[<1]+".\n" );
    }
    return 1;
  }
  else if ( ( arg == "?" ) || ( arg == "help" ) )
  {
    if (tty=="ansi")
    {
	    tmp= "Syntax: color <class> <clear>|<[bright] color [on <color]>\n\n"
	        "Valid classes are:\n"+implode(VALID_CLASSES[0..<2],",")+""
	       " and "+VALID_CLASSES[<1]+".\n\n"
	       "Valid colors are:\n"+implode(VALID_COLORS[0..<2],",")+""
	       " and "+VALID_COLORS[<1]+".\n\n"
	       "Foreground colors can be bright, i.e. bright red.\n";
    }
    else
    {
	    tmp= "Syntax: color <class> <clear>|<bold>|<normal>\n\n"
	        "Valid classes are:\n"+implode(VALID_CLASSES[0..<2],",")+""
	       " and "+VALID_CLASSES[<1]+".\n\n";
    }
    msg_write( CMSG_GENERIC,tmp);
    return 1;
  }
  else if ( arg == "chart" )
  {
    int  i2, pw;
    string ax;
    string * cn;

    if (tty!="ansi")
    {
      tmp="Colour chart only supported for ansi.\n";
      msg_write( CMSG_GENERIC|MMSG_DIRECT|MMSG_NOWRAP, tmp );
      return 1;
    }
    cn = ({string *})COLOUR_D->QueryColourNames();

    ax = "";
    for( i = 0; i < sizeof(cn); i ++ )
      ax += (" "+lower_case(cn[i])+" ");

    pw = ({int})this_player()->Query(P_PAGEWIDTH)-4;
    i2 = ( pw - sizeof( ax ) ) / 2;
    if ( i2 < 0 ) i2 = 0;
    ax = sprintf( "%*' 's", i2, "" );

    tmp = sprintf( "\n%*|s\n", pw, "Foreground colors not bright" );
    for( i = 0; i < sizeof( cn); i++ ) {
      tmp += ax;
      tmp += "%^_RESET_%^%^B_"+cn[i]+"%^";

      for( i2 = 0; i2 < sizeof(cn); i2++ ) {
	tmp += "%^"+cn[i2]+"%^ "+lower_case(cn[i2])+" ";
      }

      tmp += "%^RESET%^\n";
    }

    tmp += sprintf( "\n%*|s\n", pw, "Foreground colors bright" );

    for( i = 0; i < sizeof( cn); i++ ) {
      tmp += ax;
      tmp += "%^_RESET_%^%^B_"+cn[i]+"%^";

      for( i2 = 0; i2 < sizeof(cn); i2++ ) {
	tmp += "%^BOLD%^%^"+cn[i2]+"%^ "+lower_case(cn[i2])+" ";
      }

      tmp += "%^RESET%^\n";
    }

    msg_write( CMSG_GENERIC|MMSG_DIRECT|MMSG_NOWRAP, tmp );
    return 1;
  }
  else
    return notify_fail( "Usage:\n"+
			"'color' without arguments shows coloring.\n"+
			"'color <class> <color>|\"default\"' sets coloring.\n"+
			"'color chart' shows a chart of all colors.\n" ), 0;
}
