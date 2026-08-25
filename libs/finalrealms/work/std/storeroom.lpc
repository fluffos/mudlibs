inherit "/std/room";
#define MAXITEMS 40

mapping room_cont;
int max_num=4;

void create() {
  room_cont = ([ ]);
  max_num = 5;
  ::create();
  call_out("test_cont",0);
}

int query_max_num() { return max_num; }
void set_max_num(int i) { max_num = i; }

void add_thing(object ob) {
  string shr;
  int value;
   object *list;

  if (!ob || environment(ob) != this_object())
    return ;
  shr = (string)ob->short();
  value = (int)ob->query_value();
  if (!room_cont[shr]) {
    room_cont[shr] = ([ value : ({ ob }) ]);
    return ;
  }
  if (!room_cont[shr][value])
    room_cont[shr][value] = ({ ob });
  else
    if (sizeof(room_cont[shr][value]) > max_num)
      call_out("do_dest", 0, ob);
    else
      room_cont[shr][value] += ({ ob });
   list = all_inventory(this_object());
   if(sizeof(list) > MAXITEMS) call_out("do_dest",0,list[0]);
  return ;
}

void do_dest(object ob) {
  if (ob && !interactive(ob) && environment(ob) == this_object())
    ob->dest_me();
}

/* for updateing etc.... */
void test_cont() {
  int i;
  object *obs;

  obs = all_inventory();
  for (i=0;i<sizeof(obs);i++)
    add_thing(obs[i]);
}

void remove_thing(object ob) {
  mixed *arr;
  int i, val;
  string sh;

  if (!ob || environment(ob) == this_object())
    return ;
  sh = (string)ob->short();
  val = (int)ob->query_value();
  if (!room_cont[sh])
    return ;
  if (!room_cont[sh][val])
    return ;
  arr = room_cont[sh][val];
  if ((i = member_array(ob, arr)) == -1)
    return ;
  if (sizeof(arr) <= 1) {
    room_cont[sh] = m_delete(room_cont[sh], val);
    if (!m_sizeof(room_cont[sh]))
      room_cont = m_delete(room_cont, sh);
  } else
    room_cont[sh][val] = delete(arr, i, 1);
}

int test_add(object ob,  int flag)
{
  call_out("add_thing", 0, ob);
   return ::test_add(ob,flag);
}

void event_exit(object ob) {
  call_out("remove_thing", 0, ob);
}
