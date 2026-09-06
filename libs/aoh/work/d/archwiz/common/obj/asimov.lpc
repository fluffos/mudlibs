/* this is a file I got from Marge, wrote in 2.4.5 */
/* I am converting it to 3.X so it will work again */
/* ----------------------------------------------------------------- */
/* I found this file - with the above comments - in a directory of   */
/* Grough - I guess the above comment is his. As a couple of         */
/* 2.4.5-specific things still remained in the code and caused some  */
/* problems, I rewrote it to comply more to the Nightfall mudlib and */
/* to make it a little bit more memory-efficient.                    */
/*         Dagobert, January 11th, 1994                              */

inherit "/std/thing";
inherit "/obj/lib/string";
#include <properties.h>

string* text=
({
"\
Asimov wrote a short story called 'Nightfall' when he was 21 years old.\n\
It is perhaps his best known work.  Rest in peace, Isaac. We'll miss you.\n\
\n",

"\
From: minsky@media.mit.edu (Marvin Minsky)\n\
Subject: Re: ASIMOV\n\
Date: Sat, 11 Apr 1992 00:32:31 GMT\n\
\n\
        I first encountered Asimov's ideas some 50 years ago. I was just\n\
  beginning my teens and he was only in his early 20's- yet he seemed\n\
  centuries ahead.  I was entranced by his stories about space and time,\n\
  but the ideas about robots affected me most and after 'Runaround'\n\
  appeared in the March 1942 issue of Astounding, I never stopped\n\
  thinking about how minds might work.  Surely we'd some day build\n\
  robots that think --but how would they think, and about what?  Surely\n\
  logic might work for some purposes, but not for others.  And how to\n\
  build robots with common sense, intuition, consciousness, and emotion?\n\
  How, for that matter, do brains do those things?  And in the same\n\
  period, Robert A. Heinlein's 1940 novel 'Waldo' was already turning me\n\
  to think about the mechanical aspects of robots.\n\
\n\
        Having just exhausted the teachings of Jules Verne and\n\
  H.G.Wells, these stories (along with those of Arthur C. Clarke,\n\
  Frederik Pohl, and Ted Sturgeon) arrived just in time for me -- and\n\
  eventually I came to share the personal friendship of these great\n\
  teachers.  Why call them 'teachers'?  Because they show us ways to\n\
  explore new ideas by exercising the vital 'what if' capacity that so\n\
  often declines as we grow older and more sensible.  Another such\n\
  writer, Larry Niven, once explained, 'our job is to keep on\n\
  daydreaming for you.'\n\
\n\
       Isaac always encouraged his readers to try to see the world as\n\
  comprehensible, to despise superstition and moral cowardice, and to\n\
  think and speak as clearly and simply as possible.  He was never\n\
  falsely modest, but was always honest, unpretentious, and humorous.\n\
  To me he was among the finest of modern philosophers.\n\
\n\
  Marvin Minsky\n\
  Professor of Computer Science and E.E.\n\
  Toshiba Professor of Media Arts and Sciences,\n\
  Massachusetts Institute of Technology\n\
\n"
});



create() 
{ 
   ::create(); 
   SetShort("a statue of Isaac Asimov");
   SetLong(
"This a life-size statue of Isaac Asimov.\n\
At the base there is a plaque headed:\n\n\
   ISAAC ASIMOV  1920 - 1992\n");
   SetIds(({"statue","plaque","base","asimov","isaac","isaac asimov"}));
   Set(P_NOGET,"This statue is firmly fitted to the ground.\n");
}

init() 
{ 
   add_action("read_more", "read_more");
   add_action("read_more","read");
}

QueryLong() 
{
   say(this_player()->QueryName() +
       " studies the statue in quiet contemplation.\n");
   return ::QueryLong();
}
      

read_more(str)  
{

   if (!str || present(str)!=this_object())
   {
      notify_fail("Read what?\n");
      return 0;
   }

   write("                     ISAAC ASIMOV  1920 - 1992\n\n");

   if (random(2)==0)
   {
      write(text[0]);
   }
   else
   {
      smore (text[1]);
      say(this_player()->QueryName() +
	  " reads the plaque on the statue's base in quiet contemplation.\n");
   }
   return 1;
}


