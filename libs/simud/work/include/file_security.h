#ifndef _FILE_SECURITY_H_
#define _FILE_SECURITY_H_

#define REQ_MINIMAL_READ  1
#define REQ_READ          2
#define REQ_CREATE        3
#define REQ_MODIFY        4
#define FILE_SECURITY_OBJ "/secure/file_security"
// Objects with this prefix in their filename automatically
// get root, without the master object asking for information
// from file_security. This is necessary to allow simul_efun,
// file_security itself, etc. to load.
#define AUTO_ROOT_PREFIX  "/secure/"
#define CLEANUP_TIME      (3600 * 23)

#endif