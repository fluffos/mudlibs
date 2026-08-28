mapping color = ([ "%" : ({ "wilderness",     "^cg" }),
                   "." : ({ "ground",         "^cy" }),
                   "|" : ({ "door",           "^cY" }),
                   "-" : ({ "door",           "^cY" }),
                   "#" : ({ "wall",           "^cL" }),
                   "@" : ({ "player",         "^cW" }),
                   "&" : ({ "another living", "^cW" }),
                   ">" : ({ "ladder up",      "^cw" }),
                   "<" : ({ "ladder down",    "^cw" }),
                ]);

string
colorize (string str)
{
    string buf;
    mixed retval;
    int j, k;
         
    buf = "";
                   
    j = strlen(str);

    for (int i=0;i<j;i++)
    {   
        if (pointerp (retval = color[str[i..i]])) {
    
            if (str[i] != str[i+1])
              k = -1;
    
            if (k>0)
              buf += str[i..i];
            else
              {
                if (i-1 > -1 && str[i-1] == str[i])
                  buf += str[i..i];
                else if (retval[1][2] < 97)
                  buf += retval[1] + str[i..i];
                else 
                  buf += "^c0" + retval[1] + str[i..i];
         
                k++;
              } 
        }
        else
            buf += " ";
    }
    return buf;
}

string *
draw_map (int x, int y, string *buf, string file)
{
  string *dir;
  object o, *all;
  int x2, y2;

  dir = file->query_exit_dir();

  if (file->query_outdoors() < 4)
    {
      buf[y+0][x..x+8] = "#########";
      buf[y+1][x..x+8] = "#.......#";
      buf[y+2][x..x+8] = "#.......#";
      buf[y+3][x..x+8] = "#.......#";
      buf[y+4][x..x+8] = "#.......#";
      buf[y+5][x..x+8] = "#########";
    }
  else
    {
      buf[y+0][x..x+8] = "%%%%%%%%%";
      buf[y+1][x..x+8] = "%.......%";
      buf[y+2][x..x+8] = "%.......%";
      buf[y+3][x..x+8] = "%.......%";
      buf[y+4][x..x+8] = "%.......%";
      buf[y+5][x..x+8] = "%%%%%%%%%";
    }

  for (int i=0;i<sizeof(dir);i++)
    {
      switch (dir[i])
        {
          case "north":
            buf[y+0][x+3..x+5] = "...";
            break;
          case "west": 
            buf[y+2][x+0] = '.';
            buf[y+3][x+0] = '.';
            break;
          case "south":
            buf[y+5][x+3..x+5] = "...";
            break;
          case "east":
            buf[y+2][x+8] = '.';
            buf[y+3][x+8] = '.';
            break;
          case "northwest":
            buf[y+1][x+0] = '.';
            buf[y+0][x+0..x+2] = "...";
            break;
          case "northeast":
            buf[y+1][x+8] = '.';
            buf[y+0][x+6..x+8] = "...";
            break;
          case "southwest":
            buf[y+4][x+0] = '.';
            buf[y+5][x+0..x+2] = "...";
            break;
          case "southeast":
            buf[y+4][x+8] = '.';
            buf[y+5][x+6..x+8] = "...";
            break;
          case "up":
            buf[y+1][x+5] = '<';
            break;
          case "down":
            buf[y+4][x+3] = '>';
            break;
        }
    }

  all = all_inventory (find_object(file));

  foreach (o in all)
    {
      if (!o->query_gridmap())
        {
          x2 = 0;
          y2 = 0;
        }
      else
        {
          x2 = o->query_gridmap()[0];
          y2 = o->query_gridmap()[1];
        }

      if (buf[y+y2][x+x2] == '.' && o != THIS && living(o))
        buf[y+y2][x+x2] = '&';
    }

  return buf;
}

int
main ()
{
  string out, file, *buf, *dir, *dest;
  int x, y;

  buf = allocate(18);
  dir = ENV(THIS)->query_exit_dir();
  dest = ENV(THIS)->query_exit_dest();
  file = file_name (ENV(THIS));

  for (int i=0;i<sizeof(buf);i++)
    buf[i] = repeat_string (" ", 28);

  x = 9;
  y = 6;

  buf = draw_map (x, y, buf, file);

  for (int i=0;i<sizeof(dir);i++)
    {
      switch (dir[i])
        {
          case "north":
            buf = draw_map (9, 0, buf, dest[i]);
            break;
          case "west":
            buf = draw_map (0, 6, buf, dest[i]);
            break;
          case "south":
            buf = draw_map (9, 12, buf, dest[i]);
            break;
          case "east":
            buf = draw_map (18, 6, buf, dest[i]);
            break;
          case "northwest":
            buf = draw_map (0, 0, buf, dest[i]);
            break;
          case "northeast":
            buf = draw_map (18, 0, buf, dest[i]);
            break;
          case "southwest":
            buf = draw_map (0, 12, buf, dest[i]);
            break;
          case "southeast":
            buf = draw_map (18, 12, buf, dest[i]);
            break;
        }
    }

  buf[y+THIS->query_gridmap()[1]][x+THIS->query_gridmap()[0]] = '@';

  out = "";

  for (int i=0;i<sizeof(buf);i++)
    {
      if (buf[i] != repeat_string (" ", 28))
        out += "  " + colorize (buf[i]) + "^c0\n";
    }

  message ("0", "\n" + out + "\n", THIS);
  message ("0", "Your place is shown as '^c1@^c0'. Type '^c1describe^c0' "
    + "to see what the symbols mean.\n", THIS);

  return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "Using this command you can see the small map of the surroundings. Use 'describe' command if you don't understand it.";
}

query_see_also ()
{
  return "describe(1)";
}

query_position ()
{
  return POS_STANDING;
}

