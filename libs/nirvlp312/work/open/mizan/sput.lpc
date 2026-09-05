string msgs;

id(str) { return str == "sput"; }

short() { return "A sput"; }

long()
{
	write("Type 'sput'.\n");
}

reset()
{
	if(!msgs)
	{
		msgs = ({
			"You win a potato!",
			"You smell like cheese.",
			"The world is flat.",
			"I have to scratch myself.",
		});
	}
}

init()
{
	add_action("on_sput", "sput");
}

on_sput()
{
	int i;
	string temp;
	string result;

	/* our random number */
	i = random(1000);

	/* if our random number is at a certain range we use a default message */
	if(i > 250 && i < 750)
		temp = "This is the default message.";
	/* otherwise we generateour random message */
	else
		temp = msgs[random(sizeof(msgs))];

	/* assembly */
	result = "Random number: " + i + ", Message: " + temp + "\n";

	write(result);
	return 1;

}