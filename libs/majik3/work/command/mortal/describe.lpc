mapping color = ([ "%" : ({ "wilderness",     "^cg" }),
                   "." : ({ "ground",         "^cy" }),
                   "#" : ({ "wall",           "^cL" }),
                   "@" : ({ "player",         "^cW" }),
                   "&" : ({ "another living", "^cW" }),
                   ">" : ({ "ladder up",      "^cw" }),
                   "<" : ({ "ladder down",    "^cw" }),
                ]);

int
main ()
{
    int i;
    string result;
    string *arr;

    result = "";

    result += sprintf ("^c0^cW^bb%4s %29s          %4s %29s^c0\n",
      "code", "terrain type",
      "code", "terrain type");

    if (arr = keys (color))
    {
        for (i=0;i<sizeof(arr);i++)
        {
            if (i%2)
                result += "          ";

            if (THIS->query("term") == 2) {
            result += sprintf ("%s%4s^c0 %29s", color[arr[i]][1], arr[i],
              color[arr[i]][0]);
            }
            else
            result += sprintf ("%4s %29s", arr[i], color[arr[i]][0]);

            if (i%2)
                result += "\n";
        }
    }
    message ("0", result + "\n", THIS);
    return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "This command gives you legend of characters used in automatic "
       + "maps of Majik.";
}

query_see_also ()
{
  return "map(1)";
}

query_position ()
{
  return POS_RESTING;
}

