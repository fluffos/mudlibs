#ifndef TELNET_H__
#include "/sys/telnet.h"
#endif // TELNET_H__

private int prompt_iacga;

nomask int
query_prompt_iacga() {
    return prompt_iacga;
}

nomask void
set_prompt_iacga(int arg) {
    if (arg) {
	prompt_iacga = 1;
    } else prompt_iacga = 0;
}

varargs void
print_prompt(string prompt) {
    if (prompt_iacga) {
	binary_message(to_bytes(prompt, "UTF-8"), 1);
	binary_message(({IAC, GA}), 2);
    } else {
	write(prompt);
    }
}
