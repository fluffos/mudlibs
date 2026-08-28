mixed cmd_where() 
{
  string *who_indices;
  object *all;
  mapping who;
  int i;

  who = ([]);
  all = users();

  write( sprintf("\n%-45s %s", "Players", "Location\n\n") );

  for (i=0;i<sizeof(all);i++) 
  { 
   if(!who[ file_name(environment(all[i])) ] )
    who += ([ file_name(environment(all[i])) : capitalize(all[i]->query_real_name()) ]);
     else
   {
    // Save the previous content of the mapping and concatenate
    string tmp;
    tmp = who[ file_name(environment(all[i])) ];

    who += ([ file_name(environment(all[i])) : tmp+", "+capitalize(all[i]->query_real_name()) ]);
   }
  }

  who_indices = m_indices(who);

  for (i=0;i<sizeof(who_indices);i++) 
  {
    write(sprintf("%-45s %s\n", who_indices[i], who[who_indices[i]]) );
  }

}


