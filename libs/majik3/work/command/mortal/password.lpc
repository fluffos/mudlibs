// Author : Cendor@Majik

main(string str) {
  write("Old password :> ");
  input_to("check_old",1);
  return 1;
}

check_old(string str) {
  string old_pass;
  old_pass = THIS->query("password");
  if(old_pass && old_pass != crypt(str,"Os")) {
    write("Wrong old password. Aborting...\n");
    return 1;
}
write("New password :> ");
input_to("uus_passu1",1);
return 1;
}

uus_passu1(string str) {
  if(!str) {
    write("No password given! Aborting...\n");
    return 1;
}
  if(strlen(str) < 6 || strlen(str) > 12) {
    write("Min 6 characters and Max 12 characters allowed.\n");
    write("New password :> ");
    input_to("uus_passu1",1);
    return 1;
}

write("Again :> ");
input_to("uus_passu2",1,str);
return 1;
}

uus_passu2(string str,string eka) {
  if(!str) {
    write("No password given! Aborting...\n");
    return 1;
}

if(eka != str) {
   write("Passwords do not match! Aborting...\n");
   return 1;
}

 str = crypt(str,"Os");
 THIS->set("password",str);
 THIS->save_me();
write("Password changed succesfully.\n");
return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "You can change your password using this command. After executing"
  + " it will prompt you for your old password. Then it asks you for a new"
  + " one with repetition.";
}
