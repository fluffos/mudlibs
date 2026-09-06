// Standard module to be used by unique and pseudounique items.
// Only thing you need to add to your item's create_xxx function
// is call to set_unique; for example:
//
// void
// create_weapon()
// {
//	if (set_unique(object_name(this_object()), UNIQUENESS_PARTIAL, 5, 1) {
//		set_name("gigantic silver sword");
//		set_id(({ "silver sword", "sword" }));
//		set_long("It looks deadly!");
//		set_wc(20);
//		set_weight(4);
//		set_two_handed(1);
//	} else {
//		set_name("small silver sword");
//		set_id(({ "silver sword", "sword" }));
//		set_long("It looks quite deadly.");
//		set_wc(13);
//		set_weight(2);
//	}
// }
//
// This would create pseuodunique item, silver sword; there could be
// 5 of these in game, all in all; if more copies will be cloned,
// they will be of inferior level.

#include <unique.h>

// 1st is the actual level; 2nd level this will be, if available
// 'slots' in unique class.
// 2nd is used by lockers, for example, 1st is used by other
// objects as it defines if this really _is_ unique;
// locker has to know also, if this _could_ be unique. :-)

private int uniqueness_level;
private int uniqueness_type;

int
set_unique(string class, int level, int available, int always_available)
{
    int i;
    uniqueness_type = level;
    uniqueness_level = UNIQUENESS_NONE;

    if (level == UNIQUENESS_NONE)
	return 0;

    UNIQUE_D -> create_unique(class, available);

    if (!(i = (int) UNIQUE_D -> query_unique(class)))
	return 0;

    // No 'available slots'; ie. all unique items of this class already in use.
    // So, we can't add any more.

    if (random(available + 1) >= (i + always_available))
	return 0;

    // Also, as its harder to get unique items, when class is partially full,
    // we'll add randomization... You can configure this with argument
    // 'always_available'. It specifies how many items we get with
    // 'first try'... Ie. if it's 1, we'll always get unique item first time,
    // but after that it's possible we won't get new one even if there were
    // available slots.

    // Otherwise, we're ready to become unique...

    uniqueness_level = level;
    UNIQUE_D -> add_unique(class, this_object());
    return i;
}

varargs int
query_unique(int mode)
{
    if (!mode)
	return uniqueness_level;
    return uniqueness_type;
}
