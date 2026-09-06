#include <cmd.h>
#include <room_defs.h>

varargs nomask status
fireball_cmd(string str, object me)
{
object ob;

	if (!me && !(me = this_player())) return 0;

	if ((int) me -> query_level() < 15) return notify_fail(
		"You are not yet at level 15!\n"), 0;
	if (me -> test_dark() || !me -> query_can_move()) return 0;

	if (me -> query_sit() || me -> query_rest()) {
		me -> tell_me(TOO_RELAXED);
		return 1;
	}
	if (!str) ob = (object) me -> query_attack();
	else ob = present(lower_case(str), environment(me));
	if(!ob || !living(ob)) {
		me -> tell_me("Cast the fireball at whom?");
		return 1;
	}
	if (ob == me) {
		me -> tell_me("Cast the fireball at yourself???");
		return 1;
	}
	if (!ob->attacked_by(me, -1)) {
	  me->tell_me("No player killing here.");
	  return 1;
	}
//No delay? //F 2.8.1995
        call_out("fireball2",1,({ob,me,environment(me)}));
        return 1;
}

void
fireball2(mixed *arr) {
	if (!pointerp(arr)) return 0;
	if (!arr[1]) return 0;
	  if(environment(arr[1])!=arr[2]) {
	    arr[1]->tell_me("You moved. Cancelling fireball.");
		return;
	}
	if (!arr[0] || !present(arr[0], environment(arr[1]))) {
		arr[1]->tell_me(
"Your enemy has fled before you could cast the fireball!");
		return;
	}
	    arr[1] -> fire_ball_object(arr[0]);
}
