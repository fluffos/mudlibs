// Author: Cendor@Majik.

main(mixed arg) {
    object *obs;
    int i,total;
    string erkki,tmp,tmp2;
    obs = users();
    for(i=0;i<sizeof(obs);i++) {
      if(interactive(obs[i])) {
        if(obs[i]->query_ident()!="unknown")
        erkki = sprintf("%-15s : %-40s ",capitalize(obs[i]->query_name()),
        (obs[i]->query_ident()+"@"+query_ip_name(obs[i])));
else
	erkki = sprintf("%-15s : %-40s ",capitalize(obs[i]->query_name()),
	query_ip_name(obs[i]));
        erkki += "("+query_ip_number(obs[i])+")\n";
if(arg) {
   if(sscanf(lower_case(erkki),"%s"+arg+"%s",tmp,tmp2)) {
     write(erkki);
     total++; 
   }
}
   else {
     total++;
     write(erkki);
        }
      }
    }
    write("Listed total " + total + " ip names.\n");
    return 1;
}
