#define PREV previous_object()

main ()
{
	if (PREV->query_switch_object())
    {
		efun::exec (PREV->query_switch_object(), PREV);
		write ("\nBack!\n");
    }
	else
    {
		write ("You are not inside another body.\n");
    }
	return 1;
}
