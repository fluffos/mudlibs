/*
 * From old DW owned weapon code, this effect stops non-pts
 * and all but the pt who checked the item out from wearing
 * or holding it, and makes it worth nothing.
 */

#include "defs.h"

/** @ignore yes */
string query_classification() { return "mudlib.pt.item"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"pt_item_shadow"; }

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
void beginning( object thing, string owner, int id ) {
    if( !stringp(owner) || owner == "")
        error("The owner of the object must be set.\n");
} /* beginning() */

/** @ignore yes */
void merge_effect( object thing, string oldarg, string newarg, int id ) {
    // This is bad. Real bad. Nothing should ever try to add an
    // additional pt_item effect to an item.
    error("merge_effect() called.\n");
} /* merge_effect() */
