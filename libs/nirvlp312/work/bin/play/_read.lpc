#include "/obj/news.h"

int cmd_read(string str)
{
#ifdef __LDMUD__
  return 0;
#endif
  if(!str) {
   notify_fail("Read what?\n");
    return 0;
  }
/*
  if (str == "mail")
  {
    "/obj/mail_reader"->read();
    return 1;
  }
*/
  if (str == "news")
  {
    READER->read_it("news");
    return 1;
  }
  notify_fail("You don't see any \""+str+"\" to read.\n");
  return 0;
}
