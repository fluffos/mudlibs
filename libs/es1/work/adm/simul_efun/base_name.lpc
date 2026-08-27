// mudlib: Basis
// date:   1992/09/05
// author: Truilkan

string base_name(mixed obj)
{
        string name, base;
        int dummy;

        if (objectp(obj)) name = file_name(obj);
	else name = obj;
        if (sscanf(name, "%s#%d", base, dummy) == 2) {
                return base;
        } else {
                return name;
        }
}
