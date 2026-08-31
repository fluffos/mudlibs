#ifndef __BOON_H__
#define __BOON_H__

public nomask void init_boon();
public nomask int boon(
  string name, string cl, string type,
  int amt, int dur
);
public nomask int curse(
  string name, string cl, string type,
  int amt, int dur
);
public nomask int query_boon(string cl, string type);
public mapping query_boon_data();
public nomask int query_curse(string cl, string type);
public mapping query_curse_data();
public nomask int query_effective_boon(
  string cl, string type
);
public nomask int remove_boon(
  string cl, string type, int tag
);
public nomask int remove_curse(
  string cl, string type, int tag
);
public nomask int remove_boon_by_name(
  string cl, string type, string name
);
public nomask int remove_curse_by_name(
  string cl, string type, string name
);
protected nomask void process_boon();

#endif // __BOON_H__
