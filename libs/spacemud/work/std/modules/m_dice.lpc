/* Do not remove the headers from this file! see /USAGE for more info. */

//: MODULE
// This module handles all dice rolling functions. Sometimes dice expressions
// are just easier and more transparent to understand and work with than random functions.

//: FUNCTION roll_dice
// Roll x number of dice with y sides.
// Not all gaming systems use just the total of the dice, so each result is
// returned in an array.
int *roll_dice(int num_dice, int num_sides)
{
   int i;
   int *results = ({});

   for (i = 0; i < num_dice; i++)
   {
      results += ({random(num_sides) + 1});
   }
   return results;
}

//: FUNCTION dice
// int dice(int d)
// Roll a single die and return the result
int dice(int d)
{
   return random(d) + 1;
}

//: FUNCTION x_dice
// Return the sum of n dice with d sides .
int x_dice(int n, int d)
{
   int total = 0;

   for (int i = 0; i < n; i++)
      total += dice(d);
   return total;
}

//: FUNCTION x_dice_dl
// int x_dice_dl(int n, int d)
// Return the sum of n dice with d sides, discards the lowest one.
int x_dice_dl(int n, int d)
{
   int *total = ({});
   int min;

   for (int i = 0; i < n; i++)
      total += ({dice(d)});
   min = min(total);
   return sum(total) - min;
}
