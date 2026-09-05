int one_cmd;

int do_sql_cmd(string my_query)
{
    int handle, num_rows_affected, x, a, col_length;
    string my_row, an_error, *my_columns, *this_record;
    mixed *full_rs;
    handle = db_connect();
    full_rs = ({ });

    if(my_query == "\\q")
    {
	write("Exiting.\n");
	return 1;
    }

    if(!my_query)
    {
	write("Please enter a SQL command.\n> ");
	input_to("do_sql_cmd");
	return 1;
    }

    db_exec(handle,my_query);
    an_error = db_error(handle);

    if(an_error)
    {
	write("Error: \n" + an_error + "\n> ");
	db_close(handle);
	if(!one_cmd)
	    input_to("do_sql_cmd");
	return 1;
    }

    num_rows_affected = db_affected_rows(handle);
    my_columns = db_coldefs(handle);
    if(handle && my_query)
    {
	while(sizeof(my_row = db_fetch(handle)))
	    full_rs += ({ my_row });
	db_close(handle);
    }

    if(sizeof(my_columns))
    {
	handle = 0;
	for(x = 0; x < sizeof(my_columns); x++)
	{
	    if(handle < strlen(my_columns[x]))
		handle = strlen(my_columns[x]);
	}

	for(x = 0; x < sizeof(full_rs); x++)
	{
	    this_record = full_rs[x];
	    for(a = 0; a < sizeof(this_record); a++)
	    {
		if(handle < strlen(this_record[a]))
		    handle = strlen(this_record[a]);
	    }
	}
	col_length = (sizeof(my_columns)) * (handle+3) + 1;
	for(x = 0; x < col_length; x++)
	    write("=");
	write("\n");
	for(x = 0; x < sizeof(my_columns); x++)
	    write("| " + pad(my_columns[x],handle) +" ");
	write("|\n");
	for(x = 0; x < col_length; x++)
	    write("=");
	write("\n");
    }

    for(x = 0; x < sizeof(full_rs); x++)
    {
	this_record = full_rs[x];
	for(a = 0; a < sizeof(this_record); a++)
	{
	    write("| " +pad(this_record[a],handle) + " ");
	}
	write("|\n");
    }

    if(sizeof(my_columns))
    {
	for(x = 0; x < col_length; x++)
	    write("=");
	write("\n" + sizeof(full_rs) + " row(s) returned.\n");
    }
    if(num_rows_affected > 0)
	write(num_rows_affected + " row(s) affected.\n");
    if(one_cmd)
	return 1;
    write("> ");
    input_to("do_sql_cmd");
    return 1;
}

cmd_mysql(string str)
{
    one_cmd = 0;
    if(this_player()->query_level() < 1000) return 0;
    if(!str)
    {
        write("Input sql commands.\nUse '\\q' on a blank line when finished.\n> ");
	input_to("do_sql_cmd");
	return 1;
    }
    one_cmd = 1;
    do_sql_cmd(str);
    return 1;
}
