inherit ITEM;

create_item ()
{
  set_name ("meter");
  set_short ("a temperature meter");
  set_no_get();
}

long ()
{
  int wzoney;
  int wzonex;
  int i, j;
  string buf, block;

  wzonex = ENV(THIS)->query_weather_zone()[0];
  wzoney = ENV(THIS)->query_weather_zone()[1];

  i = WEATHER_D->query_temperature(wzonex, wzoney);

  buf   = "         .-.\n";
  block = " ";

  j = i+5;

  while (1)
    {
      j--;

      if (j<i-5)
        break;

      if (j==i)
        block = "^cR^br#^c0";

      buf += sprintf ("     %3d |%s|\n", j, block);
    } 

  buf += "         `-'\n";

  return buf += "\nThe temperature meter reaches to the "+i+" celcius degrees.\n";
}
