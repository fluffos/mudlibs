/* find matches pilfered from /std/spells/patch.c */
/* someone really ought to make one inheritable   */
/* for both command and spell bases -- Malik      */


mixed find_unique_match(string find,mixed inx){
   object *olist;
   int i,j;
   olist = find_match(find,inx);
   for(i=0;i<sizeof(olist)-1;i++)
      if(olist[i] == olist[i+1])
         olist[i] = 0; 
   olist -= ({0});      
   return olist;
}

mixed find_one_match(string find,mixed inx){
   object *olist;
   olist = find_match(find,inx);
   olist -= ({0});
   if(!sizeof(olist)) return ({});
   return ({olist[0]});
}



