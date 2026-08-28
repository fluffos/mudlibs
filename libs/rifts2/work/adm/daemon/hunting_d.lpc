//    Daemon which keeps track of player hunting...
//    Can't quit and re-enter to back stab!

mapping all_hunters;

int clean_up() { return 0; } //don't clean up or we lose hunting

void create()
{
  all_hunters = ([]);
  return;
}

void set_mon_hunting(string who, object plyr)
{
  int i;
  object *tmp;

  if (!all_hunters[who])
    return;
  tmp = filter_array(all_hunters[who], (: objectp :) );
  all_hunters[who] = tmp;
  i = sizeof(tmp);
  while (i--)
    tmp[i]->kill_ob(plyr, 0);
  return;
}

void add_hunter(string who, object att)
{
  if (!all_hunters[who])
    all_hunters[who] = ({});
  all_hunters[who] = filter_array(all_hunters[who] + ({att}), (: objectp :));
  all_hunters[who] = distinct_array(all_hunters[who]);
  return;
}