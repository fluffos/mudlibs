int main ()
{
  printf ("%-15s %-30s\n", "user name", "area name"); 

  for(int i=0;i<sizeof(users());i++)
    {
      if (environment(users()[i]))
        {
          printf ("%-15s %-30s\n", capitalize(users()[i]->query_name()),
                                   environment(users()[i])->query_area());
        }
    }
  return 1;
}

