/*
 * This file is to be included by /kernel/simul_efun.c and /basic/fold.c for
 * compatibility reasons.
 * You need not inherit basic/fold anymore since the functions in here are
 * now simul_efuns!
 */

/* 
 * fold_left folds an array of items or a string over a given function
 * it gets at least two arguments (plus an optional third), 
 * first, the function (this must be given as a lambda closure), which has 
 * to be a function getting two arguments (first of type of begin, 
 *  second of type of the items in the list)    
 * second, the list of items (an array, or a string) which you want to
 * fold over the function, and the optional third a begin-element, which 
 * otherwise will be assumed as 0.
 * the list will be folded over the given function beginning with the begin-
 * element and the most left (first) item of the list, passing the
 * result as first argument and the next item as second argument to the
 * function again ... when there are no more items in the list, the result
 * is returned (if the list is empty, begin will be the result)
 * 
 * for example: you have a function int plus(int a, int b) { return a + b; }
 * fold_left( #'plus, ({ 3, 4, 5 }), 42 ); would return the value of the
 * expression: (((42 + 3) + 4) + 5) (whatever that is P-))
 *
 * with this function many operators can be put to good use, for instance
 * max, min, +, *, (maybe even ->, if you're going through a list of objects,
 * for instance)
 *
 */

varargs mixed 
fold_left(mixed foo, mixed args, mixed begin)
{
  int size, i;
  if(!(size = (stringp(args) ? /* should the string be folded ? */
               strlen(args) :  /* else fold the array */
               sizeof(args)))) return begin;
  for( i = 0; i < size; i++ )
    begin = funcall(foo, begin, args[i]);
  return begin;
}

/*
 * fold_right works like fold_left, with the difference, that the evaluation
 * is begun with the begin-element passed as second argument, and the
 * most right (last) element of the list as first argument to the function,
 * which the list shall be folded over, passing the result again as second 
 * argument and the element before the last used one of the list, as first.
 * 
 * this could for instance be useful for a multiplication of a list
 * of matrices with a vector (begin)
 * other example:
 * string kons(int letter, string str) { 
 *   return to_string( ({ letter }) + to_array ( str ) );
 * }
 *
 * then the call fold_right ( #'kons, "Hello, ", "world!" );
 * would return the same as 
 * kons('H', kons('e', kons('l', kons('l', kons('o', kons(',', 
 *   kons(,' ',"world!"))))))), which again would be a sophisticated way of
 * doing "Hello, "+"world!" (in lpc) P-)
 *
 */

varargs mixed 
fold_right(closure foo, mixed args, mixed begin)
{
  int size, i;
  if(!(size = (stringp(args) ? 
               strlen(args) :
               sizeof(args)))) return begin;
  for( i = 1, size++; i < size; i++ ) 
    begin = funcall(foo, args[<i], begin);
  return begin;
}

