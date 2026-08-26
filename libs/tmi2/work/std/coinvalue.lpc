// coinvalue.c
// Inheritable object which controls the relative value of coins. To be
// inherited by any object which changes money from one type of coin to
// another. Makes it easy to make centralized changes.
// Defines one function, coinvalue, which returns the number of coins
// of the LOWEST value equal to that coin. Defines a second function,
// allcoins, which returns an array of all coin types.

// States the reference value of a coin. The least valuable coin (copper here)
// should have the value 1. Other coins have values indicating the number
// of copper coins they are worth. Each coin should be worth an exact
// multiple of all lower-valued coins, otherwise the money changer barfs.

#define COINVALS ({ 1000, 100, 10, 1 })
#define COINTYPES ({ "platinum", "gold", "silver", "copper" })

int coinvalue(string str) {

	int i ;

	i = member_array(str,COINTYPES) ;
	if (i==-1) return 0 ;
	return COINVALS[i] ;
}

mixed cointypes() { return COINTYPES ; }
