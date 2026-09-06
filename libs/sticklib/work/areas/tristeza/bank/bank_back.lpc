#include <room.h>
#include <areas.h>

#define	LOG_ROBBING

// If/when we use 'log_file()', we won't need full path...
//#define	LOGFILE	AREA_TRISTEZA "bank/bank_rob"
#define	LOGFILE		"bank_robbers"

int vault, code;
string *vault_desc;

void log_robber(object ob);

void
create_room()
{
    vault_desc = ({ "locked", "closed", "opened" });
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);
    set(NO_CLEANUP);
    set(PREVENT_TELEPORT);
    set_short("Small room behind the magic wall");
    set_items(([ "vault" : "There is a big wheel on the vault door", "vault door" : "=vault", "door" : "=vault", "wheel" : "It is the combination lock of the vaul\
t, you can set it to a number\n('set <number>')", "lock" : "=wheel", "combination lock" : "=wheel" ]));
    set_commands(([
	"enter" : "enter_vault",
	"set" : "set_wheel",
	"open" : "open_vault",
	"south" : "south_move"
      ]));
    add_monster(AREA_TRISTEZA+"bank/bank_guard","Bank guard arrives.",1);
}

void
set_code(int x)
{
    code = x;
    vault = 0;
}

varargs string
query_long(string str, object who)
{
    if (!str) return
	"This is a small room behind the ma\
gic wall. The vault is " + vault_desc[vault] + ".";
    else return ::query_long(str, who);
}

status
guard_hinders()
{
    if (present("guard", this_object())) {
	this_player()->tell_me("Guard doesn't allow you to do that.");
	return 1;
    }
    return 0;
}

status
south_move()
{
    this_player()->move_player(
      "through the southern wall#"+AREA_TRISTEZA+"bank/bank");
    return 1;
}

int
enter_vault(string str)
{
    if (!str || str != "vault") return 0;
    if (guard_hinders()) return 1;
    if (vault != 2) {
	this_player() -> tell_me("You have to open it first.");
	return 1;
    }
    this_player()->move_player(
      "Venters the vault#"+AREA_TRISTEZA+"bank/bank_vault");
    return 1;
}

status
set_wheel(string str)
{
    int number;

    if (!str) return 0;
    if (guard_hinders()) return 1;
    if (vault) {
	this_player()->tell_me("The vault is not locked.");
	return 1;
    }
    if (!sscanf(str, "%d", number) && !sscanf(str, "wheel %d", number) && !sscanf(str, "wheel to %d", number)) {
	this_player() -> tell_me("Try 'set <number>'.");
	return 1;
    }
    tell_here(this_player()->query_name()
      +" turns the wheel.",({ this_player() }));
    tell_here("Klick.");
    if (number == code)
	vault = 1;
    return 1;
}

int
open_vault(string str)
{
    if ( !str || ( strstr(str,"vault")==-1 && strstr(str,"door")==-1))
	return 0;
    if (guard_hinders()) return 1;
    if (!vault)
    { 
	this_player()->tell_me(
	  "You have to unlock it first using the right combination ('set <number>').");
	return 1;
    }
    if (vault == 2) {
	this_player() -> tell_me("It is already open.");
	return 1;
    }
    this_player() -> tell_me("Ok.");
    tell_here(this_player()->query_name()
      +" opens the vault.",({ this_player() }));
    log_robber(this_player());
    vault = 2;
    return 1;
}

void
log_robber(object ob)
{
    log_file(LOGFILE, capitalize((string)ob->query_real_name())
      +" " + ctime(time()) + "\n");
}

