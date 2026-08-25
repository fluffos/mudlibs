// FluffOS PORT: minimal telnet-option constants. Upstream expected these to
// come from the LDMud driver's own mudlib/sys/telnet.h (never shipped in
// this repo -- see this project's README installation notes). Values match
// the real Telnet protocol (RFC 854) and this driver's own
// src/net/sys_telnet.h.
#define IAC     255
#define DONT    254
#define DO      253
#define WONT    251
#define WILL    251
#define SB      250
#define SE      240
#define TELOPT_GMCP 201
