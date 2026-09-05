#include "/sys/ansi.h"

/* m_efuns; all by verte */

#include "/players/boltar/things/esc.h"

#ifndef __LDMUD__ /* m_indices native on LD - Rumplemintz */
mixed *
m_indices(mapping map)
{
     if(mapp(map)) return keys(map);
     else return ({ });
}
#endif

mapping
reconstruct_mapping(mixed *saved_map)
{
    int c, s;
    mapping new;

    new = ([ ]);
    s = sizeof(saved_map);

    for(c = 0; c < s; c+=2)
      new += ([ saved_map[c] : saved_map[c + 1] ]);
    
    return new;
}

mixed *
deconstruct_mapping(mapping map)
{
    int c, s;
    mixed *i, *n;
    i = keys(map);
    n = ({ });
    s = sizeof(i);

    for(c = 0; c < s; c++)
      n += ({ i[c], map[i[c]] });

    return n;
}

#ifndef __LDMUD__ /* Native on LD - Rumplemintz */

/* nog that shiznola .. this one by me :) */
int
member(mixed arg, mixed element)
{
    int i;
    mixed *k;
    if(pointerp(arg))
      return (i  = member_array(element, arg));
    else
    {
      i = sizeof(k = keys(arg));
      while(i --)
        if(k[i] == element)
          return 1;
      return 0;
    }
}

/* a verte invention */
mapping
m_delete(mapping map, string key)
{
     mapping new_map;
     mixed   *ks, x;
     int     i, s;

     new_map = ([ ]);
     s = sizeof(ks=keys(map));

     for(i = 0; i < s; i ++)
       if((x = ks[i]) && (x != key))
         new_map[x]=map[x];

     return new_map;
}


mixed *
m_values(mapping map)
{
    int s, i;
    mixed *m, *n;

    s = sizeof(m = keys(map));
    n = ({ });

    while (i < s)
    {
      n += ({ map[m[i]] });
      i ++;
    }

    return n;
}
#endif /* !LDMUD */

mixed
get_key(mapping map, mixed val)
{
    mixed *m, *v;
    int i, s;

    v = m_values(map);
    if((i = member_array(val, v)) == -1)
      return -1;

    m = keys(map);
    return m[i];
}

mapping
get_ansi_positions(string str)
{
    int i, s, ansi, non, flag;
    string let, heh;
    mapping m;

    heh = "";
    m = ([ ]);

    s = strlen(str);
    for(i = 0; i < s; i ++)
    {
      if((let = str[i..i]) == esc)
        flag = 1;
      if(flag)
      {
        heh += let;
        if(let == "m")
          if(((i + 1) == s) || (str[i + 1..i + 1] != esc))
          {
            m[non] = heh;
            heh = "";
            flag = 0;
          }
      }
      else non ++;
    }

    return m;
}         
    
string
delete_colour(string str)
{
    int i, s, flag;
    string heh, let;
    
    heh = "";
    s = strlen(str);
    for(i = 0; i < s; i ++)
    {
      if((let = str[i..i]) == esc)
        flag = 1;
      if(!flag) heh += let;
      else
        if(let == "m")
          flag = 0;
    }

    return heh;
}

string
colour_pad(string str, int length) 
{
    int i, s, d, ansi, flag, new_length;
    mapping positions;
    string x, heh;
    mixed *m;
    
    if(!stringp(str)) return 0;
    s = strlen(str);
    while(i < s)
    {
      if(str[i..i] == esc)
        flag = 1;
      if(flag) 
      {
        ansi ++;
        if(str[i..i] == "m") 
          flag = 0;
      }
      i ++;
    }
    
    new_length = (length + ansi); 

    if(s < new_length)
      return pad(str, new_length);
    else if(s > new_length)
    {
      positions = get_ansi_positions(str);
      x = delete_colour(str);
      str = pad(x, length);
      i = 0; s = strlen(str);
      heh = "";

      while(i < s)
      {
        if(positions[i])
        {
          heh += (positions[i] + str[i..i]);
        }
        else
          heh += str[i..i];
        i ++;
      }
      return heh + NORM;
      return esc+"[0m";
    }
    else
      return str;
}

status
text_contains(string str, string key)
{
    string a, b;

    if(sscanf(str, "%s" + key + "%s", a, b) && key)
      return 1;

    return 0;
}

string
upper_case(string str)
{
    string ev;
    int i, s;

    if(!stringp(str)) return str;
    ev = "";
    s = strlen(str);

    for(i = 0; i < s; i ++)
      ev += capitalize(str[i..i]);

    return ev;
}

