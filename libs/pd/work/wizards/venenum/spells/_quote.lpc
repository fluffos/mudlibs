/*

Quote is a simple ability by Venenum. It provides
meaningful, inspiring, motivating, demotivating and
witty comments for any user.

*/

#include <std.h> 
#include <daemons.h>
inherit DAEMON;
int abil(); 

string *messages = ({"The shoe that fits one person pinches another; there is no recipe for living that suits all cases. - Carl Jung (1875 - 1961)", 
  "You've got to be original, because if you're like someone else, what do they need you for? - Bernadette Peters, Inside the Actors Studio", 
  "Good ideas are not adopted automatically. They must be driven into practice with courageous patience. - Hyman Rickover (1900 - 1986)", 
  "My doctor gave me two weeks to live. I hope they're in August. - Ronnie Shakes", 
  "Man is the only animal that laughs and has a state legislature. - Samuel Butler (1835 - 1902)", 
  "Do not protect yourself by a fence, but rather by your friends. - Czech Proverb", 
  "Don't complain about growing old - many, many people do not have that privilege. - Earl Warren (1891 - 1974), Chief Justice", 
  "What we play is life. - Louis Armstrong (1900 - 1971)", 
  "I like long walks, especially when they are taken by people who annoy me. - Noel Coward (1899 - 1973)", 
  "The greatest of faults, I should say, is to be conscious of none. - Thomas Carlyle (1795 - 1881)",
  "It has been said that man is a rational animal. All my life I have been searching for evidence which could support this. - Bertrand Russell (1872 - 1970)",
  "To deny our own impulses is to deny the very thing that makes us human. - Andy & Larry Wachowski, The Matrix, 1999",
  "I have discovered that all human evil comes from this, man's being unable to sit still in a room. - Blaise Pascal (1623 - 1662)",
  "The fates have given mankind a patient soul. - Homer (800 BC - 700 BC), The Iliad",
  "I hate mankind, for I think myself one of the best of them, and I know how bad I am. - Joseph Baretti, quoted in Boswell's Life of Samuel Johnson",
  "You must not lose faith in humanity. Humanity is an ocean; if a few drops of the ocean are dirty, the ocean does not become dirty. - Mahatma Gandhi (1869 - 1948)",
  "It was enough to make a body ashamed of the human race. - Mark Twain (1835 - 1910), The Adventures of Huckleberry Finn",
  "Man is the Only Animal that Blushes. Or needs to. - Mark Twain (1835 - 1910), Following the Equator (1897)",
  "I think that God in creating Man somewhat overestimated his ability. - Oscar Wilde (1854 - 1900)"});

int cmd_quote() {

    if (!abil())
	return 0;
    if(this_player()->query_ghost()) {
	notify_fail("You cannot do that as a ghost.\n");
	return 0;
    }

    if (this_player()->query_disable())
    {
	write("Slow down there, mate.");
	return 1;
    }

    if((int)this_player()->query_sp() < 0) {
	notify_fail("You are too tired.\n");
	return 0;
    }

    this_player()->set_disable();

    tell_object(this_player(),messages[random(sizeof(messages))]+"\n");

    return 1;

}



void help() {

    write("Syntax: <quote>\n\n"
      "Quote is a simple ability which attempts to provide meaningful, inspiring, motivating or witty comments for any user.");

}



int abil() {

    if (this_player()->query_subclass() != "black") return 0;
    if (this_player()->query_level() < 40) return 0;

    return 1;

}
