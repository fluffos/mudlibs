/*
* FILE: tower.c
* DESC: An observation deck with a telescope.
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
  add_action("look_through", "look");
}

void create()
{
  ::create();
  seteuid( getuid() );
  set( "author", "gasman");
  set( "light", 1 );
  set( "short", "An obversaton deck" );
  set( "long", wrap(
"You stand atop of a large tower. From up here you have a pretty "+
"decent view of"+CITY_NAME+". You see a telescope mounted to "+
"the decking of the obversation deck."
  ));

 set("item_desc", ([
      "deck" : "An observation deck on top of a large tower.\nYou are standing on it.\n",
      "decking" : "An observation deck on top of a large tower.\nYou are standing on it.\n",
      "observation deck" : "An observation deck on top of a large tower.\nYou are standing on it.\n",
      "telescope" : "The telescope is mounted on a tripod which is fastened to the observation deck.\nYou might want to look through it.\n",
 ]));

  set( "exits", ([
    "down"  : O_ROOM+"path2",
  ]) );
}


string look_through(string arg)
{
  if(!arg) return;
  switch(arg)
  {
    default : 
       return;
    break;
    case "through telescope" :
       switch(random(3))
       {
         case 1 :
           write(wrap(
                "You peer into the telescope.\n"+
                "You have a close up view of"+CITY_NAME+" from here. "+
                "You can clearly see the renovated towers and temples of this ancient "+
                "city."
                ));
           return "";
         break;
	 case 2 :
	    write(@EndText
  ` : | | | |:  ||  :     `  :  |  |+|: | : : :|   .        `              .
      ` : | :|  ||  |:  :    `  |  | :| : | : |:   |  .                    :
         .' ':  ||  |:  |  '       ` || | : | |: : |   .  `           .   :.
                `'  ||  |  ' |   *    ` : | | :| |*|  :   :               :|
        *    *       `  |  : :  |  .      ` ' :| | :| . : :         *   :.||
             .`            | |  |  : .:|       ` | || | : |: |          | ||
      '          .         + `  |  :  .: .         '| | : :| :    .   |:| ||
         .                 .    ` *|  || :       `    | | :| | :      |:| |
 .                .          .        || |.: *          | || : :     :|||
        .            .   . *    .   .  ` |||.  +        + '| |||  .  ||`
     .             *              .     +:`|!             . ||||  :.||`
 +                      .                ..!|*          . | :`||+ |||`
     .                         +      : |||`        .| :| | | |.| ||`     .
       *     +   '               +  :|| |`     :.+. || || | |:`|| `
                            .      .||` .    ..|| | |: '` `| | |`  +
  .       +++                      ||        !|!: `       :| |
              +         .      .    | .      `|||.:      .||    .      .    `
          '                           `|.   .  `:|||   + ||'     `
  __    +      *                         `'       `'|.    `:
"'  `---"""----....____,..^---`^``----.,.___          `.    `.  .    ____,.,-
    ___,--'""`---"'   ^  ^ ^        ^       """'---,..___ __,..---""'
--"'                           ^                         ``--..,__
EndText
);
	 return "";
	 break;
	 default :
	   write("You see a dark foreboding creature pacing on a roof deck.\n");
	   return "";
	   break;
	 }
    break;
  } 
}
