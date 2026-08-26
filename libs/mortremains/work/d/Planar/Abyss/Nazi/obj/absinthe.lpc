/*
** File: absinthe.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit OBJECT ;

void create() {
set("author", "nsd");
set ("id", ({ "absinthe", "bottle", "bottle of absinthe" }) );
set ("short", "A bottle of absinthe");
    set ("long", @EndText
This is an ancient drink that makes people have
hallucinations. Side effects are the following:
*Can cause delirium tremens
*Will make you see weird stuff
*Can make you a little weak

Although it doesn't sound attractive, it's the
only way out of this place. So stop complaining
and 'drink' it. After all, this is just a mud!!!
EndText
    );
    set ("mass", 0);
    set ("value", 0);
    set ("prevent_drop", 1);
    set ("prevent_insert", 1);
    set ("prevent_give", 1);
}
void init () {
add_action ("drink", "drink");
}
int drink(string str) {
    //a ! means not, what the if(!str) means is, if no string do this
    if (!str) {
write ("Drink what?\n");
	return 1;
    }
 if (str == "absinthe") {
write(wrap(
"You drink, and immediately get tipsy *oO*...\n"+
"You have a weird feeling of your head not belonging\n"+
"to your body...  You start to hallucinate... *oO*\n"));
say(TPN+" drinks "+POSS+" absinthe and starts to behave weird...\n");
this_player()->move_player("?");
	return 1;
    }
    return 1;
}

/* End of File */
