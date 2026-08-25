//By ljty. 

#include <mudlib.h>
#include <hooks.h>

string short();
void hook_state(string, function, mixed);
mixed call_hooks(string, int);

private string locked, key_type;
private int door_damaged = 0;

string unlock_msg =
"$N用城门钥匙打开城门的开门装置，只要把$o推开就行了。\n"; 

string unlock_fail =
"$N把钥匙插入开门装置的孔里，但$o一点反应也没有。\n";

string lock_msg = "$N用城门钥匙打开城门的关门装置，$o被固定锁上了。\n";

string lock_fail = "$N把钥匙插入关门装置的孔里，但$o一点反应也没有。\n";

string chuang_msg = "$N的部队用攻城车使劲的撞$o，城门有点受损了。\n";

string chuang_fail =
"$N的部队使劲的撞$o，但它纹丝不动，一点效果也没有。\n"; 

string chuang_final_msg =
"$N的部队猛的一下把$o撞开了，全军一片欢呼，就要向城里涌进。\n"; 

string xiufu_msg = "$N指挥部队快速的修复$o，使它加固了此。\n";

string xiufu_fail =
"$N指挥部队修复$o，但一片忙乱，指挥失灵，城门没有变化。\n"; 

string xiufu_nouse_msg = 
"$N指挥部队修复$o，但一些敌人冲击之后，又破坏了不少，与没修之前一样。\n";

string xiufu_final_msg =
"$o也经修到最大的坚固程度了，不能再修了。\n";


function my_open_hook = (: short() + "锁上了。\n"    
                        :);

int is_lockable() { return 1; }

string query_locked() { return locked; }

string query_key_type() { return key_type; }

varargs void set_locked(string x, string y) 
{
  key_type = y;
  locked = x;
  hook_state("prevent_open", my_open_hook, locked);
}

int resistance_to_chuanging;
int max_resistance_to_chuanging;

void set_resistance_to_chuanging(int s)
{
  resistance_to_chuanging = s;
  max_resistance_to_chuanging = s;
}

int get_resistance_to_chuanging()
{
  return resistance_to_chuanging;
}

mixed xiufu()
{
  object ob = present("gold", this_body());
  //write("(with " + ob->short() + ")\n");
  write("(用"+ob->short() + ")\n");
  xiufu_with(ob);
}

void xiufu_with(object ob)
{
  int xiufu_prob = random(10);

  if(!( ob->chuang_type() == "gongchengche"))
    {
      this_body()->simple_action(xiufu_fail, this_object());
      return;
    }
  else 
    {
      if(xiufu_prob < 7) 
	{
	  resistance_to_chuanging ++;
	  this_body()->simple_action(xiufu_msg, this_object());
	}
      else 
	{
	  resistance_to_chuanging+= 0;
	  this_body()->simple_action(xiufu_nouse_msg, this_object());
	}
    }
  
  if (resistance_to_chuanging >= max_resistance_to_chuanging)
    {
      set_locked(0, key_type);
      door_damaged = 1;
      this_body()->simple_action(xiufu_final_msg, this_object());
    }
  else
    {
      if(resistance_to_chuanging > 10) door_damaged = 0;
    }
}



void chuang()
{
  object ob= present("gongchengche", environment(this_body()));
  write("(用"+ob->short() + ")\n");
  chuang_with(ob);
}

      
void chuang_with(object ob)
{
  if(!locked)
    //write("It's not locked.\n");
  write("它没有锁上。\n");     

  if(door_damaged) write("the door damaged\n");
  /*mixed ex = call_hooks("prevent_chuanging", HOOK_YES_NO_ERROR);

  if(!ex) ex = //"You can't seem to get it open.\n";
               "你无法把它弄开。\n"; 
  if(stringp(ex))
    {
      write(ex);
      return;
    }*/

  if(!( ob->chuang_type() == "gongchengche"))
    {
      this_body()->simple_action(chuang_fail, this_object());
      return;
    }
  else 
    {
      resistance_to_chuanging --;
    }
  
  if (resistance_to_chuanging < 0)
    {
      set_locked(0, key_type);
      door_damaged = 1;
      this_body()->simple_action(chuang_final_msg, this_object());
    }
  else
    {
      this_body()->simple_action(chuang_msg, this_object());
    }
}

void unlock_with(object ob)
{

  /*mixed ex = call_hooks("prevent_unlock", HOOK_YES_NO_ERROR);
  if (!ex) ex = //"You can't seem to unlock it.\n";
  "你无法把这锁打开。\n";
    if (stringp(ex)) {
      write(ex);
      return;
    }*/
   
  if (ob->key_type() == key_type)
    {
      printf("ob->key_type=%s   key_type=%s\n",ob->key_type(),key_type);
      this_body()->simple_action(unlock_msg, this_object(), ob);
      set_locked(0, key_type);
      hook_state("prevent_open", my_open_hook, locked);
    }
  else
    {
      this_body()->simple_action(unlock_fail, this_object(), ob);
    }
}

void unlock() 
{
  object ob = present("key", this_body());
  //write("(with " + ob->short() + ")\n");
  write("(用"+ob->short() + ")\n");
  unlock_with(ob);
}

void lock_with(object ob) 
{
  if(door_damaged) 
    {
      this_body()->simple_action(door_damaged,this_object(), ob);
    }
  else
    {
      if (ob->key_type() == key_type) 
	{
	  this_body()->simple_action(lock_msg, this_object(), ob);
	  set_locked(key_type,key_type);
	}
      else 
	{
	  this_body()->simple_action(lock_fail,this_object(), ob);
	}
    }
}

void lock() {
    object ob = present("key", this_body());
    //write("(with " + ob->short() + ")\n");
    write("(用"+ ob->short() + ")\n");
    lock_with(ob);
}

/*********************************************************/
/*    verb interactions                                   */
/**********************************************************/

mixed direct_chuang_obj(object ob)
{
    if (!locked)
      return //"It isn't locked.\n";
               "它没有锁上。\n";
    if (present("gongchengche", environment(this_body())))
      return 1;
    return "用什么？\n";     
}

mixed direct_xiufu_obj(object ob)
{
  if (present("gold", environment(this_body())))
    return 1;
  return "用什么？\n";     
}

mixed direct_unlock_obj(object ob) {
    if (!locked)
        return //"It isn't locked.\n";
               "它没有锁上。\n"; 
    if (present("key", this_body()))
        return 1;
    return //"With what?\n";
           "用什么？\n";     
}

mixed direct_lock_obj(object ob) {
    if (locked)
        return //"It is already locked.\n";
               "它已经被锁上了。\n";
    if (present("key", this_body()))
        return 1;
    return //"With what?";
           "用什么？\n";    
}

mixed direct_unlock_obj_with_obj(object ob1, object ob2) {
    return 1;
}

mixed direct_chuang_obj_with_obj() {
  return 1;
}

mixed direct_xiufu_obj_with_obj() {
  return 1;
}

mixed direct_lock_obj_with_obj() {
    return 1;
}
