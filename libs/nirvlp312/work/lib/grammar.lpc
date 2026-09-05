/*
 * lib/grammar.c
 */

#pragma strong_types
#pragma no_clone
#pragma no_inherit

inherit "basic/present";
inherit "basic/path";
inherit "basic/name";

#include <wizlevels.h>
#include <prop/item.h>
#include <gender.h>
#include <describe.h>
#include <accessible.h>
#include <kernel.h>
#include <tongue.h>
#include <libs.h>
#include <time_units.h>
#include <combat.h>
#include <money.h>
#include <inventory.h>
#include <server.h>
#include <termcol.h>
#include <udp.h>

#ifdef INTERMUD3
#include <imud3.h>
#endif

#define AL_ID(ob, str) (this_player() && this_player()->query_int() < 1 && \
                        objectp(ob) && !living(ob)?                        \
                        (str)=="thing" || (ob)->id(str) : (ob)->id(str))

object query_contains(mixed ob, object container, string container_id) {
  return
    container->contains_inventory(ob,container_id) ||
    present::present(ob,container);
}

#if 0 // this part is still heavily under construction

// [object] x id
mixed *
my_parse_containers(int first, int last, string *words, object env)
{
  my_parse_obs(first, last, words, env);
}

// [object] x id
mixed *
my_parse_obs_in_container(int first, int last, string *words,
                          object container, string container_id)
{
  my_parse_obs(first, last, words, container);
}

// [object] x id
mixed *
my_parse_obs(int first, int last, string *words, object env)
{
  int i,j,c;
  mixed h, ob;
  string name;
  mixed *container;
  mixed *result;
  if (first < last)
    for (i = first; i < last; i++)
    {
      if (i > first)
      {
        // <ob> (from|of) <container>
        if (words[i] == "from" || words[i] == "of") 
        {
          if ((container = my_parse_containers(i+1,last,words,env)))
          {
            for (j = sizeof(container[0]); j; j--)
              if (h = my_parse_obs_in_container(first,i-1,words,
                                                container[0][<j],
                                                container[1])) {
                if (!result)
                  result = h;
                else
                  result[0]+=h[0];
              }
            if (result)
              return result;
          }
          if (words[i] == "of" &&
              (ob = my_parse_ob(i+1, last, words, env)))
            if (h = my_parse_fakeitem(first,i-1,words,ob[0]))
              return ({ h[0..0], h[1] });
        }
        // <plural_container>' <ob>
        else if (words[i] == "'" && words[i-1][<1] == 's')
        {
          if ((container = my_parse_containers(first,i-1,words,env)))
            for (j = sizeof(container[0]); j; j--)
              if (h = my_parse_obs_in_container(i+1,last,words,
                                                container[0][<j],
                                                container[1]))
                return h;
          if (ob = my_parse_ob(first,i-1,words,env))
            if (h = my_parse_fakeitem(i+1,last,words,ob[0]))
              return ({ h[0..0], h[1] });
        }
      }
      // <container>'s <ob>
      if (words[i][<2..] == "'s")
      {
        w = words[0..];
        w[i] = words[i][0..<3]; // cut off the "'s"
        if ((container = my_parse_containers(first,i,w,env)))
          for (j = sizeof(container[0]); j; j--)
            if (h = my_parse_obs_in_container(i+1,last,words,
                                              container[0][<j],
                                              container[1]))
              return h;
        if (ob = my_parse_ob(first,i,w,env))
          if (h = my_parse_fakeitem(i+1,last,words,ob[0]))
            return ({ h[0..0], h[1] });
      }
    }
  if (first == last)
    switch (words[first])
    {
    case "me":
    case "myself":
      return ({ ({ this_player() }), this_player()->query_name() });
    case "it":
    case "him":
    case "her":
    case "them":
      h = (this_player()->
           query_last_referenced(OBJECTIVE_TO_PRONOUN(words[first])));
      if (!(h && objectp(h[0])))
        return 0;
      if (accessible(h[0],this_player()))
        return ({ h[0..0], h[1] });
      else
        return 0;
    }
  else if (first > last)
    return 0;
  else 
    switch (words[first])
    {
    case "my":
      if (!env)
        env = this_player();
      else if (env != this_player())
        return 0;
      first++;
      break;
    case "a":
    case "an":
      c = 1;
    case "the":
      first++;
      break;
    case "this":
    case "these":
      if (!env)
        env = environment(this_player());
      else if (env != environment(this_player()))
        return 0;
      first++;
      break;
    case "his":
    case "her":
    case "its":
    case "their":
      h = (this_player()->
           query_last_referenced(POSSESSIVE_TO_PRONOUN(words[first++])));
      if (!(h && objectp(h[0])))
        return 0;
      if (!(accessible(h[0],this_player(),h[1],A_NO_CONTAINER|A_NO_ROOM) &&
            h[0]->can_put_and_get(h[1])))
        return 0;
      env = h[0];
      break;
    }
  if (first < last && !c)
  {
    if (c=LIB_PARSE->parse_ordinal(words[first]))
      first++;
    else if (c=LIB_PARSE->parse_numeral(words[last]))
      last--;
  }
  // continue here ... 
  name = implode(words[first..last]," ");
  if (h = present(name+(c?" "+c:""),env))
    if (c && AL_ID(h,name+" "+c))
      return ({ h,name+" "+c });
    else
      return ({ h,name });
  else if (env == environment(this_player()))
  {
    h = filter_objects(INVENTORY(env,0),"id",name);
    if (c)
    {
      if (c == sizeof(h)+1)
      {
        if (AL_ID(env, name+" 1"))
          return ({ env, name+" 1" });
        else if (AL_ID(env, name))
          return ({ env,name });
      }
      else if (c > sizeof(h)+1 && AL_ID(env,name+" "+(c-sizeof(h))))
        return ({ env,name+" "+(c-sizeof(h)) });
    }
    else if (AL_ID(env, name))
      return ({ env,name });
  }
}

// object x id
mixed *
my_parse_fakeitem(int first, int last, string *words, object ob)
{
}

// object x id
mixed *
my_parse_ob(int first, int last, string *words, object env)
{
}

#else

object * my_parse_container(int first, int last, string *words,object env) {
  int i,c;
  mixed h;
  string name;
  object referenced;

  if (first == last)
    switch (words[first])
    {
    case "me":
    case "myself":
      return ({ ({ this_player() }), this_player()->query_name() });
    case "it":
    case "him":
    case "her":
    case "them":
      h = (this_player()->
           query_last_referenced(OBJECTIVE_TO_PRONOUN(words[first])));
      if (!(h && objectp(h[0])))
        return 0;
      if (accessible(h[0],this_player()),h[1],A_NO_CONTAINER)
        return ({ h[0..0], h[1] });
      else
        return 0;
    }
  else 
    switch (words[first])
    {
    case "my":
      if (!env)
        env = this_player();
      else if (env != this_player())
        return 0;
      first++;
      break;
    case "a":
    case "an":
      c = 1;
    case "the":
      first++;
      break;
    case "this":
    case "these":
      if (!env)
        env = environment(this_player());
      else if (env != environment(this_player()))
        return 0;
      first++;
      break;
    }
  if (first < last && !c)
  {
    if (c=LIB_PARSE->parse_ordinal(words[first]))
      first++;
    else if (c=LIB_PARSE->parse_numeral(words[last]))
      last--;
  }
  if (first == last &&
      (referenced = this_player()->query_referenced(words[first]))) {
    h = ({ referenced, describe(referenced, ARTICLE_NONE) });
    if (h[0]->can_put_and_get(h[1]))
      return ({ h[0..0], h[1] });
  }
  name = implode(words[first..last]," ");
  if (!env)
    return 0;
  if (!c)
  {
    h = filter_objects(INVENTORY(env,0),"id",name);
    h = filter_objects(h,"can_put_and_get",name);
    if (sizeof(h))
      return ({ h, name });
#ifdef GET_COMPONENTS
    if (sizeof(h = env->get_component(name,1)))
    // allow taking from components of environment
    {
      h = filter_objects(h,"can_put_and_get",name);
      if (sizeof(h))
        return ({ h, name });
    }
#endif
    return 0;
  }
  else if (h = present(name+" "+c,env))
  {
    if (AL_ID(h, name+" "+c))
      //if (((h)->id(name+" "+c)))
      h = ({ h,name+" "+c });
    else
      h = ({ h,name });
    if (h[0]->can_put_and_get(h[1]))
      return ({ h[0..0], h[1] });
  }
#ifdef GET_COMPONENTS
  else if (h = env->get_component(name+" "+c))
  // allow taking from components of environment
  {
    if (AL_ID(h,name+" "+c))
      h = ({ h, name+" "+c });
    else
      h = ({ h, name });
    if (h[0]->can_put_and_get(h[1]))
      return ({ h[0..0], h[1] });
  }
#endif
  return 0;
}

mixed * my_parse_ob_in_container(int first, int last, string *words,
                                 object container, string container_id) {
  int i,c;
  mixed h;
  string name;
  if (first == last) {
    switch (words[first]) {
    case "it":
    case "him":
    case "her":
    case "them":
      h = (this_player()->
           query_last_referenced(OBJECTIVE_TO_PRONOUN(words[first])));
      if (!(h && objectp(h[0])))
        return 0;
      if (query_contains(h[0],container,container_id))
        return h;
      else
        return 0;
    }
  }
  else {
    switch (words[first]) {
    case "my":
      if (environment(container) != this_player())
        return 0;
      first++;
      break;
    case "a":
    case "an":
      c = 1;
    case "the":
      first++;
      break;
    case "this":
    case "these":
      if (environment(container) != environment(this_player()))
        return 0;
      first++;
      break;
    }
  }
  if (first < last && !c) {
    if (c=LIB_PARSE->parse_ordinal(words[first]))
      first++;
    else if (c=LIB_PARSE->parse_numeral(words[last]))
      last--;
  }
  name = implode(words[first..last]," ");
  if (h = query_contains(name+(c?" "+c:""),container,container_id)) {
    if (c && AL_ID(h,name+" "+c))
      return ({ h,name+" "+c });
    else
      return ({ h,name });
  }
  return 0;
}

mixed * my_parse_fakeitem(int first, int last, string *words, object ob) {
  int i,c;
  mixed h;
  string name;
  if (first == last)
    switch (words[first]) {
    case "it":
    case "him":
    case "her":
    case "them":
      h = (this_player()->
           query_last_referenced(OBJECTIVE_TO_PRONOUN(words[first])));
      if (!(h && objectp(h[0])))
        return 0;
      if (ob == h[0] &&
          (ob->query_fakeitem_id(h[1]) ||
           ob->query_component_id(h[1])))
        return h;
      else
        return 0;
    }
  else 
    switch (words[first]) {
    case "my":
      if (environment(ob) != this_player())
        return 0;
      first++;
      break;
    case "a":
    case "an":
      c = 1;
    case "the":
      first++;
      break;
    case "this":
    case "these":
      if (environment(ob) != environment(this_player()))
        return 0;
      first++;
      break;
    }
  if (first < last && !c)
  {
    if (c = LIB_PARSE->parse_ordinal(words[first]))
      first++;
    else if (c = LIB_PARSE->parse_numeral(words[last]))
      last--;
  }
  name = implode(words[first..last]," ");
  if (!c &&
      (ob->query_fakeitem_id(name) ||
       ob->query_component_id(name)))
    return ({ ob, name });
  if (c &&
      (ob->query_fakeitem_id(name = name+" "+c) ||
       ob->query_component_id(name)))
    return ({ ob, name });
  return 0;
}

mixed my_parse_ob(int first, int last, string *words, object env) {
  int i,j,c;
  mixed h, ob;
  string name, *w;
  mixed *container;

  if (first < last)
    for (i = first; i < last; i++)
    {
      if (i > first)
      {
        // <ob> (from|of) <container>
        if (words[i] == "from" || words[i] == "of") 
        {
          if ((container = my_parse_container(i+1,last,words,env))) {
            for (j = sizeof(container[0]); j; j--)
              if (h = my_parse_ob_in_container(first,i-1,words,
                                               container[0][<j],
                                               container[1]))
                return h;
          }
          if (words[i] == "of" &&
              (ob = my_parse_ob(i+1, last, words, env)))
            if (h = my_parse_fakeitem(first,i-1,words,ob[0]))
              return h;
        }
        // <plural_container>' <ob>
        else if (words[i] == "'" && words[i-1][<1] == 's')
        {
          if ((container = my_parse_container(first,i-1,words,env)))
            for (j = sizeof(container[0]); j; j--)
              if (h = my_parse_ob_in_container(i+1,last,words,
                                               container[0][<j],
                                               container[1]))
                return h;
          if (ob = my_parse_ob(first,i-1,words,env))
            if (h = my_parse_fakeitem(i+1,last,words,ob[0]))
              return h;
        }
      }
      // <container>'s <ob>
      if (words[i][<2..] == "'s")
      {
        w = words[0..];
        w[i] = words[i][0..<3]; // cut off the "'s"
        if ((container = my_parse_container(first,i,w,env)))
          for (j = sizeof(container[0]); j; j--)
            if (h = my_parse_ob_in_container(i+1,last,w,
                                             container[0][<j],
                                             container[1]))
              return h;
        if (ob = my_parse_ob(first,i,w,env))
          if (h = my_parse_fakeitem(i+1,last,w,ob[0]))
            return h;
      }
    }
  if (first == last)
    switch (words[first])
    {
    case "me":
    case "myself":
      return ({ this_player(), this_player()->query_name() });
    case "it":
    case "him":
    case "her":
    case "them":
      h = (this_player()->
           query_last_referenced(OBJECTIVE_TO_PRONOUN(words[first])));
      if (!(h && objectp(h[0])))
        return 0;
      if (accessible(h[0],this_player()))
        return h;
      else
        return 0;
    }
  else if (first > last)
    return 0;
  else 
    switch (words[first])
    {
    case "my":
      if (!env)
        env = this_player();
      else if (env != this_player())
        return 0;
      first++;
      break;
    case "a":
    case "an":
      c = 1;
    case "the":
      first++;
      break;
    case "this":
    case "these":
      if (!env)
        env = environment(this_player());
      else if (env != environment(this_player()))
        return 0;
      first++;
      break;
    case "his":
    case "her":
    case "its":
    case "their":
      h = (this_player()->
           query_last_referenced(POSSESSIVE_TO_PRONOUN(words[first++])));
      if (!(h && objectp(h[0])))
        return 0;
      if (!(accessible(h[0],this_player(),h[1],A_NO_CONTAINER|A_NO_ROOM) &&
            h[0]->can_put_and_get(h[1])))
        return 0;
      env = h[0];
      break;
    }
  {
    object referenced;
    if (first == last &&
        (referenced=this_player()->query_referenced(words[first])))
      return ({ referenced, describe(referenced, ARTICLE_NONE) });
  }
  if (first < last && !c) {
    if (c = LIB_PARSE->parse_ordinal(words[first]))
      first++;
    else if (c = LIB_PARSE->parse_numeral(words[last]))
      last--;
  }
  if (c) {
    name = implode(words[first..last], "") + c;
    if ((h = find_object(name)) && present(h, env))
      return ({ h, describe(h, ARTICLE_NONE) });
  }
  name = implode(words[first..last]," ");
  if (h = present(name+(c?" "+c:""),env)) {
    if (c && AL_ID(h,name+" "+c))
      return ({ h,name+" "+c });
    else
      return ({ h,name });
  }
  if (env == environment(this_player())) {
    if (c) {
      h = filter_objects((INVENTORY(env,0)) - ({ 0 }),"id",name);
      if (c == sizeof(h)+1) {
        if (AL_ID(env,name+" 1"))
          return ({ env, name+" 1" });
        else if (AL_ID(env,name))
          return ({ env,name });
      }
      else
        if (c > sizeof(h)+1 && AL_ID(env,name+" "+(c-sizeof(h))))
          return ({ env,name+" "+(c-sizeof(h)) });
    }
    else
      if (AL_ID(env,name))
        return ({ env,name });
  }
  return 0;
}

#endif

mixed* parse_ob(int first, int last, string *words, object env) {
  mixed ob;
  ob = my_parse_ob(first,last,words,env);
  if (!ob || !(ob[0] && ob[1]))
    return 0;
  this_player()->set_last_referenced((ob[0]->query_pronoun()||"it"),ob);
#ifdef GET_COMPONENTS
  ob[0] = ob[0]->get_component(ob[1]) || ob[0];
#endif
  return ob;
}

private string strip_id(object ob, string str) {
  string tmp, tmp3;
  int tmp2;

  if (sscanf(str, "%s %d%s", tmp, tmp2, tmp3) == 3 && tmp3 == "" &&
      !ob->query_component_id(str) && 
      !AL_ID(ob,str))
    return tmp;
  return str;
}

private void reference_result(object ob, string id) {
  this_player()->set_last_referenced((ob->query_pronoun()||"it"),
                                     ({ ob, id }));
}

private int parse_object_in_env(mixed r, mixed a, int f, int l, string *w,
                                string *t, object env) {
  mixed ob;
  if (ob = parse_ob(f,l,w,env)) {
    a = strip_id((r = ob[0]),ob[1]);
    reference_result(r,a);
    return 1;
  }
  return 0;
}

int parse_in_inventory(mixed r, mixed a, int f, int l, string *w, string *t) {
  return parse_object_in_env(&r,&a,f,l,w,t,this_player());
}

int parse_in_environment(mixed r, mixed a, int f, int l, string *w, string *t) {
  return parse_object_in_env(&r,&a,f,l,w,t,environment(this_player()));
}

int parse_indirect(mixed r, mixed a, int f, int l, string *w, string *t) {
  return
    parse_in_environment(&r,&a,f,l,w,t) ||
    parse_in_inventory(&r,&a,f,l,w,t);
}

int parse_object(mixed r, mixed a, int f, int l, string *w, string *t) {
  return
    parse_in_inventory(&r,&a,f,l,w,t) ||
    (this_player() && environment(this_player())) &&
    parse_in_environment(&r,&a,f,l,w,t);
}

status parse_money(mixed result, mixed aux, int first, int last, string *words,
                   string *text) {
  if (parse_object(&result,&aux,first,last,words,text) &&
      result->query_property(P_MONEY)) {
    aux = result->query_amount();
    return 1;
  }
  return 0;
}

private varargs int parse_all_ob(mixed obs, mixed ids,
             int first, int last, string *words, string *text, object env) {
  status all, of, this, these, filled;
  int number, count, mid, tmp, saved_first;
  object where, *new, tp;
  string *singulars, whose;
  mixed h;
  string given_description;
  tp = this_player();
  if (!env)
    env = environment(tp);
  switch (words[first])
  {
  case "all":
    all = 1; first++; break;
  default:
    if (number = LIB_PARSE->parse_numeral(words[first]))
      first++;
  }
  if (first > last)
    if (all)
    {
      if (env == environment(tp))
        obs = INVENTORY(tp,0) + (INVENTORY(env,0) - ({ tp }));
      else
        obs = INVENTORY(env,0) - ({ tp });
      ids = ({ 0, sizeof(obs) });
      return 1;
    }
    else
      return 0;
  if (first < last && (all || number) && words[first] == "of" && of = 1)
    first++;
  if (number == 1 && !of)
    return 0; /* so no one can type 'one torches' */
  if (first < last && (!number || of))
    switch (words[first])
    {
    case "my":
      where = tp;
      filled = 1;
      first++;
      break;
    case "these":
      these = 1;
      where = env;
      filled = 1;
      first++;
      break;
    case "this":
      this = 1;
    case "the":
      filled = 1;
      first++;
      break;
    default:
      if (h = POSSESSIVE_TO_PRONOUN(words[first]))
      {
        filled = 1;
        h = tp->query_last_referenced(h);
        if (sizeof(h)) {
          if (h[0] && objectp(h[0]))
            where = h[0];
          if ((environment(where) != environment(tp) &&
               environment(where) != tp) ||
              !where->can_put_and_get(h[1]))
            return 0;
        }
        first++;
      }
    }
  if (first < last && count = LIB_PARSE->parse_ordinal(words[first]))
    first++;
  if ((these && count))
    return 0;
  saved_first = first;
  if (!these) /* 'these first bag's torches' wouldn't make much sense */
    for (mid = first; mid < last; mid++)
      if (words[mid][<2..] == "'s")
      {
        filled = 1;
        whose = implode (words[first..mid], " ")[0..<3];
        if (where)
          if (!where->can_put_and_get(whose))
            return 0;
          else if (where = present(whose+(count?" "+count:""),where))
            break;
          else
            return 0;
        where = (present(whose+(count?" "+count:""),
                         (this ? env : tp)) ||
                 present(whose+(count?" "+count:""),
                         (this ? tp : env)));
#ifdef GET_COMPONENTS
        if (!(where || 
              (where =
               env->get_component(whose+(count?" "+count:"")))))
#endif
          if (!where || !where->can_put_and_get(whose))
            return 0;
        break;
      }
  if ((count && !whose) ||    /* first of whom ??? */
      (whose && !where) ||
      (this && !where))
    return 0;    /* or something which isn't there */
  if (whose)
    first = mid + 1;         /* after the word ending on 's */
  if (of && !filled)
    return 0;
  if (!where)                 /* we still don't know, where to look */
  {
    if (last > first && count = LIB_PARSE->parse_numeral(words[last]))
      last--;
    for (mid = first; mid < last; mid++)
      if (words[mid] == "from")
      {
        tmp = mid;
        if (mid+1==last)
        {
          if (words[last] == "me")
          {
            where = tp;
            last = tmp-1;
            break;
          }
          if (h = OBJECTIVE_TO_PRONOUN(words[last]))
          {
            h = tp->query_last_referenced(h);
            if (h[0] && objectp(h[0]))
              where = h[0];
            if ((environment(where) != environment(tp) &&
                 environment(where) != tp) ||
                !where->can_put_and_get(h[1]))
              return 0;
            last = tmp - 1;
            break;
          }
        }
        if (++mid < last)
          switch (words[mid])
          {
          case "my":
            where = tp;
            mid++;
            break;
          case "this":
            this = 1;
          case "the":
            mid++;
            break;
          }
        if (mid < last && !count &&
            count = LIB_PARSE->parse_ordinal(words[mid]))
          mid++;
        whose = implode(words[mid..last], " ");
        last = tmp - 1;
        if (where)
          if ((where = present(whose+(count?" "+count:""),where)) &&
              where->can_put_and_get(whose))
            break;
          else
            return 0;
        if ((where =
             present(whose+(count?" "+count:""),(this ? env : tp)) ||
             present(whose+(count?" "+count:""),(this ? tp : env))) &&
            where->can_put_and_get(whose))
          break;
#ifdef GET_COMPONENTS
        if ((where =
             env->get_component(whose+(count?" "+count:""))) &&
            where->can_put_and_get(whose))
          break;
#endif
        return 0;
      }
    if (count && !where)
      return 0;
  }
  obs = (where ?
         INVENTORY(where,whose) :
         INVENTORY(tp,whose) +
         (env != tp ? INVENTORY(env,0) : ({})) + ({env}));
  ids = ({ 0, (number||sizeof(obs)) });
  if (last < first)
    if (all)
      return 1;
    else
      return 0;
  singulars = LIB_LANGUAGE->to_singular(words[last]);
  if (first < last)
    whose = implode (words[first..last-1], " ") + " ";
  else
    whose = "";
  for (mid = 0; mid < sizeof(singulars); mid++)
    if (sizeof(new = filter_objects(obs, "id", whose+singulars[mid])))
      break;
  if (sizeof(singulars) > mid)
    (ids)[0] = whose+singulars[mid];
  else if (where)
  {
    for (mid = 0; mid < sizeof(singulars); mid++)
      if (AL_ID(where,whose+singulars[mid]))
        break;
    if (sizeof(singulars) > mid)
    {
      (ids)[0] = whose+singulars[mid];
      new = ({ where });
    }
    else if (saved_first < first)
    {
      whose = implode(words[saved_first..last-1], " ")+" ";
      for (mid = 0; mid < sizeof(singulars); mid++)
        if (AL_ID(where,whose+singulars[mid]))
          break;
      if (sizeof(singulars) > mid)
      {
        (ids)[0] = whose+singulars[mid];
        new = ({ where });
      }
      else
        return 0;
    }
    else
      return 0;
  }
  if (!sizeof(new))
    return 0;
  if (all || !number || sizeof(new) >= number)
  {
    if (all || !number)
      (ids)[1] = sizeof(new);
    else if (number)
      (ids)[1] = number;
    obs =  new;
    return 1;
  }
  return 0;
}

varargs int parse_all_indirect(mixed r, mixed a,
                               int f, int l, string *w, string *t) {
  if (parse_indirect(&r,&a,f,l,w,t)) {
    r = ({ r });
    a = ({ a, 1 });
    return 1;
  }
  return parse_all_ob(&r,&a,f,l,w,t);
}

varargs int parse_all_object(mixed r, mixed a,
                             int f, int l, string *w, string *t) {
  if (parse_object(&r,&a,f,l,w,t)) {
    r = ({ r });
    a = ({ a, 1 });
    return 1;
  }
  return parse_all_ob(&r,&a,f,l,w,t);
}

varargs int parse_all(mixed r, mixed a, int f, int l, string *w,
                      string *t, object env) {
  if (env) {
    if (parse_object_in_env(&r,&a,f,l,w,t,env)) {
      r = ({ r });
      a = ({ a, 1 });
      return 1;
    } else if (parse_all_ob(&r,&a,f,l,w,t,env)) {
      return 1;
    }
  }
  // for compatibility purposes
  return parse_all_indirect(&r,&a,f,l,w,t);
}

int parse_all_livings(mixed result, mixed aux,
                      int first, int last, string *words, string *text) {
  mixed h, temp;
  if (!parse_all(&result, &aux, first, last, words, text)) {
    if (first == last) {
      object pl;
      h = filter(INVENTORY(environment(this_player()),0)+
                       INVENTORY(this_player(),0),#'living);
      h = filter_objects(h,"short");
      h -= filter(h, lambda(({ 'x }),
                            ({ #'&&,
                               ({ #'query_once_interactive, 'x }),
                               ({ #'!, ({ #'interactive, 'x })})})));
      temp = to_real_name(words[first]);
      h = filter(h,lambda(({'l}),
                          ({ #'&&,
                             ({ #'=, 'h,
                                ({ #'||,
                                   ({ #'call_other, 'l, "query_real_name" }),
                                   ({ #'call_other, 'l, "query_name"  })})}),
                             ({ #'!,
                                ({ #'strstr,
                                   ({ #'to_real_name, 'h }),
                                      temp })})})));
      if (sizeof(h) == 1)
      {
        result = h;
        aux = ({to_real_name((result)[0]->query_name()),1});
        return 1;
      }
    }
    return 0;
  }
  result = filter(result, #'living);
  result -= filter(result, lambda(({ 'x }),
                                  ({ #'&&,
                                     ({ #'query_once_interactive, 'x }),
                                     ({ #'!, ({ #'interactive, 'x })})})));
  return sizeof(result) > 0;
}

int parse_all_items(mixed result, mixed aux,
                    int first, int last, string *words, string *text) {
  if (!parse_all(&result, &aux, first, last, words, text))
    return 0;
  result -= filter(result, #'living);
  return sizeof(result) > 0;
}

int parse_all_in_inventory(mixed result, mixed aux,
                           int first, int last, string *words, string *text) {
  if (!parse_all(&result, &aux, first, last, words, text, this_player()))
    return 0;
  result &= deep_inventory(this_player());
  return sizeof(result) > 0;
}

varargs int parse_all_in_environment(mixed result, mixed aux,
                                     int first, int last, string *words,
                                     string *text, object env) {
  if (!env)
    env = environment(this_player());
  if (!parse_all(&result, &aux, first, last, words, text, env))
    return 0;
  result -= deep_inventory(this_player());
  return sizeof(result) > 0;
}

int parse_all_only_in_inventory(mixed result, mixed aux,
                                int first, int last, string *words,
                                string *text) {
  if (!parse_all(&result, &aux, first, last, words, text, this_player()))
    return 0;
  result &= INVENTORY(this_player(),0);
  return sizeof(result) > 0;
}

varargs int parse_all_only_in_environment(mixed result, mixed aux,
                              int first, int last, string *words,
                              string *text, object env) {
  if (!parse_all(&result, &aux, first, last, words, text, 
                 env||environment(this_player())))
    return 0;
  result &= INVENTORY(env||environment(this_player()),0);
  return sizeof(result) > 0;
}

// the following two are just for compatibility
int parse_all_inventory(mixed result, mixed aux,
                    int first, int last, string *words, string *text) {
  return parse_all_in_inventory(&result,&aux,first,last,words,text);
}

varargs int parse_all_environment(mixed result, mixed aux,
                      int first, int last, string *words, string *text,
                      object env) {
  return parse_all_in_environment(&result,&aux,first,last,words,text,env);
}
// till here

int parse_living(mixed result, mixed aux,
             int first,int last,string *words,string *text) {
  mixed ob, h;
  mixed temp;
  if (!parse_indirect(&ob,&temp,first,last,words,text))
  {
    if (first == last)
    {
      h = filter(INVENTORY(environment(this_player()),0)+
                       INVENTORY(this_player(),0),#'living);
      h = filter_objects(h,"short");
      temp = to_real_name(words[first]);
      h = filter(h, lambda(({ 'l }),
                           ({ #'&&,
                              ({ #'=, 'h,
                                 ({ #'||,
                                    ({ #'call_other, 'l, "query_real_name" }),
                                    ({ #'call_other, 'l, "query_name"  })})}),
                              ({ #'!, ({ #'strstr, 'h, temp })}),
                           })));
      if (sizeof(h) == 1)
      {
        result = h[0];
        aux = to_real_name(result->query_name());
      }
      else
        return 0;
    }
    else
      return 0;
  }
  else if (ob && objectp(ob) && living(ob))
  {
    result = ob;
    aux = temp;
  }
  else
    return 0;
  reference_result(result,aux);
  return 1;
}

status parse_fakeitem(mixed result,mixed aux,
               int first,int last,string *words,string *text) {
  if (parse_object(&result,&aux,first,last,words,text) &&
      result->query_fakeitem_id(aux)) {
    reference_result(result,aux);
    return 1;
  }
  return 0;
}

status parse_me(mixed result,mixed aux,
         int first,int last,string *words,string *text) {
  if (((result=previous_object()) &&
       (aux=implode(words[first..last]," "), AL_ID(result,aux))) ||
      (parse_object(&result,&aux,first,last,words,text) &&
       result == previous_object())) {
    reference_result(result,aux);
    return 1;
  }
  return 0;
}

status parse_this_me(mixed result,mixed aux,
              int first,int last,string *words,string *text) {
  if (((result=previous_object()) &&
       (aux=implode(words[first..last]," "), AL_ID(result,aux))) ||
      (parse_indirect(&result,&aux,first,last,words,text) &&
       result == previous_object())) {
    reference_result(result,aux);
    return 1;
  }
  return 0;
}

status parse_object_list(mixed result, mixed aux, int first, int last,
                  string *words, string *text) {
  int mid, but;
  mixed r, a, h;
  if (words[last] == "," || words[last] == "and" || words[last] == "but")
    return 0;
  result = aux = 0;
  while (1)
  {
    for (mid = first; mid <= last; mid++)
    {
      switch (words[mid])
      {
      case ",":
      case "and":
        if (mid == first)
          return 0;
        break;
      case "but":
      case "except":
        if (but || mid == first)
          return 0;
        but = 1;
        break;
      default:
        if (mid < last)
          continue;
      }
      if (mid < last)
        break;
    }
    r = a = 0;
    if (but < 2)
    {
      if (parse_object(&r, &a, first, mid-1, words, text))
      {
        if (!result)
        {
          result = ([]);
          aux = ([]);
        }
        if (!(aux)[0])
        {
          (result)[0] = ({r});
          (aux)[0]=1;
        }
        else
        {
          (result)[0] += ({r});
          (aux)[0]++;
        }
        if (!(aux)[a])
        {
          (result)[a] = ({r});
          (aux)[a]=1;
        }
        else
        {
          (result)[a] += ({r});
          (aux)[a]++;
        }
      }
      else if (parse_all(&r, &a, first, mid-1, words, text))
      {
        if (!result)
        {
          result = ([]);
          aux = ([]);
        }
        if (!(aux)[0])
        {
          (result)[0] = r;
          (aux)[0] = sizeof(r);
        }
        else
        {
          (result)[0] += r;
          (aux)[0] += sizeof(r);
        }
        if (a[0])
        {
          if (!(aux)[a[0]])
          {
            (result)[a[0]] = r;
            (aux)[a[0]] = a[1];
          }
          else
          {
            (result)[a[0]] += r;
            (aux)[a[0]] += a[1];
          }
        }
      }
      else
        return 0;
      if (but)
        but++;
    }
    else // if (but > 1)
    {
      if (parse_object(&r, &a, first, mid-1, words, text))
      {
        if (!(aux && ((aux)[a] || (aux)[0]))) // nothing to get rid of
          return 0;
        else
        {
          if ((result)[0])
          {
            (result)[0] -= ({r});
            (aux)[0]--;
            if (!sizeof((result)[0]))
            {
              m_delete(result, 0);
              m_delete(aux, 0);
            }
          }
          if (a && (aux)[a])
          {
            (result)[a] -= ({r});
            (aux)[a]--;
            if (!(aux)[a])
            {
              m_delete(result, a);
              m_delete(aux, a);
            }
          }
        }
      }
      else if (parse_all(&r, &a, first, mid-1, words, text))
      {
        if (!aux)
          return 0;
        else if ((aux)[a[0]] && a[0])
          (aux)[a[0]] -= a[1];
        if (!(aux)[a[0]])
        {
          m_delete(result, a[0]);
          m_delete(aux, a[0]);
        }
        if ((result)[0])
        {
          (result)[0] -= a[0..a[1]-1];
          (aux)[0] -= a[1];
          if (!sizeof((result)[0]))
          {
            m_delete(result, 0);
            m_delete(aux, 0);
          }
        }
      }
      else
        return 0;
    }
    if (mid < last)
    {
      first = mid + 1;
      continue;
    }
    else
      return result && sizeof(m_indices(result)) > 0;
  }
  return raise_error("This code should not be reached.\n"), 0;
}

int parse_any_living(mixed result, mixed aux,
                     int first,int last,string *words,string *text) {
  if ((result=find_living(implode(words[first..last]," "))) &&
      (result->short() || is_wizard(this_player())))
    return 1;
  return 0;
}

int parse_text(mixed result, mixed aux,
           int first,int last,string *words,string *text) {
  result = implode(text[2*first+1..2*last+1],"");
  aux = text[2*first]; // important for indented 'say' and the like.
  return 1;
}

// it's a trick, probably a very silly one :)
// But e.g. the bank wants a class which enables it to parse for money
// which is not present, e.g. a player withdrawing money and typing
// '5 gold and 5 silver coins'

int parse_any_money(mixed result, mixed aux,
                    int first, int last, string *words, string *text) {
  string tmp;

  tmp = implode(text[2*first+1..2*last+1],"");
  if (AL_ID(load_object("/etc/dummy_money"),tmp)) {
    result = "/etc/dummy_money"->query_value();
    aux = "/etc/dummy_money"->query_amount();
    return 1;
  }
  return 0;
}

int parse_words(mixed result, mixed aux,
            int first,int last,string *words,string *text) {
  result = implode((aux = words[first..last]), " ");
  return 1;
}

int parse_rem_livings(mixed result, mixed aux,
                      int first, int last, string *words, string *text) {
  int i, size;
  string *name;
  object *objs, p;
  status is_wiz;
  if (words[last] == ",")
    return 0;
  /* last word is no comma => it is a name */
  if (sizeof(words)+1>last && words[last] == ",")
    return 0;
  /* after the last word no comma is following */
  name = filter(words[first..last],
                      lambda(({'x}), ({#'!=, 'x, ","})));
  /* name contains now all the words that are not a comma => names */
  is_wiz = this_player()->query_level() >= WL_APPRENTICE;
  for (i = 0, size = sizeof(name), objs = allocate(size); i < size; i++)
  {
    if ((p = find_living(name[i])) &&
        (is_wiz ||
         (p->short() ||
          p->query_level() < WL_APPRENTICE)))
      objs[i] = p;
    else
      return 0;
  }
  result = mkmapping(name, objs);
  return 1;
}

int parse_ambig_rem_livings(mixed result, mixed aux,
                            int first, int last, string *words, string *text) {
  int i, j, k, size;
  status is_wiz;
  mapping living, real_name;
  mixed *who,h;
  string *name,na, n, *tmp;
  object p, *inter;

#ifndef PARSE_INTERMUD_LIVINGS
#define PARSE_INTERMUD_LIVINGS
#endif

  if (words[last] == ",")
    return 0;
#ifdef PARSE_INTERMUD_LIVINGS
  if (words[last] == "@" && text[2*last+1] == "")
    return 0;
#endif
  if (sizeof(words) > last+1 && words[last+1] == ",")
    return 0;
#ifdef PARSE_INTERMUD_LIVINGS
  if (sizeof(words) > last+1 &&
      text[2*last+2] == ""   &&
      (words[last+1] == "@" ||          // start of an intermud address
       words[last+1] == "."))           // unfinished intermud3-mudname
    return 0;
#endif

  name = filter(words[first..last],
                      lambda(({ 'x }),({ (#'!=),'x,"," })));
  aux = ([]);

  // in this first for() loop the tokens 'friends', 'party', 'wizards',
  // 'players' and mailing lists are evaluated and replaced by their
  // currently logged on members.
  for (i=sizeof(name);i--;) {
    if ((name[i] == "friends" &&
         file_size(n=normalize_path("~/.friends",this_player())) > 0 &&
         who = explode(read_file(n),"\n")-({""})) ||
        (who = ("room/mailing_lists"->query_mailing_list(name[i]) ||
                SECURITY->query_domain_members(name[i]))) ||
        (name[i] == "party" &&
         (p = SE_PARTY->query_party_leader()) &&
         who = map_objects(SE_PARTY->query_party_members(p) || ({ }), 
                           "query_real_name"))
        ) {
      who = filter(who,
                   lambda(({ 'n }),
                          ({ #'&&,
                             ({ #'=, 'p, ({ #'find_player, 'n }) }),
                             ({ #'interactive, 'p }) })));
      aux += ([ name[i] : who ]);
      who -= ({ this_player()->query_real_name() });
      name[i..i] = who;
#ifdef PARSE_INTERMUD_LIVINGS
    } else
      if ((j = funcall((: while ($1-$2>0 && $3[$1-$2] != "@") {
                            $2 ++;
                          }
                          return $2; :), i, 0, name)) &&
          i-j>0 &&
          (na = SE_INTERMUD->get_mud_name(implode(name[i-j+1..i], "")))) {
        aux += ([ name[i-j-1] + "@" + na : 
                     "bin/tools/intermud_soul"->create_sould(name[i-j-1],na) ]);
        name[i-j-1..i] = ({ name[i-j-1] + "@" + na });
        i -= ++j;
#endif
    }
    else {
      h = users();
      h -= filter_objects(h, "query_login");
      if (((name[i]=="players" && (who=h-filter(h,#'is_wizard))) ||
           (name[i]=="wizards" && (who=filter(h,#'is_wizard))))
         ) {
        who = map_objects(who, "query_real_name");
        if (sizeof(who))
          aux += ([ name[i] : who ]);
        who -= ({ this_player()->query_real_name() });
        name[i..i] = who;
      }
    }
  }
  living = m_allocate(size = sizeof(name),1);
  is_wiz = !(this_player()->query_level() < WL_APPRENTICE);
  for (i = 0; i < size; i++) {
    if (living[(na = name[i])])
      continue;                               /* we already know that one */
    if ((p = find_living(na))) {                /* found him just like that? */
      if ((is_wiz ||                            /* is the teller a wiz, or */
           (p->short() ||                       /* the recipient visible */
            p->query_level() < WL_APPRENTICE))) /* or an invis player */
        living[na] = p;                  /* then there can only be one :) */
      else {  // was filtered due to being an invis wizard ==> message to him.
        if (aux["filtered_invisible_wizards"])
          aux["filtered_invisible_wizards"] += ([ p ]);
        else
          aux["filtered_invisible_wizards"] = ([ p ]);
      }
    }
    else {
      if (!real_name) {
        if (!inter) {
          inter = users();
          inter -= filter_objects(inter, "query_login");
#ifdef PARSE_INTERMUD_LIVINGS
          inter += "/bin/tools/intermud_soul_d"->query_clones();
#endif
        }
        real_name = mkmapping(inter, map_objects(inter, "query_real_name"));
      }
      for (j = 0; j < sizeof(inter); j++) {
        if ((n = real_name[p = inter[j]]) &&  /* only player_obs */
            n[0..strlen(na)-1] == na  &&      /* corresponding beginnings */
            (is_wiz ||                        /* wizard ?  or ... */
             (p->short() ||                   /* recipient is player or */
              p->query_level() < WL_APPRENTICE)))  /* or visible wizard */
          living[na] = (living[na] || ({})) + ({ p });
                                        /* no, there can be more ... ! */
      }
      if (!living[na])  // if no-one is found with that given name, stop
        return 0;       // the parsing this time.
    }
    if (pointerp(living[na]) && sizeof(living[na])) {
      // aux += ([ na : map_objects(living[na],"query_real_name") ]);
      if (sizeof(living[na]) == 1)
        living[na] = living[na][0];
    }
  }
  if (!sizeof(aux))
    aux = 0;
  result = living;
  return 1;
}

int parse_ordinal(mixed result, mixed aux,
                  int first, int last, string *words, string *text) {
  result = LIB_PARSE->parse_ordinal(implode(words[first..last]," "));
  return !!result;
}

int parse_number(mixed result, mixed aux,
             int first, int last, string *words, string *text) {
  result = LIB_PARSE->parse_numeral(implode(words[first..last], ""));
  return (result || (first == last &&
                     (words[first] == "0" || words[first] == "zero")));
}

int parse_range(mixed result, mixed aux,
                int first, int last, string *words, string *text) {
  mixed temp;
  int begin, end;
  switch (last - first)
  {
  case 0:
    temp = regexplode(words[first], "[1-9][0-9]*|0");
    if (sizeof(temp) != 5 || temp[2] != "-")
      return 0;
    begin = to_int(temp[0]+temp[1]);
    end = to_int(temp[3]+temp[4]);
    if (end < begin)
      return 0;
    result = ([ end ]);
    for (; begin < end; begin++)
      result += ([begin]);
    break;
  case 2:
    if (words[first+1] != "-" && words[first+1] != "to")
      return 0;
    begin = LIB_PARSE->parse_numeral(words[first]);
    if (!begin && words[first] != "0" && words[first] != "zero")
      return 0;
    end = LIB_PARSE->parse_numeral(words[last]);
    if (!end && words[last] != "0" && words[last] != "zero")
      return 0;
    if (end < begin)
      return 0;
    result = ([ end ]);
    for(; begin < end; begin++)
      result += ([ begin ]);
    break;
  default:
    return 0;
  }
  result = sort_array(m_indices(result), #'>);
  return 1;
}

int parse_numbers(mixed result, mixed aux,
              int first, int last, string *words, string *text) {
  int mid;
  mixed temp;
  if (words[last] == "," || words[last] == "and")
    return 0;
  if (words[first] == "," || words[first] == "and")
    return 0;
  result = ({});
  for (mid = first; mid < last; mid++)
  {
    if (words[mid] != "," && words[mid] != "and")
      continue;
    if (parse_number(&temp, &aux, first, mid-1, words, text))
      result += ({ temp });
    else
    {
      temp = aux = 0;
      if (parse_range(&temp, &aux, first, mid-1, words, text))
        result += temp;
      else
        return 0;
    }

    temp = 0;
    first = mid + 1;
  }
  if (first <= mid)
    if (parse_number(&temp, &aux, first, mid, words, text))
      result += ({ temp });
    else
    {
      temp = aux = 0;
      if (parse_range(&temp, &aux, first, mid, words, text))
        result += temp;
      else
        return 0;
    }
  result = sort_array(m_indices(mkmapping(result)), #'>);
  return 1;
}

int parse_word(mixed result,mixed aux,int first,int last,
           string *words,string *text) {
  return (first == last && 
          (result = words[first]) && (aux = text[first*2+1]) && 1);
}

int parse_on_off(mixed result, mixed aux,
             int first, int last, string *words, string *text) {
  string s;
  if (first != last)
    return 0;
  switch (words[first])
  {
    case "on":
      result = "on";
      return 1;
    case "off":
      result = "off";
      return 1;
  }
  return 0;
}

status parse_time(mixed result,mixed aux,int first,int last,string *words,
                  string *text) {
  mixed h,g;
  int i;
  h = words[first..last] - ({ ",","and" });
  result = 0;
  for (i=0; i<sizeof(h); i++)
    if ((g=LIB_PARSE->parse_numeral(h[i])) || h[i]=="0" || h[i]=="zero")
      if (sizeof(h) > i+1)
        switch (h[++i]) {
        case "s":
        case "sec":
        case "secs":
        case "second":
        case "seconds":
          result += g;
          break;
        case "m":
        case "min":
        case "mins":
        case "minute":
        case "minutes":
          result += g*ONE_MINUTE;
          break;
        case "h":
        case "hour":
        case "hours":
          result += g*ONE_HOUR;
          break;
        case "d":
        case "day":
        case "days":
          result += g*ONE_DAY;
          break;
        case "M":
        case "month":
        case "months":
          result += g*ONE_MONTH;
          break;
        case "y":
        case "year":
        case "years":
          result += g*ONE_YEAR;
          break;
        }
      else
        return 0;
    else
      return 0;
  return 1;
}

status parse_exit(mixed r,mixed a,int f,int l,string *w,string *t) {
  return f == l && (a = environment(this_player())->query_exit(w[f])) && 
    r = w[f];
}

status parse_view(mixed result,mixed aux,int f,int l,string *w,string *t) {
  mixed h;
  string room, view;
  h = environment(this_player())->query_view();
  if (!h)
    return 0;
  result = implode(t[f*2+1..l*2+1],"");
  aux = h[result];
  if (!aux)
    return 0;
  return 1;
}

status parse_tongue(mixed r,mixed a,int f,int l,string *w,string *t) {
#if 1
  int res;
  res = (f == l) && member(TONGUES, w[f]) >= 0 && (r = w[f]) && 1;
  return ((!this_player() ||
           (LIB_TONGUE->tongue_exists(w[f]) &&
            LIB_TONGUE->can_speak(this_player(), w[f]))) &&
          res);
#else
  return f == l && member(TONGUES, w[f]) >= 0 && (r = w[f]) && 1;
#endif
}

/*
 * The following function will parse for bodyparts of the actual opponent
 * of this_player() (if no opponent is given) or for the given bodypart of
 * the explicitly given living.
 */
status parse_bodypart(mixed r,mixed a,int f, int l,string *w,string *t) {
  r = this_player()->get_opponent();
  if (r && r->query_bodypart(a=implode(w[f..l]," ")))
    return 1;
  if (parse_indirect(&r,&a,f,l,w,t) &&
      r->query_property(P_BODY) &&
      r->query_bodypart(a))  // do we really have a bodypart?
    return !!(r=environment(r));
  return 0;
}

int parse_side(mixed r, mixed a, int f, int l, string *w, string *t) {
  if (f == l)
    switch (w[f]) {
    case "right":
    case "left":
      r = w[f];
      return 1;
    }
  return 0;
}

// Intermud3 stuff
status parse_remote_resource(mixed r,mixed a,int f,int l,string *w,string *t) {
  mapping hosts;
  string name;

  a = implode(t[2*f+1..2*l+1],"");
  a = explode(a,"@");

  if (sizeof(a) != 2)
    return 0;
  if (!strlen(a[1]) || !strlen(a[0]))
    return 0;
  if (strstr(a[0]," ") > -1)
    return 0;
  name = 
#ifdef INTERMUD3
         IMUD3->get_mud_name(a[1]) ||
#endif
         INETD->get_mud_name(a[1]);
  if (!name)
    return 0;
  r = name;
  a = a[0];
  return 1;
}

status parse_mud_name(mixed r,mixed a,int f,int l,string *w,string *t) {
  a = implode(t[2*f+1..2*l+1], "");
  if (!(a = 
#ifdef INTERMUD3
            IMUD3->get_mud_name(a) ||
#endif
            INETD->get_mud_name(a)))
    return 0;
  r = a;
  a = 0;
  return 1;
}

status parse_colour(mixed result, mixed aux, int first, int last,
                    string *words, string *text) {
  mixed t;
  switch (last - first) {
  case 1:
  case 0:
    aux = implode(words[first..last], " ");
    if (member(m_indices(DESC2TERMCOL), aux) > -1)
      result = aux;
    aux = 0;
    return !!result;
  default:
    return 0;
  }
  return raise_error("This code should not be reached.\n"), 0;
}

status parse_adverbs(mixed result, mixed aux, int first, int last,
                     string *words, string *text) {
  mixed ad;
  ad = explode(implode(text[2*first+1 .. 2*last+1], ""), " ");
  result = LIB_SOUL->parse_adverbs(&ad);
  if (result == 1) {
    result = ad;
    aux = make_list(result);
  } else
    result = 0;
  return !!result;
}

status parse_adverb(mixed result, mixed aux, int first, int last,
                     string *words, string *text) {
  mixed ad;
  ad = ({ implode(text[2*first+1 .. 2*last+1], "") });
  result = LIB_SOUL->parse_adverbs(&ad);
  if (result == 1)
    result = ad[0];
  else
    result = 0;
  return !!result;
}

status parse_race(mixed result, mixed aux, int first, int last,
                  string *words, string *text) {
  mixed t;
  string race, *races, r;
  race = implode(text[2*first+1 .. 2*last+1], "");
  if (LIB_RACE->query_is_known_race(race)) {
    result = race;
  }
  else if (LIB_LANGUAGE->could_be_plural(race)) {
    races = LIB_LANGUAGE->to_singular(race);
    foreach (r : races) {
      if (LIB_RACE->query_is_known_race(r)) {
        result = r;
        break;
      }
    }
  }
  return !!result;
}


