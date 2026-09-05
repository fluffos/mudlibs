
status load_suicide()
{
 input_to("prompt_suicide_1");
 return 1;
}

status prompt_suicide_1(string str)
{
 if(str != "I want to die")
 {
  write("\
You changed your mind.\n\
Good "+(gender=="male"?"boy":"girl")+".\n");
  return 1;
 }
 write("Please input your password here: ");
 input_to("prompt_suicide_2");
 return 1;
}

status prompt_suicide_2(string str)
{
 if(crypt(str,password[0..1]) != password)
 {
  write("Invalid password.\n");
  return 1;
 }
 write("\n\tYou commit SUICIDE.\n\n");
 save_object("pfiles/suicide2/"+name+implode(explode(ctime()," "),""));
 this_object()->death("Suicide");
 return 1;
}
