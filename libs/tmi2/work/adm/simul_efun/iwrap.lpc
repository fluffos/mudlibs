// iwrap.c
// Simul_efun to convert a string of text into lines which are indented,
// so that you can get effects like this:
// Line of text number one begins here, and it goes on for quite a long
//      ways, and it's indented at the left on the second and following
//      lines to make it easier to see where the entire piece of text
//      begins and where it ends.
// Useful for things like channels and tell commands where someone may
// run a couple of lines in a message.

// Hacked from a copy of wrap by Artagel Aug 12 1993.
// Leto changed it to use new range (v20.26+)

// D_SZ is the default length of the string, if no value is passed, and
// D_IN is the default indentation, if no value is passed.

#define D_SZ 71
#define D_IN 4

varargs string iwrap(string str, int width, int indent) {
  if (!width) 
    return sprintf("%s%-=*s\n", str[0..D_IN], D_SZ, str[(D_IN+1)..<1]);
  if (!indent)
    return sprintf("%s%-=*s\n", str[0..D_IN], width, str[(D_IN+1)..<1]);
  return sprintf("%s%-=*s\n", str[0..indent], width, str[(indent+1)..<1]);
}
