int trick(string str) {
    string obname, pcname;
    object ob, pc, *pcs;
    int i;
    if(sscanf(str, "%s on %s", pcname, obname) != 2)
      return notify_fail("source <item> on <player>\n");
    if(obname == "myenv")
      ob = environment(this_player());
    else if(!ob = find_player(obname))
      ob = present(obname, environment(this_player()));
    if(!ob)
      return notify_fail("Couldn't find "+obname+".\n");
    if(pcname == "all") {
      pcs = all_inventory(ob);
      i = sizeof(pcs);
      while(i--) {
        pc = pcs[i];
        write("%^BOLD%^CYAN%^"+file_name(pc)+"%^RESET%^");
        }
      } 
    else if(!pc = present(pcname, ob))
      return notify_fail("No "+pcname+" on "+capitalize(ob->query_name())+".\n");
    else
    write("\n%^BOLD%^CYAN%^"+file_name(pc)+"%^RESET%^\n");
    return 1;
}
