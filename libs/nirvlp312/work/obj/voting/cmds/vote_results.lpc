/* view vote results */
#include "../DEFS.h"


status main(string str)
{
  if (!str)
  {
    write("Listing of vote results you may view...\n");
    ls(VOTEDIR);
    return 1;
  }

  str = lower_case(str);
  if (!call_other(VOTED, "voteExists", str))
  {
    write("VoteName "+str+" does not exist.\n");
    return 1;
  }

  call_other(MORED, "more_file", VOTEDIR+"/"+str);
  return 1;
}
