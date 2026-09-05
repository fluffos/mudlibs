#pragma strict_types
#pragma save_types

int
cmd_authcheck(string str)
{
   int i,d;
   string mestr,s;

   if(this_player()->query_level() < 21)
   {
      write("Go away, non-wiz person!\n");
      return 1;
   }

   if((string)this_player()->query_real_name() != "mizan" &&
      (string)this_player()->query_real_name() != "cobain")
   if(this_player()->query_level() < 49)
   {
      write("Due to abuses by low level wizards, this information is\n");
      write("currently restricted to level 50 and above.\n");
      return 1;
   }

   s = "";
   d = time()/(60*60*24)%(64*64); /* What is today? */
   for(i=0; d>0; i++)
   {
      if(d%2 == 1) s=set_bit(s,i);
      d = d/2;
   }
  if(this_player())
  mestr=(string)this_player()->query_real_name();
  if(!mestr) mestr = "nobody";
   write("Your passcode for the day is: "+extract(crypt(mestr,s),5,8)+"\n");
   write("http://ndml.beanos.com/\n");
   return 1;
}
