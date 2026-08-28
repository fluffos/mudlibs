int main (string str)
{
  object ob;
  int i;

  if (!str)
    {
      write ("Usage   : switch <path of monster object>\n");
      write ("Example : switch /home/namhas/monsie\n");
      return 1;
    }

  ob = present (str);

  if (!ob)
    {
      write ("No such object.\n");
      return 1;
    }

  if (!living(ob))
    {
      write ("You can't do that!\n");
      return 1;
    }

  if (ob)
    {
      ob->set("switch_object", THIS);
      i = exec (ob, THIS);
      tell_object (ob, "You are now inside "+ob->short()+".\n");
      ob->setup ();
    }

  return 1;
}
