#ifndef __EXIT_CL_H__
#define __EXIT_CL_H__

#include "track_cl.h"

class Exit {
  string name;
  string file;
  string *aliases;
  int invis;
  function dest_func;
  function block_func;
  string pre_func;
  string post_func;
  string *doors;
  class Track *tracks;
}

#endif

