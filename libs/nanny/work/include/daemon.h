
#ifndef _DAEMON_H
#define _DAEMON_H

#include "config.h"

#define  write_file(XX, YY)   (int)      MASTER->daemon_write(XX, YY)
#define  read_file(XX, YY)    (string)   MASTER->daemon_read(XX, YY)
#define  file_size(XX)        (int)      MASTER->deamon_file_size(XX)
#define  get_dir(XX)          (string *) MASTER->daemon_get_dir(XX);
#define  mkdir(XX)            (int)      MASTER->deamon_mkdir(XX)
#define  rm(XX)               (int)      MASTER->daemon_rm(XX)

#endif
