// Moved to /bin/usr 30-sep-94.
// 29-Aug-96 / Graah: Can't zap players so easily.
#include <cmd.h>
#include <npc_defs.h>

nomask status
zap_cmd(string str)
{
    object ob;

    if (!CHECK) return 0;

    if(!str) ob = (object) TP -> query_attacker();
    else ob = present(lower_case(str), environment(TP));

    if(!ob || !living(ob)) {
	TP -> tell_me("At whom?");
	return 1;
    }

    if (ob->query(LIV_IS_PLAYER) &&
      !ob->query_testplayer())
    {
	TP->tell_me("Don't zap players!");
	return 1;
    }

    TP -> zap_object(ob);
    return 1;
}
