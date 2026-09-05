/*
 * kernel/simul/list.c
 *
 * This contains the simul_efuns concerning lists
 * Rumpemintz
 */

#include <describe.h>
#include <closures.h>
#include <libs.h>

#define PREPOSITIONS "of|to|from|with|on|about|over"

#include "/kernel/simul/array.h"

varargs mixed
make_list (string *items, mixed alternative, string and, string comma) {
  return (sizeof (items) > 1
          ? implode(items[0..<2], (comma ? comma : ", ")) +
            (and ? and : " and ") + items[<1]
          : (sizeof(items) ? items[<1] : alternative));
}

private void
add_token(mixed token, closure f, mixed *args, mapping maps) {
  mixed key;

  key = apply(f, token, args);
  if (!maps[key])
    maps[key] = ({ token });
  else
    maps[key] += ({ token });
}

varargs mapping
factorize(mixed *tokens, closure f, mixed *args) {
  mapping maps;

  if (!f) {
    f = symbol_function("describe");
    if (!args)
      args = ({ARTICLE_NONE});
  } else if (!args)
    args = ({ });
  maps = ([ ]);
  map(tokens, #'add_token, f, args, maps);
  return maps;
}

private string
strip_brackets(string s) {
  int i, j, depth;

  if (!stringp(s))
    return s;
  i = strstr(s, "(");
  if (i<0 || sizeof(to_array(s[0..i-1]) - ({ ' ', 0 })))
    // only strip the brackets away, if they are only preceded by spaces
    return s;
  else {
    depth++;
    for (j=strlen(s)-(i+1); j>0; j--) {
      switch (s[<j]) {
      case '(':
        depth++;
        break;
      case ')':
        depth--;
        break;
      }
      if (!depth)
        break;
    }
    return s[0..(i-1)] + s[(i+1)..<(j+1)] + (j > 0 ? s[<(j-1)..<1] : "");
  }
}

private void
numeralize_and_strip_brackets(string key, mixed values) {
  values = LIB_PARSE->get_numeral(sizeof(values)) + strip_brackets(key);
}

private void
combine_descriptions(string key, mixed values, mixed article, int full,
                     int poss, mapping obs, closure descf) {
  string desc;
  mixed h, h2;
  int number, i, j;

  values = factorize(transpose_array(values)[1],
                     lambda(({ 'x }), ({ #'return, 'x })));
  number = sizeof(flatten_array(m_values(values)));
  m_delete(values, 0);
  switch (sizeof(h = m_indices(values))) {
  case 0:
    if (sizeof(obs[key]))
      values = funcall(descf, obs[key][0], article, full, number, poss);
      break;
  default:
    for (i = sizeof(h); i-- && !desc; ) {
      for (j = sizeof(h2 = obs[key + h[i]]); j-- && !desc; )
        if (objectp(h2[j]) && h2[j]->query_plural())
          desc = funcall(descf, key, article, full | DESCRIBE_IS_PLURAL,
                         number, poss);
    }
    i = sizeof(flatten_array(m_values(values)));
    if (!desc) {
      if (i < number)
        for (j = sizeof(h2 = obs[key]); j-- && !desc; )
          if (objectp(h2[j]) && h2[j]->query_plural())
            desc = funcall(descf, key, article, full | DESCRIBE_IS_PLURAL,
                           number, poss);
      if (!desc)
        desc = funcall(descf, key, article, full, number, poss);
    }
    if (sizeof(h) > 1 || i < number) {
      walk_mapping(values, #'numeralize_and_strip_brackets);
      values = desc + ", " + make_list(m_values(values));
    }
    else
      values = funcall(descf, obs[key + h[0]][0], article, full, number,
                       poss);
  }
}

varargs string *
describe_list(mixed ob, mixed article, int full, status poss, closure desc) {
  mixed h, o;

  desc = desc || symbol_function("describe");
  if (mappingp(ob))
    return walk_mapping(h = copy(ob),
                        lambda(({ 'ob, 'value }),
                               ({ (#'=),
                                  'value,
                                  ({ (#'&&),
                                     'value,
                                     ({ (#'funcall),desc,
                                        'ob, article, full, 'value,
                                        poss }) }) }))), h;
  else if (!pointerp(ob))
    ob = ({ ob });
  if (full & DESCRIBE_FULL) {
    h = filter(ob, #'objectp);    // take all objectgs
    h -= filter_objects(h, "short");  // remove all that are visible
    ob -= h;           // remove remaining (invisibles) from original
  }
  // don't make a mpaiing from ob and h except in the closure, else
  // multiple string-descs will be lost
  h = map(ob, desc, ARTICLE_NONE, full);
  o = factorize(ob, lambda(({ 'ob }), ({ CL_INDEX, mkmapping(ob, h), 'ob })));
  // explode for prepositions and opening brackets
  h = map(h - ({ 0 }),
              (#'regexplode),"[ \t]*(\\<("PREPOSITIONS")\\>|\\().*$");
#define DONT_COMBINE_PAIRS_AND_SO_ON
#ifdef DONT_COMBINE_PAIRS_AND_SO_ON
  h = map(h, lambda(({ 's }),
                    ({ (#'?),
                       ({ (#'sizeof),
                          ({ (#'regexp),
                             ({ CL_ARRAY,
                                ({ CL_INDEX, 'x, 0 }) }),
                             "\\<(pair|set)$" }) }),
                       ({ CL_ARRAY,
                          ({ (#'implode), 'x, "" }) }),
                       'x })));
#endif
  // append a 0 for the arrays that have only one element so the
  // transpose_array won't fail
  h = map(h, #'+, ({ 0 }));
  // collect all arrays whose first element is alike
  h = factorize(h, CL_INDEX, ({ 0 }));
  // combine their descriptions
  walk_mapping(h, #'combine_descriptions, article, full, poss, o, desc);
  return m_values(h);
}

/*
 * describe_heap
 * returns a nicely prepared string describing a heap
 *
 * Example:
 * describe_heap( ([ "red":7, "green":3, "yellow":5 ]), "marble" )
 * ==> "5 yellow, 3 green and 7 red marbles"
 *
 * The mapping and the name are required arguments, the order is
 * optional, if you specify it, the heap-elements will be printed
 * in that order:
 *
 * describe_heap( ([ "red":7, "yellow":1, "green":3 ]),
 *                "marble",
 *                ({"green", "yellow", "red"})
 *              )
 * ==> "3 green marbles, 1 yellow marble and 7 red marbles"
 */

varargs string
describe_heap(mapping m, string name, string *order, int threshold) {
  string *res;
  int i;

  if (!order) order = m_indices(m);
  if (!name) name = "something";
  res = ({});
  for (i=0; i<sizeof(order); i++) {
    if (!m[order[i]])
      continue;
    if (threshold && m[order[i]] > threshold)
      res += ({ "many " + order[i] });
    else
      res += ({ m[order[i]] + " " + order[i] });
  }
  if (!sizeof(res))
    return "no " + LIB_LANGUAGE->plural_word(name);
  return make_list(res) + " " +
         ( (sizeof(res) > 1 || res[0][0..1] != "1 ") ?
           LIB_LANGUAGE->plural_word(name) : name
         );
}

