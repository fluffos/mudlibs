int
main (string str)
{
  object ob;

  /* this is because otherwise we will conflict with global variables,
     and we need to have global variables if we don't want to 
     make horrible kludge, so.. */

  ob = clone_object ("/obj/redit_ob");
  ob->main (str);
  return 1;
}
