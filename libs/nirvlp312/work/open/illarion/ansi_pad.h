/* ansi_pad.h and ansi_pad.c provide replacements for the pad and format
 * functions that account for ansi codes.  They ignore ansi codes when
 * caculating string lengths, but leave any codes within the correct length
 * intact.  This makes them useful especially for formatting channels and
 * titles, which tend to change the amount of ansi they have in them.
 * #include the .h file in whatever files you want the functions available
 * in.  Make sure the .h and .c files are in the same dir, and that you
 * change the local_dir #define below to match the dir you put them in.
 *
 * Setting it up like this will let you use the functions regardless of
 * what ansi defs you use, so it's highly recommended.
 */
#define LOCAL_DIR "/players/guilds/bards/lib/"
string ansi_pad(string str,int limit) {
  return (string)call_other(LOCAL_DIR+"ansi_pad","ansi_pad",str,limit);
}
string ansi_format(string str,int columns) {
  return (string)call_other(LOCAL_DIR+"ansi_pad","ansi_format",str,columns);
}
