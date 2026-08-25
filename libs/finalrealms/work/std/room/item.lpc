// Reworked the whole thing. Instead of storing a bunch of almost
// identical arrays and mappings, I let the queries take care of it all.
// Flode - March 1997

#include "parse_command.h"
mixed *items;
int *cur_desc;

void create()
{
  items = ({ });
  cur_desc = ({ });
}

string short()
{
  int i;
  string *ret = ({ });

  for(i=0;i<sizeof(cur_desc);i++)
    ret += ( pointerp(items[i*3]) ? ({ items[cur_desc[i]*3][0] }) :
                                    ({ items[cur_desc[i]*3] }) );
  return query_multiple_short(ret);
}

string *pretty_short()
{
  int i;
  string *ret = ({ });
     
  for(i=0;i<sizeof(cur_desc);i++)
    ret += ( pointerp(items[i*3]) ? ({items[cur_desc[i]*3][0] }) :
                                    ({ items[cur_desc[i]*3] }) );
  return ret;
}

string query_plural()
{
  int i;
  string *ret = ({ });
	 
  for(i=0;i<sizeof(cur_desc);i++)
    ret += ( pointerp(items[i*3]) ? ({ pluralize(items[cur_desc[i]*3][0]) }) :
                                    ({ pluralize(items[cur_desc[i]*3]) }) );
  return query_multiple_short(ret);
}

string *pretty_plural()
{
  int i;
  string *ret = ({ });
	     
  for(i=0;i<sizeof(cur_desc);i++)
    ret += ( pointerp(items[i*3]) ? ({ pluralize(items[cur_desc[i]*3][0]) }) :
                                    ({ pluralize(items[cur_desc[i]*3]) }) );
  return ret;
}

string long()
{
  int i;
  string ret = "";

  for(i=0;i<sizeof(cur_desc);i++)
    ret += items[cur_desc[i]*3+1];
  return ret;
}

int *query_cur_desc() { return cur_desc; }

mapping query_verbs()
{
  mapping verb = ([ ]);
  int i,j;
  string s,*bits;

  for(i=0;i<sizeof(items);i+=3)
    if(!pointerp(items[i]))
    {
      bits = explode(items[i]," ");
      s = bits[sizeof(bits)-1];
      if(!verb[s])
	verb[s] =  ({ bits[0..sizeof(bits)-2], i/3 });
      else
	verb[s] += ({ bits[0..sizeof(bits)-2], i/3 });
    }
    else for(j=0;j<sizeof(items[i]);j++)
    {
      bits = explode(items[i][j]," ");
      s = bits[sizeof(bits)-1];
      if(!verb[s])
	verb[s] =  ({ bits[0..sizeof(bits)-2], i/3 });
      else
        verb[s] += ({ bits[0..sizeof(bits)-2], i/3 });
    }
  return verb;
}

mapping query_plurals()
{
  mapping plural = ([ ]);
  int i,j;
  string s,*bits;
      
  for(i=0;i<sizeof(items);i+=3)
    if(!items[i+2])
      if(!pointerp(items[i]))
      {
        bits = explode(items[i]," ");
        s = pluralize(bits[sizeof(bits)-1]);
        if(!plural[s])
          plural[s] =  ({ bits[0..sizeof(bits)-2], i/3 });
        else
          plural[s] += ({ bits[0..sizeof(bits)-2], i/3 });
      }
      else for(j=0;j<sizeof(items[i]);j++)
      {
        bits = explode(items[i][j]," ");
        s = bits[sizeof(bits)-1];
        if(!plural[s])
          plural[s] =  ({ bits[0..sizeof(bits)-2], i/3 });
        else
          plural[s] += ({ bits[0..sizeof(bits)-2], i/3 });
      }
  return plural;
}

string *query_lng()
{
  int i;
  string *ret = ({ });

  for(i=0;i<sizeof(items);i+=3)
    ret += ({ items[i+1] });
  return ret;
}

string *query_shrt()
{
  int i;
  string *ret = ({ });

  for(i=0;i<sizeof(items);i+=3)
    ret += (pointerp(items[i]) ? ({ items[i][0] }) : ({ items[i] }) );
  return ret;
}

int drop() { return 1; }
int get()  { return 1; }

varargs void setup_item(mixed nam,mixed long,int no_plural)
{
  int i,j;
  string str;

  if(pointerp(long))
  {
    if(j=member_array("long",long))
      str = long[i+1];
  }
  else
    str = long;
  if(!str) str = "You see nothing special.\n";

  items += ({ nam, str, no_plural });
}

/* If addition then keeps existing desc and adds desc,
   otherwise it completely rewrites description */

varargs int modify_item(string str, string desc, int addition)
{
  string new1;
  int i;
  if ((i=member_array(str, query_shrt())) == -1)
    return 0;
  if (!desc)
    return 0;
  if (addition)
    {  new1 = items[i*3+1];
       new1 += desc;
       items[i*3+1]=new1;
    }
  else
    items[i*3+1] = desc;
  return 1;
}

/* Old doesn't work.
int modify_item(string str, mixed long)
{
  int i,j;

  if((i=member_array(str, query_shrt())) == -1)
    return 0;
  if(pointerp(long))
  {
    if(j=member_array("long"),long)
      items[j*3+1] = long[i+1];
  }
  else items[j*3+1] = long[i+1];
  return 1;
}
*/
int remove_item(string str)
{
  int i;

  if((i=member_array(str, query_shrt())) == -1)
    return 0;
  items = delete(items, i*3, 3);
  return 1;
}

string *parse_command_id_list()
{
  int i, j;
  string *ret = ({ });
  string *bits;

  for(i=0;i<sizeof(items);i+=3)
    if(!pointerp(items[i]))
    {
      bits = explode(items[i]," ");
      ret += ({ bits[sizeof(bits)-1] });
    }
    else for(j=0;j<sizeof(items[i]);j++)
    {
      bits = explode(items[i][j]," ");
      ret += ({ bits[sizeof(bits)-1] });
    }
  return ret;
}

string *parse_command_plural_id_list()
{
  int i, j;
  string *ret = ({ });
  string *bits;

  for(i=0;i<sizeof(items);i+=3)
    if(items[i+2])
      ret += ({ "no plural" });
    else
      if(!pointerp(items[i]))
      {
        bits = explode(items[i]," ");
        ret += ({ pluralize(bits[sizeof(bits)-1]) });
      }
      else for(j=0;j<sizeof(items[i]);j++)
      {
        bits = explode(items[i][j]," ");
        ret += ({ bits[sizeof(bits)-1] });
      }
  return ret;
}

string *parse_command_adjectiv_id_list()
{
  int i, j;
  string *ret = ({ });
  string *bits;

  for(i=0;i<sizeof(items);i+=3)
    if(!pointerp(items[i]))
    {
      bits = explode(items[i]," ");
      ret += bits[0..sizeof(bits)-2];
    }
    else for(j=0;j<sizeof(items[i]);j++)
    {
      bits = explode(items[i][j]," ");
      ret += bits[0..sizeof(bits)-2];
    }
  return ret;
}

object query_parse_id(mixed *arr)
{
  string *bits;
  mixed stuff;
  int i, j;

  if(arr[P_THING] == 0)
  {
    bits = explode(arr[P_STR], " ");
    if(!(stuff = query_plurals()[bits[sizeof(bits)-1]]))
      if(!(stuff = query_verbs()[bits[sizeof(bits)-1]]))
	return 0;
    cur_desc = ({ });
    for(j=0;j<sizeof(stuff);j+=2)
    {
      for(i=0;i<sizeof(bits)-2;i++)
	if(member_array(bits[i], stuff[j]) == -1)
	  break;
     if(i<sizeof(bits)-2)
       continue;
     cur_desc += ({ stuff[j+1] });
    }
    return this_object();
  }
  if(arr[P_THING] < 0)
  {
    bits = explode(arr[P_STR], " ");
    if(!(stuff = query_verbs()[bits[sizeof(bits)-1]]))
      return 0;
    for(j=0;j<sizeof(stuff);j+=2)
    {
      for(i=0;i<sizeof(bits)-2;i++)
	if(member_array(bits[i], stuff[j]) == -1)
	  break;
      if(i<sizeof(bits)-2 || ++arr[P_THING] != 0)
	continue;
      cur_desc = ({ stuff[j+1] });
      arr[P_THING] = -10321;
      return this_object();
    }
    return 0;
  }
  bits = explode(arr[P_STR], " ");
  if(!(stuff = query_plurals()[bits[sizeof(bits)-1]]))
    if(!(stuff = query_verbs()[bits[sizeof(bits)-1]]))
      return 0;
  cur_desc = ({ });
  for(j=0;j<sizeof(stuff);j+=2)
  {
    for(i=0;i<sizeof(bits)-2;i++)
      if(member_array(bits[i], stuff[j]) == -1)
        break;
    if(i<sizeof(bits)-2)          
      continue;
    cur_desc += ({ stuff[j+1] });
    arr[P_THING]--;
    if(arr[P_THING] <= 0)
    {
      arr[P_THING] = -10786;
      return this_object();
    }
  }
  return this_object();
}
  
void dest_me()
{
  destruct(this_object());
}

void dwep()
{
  destruct(this_object());
}

int move() { return 1; }
