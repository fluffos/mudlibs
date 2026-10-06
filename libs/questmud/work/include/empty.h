/* questmud's global include, #included into every object.
 *
 * The LDMud original moved objects with the 2-arg efun move_object(A, B);
 * this port turned those calls into A->move_object(B). FluffOS's efun is
 * 1-arg (it moves this_object()) and call_other() never falls back to an
 * efun, so the call is a silent no-op unless A defines move_object()
 * itself. Defining it here gives every object that function. */
mixed move_object(mixed dest) {
    return efun::move_object(dest);
}
