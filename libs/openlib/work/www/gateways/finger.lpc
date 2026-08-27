/*  -*- LPC -*-  */
// finger.c:  finger gateway for WWW
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
//   Hastily coded by Tim on 11/1/95
//   Rewritten somewhat by Tim 29 Aug 1996
//

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

//
// header for generic finger
//
private string gen_header = @ENDHTML
<HTML>
<HEAD><TITLE>%s Finger Lookup</TITLE></HEAD>
<BODY bgcolor=##9370DB link=#00FFFF>
<H1>Users Currently on %s</H1>
<HR>
<UL>
ENDHTML;

//
// header for specific finger
//
private string spec_header = @ENDHTML
<HTML>
<HEAD><TITLE>User Information</TITLE></HEAD>
<BODY bgcolor=##9370DB link=#00FFFF>
<H1>Information for %s</H1>
<HR>
ENDHTML;

//
// footer for all pages
//
private string footer = @ENDHTML
<HR>
<H1>Enter a Username Below for Detailed Information</H1>
<FORM ACTION="/gateways/finger">
  <P><INPUT TYPE=TEXT NAME=username MAXLENGTH=12>
  <P><INPUT TYPE=SUBMIT VALUE=Submit> <INPUT TYPE=RESET VALUE=Reset>
</FORM>
<HR>
<A HREF="/index.html">Back to Main Page</A>
<ADDRESS>
<I>%s</I> /
<A HREF="mailto:%s">%s</A>
</ADDRESS>
</BODY>
</HTML>
ENDHTML;

void
create()
{
  string mn = mud_name();
  
  spec_header = sprintf(spec_header, mn, mn);
  footer = sprintf(footer, mn, ADMIN_EMAIL, ADMIN_EMAIL);
}

//
// PRE: 'args' can be specified as 0 for a general finger, a username, or
//      "username=" + a username
varargs
string
gateway(string args)
{
  string who, ret = "";

  if( !args )
  {
    object user;
    foreach(user in users())
      ret  += sprintf("<LI> %s\n", user->short());
    return gen_header + ret + "</UL>\n" + footer;
  }
  else
  {
    if( sscanf(args, "username=%s", who) != 1 || !strlen(who) )
      who = args;
    who = lower_case(who);
    return sprintf(spec_header + "<PRE>%s</PRE>\n" + footer, capitalize(who),
		   FINGER_D->GetFinger(who));
  }
}
