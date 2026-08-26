 
//  File  :  /include/priv.h
//
//  Mudlib access permission settings
 
#define PUBLIC		0
#define READ_ONLY	1
#define OWNER_ONLY	2
#define LOCKED		3
#define MASTER_ONLY	4
#define PRIVATE		5

/*
public (only the owner can change the mode, this is good for stuff like light)
read-only (owner can change anything, others can only read)
owner-only (others can't read or write, owner can read or write or change mode)
locked, read only (can be read by anyone, can't be changed by anyone, ex. name)
master-only (only root can read or write here... good for things like password)
private (can't read or write; internal use only)
*/


