/*
Color Tutorial by Tallos 05-03-07

This is a tutorial on how to add ansi color to your code. This is a working object that can be cloned if needed.
First off, in order to have color in your code you need to include a file which has the color definitions in it.
*/
inherit "obj/armor"; /* This tells the code that this object is an armor. Certain armor abilities and inherits are 
set by having this in your code.*/
 
#include "/players/tallos/ansi.h" /* This is the file that includes the color definitions for ansi for the mud. 
You must include this file using #include "file path" you must include the quotations for any include to be added
correctly to your  file. If you don't it will error.*/

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  
  set_name("Female Fairy Wings"); /* This is the game name for the item. It is not the file name, but it is the name that
  the game uses to distinguish it from other items. You can add ansi color to this if you wish but there is little use
  for color in the set_name field of an item since no one really sees this.*/
  
  set_alias("wings"); /* This gives an alternate name to your item. A player can type this along with the type of armor,
  in this case 'misc' to wear or unwear the item. 'wear wings' for example. There is no need to put ansi color in this field.*/ 
  
  set_short(""+HIM+"Fairy Wings"+NORM+""); /* the short of an item is the name that players see in their inventory. This is a
  great place to start using ansi color. Players like items of color in their inventory. (Notice the "+HIM+" in quotes? This means that any of the words after this point are Hi-Magenta. And
  the "+NORM+" sets the color back to normal low intensity white.)
  
  At this point take a look a the ansi.h file that is in my open directory. 
  
  To view it type more /open/tallos/ansi.h 
  
  You can use the enter key to scroll through the file. 
  
  You'll notice a serious of commands that look like this 'magenta = MAG' these are all the ansi functions that you can
  add to your code. For the purpose of this tutorial we will focus on the following:
  
  		/*  Foreground Colors  */
  		 
#define BLK ESC+"[30m"          /* Black    *//* You'll notice that there are two sets of colors*/
#define RED ESC+"[31m"          /* Red      */
#define GRN ESC+"[32m"          /* Green    */
#define YEL ESC+"[33m"          /* Yellow   *//*    <- Low intensity*/
#define BLU ESC+"[34m"          /* Blue     */
#define MAG ESC+"[35m"          /* Magenta  */
#define CYN ESC+"[36m"          /* Cyan     */
#define WHT ESC+"[37m"          /* White                                                        */
 
		/*   Hi Intensity Foreground Colors   */
 
#define HIR ESC+"[1;31m"        /* Red      */
#define HIG ESC+"[1;32m"        /* Green    *//* <- and Hi Intensity*/
#define HIY ESC+"[1;33m"        /* Yellow   */
#define HIB ESC+"[1;34m"        /* Blue     */
#define HIM ESC+"[1;35m"        /* Magenta  */
#define HIC ESC+"[1;36m"        /* Cyan     */
#define HIW ESC+"[1;37m"        /* White    */

/* The difference is that the low intensity are more dull and not as bright as the hi intensity ones. For example:

Hi magenta is more pink looking. While Low intensity magenta is more violet in color.*/

/* In the above short string you'll notice the "+MAG+" is used. This will set the name of the item that players see
to hi magenta which is much like a pink. If "+MAG+" was use instead it would be the low intensity magenta which is
more violet. The "+NORM+" resets the color to normal. 

Make sure in any short of long description that you have 
"+NORM+" at the end of that description. If you don't the color will bleed into other items below it in a players
inventory and in rooms or other objects. MAKE SURE TO HAVE "+NORM+" in at the end.*/
   
  set_long("A pair of "+HIM+"s"+HIW+"p"+HIM+"a"+HIW+"r"+HIM+"k"+HIW+"l"+HIM+"i"+HIW+"n"+HIM+"g pink wings"+NORM+" from a female "+HIG+"f"+NORM+""+GRN+"a"+HIG+"i"+NORM+""+GRN+"r"+HIG+"y"+NORM+".\n");
  /* This is the long description of the item. This descripion is what players see when they type 'look at itemname' 
  This is a great place to put color as well. You'll notice in the above description that it is a bit more complicated
  then the short. YOu can do amazing things with ansi color. This is just a small example. 
  
  You'll notice the word sparkling has a different color for each letter. This makes it much for flashy. The colors are
  hi magenta and high white. clone the object if you like to see what it look like. IF you want a different color you
  just have to use the name of the color abrev. as noted in the ansi.h file, or what is listed above. "HIM for hi magenta
  HIW for high white. You must have it in the form of "+HIM+" or +HIW+" for the game to assign it properly. If you don't
  it will error. 
  
  You'll notice that fairy is both low intensity green and hi. There is a trick to remember when using low and hi intenisty
  colors back to back. The hi intensity is so high that if you don't put a "+NORM+" after it, and you want to use a low
  intensity next, it will stay high. So just make sure to use "+NORM+" after your hi intensity colors before using a low
  one. Refer to how I have it placed above. You'll notice I have a "+NORM+" at the end of the long description. THIS IS
  AGAIN IMPORTANT, SO THAT THE COLOR DOES NOT BLEED!!!!
  
  You can add ansi color to all types of things that players see, not just short and long descriptions. You can use it for
  specials, writes, says, tell_objects, set_chat, etc. So play around with it.
  
  And thats it. There's really nothing else to it. Just use "+color abv+" before your words/letters to add your color and
  "+NORM+" to set the color back normal. Make sure you have #include "ansi.h path" at the top of your file, and have fun!
  
  
  HAPPY ANSING!!!!*/ 
   
  
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(150);
  set_params("magical", 0, 10, "void");
}