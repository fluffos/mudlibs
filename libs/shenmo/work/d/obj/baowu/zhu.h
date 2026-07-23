int query_max_exp()
{
if ( !userp(environment(this_object())) )
      return 100000000;
else return 2000000+random(1000000);
}
