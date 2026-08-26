int cmd_tr(string str)
 {
    mapping where;
    object ob;
    ob = this_player();
    where = ob->query("perm_exits");
    if(!where || !mapp(where))
     {
         return (int) notify_fail("Your perm_exits property is not set properly.\n");    
     }
    if(member_array(str, keys(where)) == -1)
    {
      return (int) notify_fail("You can't go there using that command right now.\n");
    }
    write("You tear the fabric of reality and step through the resulting hole.\n");
    ob->move_object(where[str] );
    return 1;
 }
    