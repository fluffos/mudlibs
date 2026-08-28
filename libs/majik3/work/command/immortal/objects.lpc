do_sort (mixed a, mixed b)
{
  int aa, bb;

  aa = memory_info(a);
  bb = memory_info(b);

  if(aa < bb)
    return 1;
  else if(aa == bb)
    return 0;
  else
    return -1;
}

int
main ()
{
  object *o;
  string s;
  string flags;
  int clones;
  int hbs;
  int inter;
  int children;
  int protos;

  o = objects();
  // o = sort_array(o, "do_sort");
  s = "";
  flags = "-----";

  for (int i=0;i<sizeof(o);i++) {
    if (query_heart_beat(o[i])) {
      flags[0] = 'H';
      hbs++;
    }
    if (interactive(o[i])) {
      flags[1] = 'I';
      inter++;
    }
    if (sizeof(children(file_name(o[i]))) > 1) {
      flags[2] = 'C';
      children++;
    }
    if (clonep(o[i])) {
      flags[3] = 'L';
      clones++;
    }
    if (!clonep(o[i])) {
      protos++;
    }
    if (living(o[i]))
      flags[4] = 'V';

    s += sprintf("%-60O %4d Kb [%s]\n",o[i], (memory_info(o[i]) /1024),
    flags);
    flags = "-----";
  }

  write ("H = heart beat I = interactive C = has children L = clone V = living\n");
  rm ("/open/meep");
  write_file ("/open/meep", s);
  THIS->more_file("/open/meep");
  rm ("/open/meep");
  return 1;
}
