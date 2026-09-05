int stat_sys()
{
	mapping obcounts = ([]);
	string name;
	object* allobs = objects();
	string* obkeys;
	int i;
    mapping callouts_counts = ([]);
    string* callouts_keys;
    mixed* info;
	for(i=0;i<sizeof(allobs);i++)
	{
		name = base_name(allobs[i]);
		if(undefinedp(obcounts[name])) 
		{
			obcounts[name] = 1;
		}
		else
		{
			obcounts[name] = obcounts[name] + 1;
		}
		if(i%100 == 0 && i)
		{
			reset_eval_cost();
		}
	}
	obkeys = keys(obcounts);
	for(i=0;i<sizeof(obkeys);i++)
	{
		write_file("/log/obcounts.csv",obkeys[i] + sprintf(",%d\r\n",obcounts[obkeys[i]]),0);
		if(i%100 == 0 && i)
		{
			reset_eval_cost();
		}
	}
    
	info = call_out_info();
 
	for(i=0; i<sizeof(info); i++)
    {
		name = base_name(info[i][0]);
		if(undefinedp(callouts_counts[name])) 
		{
			callouts_counts[name] = 1;
		}
		else
		{
			callouts_counts[name] = callouts_counts[name] + 1;
		}
		if(i%100 == 0 && i)
		{
			reset_eval_cost();
		}
    }
 	callouts_keys = keys(callouts_counts);
	for(i=0;i<sizeof(callouts_keys);i++)
	{
		write_file("/log/callouts_counts.csv",callouts_keys[i] + sprintf(",%d\r\n",obcounts[callouts_keys[i]]),0);
		if(i%100 == 0 && i)
		{
			reset_eval_cost();
		}
	}   
                        
	return 1;
}