// clean_up.c
// by Annihilator@ES2
// Adapted for XKX by Xiang (12/15/95)

int clean_up()
{
	object *inv;
	int i;

    if( !clonep() && this_object()->query("no_clean_up") ) 
    	return 1;
    
    if (this_object()->blind_random_map()&&this_object()->query("no_clean_up")) 
    	return 1;
    
//如果是虚拟物品，则按照no_clean_up来判定是否需要清理
    if( (this_object()->virtual_object() ||
    	   virtualp(this_object())) && this_object()->query("no_clean_up") ) 
      return 1;
    
    if(interactive(this_object())) return 1;
    
    
    
	// If we are contained in something, let environment do the clean
	// up instead of making recursive call. This will prevent clean-up
	// time lag.
         if(environment()) return 1;

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
    {
                if(interactive(inv[i]))
								{	
									if(this_object()->query("is_xinfang") && inv[i]->query("id") != this_object()->query("owner") 
										&& inv[i]->query("marry/lover") != this_object()->query("owner") )
									{
										//派大米站在新房里避免被系统cleanup是不可以的。
										tell_object(inv[i],"你怎么在别人家里呆这么久？\n");
									}
									else
									{
										return 1;
									}
								}
               if(clonep(inv[i])&&inv[i]->query("task_object")) return 1;
    }
    for(i = sizeof(inv)-1; i>=0; i--)
    if ( !userp(inv[i])) {
        destruct(inv[i]);
    }

	destruct(this_object());
//        return 1;
        return 0;
}
