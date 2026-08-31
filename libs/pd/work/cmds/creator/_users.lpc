//  users command

int cmd_users() {
   object *users;
   int p, i, a, im;

   users=users();
   i=sizeof(users);
   while(i--) {
     if(admp(users[i])) a++;
     if(wizardp(users[i]) && !admp(users[i])) im++;
     if(!wizardp(users[i])) p++;
   }
   write(a+" admins, "+im+" immortals, "+p+" players.\n");
   return 1;
}

