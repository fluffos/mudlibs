// file:   parsed.h
// mudlib: Basis
// date:   1992/09/26

/*
  $Locker$

  $Source$
  $Revision$
  $Author$
  $Date$
  $State$

  $Log$
*/

#define O_LIVING      1
#define O_PLAYER      2
#define O_OBJECT      4
#define O_HERE        8
#define O_INVENTORY  16
#define O_ANY  (O_LIVING|O_PLAYER|O_HERE|O_INVENTORY)
