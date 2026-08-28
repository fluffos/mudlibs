int main(string str) {
    string *commands;
    int i;

    if (str == "" || !str)
    {
	write ("Usage:  do cmd,cmd,cmd,cmd...\n");
	return 1;
    }

    commands = explode(str, ",");
    for (i=0; i<sizeof(commands); i++)
	this_player()->force_us(commands[i]);

    return 1;
}
