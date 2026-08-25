/* code to restock items / monsters up to some limit 
   in a particular location
   Taniwha September 1994
*/
/*
   First parameter is the TOTAL number of what should be present
     when this has done it's work
   Second parameter is basicall the short name of the item
   Third parameter is the FULL path the item file 
*/
 void restock(int number,string what,string wherefrom);

 void restock(int number,string what,string wherefrom)
 {
   int i;
   object ob;
   /* find the number of WHAT's that are already here */
   i = sizeof(find_match(what, this_object()));
   /* Stock it up to the number asked for, the path to the file */
   /* is in wherefrom */
   for (  ;i<number;i++)
   {
         ob = clone_object(wherefrom);
         ob->move(this_object());
   }
 }

