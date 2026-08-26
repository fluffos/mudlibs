// Last edited by deforce on 03-31-2010
inherit OBJ;
inherit M_GETTABLE;

private string owner = "someone";
private string type = "right hand";
private int sever_time = 0;

void mudlib_setup()
{
   add_save(({ "owner", "type", "sever_time" }));
}

varargs void setup(string set_owner, string set_type)
{
   if (set_owner)
   {
      owner = set_owner;
   }

   if (set_type)
   {
      type = set_type;
   }

   sever_time = time();

   set_id(type, "limb");

   if (sizeof(explode(type, " ")) > 1)
   {
      add_id(explode(type, " ")[1]);
   }

   set_long("The severed " + type + " of " + capitalize(owner) + ".");
   set_mass(3000);
}

string query_limb_type() { return type; }
string query_limb_owner() { return owner; }

int is_severed_limb() { return 1; }
int is_autoload() { return 1; }

void do_check_obj()
{
   write("This " + type + " was severed from " + capitalize(owner) + "'s body, " + convert_time(time() - sever_time) + " ago.\n");
}