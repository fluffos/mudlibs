//  Weblp Protocol Daemon
//  Whit

#include <daemons.h>

//Prototypes
mixed breakdown(string);
string getProtocolCommand(string);
mapping getProtocolArguments(string);

mixed breakdown(string pre) {
	string cmd;
	mapping args;
	mixed ret;

	cmd = getProtocolCommand(pre);

	if(!function_exists(cmd)) {
		CHAT_D->do_raw_chat("network", "Breakdown <network> Function " + cmd + " does not exist.");
		return 0;
	}

	args = getProtocolArguments(pre);

	ret = call_other(this_object(), cmd, args);

//	CHAT_D->do_raw_chat("network", "Breakdown <network> Return Data: " + ret);

	return ret;

}

string getProtocolCommand(string str) {
	string *arr_proto;
	string cmd = "";

	arr_proto = explode(str, ":/");
	
	cmd = arr_proto[0];

	return cmd;

}

mapping getProtocolArguments(string str) {
	string *arr_proto, *arr_args, str_args, *tmp;
	mapping arr_output;
	int i, bit_ok;
	string cmd = "";

	arr_output = ([ ]);

	arr_proto = explode(str, ":/");

	str_args = arr_proto[1];

	arr_args = explode(str_args, "&");

	for(i = 0; i < sizeof(arr_args); i ++) {
		tmp = explode(arr_args[i], "=");
		arr_output += ([ tmp[0]:tmp[1] ]);
	}

	return arr_output;

}

