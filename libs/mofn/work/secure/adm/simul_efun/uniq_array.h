/**
 * This method will return an array that contains no duplicates.
 *  uniq_array.c
 *  Written by: Wodan
 * <p>
 *  This function will return an array that contains no duplicates.
 *  Gotta love them mappings. :)
 * @param arr the array to convert
 * @return an array with no duplicates
 */
mixed *uniq_array(mixed *arr){
  return keys(allocate_mapping(arr, 1));
}
