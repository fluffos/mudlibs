/**
 * \c #include \c <dice.h> to use this file.
 *
 * Contains functions for emulating dice. This file currently contains only one
 * function, "roll" which is used to accurately model the values of randomly
 * rolling several dice and adding the results together. Rolling dice is a more
 * useful way to generate random numbers than the random() function because
 * dice have a heavy stabilizing property. For example, if I want a random
 * number between 2 and 12, I can use random(10)+2; however, this will
 * give me 2 or 12 just as likely as it will give me 7. If I roll two six-sided
 * dice, then the probabilities change as follows:
 *  - 2, 12: 1/36
 *  - 3, 11: 1/18
 *  - 4, 10: 1/12
 *  - 5, 9: 1/9
 *  - 6, 80: 5/36
 *  - 7: 1/6
 *
 * For combat and similar when you want all possible results, but results
 * on the average to be similar, then dice are a good way to go.
 */

/// Inheritable or externally callable object for rolling dice.

/**
 * Call this function to emulate rolling of \a num dice with \a sides spots each.
 * \return The sum of the dots on the dice rolled.
 */
int roll( int num, ///< Number of dice to roll
          int sides ///< Number of "spots" on each die.
          ) {
   int total, i;

   if( sides == 1 ) return num;

   total = 0;
   for( i = 0; i < num; i++ ) total += random(sides) + 1;

   return total;
}
