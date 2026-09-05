/*

composite.h

Description routines, composite sentences
*/

#ifndef _sys_composite_h
#define _sys_composite_h

#define COMPOSITE_FILE "/sys/global/composite"

/*
* Standard composite descriptions for living and dead objects
*
* Usable in 2.4.6 and in 3.0
*
*/
#define COMPOSITE_LIVE(x) call_other(COMPOSITE_FILE,"desc_live",x)
#define COMPOSITE_DEAD(x) call_other(COMPOSITE_FILE,"desc_dead",x)

/* This is only usable in 3.0
*
* Function:    composite
* Description: Creates a composite description of objects
* Arguments:   x:          Array of the objects to describe
*              sf:         Function to call in objects to get its <name>
*                          Objects with the same <names> are described together
*              df:         Function to call to get the actual description of
*                          a group of 'same objects' i.e objects whose
*                          'sf' returned the same value.
*              ob:         Object to call df in.
*
* Returns:     A description string on the format:
*              <desc>, <desc> and <desc>
*              Where <desc> is what ob->df() returns
*
*/
#define COMPOSITE(x,sf,df,ob) call_other(COMPOSITE_FILE,"composite",x,sf,df,ob)



/*
* Returns the array of unique objects from the last call to COMPOSITE
*
* Usable only in 3.0
*/

#define COMPOSITE_OBLAST call_other(COMPOSITE_FILE,"get_last_objects")

#endif
