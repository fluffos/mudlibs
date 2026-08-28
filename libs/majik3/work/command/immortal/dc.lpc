// dc = disconnect 

int
main (string str)
{
  int i;

  i = to_int(str);

  if (!intp(i))
    {
      write ("Usage: dc <number>\n");
      return 1;
    }

  i--;

  if (i > sizeof(users())-1 || i<0) {
    write ("No such connection available.\n");
    return 1;
  }

  write ("You disconnect user "+users()[i]->query_cap_name()+" on fd "+i+".\n");
  tell_object(users()[i], "A massive divine force crushes your connection down.\n");
  destruct (users()[i]);
  return 1;
}
