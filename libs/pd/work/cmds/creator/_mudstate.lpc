//  _mudstate.c
//  Whit 4/11/05

string alig_str(string what, int x);

int cmd_mudstate() {
   int i;
   object *u;
   string out;
   i=sizeof(u=users());
   write("Lvl "+alig_str("Player", 15)+alig_str("Vitals", 15));
   while(i--) {
     out = ""+alig_str(u[i]->query_level()+"", 3)+""+alig_str(u[i]->query_name(), 13);
     out += alig_str("hp:"+u[i]->query_hp()+"/"+u[i]->query_max_hp(), 16)+
       alig_str("sp:"+u[i]->query_sp()+"/"+u[i]->query_max_sp(), 20);
     out += (u[i]->query_current_attacker()?"%^BOLD%^%^RED%^in battle%^RESET%^ ":"")+
       (query_idle(u[i]) > 1800?"idle":"");
     write(out);
   }
   return 1;
}

string alig_str(string what, int x) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
        out = what[0..x-1] + " ";
        return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}
