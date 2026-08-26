/**
 * Generates random names for whatever reason.
 * <p>
 * Werd - a perl script that generates random words according to some
 *        simple rules (inspired by phrase structure trees in Syntax).
 * <p>
 * Based on a program by Mark Rosenfelder (markrose@spss.com)
 *        called psrGrammar
 * <p>
 * Rewritten in perl by Chris Pound (pound@rice.edu)
 * <p>
 * Rewritten in lpc by Pinkfish@Discworld MUD.
 *        10th of January 1996.
 */
#include <random_names.h>
mapping rules;

void create() {
  seteuid("Room");
  rules = ([ ]);
  unguarded((: restore_object, RANDOM_NAME_SAVE_FILE :));
} /* create() */

/**
 * Read in a random name grammer from the data dir.  Any line with
 * # at the start is considered a comment, and anything after
 * a # on a line is ignored.  Every line in the file will have
 * 3 fields seperated by a :.  The first field is the name
 * the second is a one letter expansion string, the third is a
 * a space separeted list of things to expand it to.
 * <p>
 * The word starts off as a "W", this is looked up in the expansion
 * first string list.  If it is found then that is expanded to 
 * a random selection of the space seperated data elements.  This
 * process is repeated until there are no bits in the word that can
 * be expanded.
 * @param f the name of the file to read
 */
void open_file(string f) {
  string str, *bits, *stuff, lang;
  int i;

  bits = explode(f, ".");
  if (sizeof(bits) > 1)
    lang = implode(bits[0..sizeof(bits)-2], ".");
  else
    lang = f;
  lang = replace(lang, "_", " ");

  str = unguarded((: read_file, RANDOM_NAME_DATA_DIR+f :));
  bits = explode(str, "\n");
  rules[lang] = ([ ]);
  for (i=0;i<sizeof(bits);i++) {
    sscanf(bits[i], "%s#%*s", bits[i]);
    if (strlen(bits[i])) {
      stuff = explode("G"+bits[i], ":");
      if (sizeof(stuff) >= 3)
        rules[lang][stuff[1]] = stuff[2];
      else
        write("Incorrect file format at line "+i+".\n");
    }
  }
  unguarded((: save_object, RANDOM_NAME_SAVE_FILE :));
} /* open_file() */

/**
 * Generate a random name in the given language.
 * @param lang the language to generate teh name int
 * @return the random name
 */
string random_name(string lang) {
  string word = "W", *bing;
  int some_caps = 1, i;

  do {
    some_caps = 0;
    for (i = 0; i < strlen(word); i++)
      if (word[i] >= 'A' && word[i] <= 'Z') {
        bing = explode(rules[lang][word[i..i]], " ") - ({ "" });
        word = word[0..i-1] + bing[random(sizeof(bing))] + word[i+1..];
        some_caps = 1;
      }
  } while (some_caps);
  return word;
} /* random_name() */

/**
 * The list of all the current languages known.
 * @return an array of the language names.
 */
string *query_languages() { return keys(rules); }

/**
 * Return a name that is not banished or a player name already.
 * It is > 2 and < 11 chars, it is not banished, a player or
 * in the game.
 * @param lang the language to generat ethe name in
 * @return the generated name
 */
string unique_name(string lang) {
  string str;
  int ok;

  do {
    ok = 1;
    str = random_name(lang);
    if (strlen(str) < 2 || strlen(str) > 11)
      ok = 0;
    if (ok && "/secure/login"->test_user(str))
      ok = 0;
    if (ok && file_size("/banished/"+str+".o") > 0)
      ok = 0;
    if (ok && find_living(str))
      ok = 0;
  } while (!ok);
  return str;
} /* unique_name() */

/** @ignore yes */
void dest_me() {
  destruct(this_object());
} /* dest_me() */
