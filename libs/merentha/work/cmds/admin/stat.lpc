// Petrarch
// Merentha Lib 1.0
// <stat>

int command(string str) {
    object ob;
    mapping tmp;
    string ret, *t;
    int i;
    if(!str) return notify_fail("Syntax: stat <living>\n");
    ob=present(str, environment(this_player()));
    if(!ob) ob=find_player(str);
    if(!ob) ob=find_living(str);
    if(!ob) return notify_fail("Could not find them.\n");
    ret="Name : "+ob->query_name()+"\nLevel : "+ob->query_level()+" "+ob->query_race()+" "+ob->query_class()+"\n";
    ret+="hp:"+ob->query_hp()+" "+"mp:"+ob->query_mp()+" "+"sp:"+ob->query_sp()+"\n";
    i=sizeof(t=keys(tmp=ob->query_stats()));
    while(i--) t[i]=t[i]+" "+tmp[t[i]];
    ret+=format_page(t,4);
    i=sizeof(t=keys(tmp=ob->query_skills()));
    while(i--) t[i]=t[i]+" "+tmp[t[i]]["level"];
    ret+=format_page(t,4);
    message("command", ret, this_player());
    return 1;
}


string help() {
    return "Syntax: stat <living>\n\nDisplays basic information on the living creature named.";
}
