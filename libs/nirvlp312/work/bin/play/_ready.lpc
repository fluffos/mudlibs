int cmd_ready()
{
  object name_of_item;
  object next;
  string str;
  string ob;
  int    wea;
  
  name_of_item = first_inventory(this_player());
  
  while (name_of_item)
  {
    next = next_inventory(name_of_item);
    
    if(!living(name_of_item))
    {
      if(str = (string)name_of_item->short())
      {
        if(name_of_item->weapon_class() || name_of_item->armor_class() ||
           name_of_item->is_armor())
        {
          write (str+ "...\n");
          ob = (string)name_of_item->query_name();
          name_of_item->wield(ob);
          if(name_of_item->armor_class() || name_of_item->is_armor())
              command("wear "+ob, this_player());
        }
      }
    }
    name_of_item = next;
  }
  
  command("save", this_player());
  return 1;
}
