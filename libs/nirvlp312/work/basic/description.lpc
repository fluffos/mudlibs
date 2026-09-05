/*
 * basic/description.c - Give a description to an object.
 */

#pragma strong_types

#include <message.h>
#include <libs.h>

string query_composite_long (string str);

private mixed short_desc;
private mixed long_desc;
private mixed extra_long_desc, extra_look_desc;
private mixed name_desc;


//***************** The part of name/short/long descriptions *****************

// The short description should not have a newline at the end, nor a '.'.
// varargs necessary because of complex/room::set_short
varargs void set_short(mixed str) {
  short_desc = str;
}

// The long description should include a newline at the end.
// varargs necessary because of complex/room::set_long
varargs void set_long(mixed str) {
  long_desc = str;
}

void set_extra_long(mixed str) {
  extra_long_desc = str;
}

void set_extra_look(mixed str) {
  extra_look_desc = str;
}

// Since describe allows even invisible objects to be described with their
// name, it should be possible for every object to have one
void set_name(mixed name) {
  name_desc = name;
}

string query_name() {
  return funcall(name_desc);
}

string query_short() {
  return funcall(short_desc);
}

varargs string query_long(string str) {
  return funcall(long_desc ? long_desc : query_composite_long(str), str);
}

// Because several objects from /complex overload the three functions above,
// there must be a way to provide the name, short and long description.
string query_real_name() {
  return funcall(name_desc);
}

string query_real_short() {
  return funcall(short_desc);
}

#if 1  // Trying to keep things simple
string query_real_long() {
  return funcall(long_desc);
}
#else
varargs string query_real_long(string str) {
  return funcall(long_desc ? long_desc : query_composite_long(str));
}
#endif

string query_description_long(string str) {
  return funcall(long_desc ? long_desc : query_composite_long(str));
}

string short() {
  return query_short();
}

varargs string long(string str) {
  return query_long(str);
}

string extra_long() {
  return funcall(extra_long_desc);
}

mixed extra_look() {
  return funcall(extra_look_desc);
}

/* this is just for timedepdesc */
void set_description_long(mixed str) {
  long_desc = str;
}

string query_composite_long(string str) {
  return 0;
}


//*********** The part of taste/smell/touch/sound descriptions ****************

private mixed taste;
private mixed smell;
private mixed touch;
private mixed sound; 
private mixed colour;

void set_taste(mixed m) {
  taste = m;
}

void set_smell(mixed m) {
  smell = m;
}

void set_touch(mixed m) {
  touch = m;
}

void set_sound(mixed m) {
  sound = m;
}

void set_colour(mixed c) {
  colour = c;
}

varargs string query_taste(string id) {
  string res;
  if (closurep(taste))
    res = funcall(taste, id);
  else
    res = taste;
  if (!res)
    return 0;                   // it has no special taste (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "taste",
                                      " " + res + ".\n" })));
}

varargs string query_smell(string id) {
  string res;
  if (closurep(smell)) 
    res = funcall(smell, id);
  else
    res = smell;
  if (!res)
    return 0;                   // it has no special smell (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "smell",
                                      " " + res + ".\n" })));
}

varargs string query_touch(string id) {
  string res;
  if (closurep(touch))
    res = funcall(touch, id);
  else
    res = touch;
  if (!res)
    return 0;                   // it has no special touch (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_S, M_ME_PRONOUN, " touch ", M_ME_VERB,
                                      "be", " " + res + ".\n" })));
}

varargs string query_sound(string id) {
  string res;
  if (closurep(sound))
    res = funcall(sound, id);
  else
    res = sound;
  if (!res)
    return 0;                   // it has no special sound (COMMANDS_SENSE)
  if (res[<1] == '\n')          // complete sentence given
    return res;
  return capitalize(message2string(({ M_ME_PRONOUN, M_ME_VERB, "sound",
                                      " " + res + ".\n" })));
}

mixed query_colour() {
  return colour;
}

string query_real_taste() {
  return funcall(taste);
}

string query_real_smell() {
  return funcall(smell);
}

string query_real_touch() {
  return funcall(touch);
}

string query_real_sound() {
  return funcall(sound);
}

string query_colour_description() {
  return query_colour() && LIB_COLOURS->get_colour_name(query_colour());
}

// ********************** The part of other descriptions *********************

private mixed size;   // the size of compact items in cm, e.g. a ball
                      // if (intp()), then it's an absolute size
                      // if (stringp()), then it's a macro of <size.h>

mixed query_size() {
  return size;
}

void set_size(mixed s) {
  if (intp(s)) {
    if (s > 0)
      size = s;
  }
  else
    size = s;
}


