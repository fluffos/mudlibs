#ifndef LDMUD_COMP_H
#define LDMUD_COMP_H

#include "/sys/configuration.h"
#include "/sys/interactive_info.h"

#define member_array(x, y) member(x, y)
#define strlen(x) sizeof(x)
#define file_name(x) object_name(x)
#define query_once_interactive(x) interactive(x)
#define seteuid(x) configure_object(this_object(), OC_EUID, x)
#define disable_commands() configure_object(this_object(), OC_COMMANDS_ENABLED, 0)
#define filter_array(a, b, c) filter(a, b, c)
#define allocate_mapping(s, w) m_allocate(s, w)
#define map_array(a, b, c) map(a, b, c)
#define query_ip_name(i) interactive_info(i, II_IP_NAME)
#endif