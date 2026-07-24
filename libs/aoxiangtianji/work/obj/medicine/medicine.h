// medicine.h
inherit COMBINED_ITEM;
int is_drug() {return 1;}

int query_jicun_allow() { return 1; }

void setup()
{
  set_amount(1);
  ::setup();
}

