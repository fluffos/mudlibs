#include <simul_efun.h>

/*
File     : identify.c
Syntax   : varargs string identify(mixed a, string indent)
Purpose  : identify the variable 'a' as a string.
92-12-12 : Pallando wrote this function, based on ones he wrote
           for Ephemeral Dales and other muds.
93-03-03 : Pallando@TMI-2 added floats
93-03-28 : Pallando changed implode(explode()) to replace_string()
           Pallando@Nightmare added replacement of \\ and \"
93-08-19 : Pallando added check for recursive arrays and mappings
           Pallando added check for too deep recursion
93-09-09 : Pallando@CWLIB added indent option
           Pallando included config.h (for __tmi__) and origin.h
*/
#include <origin.h>

#define MAX_RECURSION 20

private nosave mapping found;
private nosave string *position;
private nosave int recursion;

/**
 * Converts a variable to its string representation for debugging purposes,
 * handling various data types and preventing deep recursion.
 *
 * @param {mixed} a - The variable to identify.
 * @param {string} [indent=""] - The indentation string to use for formatting.
 * @returns {string} The string representation of the variable.
 */
varargs string identify(mixed a, string indent) {
  int i, s;
  string ind, rec, ret;
  mapping map;

  if(origin() != ORIGIN_LOCAL) {
    found = ([ ]);
    position = allocate(MAX_RECURSION + 1);
    recursion = 0;
    position[recursion] = "X";
  }

  ind = "";
  if(stringp(indent))
    for(i = 0; i < recursion; i++)
      ind += indent;

  if(undefinedp(a))
    return ind + "UNDEFINED";

  if(nullp(a))
    return ind + "0";

  if(intp(a))
    return ind + a;

  if(floatp(a))
    return ind + a;

  if(objectp(a)) {
    if(stringp(ret = call_if(a, "query_name")))
      ret += " ";
    else
      ret = "";
    return ind + "OBJ(" + ret + file_name(a) + ")";
  }

  if(bufferp(a))
    return ind + sprintf("%O", a);

  if(stringp(a)) {
    a = replace_string(a, "\"", "\\\"");
    a = "\"" + a + "\"";
    a = replace_string(a, "\\", "\\\\");
    a = replace_string(a, "\\\"", "\"");
    a = replace_string(a, "\n", "\\n");
    a = replace_string(a, "\r", "\\r");
    a = replace_string(a, "\t", "\\t");
    return ind + a;
  }

  if(valid_function(a))
    return ind + sprintf("%O", a);

  if(recursion == MAX_RECURSION)
    return ind + "TOO_DEEP_RECURSION";

  if(classp(a))
    return ind + "CLASS(" + identify(disassemble_class(a)) + ")";

  if(pointerp(a)) {
    found[a] = implode(position[0..recursion], "");

    if(!(s = sizeof(a)))
      return ind + "({ })";

    recursion++;
    ret = "";

    for(i = 0; i < s; i++) {
      position[recursion] = "[" + i + "]";

      if(!(rec = found[a[i]]))
        rec = identify(a[i], indent);

      ret += (i ? (indent ? ",\n" : ", ") : "") + rec;
    }

    recursion--;

    if(!indent)
      return "({ " + ret + " })";

    return ind + "({\n" + ret + "\n" + ind + "})";
  }

  if(mapp(a)) {
    found[a] = implode(position[0..recursion], "");
    map = (mapping)(a);
    a = keys(map);

    if(!(s = sizeof(a)))
      return ind + "([ ])";

    recursion++;
    ret = "";

    for(i = 0; i < s; i++) {
      ret += (i ? (indent ? ",\n" : ", ") : "");
      position[recursion] = ".KEY(" + i + ").";
      if(!(rec = found[a[i]]))
        rec = identify(a[i]);
      ret += ind + (indent ? indent : "") + rec + " : ";
      position[recursion] = "[" + rec + "]";
      if(!(rec = found[map[a[i]]])) {
        if(indent && (
           (mapp(map[a[i]]) && sizeof(keys(map[a[i]]))) ||
           (pointerp(map[a[i]]) && sizeof(map[a[i]])))
        )
          rec = "\n" + identify(map[a[i]], indent);
        else
          rec = identify(map[a[i]]);
      }
      ret += rec;
    }

    recursion--;

    if(!indent)
      return "([ " + ret + " ])";

    return ind + "([\n" + ret + "\n" + ind + "])";
  }

  return ind + "UNKNOWN";
}

/**
 * Converts a variable to its string representation in JavaScript-like format,
 * handling various data types and preventing deep recursion.
 *
 * @param {mixed} a - The variable to represent as a JS-like string.
 * @param {string} [indent=""] - The indentation string to use for formatting.
 * @returns {string} The JS-like string representation of the variable.
 */
varargs string j(mixed a, string indent) {
  int i, s;
  string ind, rec, ret;
  mapping map;

  if(origin() != ORIGIN_LOCAL) {
    found = ([ ]);
    position = allocate(MAX_RECURSION + 1);
    recursion = 0;
    position[recursion] = "X";
  }

  ind = "";
  if(stringp(indent))
    for(i = 0; i < recursion; i++)
      ind += indent;

  if(undefinedp(a))
    return ind + "undefined";

  if(nullp(a))
    return ind + "null";

  if(intp(a))
    return ind + a;

  if(floatp(a))
    return ind + a;

  if(objectp(a)) {
    if(stringp(ret = call_if(a, "query_name")))
      ret += " ";
    else
      ret = "";
    return ind + "{\"type\":\"object\",\"name\":\"" + ret + file_name(a) + "\"}";
  }

  if(bufferp(a))
    return ind + "\"" + sprintf("%O", a) + "\"";

  if(stringp(a)) {
    a = replace_string(a, "\"", "\\\"");
    a = "\"" + a + "\"";
    a = replace_string(a, "\\", "\\\\");
    a = replace_string(a, "\\\"", "\"");
    a = replace_string(a, "\n", "\\n");
    a = replace_string(a, "\r", "\\r");
    a = replace_string(a, "\t", "\\t");
    return ind + a;
  }

  if(valid_function(a))
    return ind + "\"" + sprintf("%O", a) + "\"";

  if(recursion == MAX_RECURSION)
    return ind + "\"TOO_DEEP_RECURSION\"";

  if(classp(a))
    return ind + "{\"type\":\"class\",\"value\":" + j(disassemble_class(a)) + "}";

  if(pointerp(a)) {
    found[a] = implode(position[0..recursion], "");

    if(!(s = sizeof(a)))
      return ind + "[]";

    recursion++;
    ret = "";

    for(i = 0; i < s; i++) {
      position[recursion] = "[" + i + "]";

      if(!(rec = found[a[i]]))
        rec = j(a[i], indent);

      ret += (i ? (indent ? ",\n" : ", ") : "") + rec;
    }

    recursion--;

    if(!indent)
      return "[" + ret + "]";

    return ind + "[\n" + ret + "\n" + ind + "]";
  }

  if(mapp(a)) {
    found[a] = implode(position[0..recursion], "");
    map = (mapping)(a);
    a = keys(map);

    if(!(s = sizeof(a)))
      return ind + "{}";

    recursion++;
    ret = "";

    for(i = 0; i < s; i++) {
      ret += (i ? (indent ? ",\n" : ", ") : "");
      position[recursion] = ".KEY(" + i + ").";
      if(!(rec = found[a[i]]))
        rec = j(a[i]);
      ret += ind + (indent ? indent : "") + rec + ": ";
      position[recursion] = "[" + rec + "]";
      if(!(rec = found[map[a[i]]])) {
        if(indent && (
           (mapp(map[a[i]]) && sizeof(keys(map[a[i]]))) ||
           (pointerp(map[a[i]]) && sizeof(map[a[i]])))
        )
          rec = "\n" + j(map[a[i]], indent);
        else
          rec = j(map[a[i]]);
      }
      ret += rec;
    }

    recursion--;

    if(!indent)
      return "{" + ret + "}";

    return ind + "{\n" + ret + "\n" + ind + "}";
  }

  return ind + "\"UNKNOWN\"";
}
