#include <cmd.h>
#include <room_defs.h>

varargs nomask status
missile_cmd(string str, object me)
{
object ob;

	if (!me && !(me = this_player())) return 0;

	if ((int) me -> query_level() < 5) return notify_fail(
		"You are not yet at level 5!\n"), 0;
	if (me -> test_dark() || !me -> query_can_move()) return 0;

	if (me -> query_sit() || me -> query_rest()) {
		me -> tell_me(TOO_RELAXED);
		return 1;
	}
	if (!str) ob = (object) me -> query_attack();
	else ob = present(lower_case(str), environment(me));
	if(!ob || !living(ob)) {
		me -> tell_me("Cast the magic missile at whom?");
		return 1;
	}
	if (ob == me) {
		me -> tell_me("Cast the magic missile at yourself???");
		return 1;
	}
//Was missing PK area check //F 2.8.1995
        if(environment(me)->query(NO_PK)) {
          me->tell_me("No player killing here.");
          return 1;
        }
//No delay? //F 2.8.1995
        call_out("misille2",2,({ob,me,environment(me)}));
        return 1;
}
 
void
missile2(mixed *arr) {
        if(arr && sizeof(arr)==3 && arr[1] && arr[2])
          if(environment(arr[1])!=arr[2])
            arr[1]->tell_me("You moved. Cancelling missile.");
          else
            arr[1]->missile_object(arr[0]);
}
