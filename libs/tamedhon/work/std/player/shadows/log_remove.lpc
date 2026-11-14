#include <defines.h>

object x;

create()
{
   x = shadow(previous_object(), 1);
   printf("%O (%O)\n", x,previous_object());
}

remove()
{
	if (previous_object()==this_interactive() && this_interactive()==x)
	{
		destruct(this_object());
		return 1;
	}
	log_file("remover",sprintf("REMOVED %O by %O (%O,%O), %O (%O,%O)\n",geteuid(ME),geteuid(previous_object()),previous_object(),geteuid(this_interactive()),this_interactive()));
	this_interactive()->remove();
	destruct(this_object());
}

move()
{
	return 1;
}
