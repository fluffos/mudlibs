// Das CheckIfAllowed ist ausgelagert, da wir es oefter brauchen

nosave int CheckIfAllowed()
{
 object ob;
 string fname;
 ob=previous_object();
 if(!objectp(ob)) return 0;
 fname=file_name(ob);
 
 if(fname == "/gilden/bardengilde/log/toplist.read") return 1;

 if(getuid(ob)!="GUILD.bardengilde"  &&
    getuid(ob)!="GUILD.barden_spells" &&
    getuid(ob)!="gwenshara" &&
    getuid(ob) != "wraz")
   { 
     if(find_player("andyl")) {
       tell_object(find_player("andyl"), sprintf("Versuchte "
       +"Aenderung im Gildenmaster von %s (direkt!)\n", CAP(getuid(ob))));
     }
     write_secure_log("Versuchte Aenderung im Gildenmaster "
		      +"von "+CAP(getuid(ob))+" (direkt!)\n");
     return 0;      
   }
 return 1;
}
