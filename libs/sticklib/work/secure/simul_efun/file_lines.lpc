#define	FL_BUFF_SIZE	500

int
file_lines(string s)
{
    int i, j;
    string last_str, curr_str;
    string *tmp;
    while ((curr_str = read_file(s, j, FL_BUFF_SIZE)) && sizeof(curr_str)) {
	if (last_str) {
	    i += FL_BUFF_SIZE;
	}
	j += FL_BUFF_SIZE;
	last_str = curr_str;
    }
    if (last_str) {
	tmp = explode(last_str, "\n");
	i += sizeof(tmp);
	if (!sizeof(tmp[<1])) i--;
    }
    return i;
}
