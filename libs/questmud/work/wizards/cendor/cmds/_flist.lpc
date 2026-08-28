int cmd_flist( string arg ) {
    object ob;
    object pager;
    mixed arr;
    string piu;
    int i;
    if(!arg) {
    write("Flist <object>\n");
    return 1;
    }
    ob = present( arg, this_player());
    if(!ob)
    ob = present( arg, environment(this_player()));
    if(!ob)
    ob = find_object( arg );
    if(!ob)
    ob = find_player( arg );
    if(!ob) {
    ob = find_object( arg );
    }

    if(!ob) {
    write( "Flist : Unable to find that object.\n" );
    return 1;
    }

    arr = functionlist(ob);
    i = sizeof(arr);
    piu = "";
    for(i = 0; i < sizeof(arr); i++) { 
 piu += arr[i]+ "\n ";
    }
    pager = clone_object("/wizards/cendor/pager/pager");
    pager -> move(this_object());
    pager ->page(piu);
    return 1;
}
