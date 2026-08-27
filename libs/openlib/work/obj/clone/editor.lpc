// editor.c: editor for entering text
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
// Written 12.10.95 by Tim (astasia@iastate.edu)

void enter_text(function call_func, function abort_func, mixed* args ... );
void get_text(string input, int count, function call_func,
	      function abort_func, mixed* args);

string* lines;

void
create()
{
  lines = ({});
}

void
enter_text(function call_func, function abort_func, mixed* args ... )
{
  write("Type ** on a line by itself to end; ~q to quit.\n");
  write("1>");
  input_to( (:get_text:), 0, 2, call_func, abort_func, args );
}

void
get_text(string input, int count, function call_func, function abort_func,
	 mixed* args)
{
  switch(input) {
    case "**":
      evaluate(call_func, lines, args ... );
      destruct(this_object());
      break;
    case "~q":
      if(abort_func)
	evaluate(abort_func, lines, args ... );
      destruct(this_object());
      break;
    default:
      lines += ({ input });
      printf("%d>", count++);
      input_to( (:get_text:), 0, count, call_func, abort_func, args );
  }
}
