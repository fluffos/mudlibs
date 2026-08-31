#include <std.h>

inherit OBJECT;

object __Rider;
int riding;
string mount, unmount;
int __Ride(string str);
int query_rideable();
int set_riding(int x);
int set_rider(object ob);
object query_rider();


void create()
{
 ::create();
 riding = 0;
}

int set_mount_message(string str)
{
 mount = str;
}
int set_unmount_message(string str)
{
 unmount = str;
}
int init()
{
 ::init();
 add_action("__Ride", "ride");
 add_action("__Dismount", "dismount");
}
int __Dismount(string str)
{
 if (__Rider != this_player()) return 0;
 if (!unmount)
 write("You dismount "+ capitalize(query_short())); 
  else
 write(unmount);
 say(this_player()->query_cap_name()+" dismounts "+capitalize(query_short())+".");
 __Rider = 0;
 this_player()->set_riding(0);
 return 1;
}
int __Ride(string str)
{
 object oi;
 
 if (!str || str=="")
   {
    write("Ride what?");
    return 1;
   }
 oi = present(str, environment(this_player()));
 if (oi != this_object()) return 0;
 
 if (query_rider()) 
   {
    write("Somebody is already mouting that.");
    return 1;
   }
 
 if (this_player()->query_riding() || this_player()->query_mounting())
   {
    write("You are already riding.");
    return 1;
   }
 if (this_player()->query_race() == "centaur" ||
     this_player()->query_race() == "weimic" ||
     this_player()->query_race() == "raknid" ||
      this_player()->query_race() == "satyr") 
    {
     write("You cannot ride anything.");
     return 1;
    }
 this_player()->set_riding(this_object());
 if (!mount)
 write("You mount "+capitalize(this_object()->query_short())+".");
 else
 write(mount);
 message("info", this_player()->query_cap_name()+ " mounts "+ capitalize(this_object()->query_short())+".\n", environment(this_player()), this_player());
 __Rider = this_player();
 return 1;
}
int query_rideable() { return 1; }

int set_riding(int x)
{
 riding = x;
}

int set_rider(object ob)
{
 if (__Rider) return 1;
 __Rider = ob;
 return 0;
}

object query_rider()
{
 return __Rider;
}

string query_short()
{
 string str;
 
 str = ::query_short();

 if (__Rider) str += " (ridden by "+__Rider->query_cap_name()+")";
 return str;
}
