
/* it would be best to use the roll(int) thingie. 
 * less processor intesive, but the string looks better */
/* Made by Sojan, put in Simul_efun by Baldrick. */

/* this is a dice function - rolls a dice and gives a result ... 
 * can be a simul_efun
 * or put wherever it can be accessed 
 */


int roll(int times, int type)
{
  int i,retval;
  retval=0;
  if(!times||!type) return 0;
  for(i=0;i<times;i++)
  {
    retval+=(random(type)+1);
  }
  return retval;
} /* roll */

/* input to above function is of form roll(10, 20) if you wanted to roll 
   10 20 sided dice */
