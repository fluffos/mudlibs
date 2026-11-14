
nosave mapping tested_damtypes = ALL_DAMAGE_TYPES + (["mixed": 1]);
nosave mapping taken_damtypes = ALL_DAMAGE_TYPES + (["mixed": 1]);

int Defend(int dam, mixed dam_type, mixed spell, object enemy)
{
  int d;

  if (stringp(dam_type))
    dam_type = ({dam_type});
  if (sizeof(dam_type) > 1)
    tested_damtypes["mixed"] += dam;
  else
    tested_damtypes[dam_type[0]] += dam;
  d = ::Defend(dam, dam_type, spell, enemy);
  if (sizeof(dam_type) > 1)
    taken_damtypes["mixed"] += d * 10;
  else
    taken_damtypes[dam_type[0]] += d * 10;
  return d;
}

int test_sort(string a, string b)
{
  if (tested_damtypes[a] > tested_damtypes[b])
    return 1;
  return 0;
}

void reset()
{
  string *dt;
  string output;
  int i;
  int total;
  int total2;
  
  if (file_name()[0..4] == "/std/") 
  {
    set_next_reset(-1);
    return;
  }
  ::reset();
  if (interactive(this_object()))
  {
    dt = sort_array(m_indices(tested_damtypes), "test_sort");
    total = 0;
    for (i = 0; i < sizeof(dt); i++)
      total += tested_damtypes[dt[i]];
    for (i = 0; i < sizeof(dt); i++)
      total2 += taken_damtypes[dt[i]];

    output = "\n--------------------" + dtime() + "--------------------------\n";
    for (i = sizeof(dt) - 1; i >= 0; i--)
      output += sprintf("%13O:  %12d->%12d  (%6.3f%% -> %6.3f%%) %6.3f%% absorb\n", 
          dt[i], 
          tested_damtypes[dt[i]] - 1, 
          taken_damtypes[dt[i]] - 1, 
          100.0 * (tested_damtypes[dt[i]] -1) / (total || 1),
          100.0 * (taken_damtypes[dt[i]] - 1) / (total2 || 1),
          100.0 - 100.0 * taken_damtypes[dt[i]] / tested_damtypes[dt[i]]);
    write_file("/log/ARCH/damtype_statistics/" + getuid(this_object()), output);
  }
}

