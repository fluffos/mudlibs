inherit "/global/creator";

#define  O_TYPE "T"

string query_gtitle()
{
  string patronage;
  patronage = "/secure/thanes"->query_thane(name);
  /* I don't think it is a female Thane.. title..
  if(query_female())
    return "the Master of "+patronage;
    */
   return "the Master of "+patronage;
}

/* Maybe this shouldn't be here.. but I need it right now. Should make it
   unshadowable. Baldy.. */

nomask int query_thane() {return 1;}
	    
string query_object_type() 
  {
  return O_TYPE;
  }  /* query_object_type() */

