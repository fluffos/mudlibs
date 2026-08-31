int cmd_logins() {
   object *o;
   mixed *co;
   int i, x, expire;
   string out="";

   o=children("/adm/obj/login");
   
   if(o) o=filter_array(o, "filter_main");
   if(!o || !sizeof(o)) return notify_fail("There are currently no login sessions.\n");
   i=sizeof(o);
   while(i--) {
     out += "Obj: "+file_name(o[i])+
       ". Name: "+(o[i]->query_name()?o[i]->query_name():"Undefined")+". Expire: ";
     x=sizeof(call_out_info());
     while(x--) if(call_out_info()[x][0] == o[i]) { expire = call_out_info()[x][2]; break; }
     if(undefinedp(expire)) out += "Unknown"; else out += ""+expire+" seconds. ";
     out += ""+o[i]->query_ip()+"\n";
   }
   write(out);
   return 1;
}

int filter_main(object o) {
   if(file_name(o) == base_name(o)) return 0;
   return 1;
}

