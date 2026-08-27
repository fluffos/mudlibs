// note this doesn't guarantee that the items are in the same order

mixed *
distinct_array(mixed *arr)
{
  mixed item;

  foreach(item in arr) {
    arr -= ({ item });    // remove all instances of 'item'
    arr += ({ item });    // replace with one instance
  }

  return arr;
}
