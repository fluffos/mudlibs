int same_object(object ob1, object ob2)
{
	int pos;
	string my_file, his_file;

	my_file = file_name(ob1);
	pos = member_array('#',my_file);
	if (pos == -1) return 0;
	my_file = extract(my_file, 0, pos-1);

	his_file = file_name(ob2);
	pos = member_array('#',his_file);
	if (pos == -1) return 0;
	his_file = extract(his_file, 0, pos-1);
	
	return (my_file == his_file)
}
