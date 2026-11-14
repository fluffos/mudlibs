/* ein standard-questobjekt
 * Samtpfote@Tamedhon.at
 */
#include <properties.h>

inherit "std/thing";

void reset()
{
	if(!environment() || !interactive(environment())) {
            call_out("remove", 0);
        }
}

void create()
{
	if(!clonep(this_object())) return;
	::create();

	AddId("\nquestobjekt");
	SetProp(P_AUTOLOADOBJ, 1);
	SetProp(P_NODROP, 1);
	SetProp(P_NEVERDROP, 1);
	SetProp(P_WEIGHT, 0);
	SetProp(P_VALUE, 0);
	SetProp(P_SHORT, 0);
	SetProp(P_LONG, 0);
}
