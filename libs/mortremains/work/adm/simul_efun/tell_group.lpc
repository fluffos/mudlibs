/*
// From the wonderful people at Portals.
// tell_group - tell a group of people specfified in a file a message
// Now tells either a group of the folloing types:
//   o A file containing the names of the people
//   o An array of objects to tell
//   o An array of names to be told
//   o If the first value of an array of string == "FILES"
//     then a list of files including the names.
*/

int tell_group (mixed file, string msg)
{
   string data;
   object *people;
   int i;
   object ob;
   
   people = ({ });
   if(stringp(file))
      {
      seteuid("anonymous");
      data = read_file(file);
      if (!data) {
	 write ("Couldn't find group to 'tell'.\n");
	 return 0;
      }
      file = explode(data,"\n");
      seteuid(0);
   }
   if(!pointerp(file)) return 0;
   if(objectp(file[0])) people = file;
   if(stringp(file[0])) {
      if(file[0] == "FILES") {
         for(i = 1; i < sizeof(file); i++)
	   tell_group(file[i],msg);
         return 1;
      }
      for(i = 0; i < sizeof(file); i++)
	people += ({ find_living(file[i]) });
   }
   
   for(i = 0; i < sizeof(people); i++)
     if(people[i]) tell_object(people[i],msg);
   return 1;
}
