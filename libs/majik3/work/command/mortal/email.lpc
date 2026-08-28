// Author : Cendor@Majik
main(string str) {
string tm1,tm2; 
 if(!str) {
    write("Usage : Email [Your e-mail address | none]\n");
    return 1;
}
if(str == "none") {
  write("So your e-mail address is now 'none'\n");
  THIS->set("email",str);
  return 1;
}
if(sscanf(str,"%s@%s", tm1,tm2) != 2) {
   write("That is not a valid e-mail address.\n");
   write("Example : user@userhost\n");
   return 1;
}

 THIS->set("email",str);
 write("Your new e-mail address is '"+str+"'\n");
return 1;
}

query_author ()
{
  return "cendor";
}

query_synopsis ()
{
  return "email <email address | none>";
}

query_help ()
{
  return "Using this command you can set/modify your e-mail address. All users should have real e-mail address.";
}

query_example ()
{
  return "email namhas@majik.netti.fi";
}

query_see_also ()
{
  return "finger(1)";
}

query_position ()
{
  return POS_RESTING;
}

