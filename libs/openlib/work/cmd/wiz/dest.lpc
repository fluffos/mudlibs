#include <command.h>

int
main(string arg)
{
	object obj;

	if (!arg) {
		notify_fail("usage: dest object\n");
		return 0;
	}
	obj = find_object(arg);
	if (!obj) {
		obj = present(arg, this_player());
		if (!obj) {
			obj = present(arg, environment(this_player()));
		}
	}
	if (!obj) {
		notify_fail("dest: can't find that.\n");
		return 0;
	}
	if(obj->short())
              {
	  say(sprintf("%s crushes %s into oblivion!\n",
		      this_player()->query_cap_name(),
		      obj->short()));
              write(sprintf("You just destroyed %s!\n",obj->short()));
           }
	obj->remove();
	if (obj) {
		destruct(obj);
	}
	return 1;
}
