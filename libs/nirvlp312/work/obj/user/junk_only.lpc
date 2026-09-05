chan_msg(str) {
   int index;
   object *people;
   people = users();
  for (index = 0; index < sizeof(people); index++)
   if (people[index]->on_channel("junk"))
      tell_object(people[index], str);
  return 1;
}
