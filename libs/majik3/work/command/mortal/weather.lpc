// DESCRIPTION : displays weather and stars, textually and 'graphically'
// CODER       : namhas

int wzonex, wzoney;

#define pline(x) message("0", x, THIS);
#define room(x) message("3", x, ENV(THIS), THIS);

int u, h; /* whee we have local variable limit! */

int
main (string str)
{
  int k, i, vertical, horizontal, moon1_ver, moon2_ver, moon3_ver,
      moon1_hor, moon2_hor, moon3_hor, hor_min, hor_max, linelen;

  string hors_min, hors_max, hors_mid, season, col, buf, sc;

  u = 0;
  h = 0;

  wzonex = ENV(THIS)->query_weather_zone()[0];
  wzoney = ENV(THIS)->query_weather_zone()[1];

  if (ENV(THIS)->query_outdoors() < 4)
    {
      write ("Sorry you need to be outside.\n");
      return 1;
    }

  buf = "";

  buf += "You concentrate on the sky and see:\n\n";
  if (!str)
  buf += wrap(TIME_D->describe_sky() + WEATHER_D->query_weather(wzonex, wzoney, 4)) + "\n\n";

  if (!str)
    {
      room (THIS->query_cap_name() + " concentrates on the sky.\n");
      buf += wrap("If you want to see 'graphical' picture of the sky try"
          + " typing \"weather [direction]\" example: \"weather north\".\n");
      pline (buf);
      return 1;
    }

  /* pre-query stuff to save time */

  vertical   = TIME_D->query_sun_vertical_sector();
  horizontal = TIME_D->query_sun_horizontal_sector();
  moon1_hor  = TIME_D->query_moon1_horizontal_sector();
  moon1_ver  = TIME_D->query_moon1_vertical_sector();
  moon2_hor  = TIME_D->query_moon2_horizontal_sector();
  moon2_ver  = TIME_D->query_moon2_vertical_sector();
  moon3_hor  = TIME_D->query_moon3_horizontal_sector();
  moon3_ver  = TIME_D->query_moon3_vertical_sector();
  season     = TIME_D->query_season();

  /* HORRIBLE kludge - todo: remove this kludge, eg. convert buf
     things below to array and then do this and that and so on */

  while ((moon1_ver == moon2_ver || moon1_ver == moon3_ver ||
          moon2_ver == moon3_ver || moon3_ver == moon2_ver))
    {
      if (moon1_ver == moon2_ver && moon1_ver > 10)
        moon1_ver--;
      if (moon1_ver == moon2_ver && moon1_ver <= 10)
        moon1_ver++;

      if (moon1_ver == moon3_ver && moon1_ver > 10)
        moon1_ver--;
      if (moon1_ver == moon3_ver && moon1_ver <= 10)
        moon1_ver++;

      if (moon2_ver == moon3_ver && moon2_ver > 10)
        moon2_ver--;
      if (moon2_ver == moon3_ver && moon2_ver <= 10)
        moon2_ver++;

      if (moon3_ver == moon2_ver && moon3_ver > 10)
        moon2_ver--;
      if (moon3_ver == moon2_ver && moon3_ver <= 10)
        moon2_ver++;
    }

  if (str == "north" || str == "n")
    {
      hor_min = 9;
      hor_max = 15;
      hors_min = "northwest";
      hors_max = "northeast";
      hors_mid = "north";
      room(THIS->query_cap_name() + " looks in the northern sky.\n");
    }

  if (str == "west" || str == "w")
    {
      hor_min = 5;
      hor_max = 11;
      hors_min = "southwest";
      hors_max = "northwest";
      hors_mid = "west";
      room(THIS->query_cap_name() + " looks in the western sky.\n");
    }

  if (str == "south" || str == "s")
    {
      hor_min = 1;
      hor_max = 7;
      hors_min = "southeast";
      hors_max = "southwest";
      hors_mid = "south";
      room(THIS->query_cap_name() + " looks in the southern sky.\n");
    }

  if (str == "east" || str == "e")
    {
      hor_min = 13;
      hor_max = 16;
      hors_min = "northeast";
      hors_max = "southeast";
      hors_mid = "east";
      room(THIS->query_cap_name() + " looks in the eastern sky.\n");
    }

  if (hor_min && hor_max)
    {
      if (vertical > 0)
        sc = "^bb"; /* day sky = blue */
      else
        sc = "^bl"; /* night sky = black */

      buf += "^c0" + sc;

      i = 17;
      while (1)
        {
          if (i==-1)
            break;

      linelen = 0;

      if (vertical == i)
        {
          k=0;

          for (int j=hor_min;j<hor_max;j++)
            {
              k++;

              if (horizontal == j)
                {
                  while (k)
                    {
                      k--;
                      buf += sc + "          ";
                      linelen += 10;
                    }
                  buf += "^cY*^c0"+sc+" ^cp-^c0"+sc+" ^ccsun^c0"+sc;
                  linelen += 7;
                }
            }
        }
       if (moon1_ver == i)
        {
          k = 0;
          for (int j=hor_min;j<hor_max;j++)
            {
              k++;
              if (moon1_hor == j)
                {
                  while (k)
                    {
                      k--;
                      buf += sc + "          ";
                      linelen += 10;
                    }
                  buf += "^cWo^c0"+sc+" ^cp-^c0"+sc+" ^ccafay^c0"+sc;
                  linelen += 8;
                }
            }
        }
       if (moon2_ver == i)
        {
          k = 0;
          for (int j=hor_min;j<hor_max;j++)
            {
              k++;
              if (moon2_hor == j)
                {
                  while (k)
                    {
                      k--;
                      buf += sc + "          ";
                      linelen += 10;
                    }
                  buf += "^cRo^c0"+sc+" ^cp-^c0"+sc+" ^cckizanth^c0" + sc;
                  linelen += 11;
                }
            }
        }
       if (moon3_ver == i)
        {
          k = 0;
          for (int j=hor_min;j<hor_max;j++)
            {
              k++;
              if (moon3_hor == j)
                {
                  while (k)
                    {
                      k--;
                      buf += sc + "          ";
                      linelen += 10;
                    }
                  buf += "^cLo^c0"+sc+" ^cp-^c0"+sc+" ^ccnarcos^c0"+sc;
                  linelen += 10;
                }
            }
        }

        if (!linelen) {
          buf += sc + repeat_string (" ", 76);
          linelen += 76;
        }

        buf += sc + repeat_string (" ", 76 - linelen);
         
         buf += "\n";
         i--;
       }

      if (season == "summer" || season == "spring")
        col = "^cg";
      if (season == "winter")
        col = "^cc";
      if (season == "autumn")
        col = "^cp";

      for (u=0;u<strlen(buf);u++)
        {
          if (!random(20) && buf[u] == ' ' && sc == "^bl")
            buf[u] = '.';
        }

      buf += sprintf("^c0%s- ^cy%9s^c0%s ----------------- ^cy%s horizon^c0%s ----------------- ^cy%9s^c0%s -^c0\n", col, hors_min, col,hors_mid + "ern", col, hors_max, col );
   }

  pline (buf);

  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "You can check the prevailing weather conditions with this command."
  + " You can have also have 'graphical' picture of the horizon."; 
}

query_see_also()
{
  return "time(1)";
}

query_synopsis()
{
  return "weather [direction]";
}

query_example()
{
  return "weather north";
}
query_position()
{
  return POS_STANDING;
}

