
int
getoid(object obj)
{
	string name, dummy;
	int oid;

	if (!obj) {
		return -1;
	}
	name = file_name(obj);
	sscanf(name, "%s#%d", dummy, oid);
	return oid;
}
