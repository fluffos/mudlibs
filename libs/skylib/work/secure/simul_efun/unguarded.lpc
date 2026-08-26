/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */

#include <origin.h>

/**
 * This does an unguarded apply.  An unguarded apply means it chops off
 * the call tree at this point for security purposes.  This is needed to be
 * done in places where access beyond what the caller may have is needed.
 * For example, the board handler uses this to save the messages away as
 * the players and creators do not have access to save into these directories
 * normally.
 * <p>
 * @param f the function pointer to evaluate unguarded.
 * @return returns the value of the evaluated function pointer
 */
mixed unguarded( function f ) {
    object master_ob;
    
    master_ob = master() || PO;

    return master_ob->apply_unguarded( f, origin() == ORIGIN_LOCAL );

} /* unguarded() */
