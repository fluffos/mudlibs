//  -*- LPC -*-
// more.c:  Pager for viewing files and arrays..inherited by user object
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
// Created by Tim 31 Jul 1996
//
// 09.03.96  Tim@Dysfunctional Mud
//         o Changed check for MORE_EXIT_END env to MORE_NO_EXIT_END.  Default
//           behavior is now the opposite of before.
//

//
// Global Variables
//
private string morestring; // displayed at end of each page

private function callback; // function called when done paging
private function redraw;   // function called to redraw screen

private int s_length;      // screen length
private int start, prev;   // first line to display and line from prev screen

private int length;        // number of lines in file
private mixed file;        // (string | string*) filename or array

private int in_help;       // 1 if we are at the help screen

//
// Notification messages
//
#define NOTIFY_END  "%^INVERSE%^(END)%^RESET%^ [hit 'q' to continue]"
#define NOTIFY_MORE "%%^INVERSE%%^--MORE--%%^RESET%%^"
#define NOTIFY_INST " [<spacebar> for more, 'h' for help]"
#define NOTIFY_CONT "%^INVERSE%^Hit any key to Continue%^RESET%^"

//
// Used to properly display text to user
//
#define display(x) receive_message("system", x);

//
// Prototypes
//
void receive_message(string msg_class, string msg);
mixed get_env(string var);

//
//
private:
//
//

//
// returns -1 or else number of blank lines to draw if EOF
//
int
redraw_file()
{
  string text = read_file(file, start, s_length - 1);

  if( !text )
  {
    start = prev;
    text = read_file(file, start, s_length - 1);
  }
  display("\n" + text);
  prev = start;
  start += s_length - 1;

  // make sure we can read the next screen
  // we don't subtract 1 due to the way lines are being counted...
  if( !read_file(file, start, 1) )
    return s_length - sizeof(explode(text, "\n"));
  else
    return -1;
}

//
// returns -1 or else number of blank lines to draw if EOF
//
int
redraw_array()
{
  string text = implode(file[start-1..start + s_length - 3], "");

  if( start > length )
  {
    start = prev;
    text = implode(file[start-1..start + s_length - 3], "");
  }
  display("\n" + text);
  prev = start;
  start += s_length - 1;

  // make sure we can display another screen
  if( start > length )
    return start - length - 1;
  else
    return -1;
}

void
more_show_help()
{
  display("\n");                       // Clear screen if applicable
  display("Help for MORE:\n\n"
	  +"<spacebar>    Show next page\n"
	  +"u,b           Go back to the previous page\n"
	  +"h             Show this help\n"
	  +"s             Skip 1 page\n"
	  +"q             Quit\n");

  for(int i = 1; i < s_length - 7; i++) display("\n");

  display(NOTIFY_CONT);
  return;
}

void
more_loop(string input)
{
  int blanks;

  if( !in_help )
  {
    switch( input[0] )
    {
    case ' ': case 0:                      // show NEXT page
      break;
    case 13:
      start = prev + 1;
      break;
    case 'h' :                             // show HELP
      start = prev;
      in_help = 1;
      more_show_help();
      get_char((: more_loop :), 1);
      return;
    case 's' :                             // SKIP FORWARD one page
      display("Skipping 1 page...\n");
      start += s_length - 1;
      break;
    case 'u' :
    case 'b' :                             // BACK one page
      start -= 2 * (s_length - 1);
      if( start < 1 ) start = 1;
      break;
    case 'q' :                             // Only way out
      display("\n");                       // need a newline
      evaluate(callback);
      return;
    default :
      get_char((: more_loop :), 1);
      return;
    }  /* switch(input) */
  }
  else in_help = 0;

  //
  // Display and draw blanks if needed (and wanted)
  //
  if( (blanks = evaluate(redraw)) >= 0 )
  {
    if( !get_env("MORE_NO_EXIT_END") )
    {
      evaluate(callback);
      return;
    }
    else
    {
      for(int i = 1; i <= blanks; i++)
	display("~\n");
      start = prev;
      display(NOTIFY_END);
    }
  }
  else
  {
    display(sprintf(morestring, (start-1) * 100 / length, NOTIFY_INST));
  }
  get_char((: more_loop :), 1);
}

//
//
public:
//
//

varargs int
more(mixed file_or_array, function callbk)
{
  file = file_or_array;
  start = prev = 1;
  s_length = get_env("LENGTH");
  callback = callbk;
  in_help = 0;

  if( !s_length )
    s_length = 80;

  if( arrayp(file) )
  {
    file = map(file, (: $1 + "\n" :));   // add newlength
    length = sizeof(file);
    redraw = (: redraw_array :);
    morestring = NOTIFY_MORE " (%d%%) %s";
  }
  else
  {
    length = file_length(file);
    redraw = (: redraw_file :);
    morestring = (string) file + ": (%d%%) %s";
  }

  more_loop("");
  return 1;
}
