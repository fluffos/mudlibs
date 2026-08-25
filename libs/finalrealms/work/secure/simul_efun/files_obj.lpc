// Needed these IMO, used quite a bit
// Radix - July 1996

string real_filename(object obj)
{
   string s;
   int i;
   if(sscanf(file_name(obj),"%s#%d",s,i) == 2) 
      return s;
   return file_name(obj);
}

string domain_origin(object obj)
{
   string fname = file_name(obj);
   string dom = explode(fname,"/")[1];
   if(member_array(dom,get_dir("/d/")) != -1)
      return dom;
   return 0;
}
