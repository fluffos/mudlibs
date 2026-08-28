#define pline(x) message ("0", x, THIS)

mapping m;
mapping wizlist;

do_sort (mixed a, mixed b)
{
  int aa, bb;

  aa = wizlist[a]["moves"] + wizlist[a]["objects"]*7 + wizlist[a]["heart_beats"]/100;
  bb = wizlist[b]["moves"] + wizlist[b]["objects"]*7 + wizlist[b]["heart_beats"]/100;

  if(aa < bb)
    return 1;
  else if(aa == bb)
    return 0;
  else
    return -1;
}

main (string str)
{
  string *keyarray;
  int score;
  int total = 0;
  mixed *arr;
  string poink;
  int joo;

  wizlist = ([ ]);

  if (!str)
    wizlist = author_stats();
  else
    wizlist = domain_stats();

      keyarray = keys(wizlist);

      pline ("^c0^cW^bb##. wiz name       score percent  ( heart beat | array size | errors )^c0\n");

      for(int j=0;j<sizeof(wizlist);j++) {
        if (keyarray[j] != "mortal" && keyarray[j] != "NONAME")
        total += wizlist[keyarray[j]]["moves"] +wizlist[keyarray[j]]["objects"]*7 + wizlist[keyarray[j]]["heart_beats"]/100;
      }

      for (int k=0;k<sizeof(wizlist);k++)
        {
          score = random(100) + 1;
          arr = allocate(sizeof(wizlist));
          arr[k] = ({ score, wizlist[keyarray[k]], (score * 100 / total),
                      wizlist[keyarray[k]]["heart_beats"],
                      wizlist[keyarray[k]]["array_size"],
                      wizlist[keyarray[k]]["errors"] });
        }

      keyarray = sort_array(keyarray, "do_sort");
 
      keyarray -= ({ "mortal", "NONAME" });

      if (wizardp(THIS->query_name()))
        poink = 1;

      for(int i=0;i<sizeof(keyarray);i++)
        {
          if (i>9)
            break;

          if (keyarray[i] != "mortal" && keyarray[i] != "NONAME") {
          score = wizlist[keyarray[i]]["moves"] +wizlist[keyarray[i]]["objects"]*7+wizlist[keyarray[i]]["heart_beats"]/100;
          if (poink && keyarray[i] == THIS->query_name())
            poink = 2;
          pline (sprintf ("^c0%s%2d^c0. ^c1%-14s^c0 %5d %7d    %10d   %10d   %6d\n",
            "^cc", i+1, keyarray[i], score, (score * 100 / total),
            wizlist[keyarray[i]]["heart_beats"],
            wizlist[keyarray[i]]["array_size"],
            wizlist[keyarray[i]]["errors"]));
          }
        }

      if (poink == 1 && member_array(THIS->query_name(), keyarray) > -1)
        {
          joo = member_array(THIS->query_name(), keyarray);
          score = wizlist[keyarray[joo]]["moves"]+wizlist[keyarray[joo]]["objects"]*7+wizlist[keyarray[joo]]["heart_beats"]/100;
          pline (sprintf ("^cy---^c0\n"));
          pline (sprintf ("^c0%s%2d^c0. ^c1%-14s^c0 %5d %7d    %10d   %10d   %6d\n",
            "^cc", joo+1, keyarray[joo], score, (score * 100 / total),
            wizlist[keyarray[joo]]["heart_beats"],
            wizlist[keyarray[joo]]["array_size"],
            wizlist[keyarray[joo]]["errors"]));
        }

      if (str)
        pline ("\nTotal areas in the list: "+sizeof(wizlist)+".\n");
      else
        pline ("\nTotal wizards in the list: "+sizeof(wizlist)+".\n");

  return 1;
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "Shows you top ten of most active wizzes. If you find a bug or have"
  + " something else to report you can count most on these wizzes to be"
  + " around.";
}

query_see_also()
{
  return "who(1), users(1)";
}
query_position()
{
  return POS_RESTING;
}

