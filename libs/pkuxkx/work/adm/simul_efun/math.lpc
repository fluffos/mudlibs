int random(mixed range)
{
	// int range_i;
	if(floatp(range) || intp(range))
	{
		return efun::random(to_int(range));
	}
	error("random only accept int or float number\n");
	return 0;
}
