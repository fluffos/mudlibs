/*  -*- LPC -*-  */
// termcap_d.c:  Provides Discworld/Nightmare/Lima style color code
//               translations for different terminal types.
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//
// Created 10.15.96 by Tim@Dysfunctional Mud
//

private mapping default_termcap;
private mapping database;


void
create()
{
  default_termcap =
    ([
      "RESET"     : "",     // Clear all attributes
      "BELL"      : "",     // Audible signal

      /* Attributes */
      "INVERSE"   : "",
      "UNDERSCORE": "",
      "BOLD"      : "",
      "FLASH"     : "",

      /* Foreground colors */
      "BLACK"     : "",
      "RED"       : "",
      "GREEN"     : "",
      "ORANGE"    : "",
      "YELLOW"    : "",
      "BLUE"      : "",
      "MAGENTA"   : "",
      "CYAN"      : "",
      "WHITE"     : "",

      /* Background colors */
      "B_BLACK"   : "",
      "B_RED"     : "",
      "B_GREEN"   : "",
      "B_ORANGE"  : "",
      "B_YELLOW"  : "",
      "B_BLUE"    : "",
      "B_MAGENTA" : "",
      "B_CYAN"    : "",
      "B_WHITE"   : "",

      /* Screen & Cursor functions */
      "INITTERM"  : "",     // Clear screen and home cursor
      "CLEARLINE" : "",
      "HOME"      : "",      // Home cursor
      "SAVE"      : "",
      "RESTORE"   : "",
      ]);

  database =
    ([
      "default" : default_termcap,
      "ansi" : default_termcap +
      ([
	"RESET"     : "\e[0m",
	"BOLD"      : "\e[1m",
	"UNDERSCORE": "\e[4m",
	"FLASH"     : "\e[5m",
	"INVERSE"   : "\e[7m",
	"BLACK"     : "\e[30m",
	"RED"       : "\e[31m",
	"GREEN"     : "\e[32m",
	"ORANGE"    : "\e[33m",
	"YELLOW"    : "\e[1m\e[33m",
	"BLUE"      : "\e[34m",
	"MAGENTA"   : "\e[35m",
	"CYAN"      : "\e[36m",
	"WHITE"     : "\e[37m",
	"B_BLACK"   : "\e[40m",
	"B_RED"     : "\e[41m",
	"B_GREEN"   : "\e[42m",
	"B_ORANGE"  : "\e[43m",
	"B_YELLOW"  : "\e[1m\e[43m",
	"B_BLUE"    : "\e[44m",
	"B_MAGENTA" : "\e[45m",
	"B_CYAN"    : "\e[46m",
	"B_WHITE"   : "\e[47m",
	"CLEARLINE" : "\e[L\e[G",
	"INITTERM"  : "\e[H\e[2J",
	"HOME"      : "\e[H",
	"SAVE"      : "\e7",
	"RESTORE"   : "\e8",
	]),
      "xterm" : default_termcap +
      ([
	"RESET"     : "\e[m",
	"BELL"      : "",
	"HOME"      : "\e[H",
	"BOLD"      : "\e[1m",
	"FLASH"     : "\e[5m",
	"INVERSE"   : "\e[7m",
	"CLEARLINE" : "\e[L\e[G",
	"INITTERM"  : "\e[H\e[2J",
      ]),
      /* FreeBSD Console -- subset of ANSI */
      "cons25" : default_termcap +
      ([
	"RESET"     : "\e[0m",
	"BOLD"      : "\e[1m",
	"UNDERSCORE": "\e[4m",
	"FLASH"     : "\e[5m",
	"INVERSE"   : "\e[7m",
	"BLACK"     : "\e[30m",
	"RED"       : "\e[31m",
	"GREEN"     : "\e[32m",
	"ORANGE"    : "\e[33m",
	"YELLOW"    : "\e[1m\e[33m",
	"BLUE"      : "\e[34m",
	"MAGENTA"   : "\e[35m",
	"CYAN"      : "\e[36m",
	"WHITE"     : "\e[37m",
	"B_BLACK"   : "\e[40m",
	"B_RED"     : "\e[41m",
	"B_GREEN"   : "\e[42m",
	"B_ORANGE"  : "\e[43m",
	"B_YELLOW"  : "\e[1m\e[43m",
	"B_BLUE"    : "\e[44m",
	"B_MAGENTA" : "\e[45m",
	"B_CYAN"    : "\e[46m",
	"B_WHITE"   : "\e[47m",
	"CLEARLINE" : "\e[2K",
	"INITTERM"  : "\e[H\e[2J",
	"HOME"      : "\e[H",
	]),
      ]);
}


string*
query_supported_termtypes()
{
  if( !nullp(database) )
    return keys(database);
  else
    return ({ });  // shouldn't happen
}


string
translate(string msg, string ttype, int width)
{
  mapping translations;

  if( nullp(database) )
    return msg;  // shouldn't happen
  else if( undefinedp(translations = database[ttype]) )
    return msg;  // shouldn't happend if termtype is set up correctly
  else
    return terminal_colour(msg, translations, width);
}
