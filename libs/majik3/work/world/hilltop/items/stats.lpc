inherit ITEM;

#define pline(x) messge ("0", x, THIS);

create_item ()
{
  set_name ("box");
  set_short ("a strange box labeled \"traffic analyzer\"");
}

long ()
{
  int *statistics;
  string data;
  string *datas;
  int tunti, aika, total;
  string buf;
  string *meep;
  int u;
  int h;

  statistics = allocate(24);
  
  data = read_file("/log/stats");
  datas = explode(data, "\n");

  for (int i=0;i<sizeof(datas);i++)
    {
      sscanf(datas[i], "%d %d", tunti, aika);
      total += aika;

      if (aika > 60)
        {
          while (1)
            {
              if (aika > 60)
                {
                  statistics[tunti] += 60;
                  aika-=60;
                  tunti++;
                  if (tunti > 23)
                    tunti = 0;
                }
              else {
                  statistics[tunti] += aika;
                  break;
              }
           }
        }
       else   
        statistics[tunti] += aika;
      h = i;
    }

  buf  = "";     
  meep = ({ });
  meep = allocate(24); 

  buf += "Total logins since 20-Oct-97   : ^cc"+sprintf("%6d", h)+"^c0\n";
  buf += "Total time used (minutes)      : ^cc"+sprintf("%6d", total)+"^c0\n";
  buf += "Average login length (minutes) : ^cc"+sprintf("%6d", (total/h))+"^c0\n";
  buf += "^cg" + repeat_string("-", 78) + "^c0\n";
  
  u = -1;

  for (int k=0;k<sizeof(statistics);k++)
    {
      u++;
      if(k==12)
        k=0;

      if (!meep[k])
        meep[k] = "";

      if (u>23)
        break;

      statistics[u] = (statistics[u] * 100 / total);
      meep[k] += sprintf ("^cp%2d ^cy%2d^c0 ^cg|^c0 ^cc%-31s^c0", u, statistics[u], repeat_string("#", statistics[u])[0..30]);
    }

  buf += implode(meep, "\n");
  buf += "^cg" + repeat_string("-", 78) + "^c0\n";

  return buf;
}
