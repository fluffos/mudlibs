/*  uniq_array.c
 *  Written by: Huthar@Portals
 *
 *  This function will return an array that contains no duplicates.
 *  Gotta love them mappings. :)
 */

mixed *uniq_array(mixed *arr)
{
   mapping tmp;
   int i;

   tmp = allocate_mapping(sizeof(arr));
   for(i = 0; i < sizeof(arr); i++)
      tmp[arr[i]] = 1;

   return keys(tmp);
}
