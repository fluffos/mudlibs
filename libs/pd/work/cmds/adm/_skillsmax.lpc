//  Skills Max

int cmd_skillsmax(string str) {
   int amt, size;
   string *sk;
   mapping skills;

   amt=atoi(str);
   if(!amt) amt=1000;
   this_player()->init_skills();
   this_player()->fix_skills();
   skills=this_player()->query_skills();
   size=sizeof(sk=keys(skills));
   while(size--) {
     this_player()->set_skill(sk[size], amt);
   }
   write("Your skills are max.\n");
}

