/*
 * money2.h
 *
 * This file defines the local currency units.
 * The only use of this file is that it should be included by /sys/money.h.
 */

/*
 * MONEY_TYPES  - array with the different types of money.
 * MONEY_VALUES - the values of the coins relative to the lowest denomination.
 * MONEY_WEIGHT - the weight of the types of money per coin.
 * MONEY_VOLUME - the volume of the types of money per coin.
 */
#if 0
#define MONEY_VALUES ({ 1       ,  12     , 144   , 1728 })
#endif

#define MONEY_TYPES  ({ "miedz", "srebro", "zloto", "mithryl" })
#define MONEY_VALUES ({ 1       ,  12     , 240   , 24000 })
#define MONEY_WEIGHT ({ 18      ,  21     , 19    , 21  })
#define MONEY_VOLUME ({ 2       ,  2      , 1     , 1   })

#define MONEY_ODM ({	({ "miedziany", "miedziani" }),		\
			({ "srebrny", "srebrni" }),		\
			({ "zloty", "zloci" }),			\
			({ "mithrylowy", "mithrylowi" }),	\
		  })
		  
#define MONEY_TEMATY ({	"miedz",	\
			"srebr",	\
			"zlot",		\
			"mithryl",	\
		     })

/*
 * These macros return the objectpointer to a heap of coins of the type of
 * choice. I am sure you'll know the types from the macros. The argument
 * 'num' is the number of coins that should be in the heap.
 */
#define MONEY_MAKE_CC(num)    MONEY_MAKE(num, "miedz")
#define MONEY_MAKE_SC(num)    MONEY_MAKE(num, "srebro")
#define MONEY_MAKE_GC(num)    MONEY_MAKE(num, "zloto")
#define MONEY_MAKE_MC(num)    MONEY_MAKE(num, "mithryl")
/* Dla kompatybilnosci wstecz */
#define MONEY_MAKE_PC(num)    MONEY_MAKE(num, "mithryl")

/*
 * These macros will try to move a certain amount of coins of the type
 * in the macro from the object 'from' to the object 'to'. The amount of
 * coins to be moved is stored in 'num'. I am sure that you will know the
 * types from the macro-names. If 'from' == 0, coins will be created.
 *
 * This macro has three return levels:
 *  -1 : not enough coins of the specified type in 'from'.
 *   0 : the move was succesful!
 * >=1 : an error from the function move().
 */
#define MONEY_MOVE_CC(num, from, to) MONEY_MOVE(num, "miedz", from, to)
#define MONEY_MOVE_SC(num, from, to) MONEY_MOVE(num, "srebro", from, to)
#define MONEY_MOVE_GC(num, from, to) MONEY_MOVE(num, "zloto", from, to)
#define MONEY_MOVE_MC(num, from, to) MONEY_MOVE(num, "mithryl", from, to)
/* Dla kompatybilnosci wstecz */
#define MONEY_MOVE_PC(num, from, to) MONEY_MOVE(num, "mithryl", from, to)


#define MONEY_LOG_LIMIT ([ "miedz" : 900, "srebro" : 50, "zloto" : 2, "mithryl" : 1 ])
#define MONEY_LOG_SIZE	4000000

