#ifndef _SEARCH_H
#define _SEARCH_H 1

// Modefield 'SEARCH_WHERE'
#define SEARCH_ENV_INV   0
#define SEARCH_ENV       1
#define SEARCH_INV       2
#define SEARCH_INV_ENV   3

// Modeflags
#define SM_ALL       0
#define SM_OBJECT    (1<<2)
#define SM_IGNLIGHT  (1<<3)
#define SM_MULTI     (1<<4)
#define SM_COUNT     (1<<5)
#define SM_REALLY    (1<<6)
#define SM_LOCATE    (1<<7)

#define SM_CMULTI    (SM_MULTI|SM_COUNT)

// Modefields
#define SEARCH_WHERE     3

// Result fields for SEARCH_MULTI and SearchM()
#define FOUND_NUMBER  0 // Search() only
#define FOUND_IDS     0 // SearchM() only
#define FOUND_SINGLE  1
#define FOUND_CLASS   2
#define FOUND_MULTI   3
#define FOUND_SPECS   4 // searchm() only
#define FOUND_NOTHANDLE 4 // sort_findings() only

#define FOUND_FREE     5 // First number useable by others.

// Miscellaneous
#define SEARCH_MIN_TRANSP 250

// Aliases
#define SEARCH_ALL       SM_ALL
#define SEARCH_OBJECT    SM_OBJECT
#define SEARCH_IGNLIGHT  SM_IGNLIGHT
#define SEARCH_MULTI     SM_MULTI
#define SEARCH_COUNT     SM_COUNT
#define SEARCH_REALLY    SM_REALLY

// Abbreviations.
#define WizSearch() ((!query_user_level(this_player()) || ({int})this_player()->Query(P_NOWIZ)) ? 0 : SM_IGNLIGHT)
#define TWizSearch() ((!query_user_level(this_player()) || ({int})this_object()->Query(P_NOWIZ)) ? 0 : SM_IGNLIGHT)

#define search_env(what) search(this_player(), what, SEARCH_ENV|SM_OBJECT)
#define search_inv(what) search(this_player(), what, SEARCH_INV|SM_OBJECT)
#define search_env_inv(what) search(this_player(), what, SEARCH_ENV_INV|SM_OBJECT)
#define search_inv_env(what) search(this_player(), what, SEARCH_INV_ENV|SM_OBJECT)

#define wsearch_env(what) search(this_player(), what, SEARCH_ENV|SM_OBJECT|WizSearch())
#define wsearch_inv(what) search(this_player(), what, SEARCH_INV|SM_OBJECT|WizSearch())
#define wsearch_env_inv(what) search(this_player(), what, SEARCH_ENV_INV|SM_OBJECT|WizSearch())
#define wsearch_inv_env(what) search(this_player(), what, SEARCH_INV_ENV|SM_OBJECT|WizSearch())

#define locate_obj(where,what) locate(where,what, SM_OBJECT)
#define wlocate(where,what) locate(where,what, WizSearch())
#define wlocate_obj(where,what) locate(where,what, SM_OBJECT|WizSearch())

// Compatibility, don't use.
#define SearchEnv(what) Search(what, SEARCH_ENV|SM_OBJECT)
#define SearchInv(what) Search(what, SEARCH_INV|SM_OBJECT)
#define SearchEnvInv(what) Search(what, SEARCH_ENV_INV|SM_OBJECT)
#define SearchInvEnv(what) Search(what, SEARCH_INV_ENV|SM_OBJECT)

#define WSearchEnv(what) Search(what, SEARCH_ENV|SM_OBJECT|WizSearch())
#define WSearchInv(what) Search(what, SEARCH_INV|SM_OBJECT|WizSearch())
#define WSearchEnvInv(what) Search(what, SEARCH_ENV_INV|SM_OBJECT|WizSearch())
#define WSearchInvEnv(what) Search(what, SEARCH_INV_ENV|SM_OBJECT|WizSearch())

#define LocateObj(what) Locate(what, SM_OBJECT)
#define WLocate(what) Locate(what, WizSearch())
#define WLocateObj(what) Locate(what, SM_OBJECT|WizSearch())

#endif
