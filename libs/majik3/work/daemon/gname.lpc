string
generate (string str)
{

/*
 *  RANDOM NAME GENERATOR for Majik MURPE (http://majik.netti.fi)
 *    Copyright (C) 1997 Tommi "Namhas" Leino, namhas@majik.netti.fi
 *
 */

  int i;
  int j;
  int k;
  int standard;
  int dwarven;
  int high;
  int low;
  int kludge;

  string *v_standard;
  string *c_standard;
  string *v_dwarven;
  string *c_dwarven;
  string *v_high;
  string *c_high;
  string *v_low;
  string *c_low;
  string name;

/* standard language */

  v_standard = ({ "a", "a", "e", "e", "e", "ei", "i", "i", "o", "u", "y" });
  c_standard = ({ "b", "c", "ch", "ck", "cr", "d", "d", "dr", "f", "fr", "fl",
                  "g", "gl", "h", "h", "j","k", "kr", "l", "m", "n", "n", "n",
                  "n", "nt", "p", "ph", "qu", "r", "r", "r", "s", "s", "sh",
                  "sh", "st", "t", "t", "t", "t", "t", "th", "tr", "v", "w",
                  "x", "z" });

/* dwarven language without special characters */

  v_dwarven = ({ "a", "a", "a", "e", "e", "i", "i", "i", "i", "i","hy","o","o",
                 "o","oi","o","o","u","u","u","u","y" });

  c_dwarven = ({ "b", "b", "b", "ch", "d", "dh", "f", "g", "gh", "ghw", "gw",
                 "h", "h", "hw", "j", "j", "k", "kh", "khw", "kw", "l", "l",
                 "l", "lh", "m", "m", "m", "mb", "n", "n", "nd", "ng", "nj",
                 "ngw", "nw", "p", "ps", "r", "r", "r", "s", "s", "sh", "t",
                 "ts", "th", "v", "w", "z", "z", "zh", "zh" });

/* highspeak language (elves, gnomes ...) */

  v_high = ({ "a", "a", "ae", "au", "ay", "a", "e", "e", "e", "ee", "ee",
              "ey", "eou", "i", "ia", "ia", "ie", "ie", "ii", "o", "o", "oo",
              "ou", "u", "u", "y" });

  c_high = ({ "b", "c", "ch", "d", "d", "dr", "f", "fr", "g", "h", "j", "k",
              "l", "l", "ll", "m", "n", "n", "n", "ng", "p", "qu", "r", "r",
              "r", "s", "s", "sh", "st", "sp", "t", "t", "t", "t", "th",
              "tr", "v", "w", "x", "y", "z" });

/* lowspeak language */

  v_low = ({ "a", "a", "a", "e", "e", "e", "i", "o", "o", "ou", "u", "u",
             "y" });

  c_low = ({ "b", "c", "ch", "ck", "d", "d", "dr", "f", "fr", "g", "gg",
             "gh", "gr", "h", "j", "k", "kh", "kh", "kr", "l", "ll", "m",
             "n", "n", "ng", "nt", "p", "qu", "r", "r", "r", "s", "s",
             "sh", "st", "t", "t", "t", "t", "th", "tr", "ts", "v", "w",
             "x", "y", "z", "zj" });

  name = "";

  if(str == "standard")     standard=1;
  else if(str == "dwarven") dwarven=1;
  else if(str == "high")    high=1;
  else if(str == "low")     low=1;
  else
   {
     name = "error";
   }

  k = random (4);
  k += 4;
  for (i = 0; i < k; i++)
    {
      if ((kludge == 2 || random (100) < 50) && (!kludge || kludge == 2))
{
          kludge = 1;
          if(standard)
            {
            j = random (sizeof(v_standard));
    name = name + v_standard[j];
            }
          else if(dwarven)
            {
            j = random (sizeof(v_dwarven));
            name = name + v_dwarven[j];
            }
          else if(high)
            {
            j = random (sizeof(v_high));
            name = name + v_high[j];
            }
          else if(low)
            {
            j = random (sizeof(v_low));
            name = name + v_low[j];
            }
          else {
            name = "error";
          }
}
      else if(!i || kludge)
{
          if(!i) kludge = 2;
          else kludge = 0;
          if(standard)
            {
            j = random (sizeof(c_standard));
            name = name + c_standard[j];
            }
          else if(dwarven)
            {
            j = random (sizeof(c_dwarven));
            name = name + c_dwarven[j];
            }
          else if(high)
            {
            j = random (sizeof(c_high));
            name = name + c_high[j];
            }
          else if(low)
            {
            j = random (sizeof(c_low));
            name = name+ c_low[j];
            }
          else {
            name = "error";
          }
}
    }
  return capitalize(name);
}
