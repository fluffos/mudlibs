varargs status CheckArgument(string arg, string noArgFailMsg, string idFailMsg)
{
 object referenceObj;

 if(!arg)
  return (notify_fail(noArgFailMsg ? noArgFailMsg : 
              "Usage: '" + query_verb() + " <what>'\n"), 0);

 if(!(referenceObj = previous_object()))
  referenceObj = this_object();

  if(referenceObj->short() && !referenceObj->id(arg))
  return (notify_fail(idFailMsg ? idFailMsg : "\
You may only " + query_verb() + " " + 
  (string)referenceObj->short() + ".\n"), 0);

 return 1;
}
 
