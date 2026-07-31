string msg = "";

void create()
{
	seteuid(getuid());
	call_out("cycle", 1);
}

int main(object me, string arg)
{
	if (!arg) return 0;

	msg = arg;
	return 1;
}

int s = 1;
int dir = 1;

void cycle()
{
	remove_call_out("cycle");
	s += dir;
	if (s < 2 || s > 10)
		dir = -dir;
	efun::shout("[s[1;" + s + "H " + msg + " [u");
	call_out("cycle", 3);
}
