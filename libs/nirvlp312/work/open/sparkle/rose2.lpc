/*
 *  A red rose that you can smell.
 *  Read WOLFSKIN.c, than this file, than WHISTLE.c
 *  This is an alternate way to write an object, without using
 *    the inheritance of another object.
 *                                           -- Saber
 */

/* You inherit this file in any custom item where you are not
       going to inherit any other file.                        */
#include </players/tallos/ansi.h>
       inherit "obj/clean";

/* This name of an object.  Notice that str can be equal to either
        the word rose or red rose.  If the code had read
        return str == "rose" || str == "red rose" || str == "flower";
        than the rose would respond to the name 'flower' as well   */
id(str)  {
return str == "rose" || str == "red rose";
}

/* The appearance in your inventory  */
short()  {  return "A small "+HIM+"purple rose"+NORM+"";  }

/* The items appearance when you look at it  */
long()  {
    write("This is a special "+HIM+"purple rose"+NORM+" for"+HIM+" Sparkle."+NORM+" It is very beautiful to look at.\n"+
    "Yet somehow it pales in comparison to the beauty of "+HIM+"Sparkle"+NORM+" herself.\n");
}

/* This lets you pick up the item.  If it had been 0, you could NOT
        pick up the rose.   */
get()  { return 1;  }

/* How much does the rose weigh?  */
query_weight()  {  return 1;  }

/* How much is the rose worth?  */
query_value()  {  return 1;  }

/* This initializes a new action with the add_action() command.
     The first word is what will be called when the second word
     is typed.  Thus, when smell is written, the function smell_rose
     is called within the object.       */
init()  {
 add_action("smell_rose", "smell");
}

/* The function called when 'smell' is typed.  */
smell_rose(str)  {

/* If no string is typed, or if the string does not match the name
      of the object (in this case the rose) than the return 0 will
      return false  (in other words, it will say 'what?'    */
  if((!str) || !id(str))  {
  return 0;
}

/*  What the player will see if they smell the rose.  */
write("You smell the sweet fragrance of the "+HIM+"rose"+NORM+".\n");

/* What others will see if the player smells the rose.  */
/* Note that this checks the name of the player calling the action. */
say(this_player()->query_name()+" smells the "+HIM+"purple rose"+NORM+".\n");

return 1;
}
