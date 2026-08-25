/* code to restock items / monsters up to some limit 
   in a particular location
   Taniwha September 1994
   under Thane Grimbrand of Hoerk
*/
/*
   First parameter is the TOTAL number of what should be present
     when this has done it's work
   Second parameter is basically the plural of the item.  Yes, its
      weird, code another find_match() if you don't like it.  (=
      The name here should be the plural of the items.  If you've
      biffed the add_plural() and set_main_plural() of the object
      or monster, the code will 'seem' to work but the restock
      portion won't and everything becomes a total mess.  (ie. if
      the code doesn't work, check the code for the items trying
      to be stocked and make sure its good code)
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

