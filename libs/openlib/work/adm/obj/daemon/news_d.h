/*  -*- LPC -*-  */
#ifndef _NEWS_D_H
#define _NEWS_D_H

#define MAX_POSTS 100

class post {
  int timestamp;
  string thread;
  string subject;
  string author;
  string content;
}

class newsgroup {
  mapping posts;
  int first_id;
  int last_id;
  string domain;  // if this is set only members of this domain can use it
}

#endif /* _NEWS_D_H */
