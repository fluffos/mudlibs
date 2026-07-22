// duplicate.c

mixed duplicate(mixed var)
{
	if(mapp(var))
	{
		mapping res;
		mixed *index;
		int i;

		res = var + ([]);
		i = sizeof(index = keys(var));
		while(i-- > 0)
			if(pointerp(res[index[i]]) || mapp(res[index[i]]))
				res[index[i]] = duplicate(var[index[i]]);
		return res;
	}

	else if(pointerp(var))
		return map_array(var, "duplicate", this_object());
	return var;
}  
