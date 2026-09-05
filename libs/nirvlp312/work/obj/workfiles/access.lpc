check_access(str,nom,lvl) {
   string ban;
   int x,num,denied;
   if(file_size("players/"+str+"/access") < 1) return 1;
   ban = grab_file("players/"+str+"/access");
   denied = 1;
   x = 0;
   num=sizeof(ban);
   while (x < num) {
     if(ban[x] == nom) denied = 0;
    x=x+1;
  }
    if(lvl > 39) return 1;
    return denied;
}
