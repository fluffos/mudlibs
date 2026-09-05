chan_msg(str,chan) {
   int index;
   object *people;
   people = users();
  for (index = 0; index < sizeof(people); index++)
     if(people[index])
   if (people[index]->on_channel(chan))
      tell_object(people[index], str);
  return 1;
}
