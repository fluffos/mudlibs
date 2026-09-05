string query_testchar_owner()
{
  return (string)TESTCHAR_D->query_owner(name);
}

/* added by illarion to prevent daemon calls on every check
   this function is called by the login sequence
*/
testchar_check() {
  if(query_testchar_owner())
    testchar_var=1;
  else
    testchar_var=0;
}

status is_testchar()
{ /*
  return (query_testchar_owner() ? 1 : 0);
  */
  return testchar_var;
}

status is_test_char()
{
  return is_testchar();
}

status is_tester()
{
  return is_testchar();
}

