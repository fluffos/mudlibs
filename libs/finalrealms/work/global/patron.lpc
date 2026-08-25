inherit "/global/creator";

#define  O_TYPE "P"

nomask
string query_gtitle()
{
  string patronage;
  patronage = "/secure/patrons"->query_patronage(name);
  if(query_female())
    return "the Bachelor of "+patronage;
   return "the Bachelor of "+patronage;
}
	    
nomask
string query_object_type() 
  {
  return O_TYPE;
  }  /* query_object_type() */

