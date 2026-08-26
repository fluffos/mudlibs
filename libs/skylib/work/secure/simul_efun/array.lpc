
#if !efun_defined(find_member)
/**
 * This function finds all the occurrences of the target in an array.
 * It returns an array of the positions.
 * @param target the target to get the positions for
 * @param arr the array to scan for the target
 * @return the array of target's positions in arr
 * @author Terano
 */
int *find_member( mixed target, mixed arr ) {
    int i, *ret;

    ret = ({ });

    while( ( i = member_array( target, arr, i ) ) != -1 )
        ret += ({ i++ });

    return ret;

} /* find_member() */
#endif

#if !efun_defined(delete)
/**
 * This method deletes and element from an array.
 * @param arr the array to delete an element from
 * @param start the start position to delete from
 * @param len the number of elements to delete
 * @return the new array
 */
mixed delete( mixed arr, int start, int len ) {
    return arr[0..start-1] + arr[start+len..];
} /* delete() */
#endif

#if !efun_defined(insert)
/**
 * This method inserts an element into the array.
 * It inserts an element into the array at the specified point.
 * This function accepts strings as well as arrays.
 * <p>
 * The code to do this is: "arr[0..pos-1] + ({ el }) + arr[pos..]".
 * @param arr the array to insert the element into.
 * @param el the element to insert
 * @param pos the position at which to insert it
 * @return the array with the element inserted into it
 */
mixed insert( mixed arr, mixed el, int pos ) {
    if( stringp(arr) )
        return arr[0..pos-1] + el + arr[pos..];
    return arr[0..pos-1] + ({ el }) + arr[pos..];
} /* insert() */
#endif
