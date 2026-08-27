/*  -*- LPC -*-  */
#include <dirs.h>

/*
 * this is a helper for the function below
 */
private string
count_items(string desc, int num)
{
  if( num > 1 )
    return sprintf("%s %s", to_english(num), pluralize(desc));
  else
    return desc;
}

/*
 * this is a helper for the function below
 */
private string
get_short(object ob)
{
  string tmp = ob->short();

  if( !tmp )
    return sprintf("an invisible object [%O]", ob);
  else
    return tmp;
}

/*
 * Returns a string representation of a list of items (their short desc's)
 * arg is an array of objects
 *
 * if enumerate == 0 a string is returned that is  suitable for use in
 * an English sentence.  If enumerate == 1 the string returned is a list of
 * short descriptions preceded by the number of items with that description.
 */
varargs string
list_obs(object* list, int enumerate)
{
  mapping items = ([]);
  string* descs;

  if( !sizeof(list) ) return "";

  if( this_player() && !wizardp(this_player()) )
    list = filter(list, (: $1->short() :));   // filter invisible

  descs = map(list, (: get_short :));
  foreach(string desc in descs) items[desc]++;

  if( !enumerate ) {
    items = map(items, (: count_items :));
    descs = values(items);

    if( sizeof(descs) == 1 )
      return descs[0];
    else
      return implode(descs[0..<2], ", ") + " and " + descs[<1];
  } else {
    string ret = "";

    foreach(string key, int val in items)
      ret += sprintf("[%i] %s\n", val, capitalize(key));

    return ret;
  }
}
