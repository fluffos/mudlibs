string *past;

create()
{
	past = ({ });
}

void add_past(string msg) {
	if (sizeof(past) > 19)
		past = past[1..];
	past += ({ msg });
}

string get_past() {
	int i, x;
	string msg;

	if (!(i = sizeof(past)))
		return "No han habido gritos.\n";
	for (x=0;x<i;x++) {
		msg = msg + (x+1)+": "+past[x];
	}
	return msg;
}
