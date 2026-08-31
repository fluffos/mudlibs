#include <daemons.h>
#include <security.h>
#include <std.h>
#include <objects.h>

//  Prototypes
private string get_password(string);
int userAuthenticate(mapping);
int userIsAuthenticated(mapping);

mapping userAuthentication = ([]);

//  Store authentication as user, uniqid, ip

int userAuthenticate(mapping data) {
	string username		= data["username"];
	string password		= data["password"];
	string pass			= "";
	string uniqid		= "";
	string ip			= data["ip"];
	object obj_user		= new(OB_USER);
	int ok				= 0;

	if(!user_exists(username)) {
		return 0;
	}
    if((pass = (string)get_password(username)) != crypt(password, pass) && (pass!=oldcrypt(password,pass))) {
		CHAT_D->do_raw_chat("network", "Authentication <network> FAIL: " + crypt(password, pass));
		return 0;
	} else {
		CHAT_D->do_raw_chat("network", "Authentication <network> " + username + " authenticated at " + ip);
		return 1;
	}
}

int userIsAuthenticated(mapping data) {
	string user = data["username"];
	string id   = data["id"];
	string ip   = data["ip"];

	if(!userAuthentication[user]) return 0;
	if(userAuthentication[user]["ip"] != ip) return 0;
	if(userAuthentication[user]["id"] != id) return 0;

	return 1;
}

private string get_password(string username) {
	string file = "/adm/save/users/" + username[0..0] + "/" + username + ".o";
	string *lines;
	string password;
	int i;

	if(!file_size(file) < 0) return "";

	seteuid(UID_ROOT);
	lines = explode(read_file(file), "\n");
	seteuid(getuid());

	for (i = 0; i < sizeof(lines); i ++) {
		if(lines[i][0..7] == "password") {
			password = lines[i][10..sizeof(lines[i]) - 2];
		}
	}
	return password;
}
