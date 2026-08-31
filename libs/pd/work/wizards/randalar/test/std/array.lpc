
// Some extra array functions.  Inspired from TubMUD's lib
// (don't remember all of them, but remember some that
// were useful) --Randalar
// Problems with call not liking my usage of 
// call array;flatten_array;({({3,4,5}),({5,6})}) 
// so adding simple functions that are callable
// to get the result


varargs mixed *flatten_array(mixed *arr, int recursive)
{

    for (int i = sizeof(arr); i--;)
        if (pointerp(arr[i]))
            arr[i..i] = recursive ? flatten_array(arr[i], 1) : arr[i];
    return arr;
}

mixed *flat()
{
    return flatten_array(({ ({ 1,2,3 }), ({4,5,6}) }));
}

mixed *flat1()
{
    return flatten_array( ({ ({1,2,3, ({ 4,5 }) }), ({6,7}) }), 1);
}

mixed *flat2()
{
    return flatten_array( ({ ({ 1,2,3 }), 4, 5, ({ 6, 7 }) }) );
}

mixed *flat3()
{ // Not recursive, similar to flat1()
    return flatten_array( ({ ({1,2,3, ({ 4,5 }) }), ({6,7}) }) );
}

mixed shuffle_array(mixed m) {
  int i,j;
  mixed h;
  for (i=(stringp(m)? strlen(m) : sizeof(m)); i--; )
    j=random(i+1), h=m[i], m[i]=m[j], m[j]=h;
  return m;
}
